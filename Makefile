#============================= FILES PART =====================================
SRCS			=	exec.c	\
					free.c	\
					pipex.c	\
					verif_command.c	\

SRCS_D			=	srcs/

OBJS			=	$(SRCS:%.c=$(OBJS_D)%.o)

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

$(OBJS)			:	$(OBJS_D)%.o: $(SRCS_D)%.c $(HEAD_D)$(HEAD) $(MLX_A) $(LIBFT_A)
				$(CC) $(CCFLAG) -I$(HEAD_D) -I$(LIBFT_D) -c $< -o $@

$(OBJS_D)		:
				mkdir -p $(OBJS_D)

$(LIBFT_A)		:	FORCE
				make -C $(LIBFT_D)

fsanitize		:	$(MLX_A) $(LIBFT_A) $(OBJS_D) $(HEAD_D)$(HEAD) $(OBJS)
				$(CC) $(CCFLAG) $(FSA) -o $(NAME) $(OBJS) $(LIBFT_A) $(MLX_A) $(MLXFLAG)

bonus			:	$(NAME_B)

all				: $(HEAD) $(NAME)

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

