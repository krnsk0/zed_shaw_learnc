#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;

  for (i = 1; i < argc; i += 1)
  {
    printf("arg %d: %s\n", i, argv[i]);
  };
}
