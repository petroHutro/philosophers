NAME			=	philo_bonus

SRC	=				main_bonus.c \
					src/init_bonus.c \
					src/life_bonus.c \
					src/spectator_bonus.c \
					src/utils_bonus.c \
					src/utils_2_bonus.c \
					src/forking_bonus.c \
					

OBJ			=		$(patsubst %.c,%.o,$(SRC))

HEADERS		=		includes/philo_bonus.h \
					includes/s_philo_bonus.h \

CC				=	gcc

CFLAGS			= -Wall -Wextra -Werror -g -fsanitize=thread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)