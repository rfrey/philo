# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbersac <gbersac@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/16 17:32:22 by gbersac           #+#    #+#              #
#    Updated: 2014/05/09 18:32:12 by gbersac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# BASIC VARIABLES															   #
################################################################################

NAME			:= libft_math.a
CFLAGS			:= -Wall -Wextra -Werror

PATH_OBJ		:= obj
PATH_SRC		:= src
PATH_INC		:= inc

SRCS			:= ft_create_point2d.c ft_set_point2d.c ft_abs.c ft_sqrt.c \
					ft_create_point3d.c ft_set_point3d.c ft_plan_o_proj.c \
					ft_v2d_length.c ft_v3d_length.c ft_pow.c ft_v2d_vunit.c \
					ft_v2d_divide.c ft_v3d_divide.c ft_v3d_vunit.c \
					ft_pt_to_px.c ft_v2d_multiply.c
OBJECTS			:= $(patsubst %.c, $(PATH_OBJ)/%.o, $(SRCS))

################################################################################
# LIBRARY VARIABLES															   #
################################################################################

################################################################################
# BASIC RULES																   #
################################################################################

.PHONY: all

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $@ $(OBJECTS)
	@ranlib $(NAME)
	@echo Creating Library $(NAME) $(words $(OBJECTS)) files inside

$(PATH_OBJ)/%.o: $(addprefix $(PATH_SRC)/,%.c)
	@mkdir -p $(PATH_OBJ)
	@cc -c -o $@ $(CFLAGS) $^ $(DEBUG) -I$(PATH_INC)/ $(INCLUDES)
	@echo -n .

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
