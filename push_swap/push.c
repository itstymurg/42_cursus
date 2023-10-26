#include "push_swap.h"

void    push(t_stack **src, t_stack **dest)
{
    t_stack *aux;

    if (!*src)
        return (NULL);
    aux = (*src)->next;
    (*src)->next = *dest;
    *dest = *src;
    *src = aux;
}

void    pa(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void     pb(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pb\n", 3);
}