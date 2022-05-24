/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:38:39 by cagonzal          #+#    #+#             */
/*   Updated: 2022/04/28 15:00:22 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **head)
{
	int		size;
	t_list	*del;

	if (!head)
		return ;
	size = ft_lstsize(*head);
	while ((*head)->next)
	{
		del = (*head)->next;
		ft_lstdelone(head, del);
	}
}
