## ########################################################################## ##
##                                                                            ##
##                                                        :::      ::::::::   ##
##   Makefile                                           :+:      :+:    :+:   ##
##                                                    +:+ +:+         +:+     ##
##   By: jramondo <jramondo@student.42sp.org.br>    +#+  +:+       +#+        ##
##                                                +#+#+#+#+#+   +#+           ##
##   Created: 2021/09/20 19:37:30 by jramondo          #+#    #+#             ##
##   Updated: 2021/09/20 19:37:30 by jramondo         ###   ########.fr       ##
##                                                                            ##
## ########################################################################## ##

NAME 		= libft.a

CC			=  clang

CFLAGS		= -Wall -Werror -Wextra -fPIE

RM 			= rm -f

SRCS		= ft_isascii.c    	\
			  ft_isprint.c    	\
			  ft_isalnum.c    	\
			  ft_isalpha.c    	\
			  ft_isdigit.c    	\
			  ft_tolower.c    	\
			  ft_toupper.c    	\
			  ft_memset.c     	\
			  ft_bzero.c      	\
			  ft_memcpy.c     	\
			  ft_memmove.c    	\
			  ft_strlen.c     	\
			  ft_strlcpy.c    	\
			  ft_strlcat.c    	\
			  ft_strchr.c     	\
			  ft_strrchr.c    	\
			  ft_strncmp.c    	\
			  ft_memchr.c     	\
			  ft_memcmp.c     	\
			  ft_strnstr.c    	\
			  ft_atoi.c       	\
			  ft_calloc.c     	\
			  ft_strdup.c     	\
			  ft_substr.c     	\
			  ft_strjoin.c    	\
			  ft_strtrim.c    	\
			  ft_split.c      	\
			  ft_itoa.c       	\
			  ft_strmapi.c    	\
			  ft_striteri.c   	\
			  ft_putchar_fd.c 	\
			  ft_putstr_fd.c  	\
			  ft_putendl_fd.c 	\
			  ft_putnbr_fd.c	\
			  ft_uitoa.c		\
			  ft_itoh.c		\
			  gnl.c

SRCS_BONUS = ft_lstnew.c        \
			 ft_lstadd_front.c  \
			 ft_lstadd_back.c   \
			 ft_lstlast.c       \
			 ft_lstdelone.c     \
			 ft_lstclear.c      \
			 ft_lstsize.c       \
			 ft_lstiter.c       \
			 ft_lstmap.c

OBJS		=	${SRCS:.c=.o} 	

OBJS_BONUS	= 	${SRCS_BONUS:.c=.o}

all:		${NAME}

${NAME}:	${OBJS}
	ar -rcsv $@ ${OBJS}

bonus:		${NAME} ${OBJS_BONUS}
	ar -rcsv ${NAME} ${OBJS_BONUS}

%.o:  		%.c
	${CC} ${CFLAGS} -c ${SRCS} ${SRCS_BONUS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
	${RM} ${NAME}
re:	fclean all

.PHONY:		all clean fclean bonus
