CFLAGS = -Werror -W -Wall

#regle 1
tp3: tp3.o main.o
	gcc $(CFLAGS) -o $@ $^

%.o: %.c 
	gcc $(CFLAGS) -c $^
