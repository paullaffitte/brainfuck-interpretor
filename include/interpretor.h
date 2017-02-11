#ifndef INTERPRETOR_H_
# define INTERPRETOR_H_

# define MEM_SIZE 1000000
# define STACK_SIZE 100

typedef struct	s_loop
{
  struct s_loop	*next;
  struct s_loop	*pair;
  char		symbol;
  unsigned int	position;
}		t_loop;

typedef struct	s_bf
{
  char		*code;
  unsigned int	code_position;
  t_loop	*loops;
  char		memory[MEM_SIZE];
  int		mem_pos;
  char		*stack;
  int		stack_head;
  int		stack_size;
}		t_bf;

int		init_bf(t_bf *bf);
char		*load_code(char *filename);

int		interprete(char *filename);

int		open_loop(t_bf *bf);
int		close_loop(t_bf *bf);

#endif /* !INTERPRETOR_H_ */
