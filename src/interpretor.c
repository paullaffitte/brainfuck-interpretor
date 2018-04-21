#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "interpretor.h"
#include "parser.h"

int		stack(t_bf *bf, char c)
{
  char		*tmp;

  if (bf->stack_head == bf->stack_size)
    {
      if (!(tmp = malloc(sizeof(char) * (bf->stack_size + STACK_SIZE))))
	return (-1);
      strcpy(tmp, bf->stack);
      free(bf->stack);
      bf->stack = tmp;
      bf->stack_size += STACK_SIZE;
    }
  bf->stack[bf->stack_head] = c;
  bf->stack_head++;
  bf->stack[bf->stack_head] = '\0';
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
    bf->mem_pos = bf->mem_pos == 0 ? MEM_SIZE - 1 : bf->mem_pos - 1;
  else if (c == '>')
    bf->mem_pos = bf->mem_pos == MEM_SIZE - 1 ? 0 : bf->mem_pos + 1;
  else if (c == '+')
    bf->memory[bf->mem_pos]++;
  else if (c == '-')
    bf->memory[bf->mem_pos]--;
  else if (c == '.')
    return (stack(bf, bf->memory[bf->mem_pos]));
  else if (c == ',')
    read(0, &bf->memory[bf->mem_pos], 1);
  else if (c == '[')
    return (open_loop(bf));
  else if (c == ']')
    return (close_loop(bf));
  else if (c != ' ' && c != '\n' && c != '\t')
    return (-1);
  return (0);
}

int		interprete(char *filename)
{
  t_bf		bf;

  if ((bf.code = load_code(filename)) == NULL
      || init_bf(&bf) == -1
      || parse_loops(bf.code, &bf.loops) == -1)
    return (-1);
  while (bf.code[bf.code_position])
    {
      if (interprete_char(bf.code[bf.code_position], &bf) == -1)
	return (-1);
      bf.code_position++;
    }
  destack(&bf);
  return (0);
}
