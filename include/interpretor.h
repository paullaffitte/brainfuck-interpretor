#ifndef INTERPRETOR_H_
# define INTERPRETOR_H_

# define MEM_SIZE 1000000
# define STACK_SIZE 100

typedef struct	s_bf
{
  char		memory[MEM_SIZE];
  int		position;
  char		*stack;
  int		stack_head;
  int		stack_size;
}		t_bf;

int		init_bf(t_bf *bf);
char		*load_code(char *filename);

int		interprete(char *filename);

#endif /* !INTERPRETOR_H_ */
