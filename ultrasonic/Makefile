CC		=	gcc
RM		=	rm -rf

NAME	=	ultrasonic

WPLIB	=	-lwiringPi

SRC		=	ultrasonic.c
OBJ		=	$(SRC:%.c=%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(WPLIB)

%.o		:	%.c
	$(CC) -c $< -o $@

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

.PHONY	:	all clean fclean
