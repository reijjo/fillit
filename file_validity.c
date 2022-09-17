/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:06:51 by taitomer          #+#    #+#             */
/*   Updated: 2022/03/08 18:37:35 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_file_valid(char *buf)
{
	int	i;

	i = 0;
	while (i <= 19)
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (0);
		if (buf[i] == '\n' && !((i + 1) % 5 == 0))
			return (0);
		if (i == 19 && buf[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	count_hits_for_shape(char *buf)
{
	int	i;
	int	hits;

	i = 0;
	hits = 0;
	while (i <= 18)
	{
		if (buf[i] == '#')
			hits++;
		i++;
	}
	if (hits != 4)
		return (0);
	return (1);
}

static int	is_shape_valid(char *buf)
{
	int	i;
	int	adjacent;

	i = 0;
	adjacent = 0;
	while (i <= 18)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				adjacent++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				adjacent++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				adjacent++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				adjacent++;
		}
		i++;
	}
	if (adjacent != 6 && adjacent != 8)
		return (0);
	else
		return (1);
}

void	file_validity(char *buf, int ret, int fd)
{
	int	i;
	int	validity;

	i = 0;
	validity = 1;
	while (i <= ret)
	{
		if (is_file_valid(&buf[i]) == 0)
			validity = 0;
		if (count_hits_for_shape(&buf[i]) == 0)
			validity = 0;
		if (is_shape_valid(&buf[i]) == 0)
			validity = 0;
		i = i + 21;
		if (ret > 20 && (buf[i - 1] != '\n' && buf[i - 1] != '\0'))
			validity = 0;
	}
	if (validity == 0)
	{
		ft_putstr("error\n");
		close(fd);
		exit(1);
	}
}
