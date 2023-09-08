#makefile should put everything in static libraries and should also handle tests
NAME:=Minishell
CC:= gcc
PRJT_PATH:= ~/Documents/Minishell_V2/
CFLAGS:= -Wall -Werror -Wextra
HEADERS:= -I${PRJT_PATH}headers/
PROMPT_PATH:=${PRJT_PATH}srcs/prompt/
ENV_PATH:=${PRJT_PATH}srcs/env
INPUT_PATH:=${PRJT_PATH}srcs/input/
BUILTIN_PATH:=${PRJT_PATH}srcs/built-ins/
TEST_PATH:=${PRJT_PATH}tests/
COMMON_SRCS:=  $(wildcard ${PRJT_PATH}srcs/common/*.c)
ENV_SRCS:=  $(wildcard ${PRJT_PATH}srcs/env/*c)
INPUT_SRCS:=  $(wildcard ${PRJT_PATH}srcs/input/*.c)
SYNTAX_SRCS:=  $(wildcard ${PRJT_PATH}srcs/syntax/*.c)
SRCS:= ${COMMON_SRCS} ${ENV_SRCS} ${INPUT_SRCS} ${SYNTAX_SRCS}


ptest:	libft.a
	${CC} ${CFLAGS} ${TEST_PATH}prompt_testing.c ${HEADERS} ${COMMON_SRCS} ${INPUT_SRCS} -o ptest
