/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 11:43:42 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/24 21:40:18 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*pointer;
	t_list	*new_lst;
	t_list	*new_elem;
	void	*content;

	if (!lst || !f)
		return (NULL);
	pointer = lst;
	new_lst = NULL;
	while (pointer)
	{
		content = f(pointer->content);
		if ((new_elem = ft_lstnew(content)) == 0)
		{
			free(content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_elem);
		pointer = pointer->next;
	}
	return (new_lst);
}
