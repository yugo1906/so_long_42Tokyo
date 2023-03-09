NAME			=	so_long
CFLAGS		=	-Wall -Wextra -Werror
LIBFTDIR	=	./include_libft
PRINTFDIR	=	./include_printf
GNLDIR		=	./include_gnl
SRCS = main.c
OBJS = ${SRCS:%.c=%.o}

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	make -C $(PRINTFDIR)
	make -C $(GNLDIR)
	make -C ./minilibx-linux
	cc $(CFLAGS)  \
	-framework OpenGL \
	-framework AppKit \
	/usr/X11R6/lib/libX11.dylib \
	/usr/X11R6/lib/libXext.dylib \
	-L./minilibx-linux \
	-lmlx_Darwin \
	$^ $(LIBFTDIR)/libft.a $(PRINTFDIR)/libftprintf.a $(GNLDIR)/libgnl.a -o $@

clean :
		make clean -C $(LIBFTDIR)
		make clean -C $(PRINTFDIR)
		make clean -C $(GNLDIR)
	rm -f $(OBJS)

fclean : clean
	make fclean -C $(LIBFTDIR)
	make fclean -C $(PRINTFDIR)
	make fclean -C $(GNLDIR)
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
