/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:23:13 by cagonzal          #+#    #+#             */
/*   Updated: 2022/05/09 17:20:40 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/* Returns TRUE if the file is valid */
int	valid_file(int argc, char *file)
{
	if (argc == 1)
		return (error("no args"));
	if (argc > 2)
		print_warning("only the first file would be used");
	if (!ft_strend_cmp(file, ".ber"))
		return (error("map should be a .ber file"));
	return (1);
}

/* Initialize the data needed to check if the map is valid */
static t_mapcheckerdata	init_checkerdata(char **map)
{
	t_mapcheckerdata	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_chartable_linecount(map);
	data.b_player = FALSE;
	data.b_exit = FALSE;
	data.b_collect = FALSE;
	data.point.y = 0;
	data.point.x = 0;
	return (data);
}

/* Checks to do to each indivial tile of the map.
* When it founds one, pritns an error and returns FALSE. */
static int	checks(char **map, t_mapcheckerdata *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (!valid_char(map[y][x]))
		return (error("invalid map character"));
	if (!valid_uniquechar(map[y][x], 'P', &data->b_player))
		return (error("must be only one player 'P'"));
	if (map[y][x] == 'E')
		data->b_exit = TRUE;
	if (!valid_border(map[y][x], data->point, data->size))
		return (error("map must be surrounded by walls '1'"));
	if (map[y][x] == 'C')
		data->b_collect = TRUE;
	return (TRUE);
}

/* Returns TRUE if the map is valid.
* Printing an error message and returning FALSE if not */
int	valid_map(char **map)
{
	t_mapcheckerdata	data;
	t_bool				valid;

	data = init_checkerdata(map);
	valid = TRUE;
	if (data.size.y == data.size.x)
		valid = error("map must be rectangular");
	while (map[data.point.y])
	{
		data.point.x = 0;
		while (map[data.point.y][data.point.x])
		{
			if (checks(map, &data) == FALSE)
				valid = FALSE;
			data.point.x++;
		}
		data.point.y++;
	}
	if (!data.b_player || !data.b_exit || !data.b_collect)
		valid = error("there must be one 'P' and 'E', and at least one 'C'");
	return (valid);
}
