# make prog -> ... -> make clean
CXX = gcc
CXX_FLAGS = -g -Wall -Wextra#-I/directory/path

SOURCES =   6.c\
			matrix.c\
#			main.c\   #lol gens main.o
#			12.c\

OBJECTS = $(SOURCES:.c=.o)

GENERATES = $(OBJECTS) prog

prog:		$(OBJECTS)
			$(CXX) $(CXX_FLAGS) $^ -o $@

%.o:		%.c
			$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
		rm -f $(GENERATES)