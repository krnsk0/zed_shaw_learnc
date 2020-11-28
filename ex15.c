#include <stdio.h>

int main(int argc, char *argv[])
{
  // create two arrays
  int ages[] = {23, 43, 12, 89, 2};
  char *names[] = {
      "Alan",
      "Frank",
      "Mary",
      "John",
      "Lisa"};

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // using indexing
  for (i = 0; i < count; i += 1)
  {
    printf("%s has %d years alive.\n", names[i], ages[i]);
  }
  printf("---\n");

  // using pointers

  int *cur_age = ages;
  char **cur_name = names;
  for (i = 0; i < count; i += 1)
  {
    printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
  }
  printf("---\n");
  // third way, pointers are just arrays
  for (i = 0; i < count; i += 1)
  {
    printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
  }
  printf("---\n");

  // fourth way
  for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name += 1, cur_age += 1)
  {
    printf("%s lives %d years so far.\n", *cur_name, *cur_age);
  }

  return 0;
}
