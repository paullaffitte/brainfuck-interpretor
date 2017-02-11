#ifndef PARSER_H_
# define PARSER_H_

# define CALC_DEPTH(depth, symbol) (depth += (symbol == '[') ? 1 : -1)

# include "interpretor.h"

int	parse_script(char *script, t_loop **buffer);

#endif /* !PARSER_H_*/
