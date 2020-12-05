#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address
{
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

struct Database
{
  struct Address rows[MAX_ROWS];
};

struct Connection
{
  FILE *file;
  struct Database *db;
};

// Report an internal error from a header if any
// printing the message passe din
void die(const char *message, struct Connection *conn)
{
  if (errno)
    perror(message);
  else
    printf("Error: %s\n", message);

  Database_close(conn);
  exit(1);
}

// prints an address struct to stdout
void Address_print(struct Address *addr)
{
  printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// read an opened DB into memory
void Database_load(struct Connection *conn)
{
  int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
  if (rc != 1)
    die("Failed to load database.", conn);
}

// set up connection in memory
// open the db file for r or w
struct Connection *Database_open(const char *filename, char mode)
{
  // allocate the struct in memory
  struct Connection *conn = malloc(sizeof(struct Connection));
  if (!conn)
    die("Memory error", conn);
  conn->db = malloc(sizeof(struct Database));
  if (!conn->db)
    die("Memory error", conn);

  // create mode, open file for write only
  if (mode == 'c')
    conn->file = fopen(filename, "w");
  // all other modes, open for read & write
  else
  {
    conn->file = fopen(filename, "r+");
    if (conn->file)
      Database_load(conn);
  }

  // handle failure
  if (!conn->file)
    die("Failed to open the file", conn);

  return conn;
}

// close the db and free memory used to store
// its contents
void Database_close(struct Connection *conn)
{
  if (conn)
  {
    if (conn->file)
      fclose(conn->file);
    if (conn->db)
      free(conn->db);
    free(conn);
  }
}

void Database_write(struct Connection *conn)
{
  // rewind to the beginning of the file if not there
  rewind(conn->file);

  // attempt write
  // pass in db pointer, size to block write,
  // # blocks, file pointer
  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);

  // handle failed write
  if (rc != 1)
    die("Failed to write database.", conn);

  // flush any buffered input to disk
  rc = fflush(conn->file);
  if (rc == -1)
    die("Cannot flush database", conn);
}

// Iterates MAX_ROWS, initializing the db in memory
// to empty entries
void Database_create(struct Connection *conn)
{
  int i = 0;
  for (i = 0; i < MAX_ROWS; i++)
  {
    // make a prototype to initialize it
    struct Address addr = {.id = i, .set = 0};

    // assign it
    conn->db->rows[i] = addr;
  }
}

// set a value in the db
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
  // get ref to a row in memory
  struct Address *addr = &conn->db->rows[id];

  // if set bit is already set, exit
  if (addr->set)
    die("Already set, delete it first", conn);

  // set the set bit
  addr->set = 1;

  char *res = strncpy(addr->name, name, MAX_DATA);
  (addr->name)[MAX_DATA - 1] = '\0';

  if (!res)
    die("Name copy failed", conn);

  res = strncpy(addr->email, email, MAX_DATA);
  (addr->email)[MAX_DATA - 1] = '\0';

  if (!res)
    die("Email copy failed", conn);
}

// Retreives a record for printing and prints it
// but only if its set flad is 1
void Database_get(struct Connection *conn, int id)
{
  struct Address *addr = &conn->db->rows[id];
  if (addr->set)
    Address_print(addr);
  else
    die("ID is not set", conn);
}

// overwrite the selected ID with an empty entry
void Database_delete(struct Connection *conn, int id)
{
  struct Address addr = {.id = id, .set = 0};
  conn->db->rows[id] = addr;
}

// list all entries that have the set bit
void Database_list(struct Connection *conn)
{
  int i = 0;
  struct Database *db = conn->db;

  for (i = 0; i < MAX_ROWS; i += 1)
  {
    struct Address *cur = &db->rows[i];

    if (cur->set)
      Address_print(cur);
  }
}

int main(int argc, char *argv[])
{
  // fail if not enough args passed
  if (argc < 3)
    die("USAGE: ex17 <dbfile> <action> [action params]", 0);

  // initialize vars
  char *filename = argv[1]; // pointer to filename
  char action = argv[2][0]; // character selecting action
  struct Connection *conn = Database_open(filename, action);
  int id = 0;

  // get the ID argument
  if (argc > 3)
    id = atoi(argv[3]);
  if (id >= MAX_ROWS)
    die("There's not that many records.", conn);

  // branch based on action argument
  switch (action)
  {
  // create new db
  case 'c':
    Database_create(conn); // create DB in memory
    Database_write(conn);  // write it to disk
    break;
  // get and print an entry
  case 'g':
    if (argc != 4)
      die("Need an id to get", conn);
    Database_get(conn, id); // get the entry
    break;
  case 's':
    if (argc != 6)
      die("Need if, name, email to set", conn);
    Database_set(conn, id, argv[4], argv[5]);
    Database_write(conn);
    break;
  case 'd':
    if (argc != 4)
      die("Need id to delete", conn);
    Database_delete(conn, id);
    Database_write(conn);
    break;
  case 'l':
    Database_list(conn);
    break;
  default:
    die("Invalid action: c=create, g=get, s=set, d=del, l=list", conn);
  }

  Database_close(conn);

  return 0;
}
