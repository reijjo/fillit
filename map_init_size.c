/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:26:26 by taitomer          #+#    #+#             */
/*   Updated: 2022/03/01 18:41:38 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	map_init_size(int tetr)
{
	int	x;

	if (tetr == 1)
		x = 2;
	if (tetr >= 2 && tetr <= 3)
		x = 3;
	if (tetr == 4)
		x = 4;
	if (tetr >= 5 && tetr <= 6)
		x = 5;
	if (tetr >= 7 && tetr <= 9)
		x = 6;
	if (tetr >= 10 && tetr <= 12)
		x = 7;
	if (tetr >= 13 && tetr <= 16)
		x = 8;
	if (tetr >= 17 && tetr <= 20)
		x = 9;
	if (tetr >= 21 && tetr <= 25)
		x = 10;
	if (tetr == 26)
		x = 11;
	return (x);
}
