NAME = so_long

all : $(NAME)
SRCS = main.c
OBJS = ${SRCS:%.c=%.o}

$(NAME) : $(OBJS)
	cc -Werror  \
	-framework OpenGL \
	-framework AppKit \
	/usr/X11R6/lib/libX11.dylib \
	/usr/X11R6/lib/libXext.dylib \
	-L./minilibx-linux \
	-lmlx_Darwin \
	-o $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
