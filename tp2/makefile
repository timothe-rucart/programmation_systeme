CFLAGS = -Werror -W -Wall

#regle 1
tp2: tp2_2.o tp2_1.o main.o
	gcc $(CFLAGS) -o $@ $^

%.o: %.c 
	gcc $(CFLAGS) -c $^
