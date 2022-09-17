/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_coors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:22:18 by taitomer          #+#    #+#             */
/*   Updated: 2022/03/03 16:59:07 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fit_tetr(char *map, int j, int *placed, t_cont cont)
{
	int	i;

	i = *placed;
	while (map[i] != '\0')
	{
		if (map[i] == '.')
		{
			if (check_tetr_fit(map, i, j, cont) == 4)
			{
				*placed = i;
				map = fill_map(map, i, j, cont);
				break ;
			}
		}
		i++;
		if (map[i] == '\0')
			return (0);
	}
	return (1);
}

int	place_tetrs(char *map, int j, int tetr, t_cont cont)
{
	int	placed;
	int	map_size;

	placed = 0;
	map_size = (int)ft_strlen(map);
	if (j == tetr)
		return (1);
	while ((placed < map_size) && fit_tetr(map, j, &placed, cont) == 1)
	{
		if (place_tetrs(map, j + 1, tetr, cont) == 1)
			return (1);
		clear_map_by_tetr(map, placed, j, cont);
		placed = placed + 1;
	}
	return (0);
}	

static int	var_for_map_size(char *map)
{
	int	i;
	int	z;
	int	b;

	i = 0;
	b = 0;
	z = -2;
	while (map[i] != '\0')
		i++;
	while (i > 5)
	{
		i = i - (6 + b);
		b = b + 2;
		z++;
	}
	return (z);
}

char	*place_coors(int tetr, t_cont cont)
{
	int		x;
	char	*map;

	x = map_init_size(tetr);
	map = create_map(x);
	cont.z = var_for_map_size(map);
	while (place_tetrs(map, 0, tetr, cont) == 0)
	{
		ft_memdel((void *)(&map));
		x++;
		map = create_map(x);
		cont.z = var_for_map_size(map);
	}
	return (map);
}
