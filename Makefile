# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tturto <tturto@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 15:05:17 by taitomer          #+#    #+#              #
#    Updated: 2022/03/07 15:02:33 by tturto           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

SRCS =	main.c \
		tetr_count.c \
		file_validity.c \
		map_init_size.c \
		tetrs_to_arr.c \
		create_map.c \
		get_coor.c \
		check_tetr_fit.c \
		fill_map.c \
		clear_map_by_tetr.c \
		place_coors.c

OBJ = *.o

LIBFT = make -C ./libft/

LIBFTA = ./libft/libft.a

all : $(NAME)

$(NAME):
	@ $(LIBFT)
	@ gcc $(FLAGS) -c $(SRCS)
	@ gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFTA)
	@ echo "	Makefile was executed succesfully"

clean:
	@ rm -f $(OBJ)
	@ $(LIBFT) clean
	@ echo "	Object files were removed"

fclean: clean
	@ rm -f $(NAME)
	@ $(LIBFT) fclean
	@ echo "	Binary and libft.a were removed"

re: fclean all
