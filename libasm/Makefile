NAME = libasm.a

CC = gcc -Werror -Wextra -Wall
NASM = nasm -f macho64

SRCS =	ft_strlen.s \
		ft_strcpy.s

OBJS = $(SRCS:.s=.o)

%.o: %.s
	nasm -f macho64 $<

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

test: all
	$(CC) -L. -lasm -o test main.c
	./test

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf test

re: fclean all