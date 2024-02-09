# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 17:21:03 by atereso-          #+#    #+#              #
#    Updated: 2023/04/20 19:37:29 by atereso-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = -I.libft.h -I.ft_printf.h
LIB = ar -rcs
SRCS =  ft_atoi.c ft_bzero.c ft_calloc.c ft_chrcmp.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c print_hexa.c print_integer.c print_pointer.c print_string.c print_unsigned_int.c ft_printf.c ft_utoa.c ft_atol.c ft_smol_strlen.c ft_divide_tokens.c
OBJS = ${SRCS:.c=.o}
BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS = ${BONUS:.c=.o}
CC = cc
FLAGS = -g -Wall -Wextra -Werror
RM = rm -f

all: bonus

 $(NAME): ${OBJS}
		@${LIB} ${NAME} ${OBJS}

bonus: ${OBJS} ${BONUS_OBJS}
		@${LIB} ${NAME} ${OBJS} ${BONUS_OBJS}

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} ${HEADER}

clean:
	@${RM} ${OBJS}
	@${RM} ${BONUS_OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all re clean fclean bonus
