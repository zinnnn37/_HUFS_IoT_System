CC		=	gcc
RM		=	rm -f

NAME	=	touchSensor

WPLIB	=	-lwiringPi

SRC		=	touchSensor.c
OBJ		=	$(SRC:%.c=%.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $< $(WPLIB)

%.o		:	%.c
	$(CC) -c $< -o $@

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

.PHONY	:	all clean fclean
