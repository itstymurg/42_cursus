#include "push_swap.h"

void    reverse(t_stack **stack)
{
    t_stack *aux;
    t_stack *final;
    t_stack *prefinal;

    final = where_final(*stack);
    prefinal = where_prefinal(*stack);
    aux = *stack;
    *stack = final;
    (*stack)->next = aux;
	prefinal->next = NULL;
}

void    rra(t_stack **a)
{
    reverse(a);
    ft_printf("rra\n");
}

void    rrb(t_stack **b)
{
    reverse(b);
    ft_printf("rrb\n");
}

void    rrr(t_stack **a, t_stack **b)
{
    reverse(a);
    reverse(b);
    ft_printf("rrr\n");
}