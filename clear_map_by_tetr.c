/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_map_by_tetr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:03:05 by taitomer          #+#    #+#             */
/*   Updated: 2022/03/02 09:12:09 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*clear_map_by_tetr(char *map, int placed, int j, t_cont cont)
{
	int	k;

	k = 0;
	map[placed] = '.';
	while (k < 3)
	{
		if ((cont.coor[j][k + 1] - cont.coor[j][k]) > 1)
		{
			map[placed + cont.coor[j][k + 1] - cont.coor[j][k] + cont.z] = '.';
			placed = placed + cont.coor[j][k + 1] - cont.coor[j][k] + cont.z;
		}
		else
		{
			map[placed + cont.coor[j][k + 1] - cont.coor[j][k]] = '.';
			placed = placed + cont.coor[j][k + 1] - cont.coor[j][k];
		}
		k++;
	}	
	return (map);
}
