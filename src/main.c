#include <stdio.h>
#include "interpretor.h"

int		main(int argc, char **argv)
{
  if (argc != 2)
    printf("%s\n", "Usage: ./bfi filename");
  else if (interprete(argv[1]) == -1)
    printf("%s\n", "An error occured");
  return (0);
}
