#ifndef HEADER_H
# define HEADER_H

# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list			*top;
}					t_stack;

#endif