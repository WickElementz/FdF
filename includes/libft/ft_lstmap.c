/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jominodi <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/11 13:57:27 by jominodi     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/23 11:47:47 by jominodi    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *new_last;

	if (!lst || !f)
		return (NULL);
	new_last = f(lst);
	new = new_last;
	if (new == NULL)
		return (new);
	lst = lst->next;
	while (lst)
	{
		new_last->next = f(lst);
		if (new_last->next == NULL)
			return (NULL);
		new_last = new_last->next;
		lst = lst->next;
	}
	return (new);
}
