NAME			=	zombie

SRCS			=	main.cpp	newZombie.cpp	randomChump.cpp	Zombie.cpp
LIB				=	Zombie.hpp
					
OBJS			=	$(SRCS:%.cpp=%.o)

CC				= 	c++
RM				= 	rm -rf
CPPFLAGS		= 	-Wall -Wextra -Werror -std=c++98

all:			$(NAME)

$(NAME):		$(OBJS) $(LIB)
				$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:			
				norminette *.[ch]

.PHONY:			all clean fclean re bonus