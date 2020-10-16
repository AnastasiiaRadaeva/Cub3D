/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 11:16:51 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/05/24 21:33:27 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *new;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		new = *lst;
		*lst = new->next;
		del(new->content);
		free(new);
	}
}
