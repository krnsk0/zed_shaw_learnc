#include <stdio.h>

int main(int argc, char *argv[])
{
  int numbers[4] = {0};
  char name[4] = {'a'};

  // first print them out raw
  printf("\nRAW:\n");
  printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
  printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
  printf("name: %s\n", name);

  // set up the numbers
  numbers[0] = 1;
  numbers[1] = 2;
  numbers[2] = 3;
  numbers[3] = 4;

  // set up the name
  name[0] = 'J';
  name[1] = 'o';
  name[2] = 'n';
  name[3] = '\0';

  // print them out initialized
  printf("\nINITIALIZED:\n");
  printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
  printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
  printf("name: %s\n", name);

  // print name as a big integer
  unsigned int the_number = 0;
  the_number += name[0] * 1000000;
  the_number += name[1] * 1000;
  the_number += name[2];

  printf("\nCONCAT STRING INTS AS INTS:\n");
  printf("char 1: %d\n", name[0]);
  printf("char 2: %d\n", name[1]);
  printf("char 3: %d\n", name[2]);

  printf("name as unsigned int: %d\n", the_number);

  // another way
  char *another = "Jon";
  printf("\nASTERIX METHOD:\n");
  printf("another each: %c %c %c %c\n", another[0], another[1], another[2], another[3]);
  printf("another: %s\n", another);

  return 0;
};
