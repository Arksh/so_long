/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:24:05 by cagonzal          #+#    #+#             */
/*   Updated: 2022/05/09 10:26:13 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Returns 0 printing <message> in red */
int	error(char *message)
{
	ft_printf("\033[0;31m" " Error\n    %s\n" "\033[0m", message);
	return (0);
}

/* Returns NULL printing <message> in red */
void	*null_error(char *message)
{
	ft_printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	return (0);
}

/* Prints <message> in yellow */
void	print_warning(char *message)
{
	ft_printf("\033[0;33m" " Warning\n %s\n" "\033[0m", message);
}
