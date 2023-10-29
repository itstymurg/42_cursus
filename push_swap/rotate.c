#include "push_swap.h"

void    rotate(t_stack **stack)
{
    t_stack *aux;
    t_stack *final;

    aux = *stack;
    stack = (*stack)->next;
    final = where_final(*stack);
    aux->next = NULL;
    final->next = aux;
}

void    ra(t_stack **a)
{
    rotate(a);
    ft_printf("ra\n");
}

void    ra(t_stack **b)
{
    rotate(b);
    ft_printf("rb\n");
}

void    rr(t_stack **a, t_stack **b)
{
    rotate(a);
    rotate(b);
    ft_printf("rr\n");
}