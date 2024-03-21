##
## EPITECH PROJECT, 2022
## Luan BOURBIER
## File description:
## Makefile n 1
##

SRC			=	./my_array_len.c\
				./my_free_array.c\
				./my_getnbr.c\
				./my_strcat.c\
				./my_strcmp.c\
				./my_strdup.c\
				./my_strcpy.c\
				./my_strlen.c\
				./str_sep.c\
				./my_strncpy.c\


OBJ			=	$(SRC:.c=.o)

MYH			=	my.h

LIBNAME		=	libmy.a

CPPFLAGS	=	-Wall -Wextra

all:	build

build:	$(OBJ)
	$(CC) -c $(SRC)
	ar rc $(LIBNAME) $(OBJ)
	cp $(MYH) ../../include/
	cp $(LIBNAME) ../

clean:
	$(RM) -f $(OBJ)

fclean:	clean
	$(RM) -f $(LIBNAME)
	$(RM) ../$(LIBNAME)

re:	fclean all

.PHONY:	all build clean fclean re
