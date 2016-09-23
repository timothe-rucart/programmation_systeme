CFLAGS = -Werror -W -Wall

#regle 1
tp1: tp1_1.o tp1_2.o tp1_3.o
	gcc $(CFLAGS) -o $@ $^

%.o : %.c tp1_2.h
	gcc $(CFLAGS) -c $^

