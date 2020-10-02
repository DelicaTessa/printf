# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tclement <tclement@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/11 10:31:15 by tclement      #+#    #+#                  #
#    Updated: 2020/10/02 16:14:27 by tclement      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 	 libftprintf.a

LIBFT = libft

CFLAGS = -Wall -Werror -Wextra

SRC = 	ft_printf.c \
        check_one.c \
		check_two.c \
		arg.c \
		char.c \
		hex.c \
		int.c \
		octal.c \
		len.c \
		pointer.c \
		width_prec.c \
		print.c \
		utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rcs $(NAME) $?

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT)

fclean:    clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: clean fclean re bonus all
