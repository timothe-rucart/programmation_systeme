CFLAGS = -Werror -W -Wall

tp8: tp8.o main.o
	gcc $(CFLAGS) -o $@ $^

%.o: %.c 
	gcc $(CLFAGS) -c $^
