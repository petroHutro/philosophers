NAME			=	philo

SRC	=				main.c \
					src/init.c \
					src/life.c \
					src/spectator.c \
					src/utils.c \
					src/utils_2.c \
					

OBJ			=		$(patsubst %.c,%.o,$(SRC))

HEADERS		=		includes/philo.h \
					includes/s_philo.h \

CC				=	gcc

CFLAGS			=	-O2 -Wall -Wextra -Werror

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