# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julio <julio@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 17:28:13 by jmontija          #+#    #+#              #
#    Updated: 2016/01/17 21:59:10 by julio            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	fillit
COMPIL			=	gcc -Wall -Wextra -Werror

LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

INCLUDES		=	-I $(LIB_PATH) -I ./includes
SRCS			+=	srcs/fillib.c
SRCS			+=	srcs/fillst.c
SRCS			+=	srcs/main.c
SRCS			+=	srcs/launcher.c
SRCS			+=	srcs/prelauncher.c
SRCS			+=	srcs/resolve.c
SRCS			+=	srcs/save_reset.c

OBJS			=	$(SRCS:srcs/%.c=srco/%.o)

all: srco $(NAME)

srco:
	@mkdir -p srco

$(NAME): $(LIB) $(OBJS)
	@$(COMPIL) -o $@ $^ $(LIB_LINK)
	@echo "Compiled" $(NAME) "done"

$(LIB):
	@make -C $(LIB_PATH)
	@echo "Created libft.a"

srco/%.o: srcs/%.c ./includes/*.h
	@$(COMPIL) $(INCLUDES) -c -o $@ $<

clean:
	@rm -f $(OBJS)
	@rm -rf srco
	@echo "Cleaning" $(NAME)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" $(NAME)

re: fclean all
