CC		=	gcc
RM		=	rm -f

NAME	=	humid_temp

WPLIB	=	-lwiringPi

SRC		=	humid_temp.c
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
