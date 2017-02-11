#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "interpretor.h"

int	init_bf(t_bf *bf)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      bf->memory[i] = 0;
      i++;
    }
  bf->code_position = 0;
  bf->mem_pos = 0;
  bf->stack_head = 0;
  bf->stack_size = 0;
  if (!(bf->stack = malloc(sizeof(char) * STACK_SIZE)))
    return (-1);
  bf->stack[0] = '\0';
  return (0);
}

char		*load_code(char *filename)
{
  int		fd;
  struct stat	buffer;
  char		*code;

  if ((fd = open(filename, O_RDONLY)) == -1
      || fstat(fd, &buffer) == -1
      || !(code = malloc(sizeof(char) * (buffer.st_size + 1)))
      || read(fd, code, buffer.st_size) < 0)
    return (NULL);
  code[buffer.st_size] = '\0';
  return (code);
}
