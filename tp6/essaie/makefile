CFLAGS = -Werror -W -Wall

tp6 : main.o tp6.o
	gcc $(CFLAGS) -o $@ $^

%.o : %.c 
	gcc $(CLFAGS) -c $^
