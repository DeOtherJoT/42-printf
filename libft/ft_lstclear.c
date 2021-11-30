/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthor <jthor@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:30:24 by jthor             #+#    #+#             */
/*   Updated: 2021/10/12 21:31:03 by jthor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_in_list;

	current = *lst;
	if (*lst)
	{
		while (current)
		{
			next_in_list = current->next;
			del(current->content);
			free(current);
			current = next_in_list;
		}
		*lst = NULL;
	}
}
