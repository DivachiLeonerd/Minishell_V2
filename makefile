NAME:=minishell
CC:= gcc
CFLAGS:= -Wextra -Werror -Wall
PRJT_PATH:=~/Documents/Minishell_V2/
HEADERS:= -I./HEADERS/

all: libft.a
	${CC} ${CFLAGS} ${NAME}.c ${HEADERS} -L./ -lf 
