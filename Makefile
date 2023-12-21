# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abutet <abutet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 11:19:06 by abutet            #+#    #+#              #
#    Updated: 2023/11/20 11:22:22 by abutet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft.a
LIBFT_WA	= ft

LIBFT_FOLDER	= libft

SRCS		= src/ft_putchar_fd_len.c src/ft_puthex.c src/ft_putnbr_fd_len.c \
		  src/ft_putp.c src/ft_putstr_fd_len.c src/ft_putunbr.c ft_printf.c

OBJS		= $(SRCS:.c=.o)

CC		= cc
CFLAGS		= -Wall -Wextra -Werror -I

all:		$(NAME)

$(NAME):	$(OBJS)
	mv $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS):	$(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) -l$(LIBFT_WA) -c $(SRCS)
	mv ft_put* src

$(LIBFT):
	make -C $(LIBFT_FOLDER)
	cp $(LIBFT_FOLDER)/$(LIBFT) .

fclean:		clean
	rm -f $(NAME)
	make -C $(LIBFT_FOLDER) fclean

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_FOLDER) clean

re:		fclean $(NAME)

.PHONY:		all clean fclean re