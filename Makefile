#============================= FILES PART =====================================
SRCS			=	exec.c	\
					free.c	\
					pipex.c	\
					verif_command.c	\

SRCS_B			=	exec_bonus.c			\
					free_bonus.c			\
					pipex_bonus.c			\
					verif_command_bonus.c	\
					here_doc_bonus.c		\

SRCS_D			=	srcs/mandatory/

SRCS_D_B		=	srcs/bonus/

OBJS			=	$(SRCS:%.c=$(OBJS_D)%.o)

OBJS_B			=	$(SRCS_B:%.c=$(OBJS_D_B)%.o)

OBJS_D			=	obj/

OBJS_D_B		=	obj_b/

HEAD			=	pipex.h

HEAD_MAP		=	map.h

HEAD_D			=	include/

NAME			=	pipex

LIBFT_D			=	Libft_w_a/

LIBFT_A			=	Libft_w_a/libft.a

LIBFT_H			=	Libft_w_a/libft.h

#==============================================================================

#============================= BASH COMMAND ===================================
CC				=	cc

GCC				=	gcc

CCFLAG			=	-Wall -Werror -Wextra -g3

FSA				=	-fsanitize=address -g3

RM				=	rm -f -r
#==============================================================================

#============================= MK COMMAND =====================================
$(NAME)			:	$(OBJS_D) $(OBJS) $(HEAD_D)$(HEAD)
				$(CC) $(CCFLAG) -o $(NAME) $(OBJS) $(LIBFT_A)

$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_D)$(HEAD) $(LIBFT_A)
				$(CC) $(CCFLAG) -I$(HEAD_D) -I$(LIBFT_D) -c $< -o $@

$(OBJS_B)		:	$(OBJS_D_B)%.o: $(SRCS_D_B)%.c $(HEAD_D)$(HEAD) $(LIBFT_A)
				$(CC) $(CCFLAG) -I$(HEAD_D) -I$(LIBFT_D) -c $< -o $@

$(OBJS_D)		:
				mkdir -p $(OBJS_D)

$(OBJS_D_B)		:
				mkdir -p $(OBJS_D_B)

$(LIBFT_A)		:	FORCE
				make -C $(LIBFT_D)

fsanitize		:	$(MLX_A) $(LIBFT_A) $(OBJS_D) $(HEAD_D)$(HEAD) $(OBJS)
				$(CC) $(CCFLAG) $(FSA) -o $(NAME) $(OBJS) $(LIBFT_A)

bonus			:	$(OBJS_D_B) $(OBJS_B) $(HEAD_D)$(HEAD)
				$(CC) $(CCFLAG)  -o $(NAME) $(OBJS_B) $(LIBFT_A)

all				: $(NAME) bonus

clean			:
				$(RM) $(OBJS) $(OBJS_D) $(OBJS_D_B)

cleanlibext		:
				make fclean -C $(LIBFT_D)

fclean			:	clean cleanlibext
				$(RM) $(NAME) $(NAME_B) $(NAME_MAP)

re				:	fclean $(NAME)

refs			:	fclean fsanitize

.PHONY			:	all clean fclean re bonus refs cleanlibext fsanitize map FORCE
#==============================================================================

