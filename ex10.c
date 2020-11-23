#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    printf("ERROR: You need to pass at least one argument.\n");
    // this abords with stderr 1
    return 1;
  };

  int argIndex = 1;
  for (argIndex = 1; argIndex <= argc - 1; argIndex += 1)
  {
    int i = 0;
    char letter;
    for (i = 0, letter = argv[argIndex][i]; argv[argIndex][i] != '\0'; i += 1, letter = argv[argIndex][i])
    {

      char lower = letter >= 65 && letter <= 90 ? letter + 32 : letter;

      switch (lower)
      {
      case 'a':
        printf("%d: 'a'\n", i);
        break;
      case 'e':
        printf("%d: 'e'\n", i);
        break;
      case 'i':
        printf("%d: 'i'\n", i);
        break;
      case 'o':
        printf("%d: 'o'\n", i);
        break;
      case 'u':
        printf("%d: 'u'\n", i);
        break;

      case 'y':
        // why i > 2?
        if (i > 2)
        {
          // it's only sometimes Y
          printf("%d: 'y'\n", i);
        }
        break;

      default:
        printf("%d: %c is not a vowel\n", i, lower);
      };
    };
  };
}
