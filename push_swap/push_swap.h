#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	    put_numbers(char *str, t_stack **stack_a);
char	    **ft_split(char const *s, char c);
long	    input_checker(char	*str);
int         duplicate_checker(t_stack *column);
size_t      ft_strlen(char * str);
int	        duplicate_checker(t_stack *column);
void	    free_stack(t_stack **stack);
void	    error(t_stack **stack_a, t_stack **stack_b);
t_stack	    *where_final(t_stack *last_stack);

# endif