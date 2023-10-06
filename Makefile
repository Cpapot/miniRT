#				______ _ _
#				|  ____(_) |
#				| |__   _| | ___  ___
#				|  __| | | |/ _ \/ __|
#				| |    | | |  __/\__ \.
#				|_|    |_|_|\___||___/

HEADERS 	=	camera.h	\
				check_lines_ft.h	\
				color.h	\
				cone.h	\
				cylinder.h	\
				disk.h	\
				filling_ft.h	\
				find_object.h	\
				hit.h	\
				key.h	\
				light.h	\
				material.h	\
				miniRT.h	\
				mini_parse_ft.h	\
				minirt_data.h	\
				minirt_manipulation.h	\
				parsing.h	\
				plane.h	\
				reflection.h	\
				sphere.h	\
				structure.h	\
				vec3.h	\
				window.h	\
				close.h	\

SRCS		=	object/light.c \
				camera/camera.c \
				camera/gamma.c \
				parsing/parsing.c \
				parsing/fill_data/get_line_data.c \
				parsing/fill_data/get_line_data_object.c \
				parsing/fill_data/get_line_data_numbers.c \
				parsing/fill_data/get_line_data_ft.c \
				parsing/fill_data/get_line_data_motions.c \
				parsing/fill_data/material.c \
				parsing/fill_data/basic_material.c \
				parsing/fill_data/fill_data.c \
				parsing/fill_data/filling_ft.c \
				parsing/fill_data/filling_ft_object.c \
				parsing/fill_data/mini_parse_ft.c \
				parsing/fill_data/motions.c \
				parsing/fill_data/number.c \
				parsing/fill_data/manage_ft.c \
				parsing/fill_data/manage_ft_object.c \
				parsing/fill_data/warning.c \
				parsing/listc/lstc_2.c \
				parsing/listc/lstc.c \
				utils/object_utils.c \
				utils/light_utils.c	\
				utils/minirt_data.c \
				utils/vec3_utils.c \
				utils/vec3_utils2.c \
				utils/mlx_utils.c \
				utils/data_utils.c \
				utils/vec3_math.c \
				object/plane.c \
				render.c \
				object/find_object.c \
				main.c \
				color.c \
				hit.c \
				object/sphere.c \
				shadow.c \
				hook.c \
				close.c \
				camera/print_info.c \
				camera/anti_aliasing.c \
				object/ambient_light.c \
				object/cone.c \
				object/cylinder.c \
				object/disk.c \
				utils/math.c \
				reflection.c \

MLXSRC		=	libmlx.a

LIBFTSRC	=	libftprintf.a libft.a printffd.a

#					Directories

UTILSDIR		=	./srcs/utils/

MLXDIR			=	./mlx_lin/

HEADERSDIR		=	./inc/

SRCSDIR			=	./srcs/

LIBFTDIR		=	./libft/

OBJSDIR			=	./.objs/

#					Full Path

MLX			=	$(addprefix $(MLXDIR),$(MLXSRC))

HEAD		=	$(addprefix $(HEADERSDIR),$(HEADERS))

SRCSPATH	=	$(addprefix $(SRCSDIR),$(SRCS))

LIBFT		=	$(addprefix $(LIBFTDIR),$(LIBFTSRC))

OBJS		=	$(addprefix $(OBJSDIR), $(SRCSPATH:.c=.o))

#		 __      __        _       _     _
#		 \ \    / /       (_)     | |   | |
#		  \ \  / /_ _ _ __ _  __ _| |__ | | ___  ___
#		   \ \/ / _` | '__| |/ _` | '_ \| |/ _ \/ __|
#		    \  / (_| | |  | | (_| | |_) | |  __/\__ \.
#		     \/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/

define HEADER
"\e[2J\e[H
\033[1;36m
	    __  ____       _ ____  ______
	   /  |/  (_)___  (_) __ \/_  __/
	  / /|_/ / / __ \/ / /_/ / / /
	 / /  / / / / / / / _, _/ / /
	/_/  /_/_/_/ /_/_/_/ |_| /_/
\033[0m
endef
export HEADER

RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
CYAN		=	\033[1;36m
DEFAULT		=	\033[0m
SUPPR		=	\r\033[2K

NAME		=	miniRT

AR			=	ar rc

FLAGS		=	-lX11 -lXext -L$(MLXDIR) -lm

CFLAGS		=	-Wall -Wextra -Werror -Ofast

CC			=	gcc

RM			=	rm -rf

MKDIR		=	mkdir -p

MUTE		:=	1

#				  _____       _
#				 |  __ \     | |
#				 | |__) |   _| | ___  ___
#				 |  _  / | | | |/ _ \/ __|
#				 | | \ \ |_| | |  __/\__ \.
#				 |_|  \_\__,_|_|\___||___/

all : header lib ${NAME}

${NAME}: $(OBJS) $(LIBFT)
ifeq ($(MUTE),1)
	@${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME} $(FLAGS)
	@echo -n "${SUPPR} ${GREEN}	${NAME} : 🆗${DEFAULT}\n"
else
	${CC} ${OBJS} ${LIBFT} ${MLX} -o ${NAME} $(FLAGS)
endif

$(OBJSDIR)%.o: %.c ${HEAD}
	@$(MKDIR) .objs
	@$(MKDIR) $(dir $@)
ifeq ($(MUTE),1)
	@echo -n "${YELLOW}${SUPPR}	⌛ Creating MiniRT objects : $@"
	@$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERSDIR) -Ilibft/includes
else
	$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERSDIR) -Ilibft/includes
endif

clean:
	@${MAKE} clean -C ${LIBFTDIR}
	@${RM} ${OBJS}

fclean:
	@echo "${RED}🗑  ${NAME} cleanded"
	@${RM} ${OBJS}
	@${RM} ${OBJSDIR}
	@${RM} ${NAME}
	@echo "${RED}🗑  MLX cleanded"
	@${MAKE} fclean --no-print-directory -C ${LIBFTDIR}
	@${MAKE} clean --no-print-directory  --silent -C ${MLXDIR}

reobj:
	rm -rf $(OBJSDIR)
	@${MAKE} --no-print-directory all

header:
	@echo "$$HEADER"

re:
	@${MAKE} --no-print-directory fclean
	@${MAKE} --no-print-directory all

lib:
	@${MAKE} --no-print-directory -C ${LIBFTDIR}
	@${MAKE} --no-print-directory  --silent -C ${MLXDIR}
	@echo "\033[1A${SUPPR}${GREEN}	LIBMLX : 🆗${DEFAULT}"

.PHONY : re all clean fclean printf lib header


