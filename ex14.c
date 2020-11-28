#include <stdio.h>
#include <ctype.h>

// forward declarations
int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
  int i;

  for (i = 1; i < argc; i += 1)
  {
    print_letters(argv[i]);
  }
}

void print_letters(char arg[])
{
  int i;
  char ch;

  for (i = 0; (ch = arg[i]) != '\0'; i += 1)
  {
    if (can_print_it(ch))
    {
      printf("%c: %d\t ", ch, ch);
    }
  }

  printf("\n");
}

int can_print_it(char ch)
{
  return isalpha((int)ch) || isblank((int)ch);
}

int main(int argc, char *argv[])
{
  print_arguments(argc, argv);
  return 0;
}
