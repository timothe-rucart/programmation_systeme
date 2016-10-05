CFLAGS = -Werror -W -Wall

#regle 1
tp4: tp4.o main.o
	gcc $(CFLAGS) -o $@ $^

%.o: %.c 
	gcc $(CFLAGS) -c $^
