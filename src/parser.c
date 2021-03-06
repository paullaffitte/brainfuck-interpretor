#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "interpretor.h"

static int	add_loop(t_loop **list_head, char symbol,
			 unsigned int position)
{
  t_loop	*new;

  if (!(new = malloc(sizeof(t_loop))))
    return (-1);
  new->symbol = symbol;
  new->position = position;
  new->next = NULL;
  if (*list_head)
    new->next = *list_head;
  *list_head = new;
  return (0);
}

t_loop		*find_pairs(t_loop *loops)
{
  t_loop	*left_pair;

  if (loops && loops->symbol == '[')
    return (loops);
  else if (loops && loops->symbol == ']')
    {
      left_pair = find_pairs(loops->next);
      left_pair->pair = loops;
      loops->pair = left_pair;
    }
  return (left_pair->next);
}

int		parse_loops(char *script, t_loop **buffer)
{
  int		depth;
  int		i;

  *buffer = NULL;
  depth = 0;
  i = 0;
  while (script[i])
    {
      if (script[i] == '[' || script[i] == ']')
	{
	  if (CALC_DEPTH(depth, script[i]) < 0)
	    return (-1);
          if (add_loop(buffer, script[i], i) == -1)
	    return (-1);
	}
      i++;
    }
  if (depth != 0)
    return (-1);
  if (*buffer)
    find_pairs(*buffer);
  return (0);
}
