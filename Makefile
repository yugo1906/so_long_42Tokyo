NAME				=	so_long
# CFLAGS			=	-Wall -Wextra -Werror
CFLAGS			=	-g -fsanitize=address
LIBFT_DIR		=	./include_libft
PRINTF_DIR	=	./include_printf
GNL_DIR			=	./include_gnl
SRC_DIR			=	./src
SRCS 				= main.c \
							check_arg.c \
							get_loaded_map.c
SRCS				:= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS 				= ${SRCS:%.c=%.o}

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	make -C $(GNL_DIR)
	make -C ./minilibx-linux
	cc $(CFLAGS)  \
	-framework OpenGL \
	-framework AppKit \
	/usr/X11R6/lib/libX11.dylib \
	/usr/X11R6/lib/libXext.dylib \
	-L./minilibx-linux \
	-lmlx_Darwin \
	$^ $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a $(GNL_DIR)/libgnl.a -o $@

clean :
		make clean -C $(LIBFT_DIR)
		make clean -C $(PRINTF_DIR)
		make clean -C $(GNL_DIR)
	rm -f $(OBJS)

fclean : clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	make fclean -C $(GNL_DIR)
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
