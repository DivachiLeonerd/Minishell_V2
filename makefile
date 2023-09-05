#makefile should put everything in static libraries and should also handle tests
NAME:=Minishell
CC:= gcc
CFLAGS:= -Wall -Werror -Wextra
HEADERS:= -I../headers/

prompttest:	libft.a
	${CC} ${CFLAGS} ./tests/prompt_testing.c ${HEADERS} ./srcs/prompt/prompt_input.c ./srcs/env/env_tools.c -L./ -lft -o prompt_test
