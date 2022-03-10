NAME		=	program

HEADER		=	Zombie.hpp

SRCS		=	main.cpp Zombie.cpp zombieHorde.cpp

OBJS		= 	$(patsubst %.cpp,%.o,$(SRCS))

CPP			= 	@c++

CFLAGS		= 	-Wall -Wextra -Werror -std=c++98 -I.

RM			= 	rm -rf

all: 			$(NAME)

$(NAME): 		$(OBJS) $(HEADER)
				$(CPP) $(CFLAGS) -o $(NAME) $(OBJS) 
				@echo "\033[30;42m      Program completed      \033[0m"

clean:
				@${RM} $(OBJS)
				@echo "\033[30;43m        files deleted        \033[0m"

fclean:			
				@${RM} $(OBJS) $(NAME)
				@echo "\033[30;43m        files deleted        \033[0m"

re:				fclean all

.PHONY:			all clean fclean re