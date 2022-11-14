# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guyar <guyar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 12:53:10 by gchatain          #+#    #+#              #
#    Updated: 2022/11/14 15:39:16 by guyar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ERASE		=	\033[2K\r
GREY		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PINK		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
BOLD		=	\033[1m
UNDER		=	\033[4m
SUR			=	\033[7m
END			=	\033[0m

PRSG_SRCS =  condition_function.c initialisation.c parsing_main.c player_initialisation.c texture_color.c verif_map.c
MAIN_SRCS =  main.c put_line.c put_rectangle.c sky_and_floor.c minimap.c game.c game2.c initialize.c move.c 
LST_SRCS = $(MAIN_SRCS) ${addprefix parsing/,$(PRSG_SRCS)}

LST_OBJS = ${LST_SRCS:.c=.o}
LIBRARY = libft/libft.a mlx/libmlx.a
SRCS = $(addprefix sources/,$(LST_SRCS))
OBJS = $(addprefix .objects/,$(LST_OBJS))
INCLUDES    = mlx/mlx.h includes/ libft/includes/
DIR_INCLUDES = $(sort $(addprefix -I, $(dir $(INCLUDES))))
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g3 #-fsanitize=address
NAME        = cub3d
RM          = rm -f
LIBX        = -I /usr/X11/include -g -L ./mlx -l mlx -framework OpenGL -framework AppKit
NORM        = $(shell norminette sources | grep -c 'Error!')

ifeq ($(NORM), 0)
	NORM_RET = "${ERASE}${GREEN}[DONE]${END} ${NAME}"
else
	NORM_RET = "${ERASE}${RED}[NORM]${END} ${NAME}"
endif

all:        compilation
	$(MAKE) $(NAME)

.objects/%.o:		sources/%.c | .objects
			${CC} ${CFLAGS} -c $< -o $@ $(DIR_INCLUDES)
			printf "${ERASE}${BLUE}[BUILD]${END} $<"

${NAME}:	${OBJS} ${INCLUDES} Makefile
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBRARY} ${LIBX} $(DIR_INCLUDES)
			echo $(NORM_RET)
			
debug:	${OBJS} ${INCLUDES} Makefile
			echo DEBUG
			${CC} ${CFLAGS} -o Dcub ${OBJS} ${LIBRARY} ${LIBX} $(DIR_INCLUDES) -g -fdiagnostics-color=always
			echo $(NORM_RET)

clean:
			rm -rf .objects
			${RM} -rf a.out.dSYM
			make fclean -s -C libft
			make clean -s -C mlx
			printf "${RED}[DELETE]${END} *.o"

fclean:	clean
			${RM} -r ${NAME} .objects
			printf "${ERASE}${RED}[DELETE]${END} ${NAME}\n"

re:		fclean
	$(MAKE) all

compilation :
	make -s -C mlx
	make -s -C libft

.objects:
			mkdir -p .objects
			mkdir -p .objects/parsing
.PHONY:	all clean fclean re

.SILENT: