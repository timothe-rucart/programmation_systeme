CFLAGS = -Werror -W -Wall

tp8: tp8.o ligne_commande.o
	gcc $(CFLAGS) -o $@ $^

%.o: %.c 
	gcc $(CLFAGS) -c $^
