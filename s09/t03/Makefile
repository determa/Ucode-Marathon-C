all: obj MINILIBMX create_lib

FLAGS = -Wall -Wextra -Werror -Wpedantic
CC = clang

obj:
	mkdir obj

MINILIBMX: object.o

object.o:
	$(CC) $(FLAGS) -c src/*.c

create_lib:
	ar -src minilibmx.a *.o
	ranlib minilibmx.a
	mv *.o obj

uninstall:
	rm -rf obj
	rm *.a

clean:
	rm -rf src
	rm -rf inc

reinstall:
	make uninstall
	make

	