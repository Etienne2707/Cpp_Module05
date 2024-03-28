NAME 		= 	Bureaucrat

SRCS		=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
OBJS		=	$(SRCS:.cpp=.o)

CC = clang++
CFLAGS = -std=c++03 -Wall -Wextra -Werror -gdwarf-4
 CFLAGS += -g3
# CFLAGS += -fsanitize=address
ifeq ($(DEBUG),true)
	CFLAGS += -g
endif
OCFLAGS		=	-Wall -Wextra -Werror

all:	 		$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OCFLAGS) $(OBJS) -o $@

%.o: %.cpp
	 $(CC) $(CFLAGS) -c $< -o $@

clean:
				@rm -f $(OBJS)

fclean: 		clean
				@rm -f $(NAME)

re: 			fclean all
