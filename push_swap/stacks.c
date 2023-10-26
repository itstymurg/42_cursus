#include "push_swap.h"

void	stack_add(t_stack **stack, t_stack *new)
{
	t_stack	*final;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	final = where_final(*stack);
	final->next = new;
}

t_stack	*new_s(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target = -1;
	new->next = NULL;
	return (new);
}

t_stack	*where_final(t_stack *last_stack)
{
	while (last_stack && last_stack->next != NULL)
		last_stack = last_stack->next;
	return (last_stack);
}