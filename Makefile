_FDF_ =		\
		fdf.c draw.c error.c read_file.c color.c colors_utils.c coords.c events.c ft_mats.c event_utils.c free_data.c \
		read_file_utils.c event_utils2.c draw_utils.c  error_utils.c\

_LIBFT_ =		\
		ft_strlen.c ft_split.c ft_atoi.c ft_substr.c ft_isdigit.c ft_putstr_fd.c \

_GET_NEXT_LINE_ =	\
		get_next_line.c get_next_line_utils.c \

FDF			= ${addprefix FDF/, ${_FDF_}}
LIBFT		= ${addprefix my_libfts/, ${_LIBFT_}}
GNL			= ${addprefix my_get_nl/, ${_GET_NEXT_LINE_}}

FDF		+=  ${LIBFT}
FDF 	+= 	${GNL}

OBJ = ${FDF:.c=.o}

DEP = ${OBJ:.o=.d}

NAME			= fdf
INDIR			= include
CC				= gcc
MLXDIR			= mlx_linux
MLX				= mlx_linux/libmlx_Linux.a
CCFLAGS			= -Leaks -Wall -Werror -Wextra -I/usr/include -Imlx_linux -g -O3
CPPFLAGS		= -MMD -I./${INDIR} -I./${MLXDIR}

all:	${NAME}

${NAME}:	${OBJ}
	${CC} ${CCFLAGS} ${OBJ} -Lmlx_linux -lmlx_Linux -L/usr/X11 -Imlx_linux -lXext -lX11 -lm -lz -o ${NAME}

clean:
	${RM} ${DEP} ${OBJ}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re

-include ${DEP}