/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetr_fit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:01:41 by taitomer          #+#    #+#             */
/*   Updated: 2022/03/02 09:10:52 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_tetr_fit(char *map, int i, int j, t_cont cont)
{
	int	h;
	int	k;

	h = 1;
	k = 0;
	while (k < 3)
	{
		if ((cont.coor[j][k + 1] - cont.coor[j][k]) > 1)
		{
			if (map[i + cont.coor[j][k + 1] - cont.coor[j][k] + cont.z] == '.')
			{
				h++;
				i = i + cont.coor[j][k + 1] - cont.coor[j][k] + cont.z;
			}
		}
		else if (map[i + cont.coor[j][k + 1] - cont.coor[j][k]] == '.')
		{
			h++;
			i = i + cont.coor[j][k + 1] - cont.coor[j][k];
		}
		k++;
	}
	return (h);
}
