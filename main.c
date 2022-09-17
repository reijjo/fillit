/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:24:36 by tturto            #+#    #+#             */
/*   Updated: 2022/03/08 17:55:15 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	exit_function(int a, int fd)
{
	if (a == 1)
		ft_putstr("Error: Arg. value must be 1. Usage: ./fillit <filename>\n");
	if (a == 2)
	{
		ft_putstr("error\n");
		close(fd);
	}
	exit(1);
}

static int	read_and_validity(char **argv, char *buf)
{
	int		fd;
	int		ret;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_function(2, fd);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret < 20)
		exit_function(2, fd);
	buf[ret] = '\0';
	file_validity(buf, ret, fd);
	close(fd);
	return (ret);
}

int	main(int argc, char **argv)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		tetr;
	char	*map;
	t_cont	cont;

	if (argc != 2)
		exit_function(1, 0);
	ret = read_and_validity(argv, buf);
	if (ret > BUFF_SIZE)
		exit_function(2, 0);
	tetr = tetr_count(ret);
	cont.arr = tetrs_to_arr(tetr, buf, 0, 0);
	cont.coor = get_coor(tetr, cont, 0, 0);
	map = place_coors(tetr, cont);
	ft_memdel((void **)cont.arr);
	ft_memdel((void **)cont.coor);
	ft_putstr(map);
	ft_putchar('\n');
	ft_memdel((void *)(&map));
	return (0);
}
