# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/18 20:52:10 by rfrey             #+#    #+#              #
#    Updated: 2014/05/10 19:27:39 by rfrey            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
                                                                    #
# **************************************************************************** #

################################################################################
# BASIC VARIABLES															   #
################################################################################

NAME     = philo
CC       = cc
CFLAGS   = -Wall -Werror -Wextra
PATH_OBJ = obj
PATH_SRC = src
PATH_INC = inc
SRC      = main.c init.c free.c philo.c action.c hook.c display.c \
		   display_sticks.c state.c
OBJ      = $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRC))

################################################################################
# LIBRARY VARIABLES															   #
################################################################################

PATH_LIBFT     = libft
LIBFT          = ft
PATH_LIBFT_INC = $(PATH_LIBFT)/includes

PATH_DRAW      = draw
DRAW           = ft_draw
PATH_DRAW_INC  = $(PATH_DRAW)/inc

PATH_MATH      = libmath
MATH           = ft_math
PATH_MATH_INC  = $(PATH_MATH)/inc

LIB_INC_LST    = $(PATH_MATH)/inc $(PATH_DRAW)/inc $(PATH_LIBFT)/includes
LIB_INC        = $(patsubst %, -I%, $(LIB_INC_LST))
LIB_OBJ        = $(PATH_LIBFT)/$(LIBFT) $(PATH_DRAW)/$(DRAW) \
				$(PATH_MATH)/$(MATH)
LIB_OBJ_OPTION = -L$(PATH_LIBFT) -l$(LIBFT) -L$(PATH_MATH) -l$(MATH) \
				-L$(PATH_DRAW) -l$(DRAW) -L/usr/X11/lib -lmlx -lXext -lX11

################################################################################
# RULES																		   #
################################################################################

all : $(PATH_MATH)/$(MATH) $(PATH_DRAW)/$(DRAW) $(PATH_LIBFT)/$(LIBFT) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(LIB_OBJ_OPTION) $(CFLAGS) $^ -o $@
	@echo " done !"

$(PATH_OBJ)/%.o : $(addprefix $(PATH_SRC)/, %.c)
	@echo -n .
	@mkdir -p $(PATH_OBJ)
	$(CC) $(CFLAGS) -o $@ -c $< -I $(PATH_INC)/ $(LIB_INC)

$(PATH_LIBFT)/$(LIBFT) : $(PATH_LIBFT)/Makefile
	@cd $(PATH_LIBFT)/ && $(MAKE)

$(PATH_DRAW)/$(DRAW) : $(PATH_DRAW)/Makefile
	@cd $(PATH_DRAW)/ && $(MAKE)

$(PATH_MATH)/$(MATH) : $(PATH_MATH)/Makefile
	@cd $(PATH_MATH)/ && $(MAKE)

clean :
	@rm -f $(OBJ)
	@cd $(PATH_LIBFT) && $(MAKE) $@
	@cd $(PATH_DRAW) && $(MAKE) $@
	@cd $(PATH_MATH) && $(MAKE) $@

fclean : clean
	@rm -f $(NAME)
	@rm -f $(PATH_LIBFT)/libft.a
	@rm -f $(PATH_MATH)/libft_math.a
	@rm -f $(PATH_DRAW)/libft_draw.a

re : fclean all

.PHONY: clean fclean
