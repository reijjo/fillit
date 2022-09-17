/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:05:03 by taitomer          #+#    #+#             */
/*   Updated: 2022/03/02 14:45:58 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	initialize(int *i, int *c, int *cells, int x)
{
	*cells = (x + 1) * x;
	*i = 0;
	*c = 0;
}

char	*create_map(int x)
{
	int		cells;
	int		i;
	int		c;
	char	*map;

	initialize(&i, &c, &cells, x);
	map = (char *)(malloc(sizeof(char) * cells));
	if (!map)
		return (NULL);
	while (i < cells)
	{
		while (c < x)
		{
			map[i++] = '.';
			c++;
		}
		if (i == (cells - 1))
		{
			map[i] = '\0';
			break ;
		}
		map[i++] = '\n';
		c = 0;
	}
	return (map);
}
