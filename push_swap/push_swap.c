#include "push_swap.h"

void	put_numbers(char *str, t_stack **stack_a)
{
	char		**matrix;
	long int	num;
	int			i;

	matrix = ft_split(str, ' ');
	i = 0;
	while (matrix[i])
	{
		if (input_checker(matrix[i]))
		{
			num = ft_atoi(matrix[i]);
			if (num > INT_MAX || num < INT_MIN)
				error(stack_a, NULL);

			s_add(stack_a, new_s(num));
		}
		else
			error(NULL, NULL);
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		s_size;
	int		i;

	i = 1;
	stack_b = NULL;
	stack_a = NULL;
	while (i < argc)
		put_numbers(argv[i++], &stack_a);
	if (is_duplicate(stack_a) == 1)
		error(&stack_a, NULL);
	s_size = stack_size(stack_a);
	stack_free(&stack_a);
	stack_free(&stack_b);
	return (0);
}