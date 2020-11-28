#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
void print_letters(char arg[], int length);

void print_arguments(int argc, char *argv[])
{
  int i;

  for (i = 1; i < argc; i += 1)
  {
    print_letters(argv[i], strlen(argv[i]));
  }
}

void print_letters(char arg[], int length)
{
  int i;
  char ch;

  for (i = 0; i < length; i += 1)
  {
    ch = arg[i];
    if (isalpha((int)ch) || isblank((int)ch) || isdigit((int)ch))
    {
      printf("%c: %d\t ", ch, ch);
    }
  }

  printf("\n");
}

int main(int argc, char *argv[])
{
  print_arguments(argc, argv);
  return 0;
}
