/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiyarash <tiyarash@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 05:21:53 by tiyarash          #+#    #+#             */
/*   Updated: 2023/08/30 06:06:31 by tiyarash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_e;
	void	*content;

	if (!lst || !f)
		return (0);
	new = 0;
	while (lst)
	{
		content = f(lst->content);
		if (content)
			new_e = ft_lstnew(content);
		if (!content || !new_e)
		{
			free (content);
			ft_lstclear (&new, del);
			return (0);
		}
		ft_lstadd_back(&new, new_e);
		lst = lst->next;
	}
	return (new);
}
