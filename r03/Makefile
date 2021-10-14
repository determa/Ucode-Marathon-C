NAME = matrix_rain

SRCS = src/*.c

INC = inc/*.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses

all: install clean

install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) -o $(NAME) *.c

uninstall: clean
	@rm -f $(NAME)

clean:
	@rm -f *.h
	@rm -f *.c
	
reinstall:
	@make uninstall
	@make

