/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrs_to_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:09:22 by taitomer          #+#    #+#             */
/*   Updated: 2022/03/07 17:26:13 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	initialize(int *k)
{
	*k = 0;
	return ('A');
}

static void	initialize2(int *k, char *letter, int *j, int *i)
{
	*k = *k + 2;
	*letter = *letter + 1;
	*j = *j + 1;
	*i = 0;
}

char	**tetrs_to_arr(int tetr, char *buf, int i, int j)
{
	int		k;
	char	letter;
	t_cont	cont;

	cont.arr = (char **)malloc(sizeof(char *) * tetr);
	if (!cont.arr)
		return (NULL);
	letter = initialize(&k);
	while (j < tetr)
	{
		cont.arr[j] = (char *)malloc(sizeof(char) * 20);
		if (!cont.arr)
			return (NULL);
		while (i <= 18)
		{
			if (buf[k] == '#')
				cont.arr[j][i++] = letter;
			else
				cont.arr[j][i++] = buf[k];
			k++;
		}
		cont.arr[j][i] = '\0';
		initialize2(&k, &letter, &j, &i);
	}
	return (cont.arr);
}
