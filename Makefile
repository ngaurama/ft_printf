NAME			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar -rcs
RM				=	rm -rf

SRCS				=	ft_assign.c ft_printf_d_i_helper.c  ft_printf_u.c	ft_result.c ft_printf.c \
					ft_printf.c ft_printf_u_helpers.c handler.c ft_printf_c.c ft_printf_p.c \
					ft_printf_x.c	helpers.c utils.c ft_printf_d_i.c ft_printf_s.c	 ft_printf_x_helpers.c

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

bonus:				all

$(NAME):			$(LIBFT) $(OBJ_DIR) $(OBJS)
				cp	$(LIBFT) $(NAME)
					$(AR) $(NAME) $(OBJS)

$(LIBFT):
					make bonus -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all bonus clean fclean re libft