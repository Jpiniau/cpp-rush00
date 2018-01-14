NAME = ft_retro

FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./

SRC_NAME =	main.cpp\
			AEnemy.cpp\
			AEntity.cpp\
			APlayer.cpp\
			ASpaceShip.cpp\
			BaseShip.cpp\
			Frame.cpp\
			Meteor.cpp\
			Mine.cpp\
			Projectile.cpp \
			EnemyShip.cpp

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = ./

OBJ_NAME = $(SRC_NAME:.cpp=.o)

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME) : $(OBJ)
	g++ $(FLAGS) -o $@ $^ -lncurses

$(OBJ_PATH)%.o : $(SRC_PATH)%.cpp
	g++ $(FLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ_PATH)*.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
