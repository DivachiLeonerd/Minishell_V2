NAME:=minishell
CC:= gcc
CFLAGS:= -Wextra -Werror -Wall -fsanitize=address -g
PRJT_PATH:=~/Documents/Minishell_V2/
SRCS:=${PRJT_PATH}srcs/
BUILTIN_PATH:=${SRCS}builtins/
COMMON_PATH:=${SRCS}common/
ENV_PATH:=${SRCS}env/
INPUT_PATH:=${SRCS}input/
SIGNALS_PATH:=${SRCS}signals/
HEADERS:= ${PRJT_PATH}headers/
LIB:=ar -rcs
LIBFT_PATH:= ${PRJT_PATH}srcs/libft/

NAME: all

all: libft.a
	${CC} ${CFLAGS} ${NAME}.c ${BUILTIN_PATH}*.c \
		${COMMON_PATH}*.c \
		${ENV_PATH}*.c \
		${INPUT_PATH}*.c \
		${SIGNALS_PATH}*.c \
		-I${HEADERS} -L./ -lft -lreadline -o minishell

libft.a: 
	${CC} ${CFLAGS} -c ${LIBFT_PATH}*.c -I${HEADERS} && \
		${LIB} libft.a *.o 

clean:
		rm *.o


