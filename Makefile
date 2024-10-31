NAME			:=	so_long

CC				:=	gcc

CFLAGS			:=	-Wall -Werror -Wextra -g

LIB				:=	-lbsd -lmlx -lXext -lX11 -lm -lz

LIBFT			:=	./libft/libft.a

DIR				:=	./src/

SRC		:=		$(addprefix $(DIR),	\
				so_long.c			\
				read_map.c			\
				render_game.c		\
				exit_free.c			\
				verify_error.c		\
				player_move.c		\
				)

OBJS			:=	${SRC:%.c=%.o}

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME): 		$(LIBFT) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LIBFT)

$(NAME_BONUS):	$(LIBFT) 
				$(CC) $(CFLAGS) -o $(LIB) $(LIBFT)

$(LIBFT):
				make bonus -C ./libft

clean:
				rm -f $(OBJS) 
				make clean -C ./libft

fclean:			clean
				rm -f $(NAME) 
				make fclean -C ./libft

re:				fclean all

rebonus:		fclean bonus

.PHONY: 		all clean fclean re
