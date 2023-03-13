/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:08:54 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/16 15:44:46 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*tempnxt;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		tempnxt = temp;
		temp = temp->next;
		ft_lstdelone(tempnxt, del);
	}
	*lst = NULL;
}
