#makefile should put everything in static libraries and should also handle tests
NAME:=Minishell
CC:= gcc
PRJT_PATH:= ~/Documents/Minishell_V2/
CFLAGS:= -Wall -Werror -Wextra
COMMON_SRCS:= ${PRJT_PATH}common/%.c
HEADERS:= -I${PRJT_PATH}/headers/
PROMPT_PATH:=${PRJT_PATH}srcs/prompt/
ENV_PATH:=${PRJT_PATH}srcs/env
INPUT_PATH:=${PRJT_PATH}srcs/input/
BUILTIN_PATH:=${PRJT_PATH}srcs/built-ins/
TEST_PATH:=${PRJT_PATH}/tests/

ptest:	libft.a
	${CC} ${CFLAGS} ${TEST_PATH}prompt_testing.c ${HEADERS} 
