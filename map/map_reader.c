/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:48:47 by cagonzal          #+#    #+#             */
/*   Updated: 2022/05/17 12:57:30 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

/* Return how many '\n' are in <file> */
static int	file_linecount(char *file)
{
	int		line_count;
	int		fd;
	int		readcount;
	char	c;	

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	line_count = 1;
	while (TRUE)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			line_count++;
	}
	close(fd);
	return (line_count);
}

/* Allocates memory for a string array with the same lines as the file */
static char	**alloc_map(char *file)
{
	char	**map;
	int		line_count;
	int		fd;
	int		i;

	line_count = file_linecount(file);
	if (line_count <= 0)
		return (null_error("open or reading error, the file may not exist"));
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
		return (null_error("malloc error on alloc_map()"));
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < line_count)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

/* Creates -with malloc- a 2D char map as found in file */
char	**read_map(char *file)
{
	char	**map;

	map = alloc_map(file);
	if (map == NULL)
		return (NULL);
	return (map);
}
