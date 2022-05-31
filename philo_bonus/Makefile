NAME			=	philo_bonus

SRC	=				main_bonus.c \
					init_bonus.c \
					life_bonus.c \
					spectator_bonus.c \
					utils_bonus.c \
					forking_bonus.c \
					

OBJ			=		$(patsubst %.c,%.o,$(SRC))

HEADERS		=		philo_bonus.h \
					s_philo_bonus.h \

CC				=	gcc

CFLAGS			= -Wall -Wextra -Werror -g #-fsanitize=address

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