#============================= FILES PART =====================================
SRCS		=	ft_striteri.c	\
				ft_putnbr_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_strmapi.c	\
				ft_putchar_fd.c	\
				ft_split.c		\
				ft_itoa.c		\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_substr.c		\
				ft_strdup.c		\
				ft_calloc.c		\
				ft_memcmp.c		\
				ft_atoi.c		\
				ft_bzero.c		\
				ft_isalnum.c	\
				ft_isalpha.c	\
				ft_isascii.c	\
				ft_isdigit.c	\
				ft_isprint.c	\
				ft_memchr.c		\
				ft_memcpy.c		\
				ft_memmove.c	\
				ft_memset.c		\
				ft_strchr.c		\
				ft_strlcat.c	\
				ft_strlcpy.c	\
				ft_strlen.c		\
				ft_strncmp.c	\
				ft_strnstr.c	\
				ft_strrchr.c	\
				ft_tolower.c	\
				ft_toupper.c	\
				ft_putchar.c	\
				ft_putnbr_10.c	\
				ft_putnbr_16.c	\
				ft_putpointer.c	\
				ft_putstr.c		\
				ft_printf.c		\
				get_next_line.c	\

BONUS		=	ft_lstadd_back.c	\
				ft_lstadd_front.c	\
				ft_lstclear.c		\
				ft_lstdelone.c		\
				ft_lstiter.c		\
				ft_lstlast.c		\
				ft_lstmap.c			\
				ft_lstnew.c			\
				ft_lstsize.c

OBJS			=	${SRCS:%.c=$(OBJS_DIR)%.o}

BONUSOBJS 		=	${BONUS:%.c=$(OBJS_DIR)%.o}

OBJS_DIR		=	obj/

HEAD			=	libft.h

MK				=	Makefile

NAME    		=	libft.a
#==============================================================================

#============================= BASH COMMAND ===================================
CC				=	cc

FLAG			=	-Wall -Werror -Wextra

ARC				=	ar rc

RM				=	rm -f -r
#==============================================================================

#============================= MK COMMAND =====================================
$(OBJS_DIR)%.o	:	%.c $(HEAD) $(MK)
				$(CC) $(FLAG) -c $< -o $@

$(NAME)			:	$(OBJS_DIR) $(MK) $(HEAD) $(OBJS)
				$(ARC) $(NAME) $(OBJS)

$(OBJS_DIR)		:
				mkdir -p $(OBJS_DIR)

bonus			:	$(OBJS_DIR) ${MK} ${BONUSOBJS} ${HEAD}
				${ARC} ${NAME} ${BONUSOBJS}

all				:	$(HEAD) $(MK) $(NAME)

clean			:
				$(RM) $(OBJS) $(BONUSOBJS) $(OBJS_DIR)

fclean			:	clean
				$(RM) $(NAME)

re				:	fclean $(NAME)

.PHONY			:	all clean fclean bonus re
#==============================================================================
