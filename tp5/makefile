CFLAGS = -Werror -W -Wall

#regle 1
tp5: tp5.o main.o
	gcc $(CFLAGS) -o $@ $^

%.o: %.c 
	gcc $(CFLAGS) -c $^
