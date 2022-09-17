/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:55:33 by taitomer          #+#    #+#             */
/*   Updated: 2022/03/07 15:33:01 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 546
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_cont
{
	char	**arr;
	int		**coor;
	int		z;
}	t_cont;

int		tetr_count(int size);
void	file_validity(char *buf, int size, int fd);
int		map_init_size(int tetr);
char	**tetrs_to_arr(int tetr, char *buf, int i, int j);
char	*create_map(int x);
int		**get_coor(int tetr, t_cont cont, int i, int k);
int		check_tetr_fit(char *map, int i, int j, t_cont cont);
char	*fill_map(char *map, int i, int j, t_cont cont);
char	*clear_map_by_tetr(char *map, int placed, int j, t_cont cont);
char	*place_coors(int tetr, t_cont cont);

#endif
