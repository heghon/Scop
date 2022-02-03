# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 16:17:22 by bmenant           #+#    #+#              #
#    Updated: 2022/02/03 12:19:40 by bmenant          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =			main.cpp \
				window.cpp \
				glad.cpp \
				input.cpp \
				Shader.cpp \
				Vektor.cpp \
				# shaders.cpp

GREEN =			\033[0;32m
BLUE =			\033[1;34m
YELLOW =		\033[1;33m
WHITE =			\033[0;37m
OK =			$(GREEN)-OK-$(WHITE)

CXX =			clang++
NAME =			scop

SRC_FILE =		./src/
OBJ_FILE =		./obj/

OBJ =			$(SRC:.cpp=.o)

SRCS =			$(addprefix $(SRC_FILE),$(SRC))
OBJS =			$(addprefix $(OBJ_FILE),$(OBJ))

WFLAGS =		-Wall -Wextra -Werror
STDFLAGS =		-std=c++11

FRMWRK =		-framework OpenGL
LIBFLAGS =		GLFW/lib/libglfw.3.3.dylib glad/lib/libglad.a

RM =			/bin/rm -f

.PHONY:			all clean fclean re


all : $(NAME)

$(OBJ_FILE)%.o : $(SRC_FILE)%.cpp
	@mkdir $(OBJ_FILE) 2> /dev/null || true
	@$(CXX) -c $(WFLAGS) -o $@ $<
	@echo "$@\r				$(OK)"

$(NAME) : $(OBJS)
	@$(CXX) $(OBJS) -o $(NAME) $(FRMWRK) $(LIBFLAGS)
	@echo "$(BLUE)-$(NAME)-\r				$(OK)"

clean :
	@rm -Rf $(OBJ_FILE)
	@echo "$(BLUE)-clean-\r				$(OK)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(BLUE)-fclean-\r				$(OK)"

re	: fclean all

test : all 
	./$(NAME)