LIBRARY			=	libftprintf.a

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	ft_printf_c ft_printf_s ft_printf_p ft_printf_xX ft_printf_u ft_printf_d_i ft_printf handler helpers ft_result
SRCS 			=	$(addsuffix .c, $(SRC))

OBJ_DIR			=	obj
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

$(OBJ_DIR)/%.o:		%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(LIBRARY)

bonus:				all

$(LIBRARY):			$(LIBFT) $(OBJ_DIR) $(OBJS)
				cp	$(LIBFT) $(LIBRARY)
					$(AR) $(ARFLAGS) $(LIBRARY) $(OBJS)

$(LIBFT):
					make -C $(LIBFT_PATH) all

$(OBJ_DIR):
					mkdir -p $(OBJ_DIR)

clean:
					make -C $(LIBFT_PATH) clean
					$(RM) $(OBJ_DIR)

fclean:				clean
					make -C $(LIBFT_PATH) fclean
					$(RM) $(LIBRARY)

re:					fclean all

.PHONY:				all bonus clean fclean re libft