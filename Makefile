# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wasahmed <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 09:10:15 by wasahmed          #+#    #+#              #
#    Updated: 2019/07/23 11:18:12 by wasahmed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c check_flags.c

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):
	@echo "<<<<<Compiling $(NAME)>>>>>"
	@make -C libft/
	@gcc $(FLAGS) -o $(NAME) $(SRC) libft/libft.a
	@echo "DONE!"

#clean:
#		/bin/rm -f $(OBJ_NAME)

fclean:
	@make fclean -C libft/
	@/bin/rm -f $(NAME)
	@echo "<<<<<Removed exe and cleaned libft>>>>>"

re: fclean all

normall:
	@norminette $(SRC) *.h libft/*

list:
	@echo "<<<<CURRENT DIRECTORY>>>>"
	ls
	@echo "<<<<LIST LIBFT>>>>"
	ls ./libft/
