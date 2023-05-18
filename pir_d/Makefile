CC		=	gcc
RM		=	rm -f

NAME	=	pir_d

WPLIB	=	-lwiringPi

SRC		=	pir_d.c
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
