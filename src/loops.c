#include "interpretor.h"

t_loop		*get_loop(t_bf *bf, unsigned int position)
{
  t_loop	*loop;

  loop = bf->loops;
  while (loop && loop->position != position)
    loop = loop->next;
  return (loop);
}

int		open_loop(t_bf *bf)
{
  t_loop	*loop;

  if (bf->memory[bf->mem_pos] == 0)
    {
      if (!(loop = get_loop(bf, bf->code_position)))
	return (-1);
      bf->code_position = loop->pair->position;
    }
  return (0);
}

int		close_loop(t_bf *bf)
{
  t_loop	*loop;

  if (bf->memory[bf->mem_pos] != 0)
    {
      if (!(loop = get_loop(bf, bf->code_position)))
	return (-1);
      bf->code_position = loop->pair->position;
    }
  return (0);
}
