#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;

  if (argc < 2)
  {
    printf("You did not pass in enough arguments.\n");
  }
  else if (argc >= 2 && argc <= 4)
  {
    printf("Here's the argument(s) passed in:\n");

    for (i = 0; i < argc; i += 1)
    {
      printf("%s ", argv[i]);
    };
    printf("\n");
  }
  else
  {
    printf("You passed too many arguments.");
  };
}
