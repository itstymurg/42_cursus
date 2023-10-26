#include "push_swap.h"

void    swap(t_stack **stack)
{
    t_stack *aux;

    if (!*stack || !((*stack)->next))
        return ;
    aux = *stack;
    *stack = (*stack)->next;
    (*stack)->next = aux;
}

void    sa(t_stack **a)
{
    swap(a);
    ft_print("sa\n");
}

void    sa(t_stack **b)
{
    swap(b);
    ft_print("sb\n");
}

void    ss(t_stack **a, t_stack **b)
{
    swap(a);
    swap(b);
    ft_print("ss\n");
}