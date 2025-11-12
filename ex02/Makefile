# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theo <theo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 16:04:41 by tbahin            #+#    #+#              #
#    Updated: 2025/10/21 16:37:18 by theo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Bureaucrat

INCLUDE = .

CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJS = ${SRCS:.cpp=.o}

all : ${NAME} 

${NAME} : $(OBJS)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

bonus: $(OBJSB)
	$(CC) $(CFLAG) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAG) -I $(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f ${NAME}

re :  fclean all

.phony : all clean fclean re bonus
