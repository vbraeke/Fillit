# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julio <julio@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 17:28:13 by jmontija          #+#    #+#              #
#    Updated: 2016/01/04 01:14:13 by julio            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC				=	gcc
NAME			=	fillit
FLAGS			=	-Wall -Wextra -Werror

LIB_PATH		=	libft/
LIB				=	$(LIB_PATH)libft.a
LIB_LINK		=	-L $(LIB_PATH) -lft

INCLUDES		=	-I $(LIB_PATH) -I ./includes
SRCS			+=	srcs/fillib.c
SRCS			+=	srcs/main.c
SRCS			+=	srcs/launcher.c
SRCS			+=	srcs/prelauncher.c
SRCS			+=	srcs/resolve.c
SRCS			+=	srcs/save_reset.c

OBJS			=	$(SRCS:srcs/%.c=srco/%.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[34m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	[ $(C_GOOD)OK$(C_NO) ]
OK				=	[ $(C_OK)OK$(C_NO) ]


all: srco $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^ $(LIB_LINK)
	@echo "Compiling" $(NAME) "\t\t" $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)
	@echo "Creating" libft.a"\t\t" $(SUCCESS)

srco:
	@mkdir -p srco
	@echo "Dir srco created\t\t" $(SUCCESS)

srco/%.o: srcs/%.c ./includes/*.h
	@$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<
	@echo "Linking" $< "\t\t" $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf srco
	@echo "Cleaning" $(NAME) "\t\t" $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" $(NAME) "\t\t\t" $(OK)

re: fclean all
