all: inst

FLAGS = -Wall -Wextra -Werror -Wpedantic
CC = clang
name = calc

inst: $(name)

$(name):
	$(CC) $(FLAGS) -o $(name) src/*.c

uninstall:
	rm calc

clean:
	rm -rf src
	rm -rf inc

reinstall:
	make uninstall
	make

