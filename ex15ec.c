#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;
  for (i = 0; i < argc; i += 1)
  {
    printf("pointer: %p\t value: %s\n", (argv + i), *(argv + i));
  }
}
