#				______ _ _
#				|  ____(_) |
#				| |__   _| | ___  ___
#				|  __| | | |/ _ \/ __|
#				| |    | | |  __/\__ \.
#				|_|    |_|_|\___||___/

HEADERS 	=	miniRT.h

SRCS		=	camera.c \
		parsing/parsing.c \
		parsing/fill_data/fill_data.c \
		main.c \
		sphere.c

MLXSRC		=	libmlx.a

LIBFTSRC	=	libftprintf.a libft.a printffd.a

UTILSSRC	=	mlx_utils.c vec3_utils.c

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

SRCSPATH	=	$(addprefix $(SRCSDIR),$(SRCS)) \
				$(addprefix $(UTILSDIR),$(UTILSSRC))

LIBFT		=	$(addprefix $(LIBFTDIR),$(LIBFTSRC))

OBJS		=	$(addprefix $(OBJSDIR), $(SRCSPATH:.c=.o))

#		 __      __        _       _     _
#		 \ \    / /       (_)     | |   | |
#		  \ \  / /_ _ _ __ _  __ _| |__ | | ___  ___
#		   \ \/ / _` | '__| |/ _` | '_ \| |/ _ \/ __|
#		    \  / (_| | |  | | (_| | |_) | |  __/\__ \.
#		     \/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/

RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
BLUE		=	\033[1;34m
CYAN		=	\033[1;36m
DEFAULT		=	\033[0m
SUPPR		=	\r\033[2K

NAME		=	MiniRT

AR			=	ar rc

FLAGS		=	-lX11 -lXext -lm -L$(MLXDIR)

CFLAGS		=	-Wall -Wextra -Werror -g

CC			=	cc

RM			=	rm -rf

MKDIR		=	mkdir -p

#				  _____       _
#				 |  __ \     | |
#				 | |__) |   _| | ___  ___
#				 |  _  / | | | |/ _ \/ __|
#				 | | \ \ |_| | |  __/\__ \.
#				 |_|  \_\__,_|_|\___||___/

all : lib ${NAME}

${NAME}: $(UTILSOBJS) $(OBJS)  $(LIBFT)
	@${CC} ${OBJS} ${LIBFT} $(FLAGS) ${MLX} -o ${NAME}
	@echo -n "${SUPPR}	${GREEN} ${NAME} : 🆗${DEFAULT}\n\n"

$(OBJSDIR)%.o: %.c ${HEAD}
	@$(MKDIR) .objs
	@mkdir -p $(dir $@)
	#@echo -n "${YELLOW}${SUPPR}	⌛ Creating MiniRT objects : $@"
	$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERSDIR)

clean:
	@${MAKE} clean -C ${LIBFTDIR}
	@${RM} ${OBJS}

fclean:
	@echo "${RED}🗑  ${NAME} cleanded"
	@${RM} ${OBJS}
	@${RM} ${OBJSDIR}
	@${RM} ${NAME}
	@${MAKE} fclean --no-print-directory -C ${LIBFTDIR}

re:
	@${MAKE} --no-print-directory fclean
	@${MAKE} --no-print-directory all

lib:
	@${MAKE} --no-print-directory -C ${LIBFTDIR}
	@${MAKE} --no-print-directory  --silent -C ${MLXDIR}

.PHONY : re all clean fclean printf lib

