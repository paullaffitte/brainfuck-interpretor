#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "interpretor.h"

int		stack(t_bf *bf, char c)
{
  char		*tmp;

  if (bf->stack_head == bf->stack_size)
    {
      if (!(tmp = malloc(sizeof(char) * (bf->stack_size + STACK_SIZE))))
	return (-1);
      strcpy(bf->stack, tmp);
      free(bf->stack);
      bf->stack = tmp;
      bf->stack_size += STACK_SIZE;
    }
  bf->stack[bf->stack_head] = c;
  bf->stack_head++;
  return (0);
}

void		destack(t_bf *bf)
{
  int		i;

  i = 0;
  while (i < bf->stack_head)
    {
      write(1, &bf->stack[i], 1);
      i++;
    }
  write(1, "\n", 1);
  free(bf->stack);
  bf->stack_head = 0;
  bf->stack_size = 0;
}

int		interprete_char(char c, t_bf *bf)
{
  if (c == '<')
    bf->position = bf->position == 0 ? MEM_SIZE - 1 : bf->position - 1;
  else if (c == '>')
    bf->position = bf->position == MEM_SIZE - 1 ? 0 : bf->position + 1;
  else if (c == '+')
    bf->memory[bf->position]++;
  else if (c == '-')
    bf->memory[bf->position]--;
  else if (c == '.' && stack(bf, bf->memory[bf->position]))
    return (-1);
  else if (c == ',')
    read(0, &bf->memory[bf->position], 1);
  else if (c != ' ' && c != '\n' && c != '\t')
    return (-1);
  return (0);
}

int		interprete(char *filename)
{
  char		*brainfuck;
  t_bf		bf;
  int		i;

  if ((brainfuck = load_code(filename)) == NULL
      || init_bf(&bf) == -1)
    return (-1);
  i = 0;
  while (brainfuck[i])
    {
      if (interprete_char(brainfuck[i], &bf) == -1)
	return (-1);
      i++;
    }
  destack(&bf);
  return (0);
}
