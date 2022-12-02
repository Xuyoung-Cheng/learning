main_exec : user_global.o user_control.o user_print.o main.o
	gcc user_global.o user_control.o user_print.o main.o

main.o : main.c
	gcc -c main.c -o main.o

user_global.o : user_global.c
	gcc -c user_global.c -o user_global.o

user_control.o : user_control.c
	gcc -c user_control.c -o user_control.o

user_print.o : user_print.c
	gcc -c user_print.c -o user_print.o

clean :
	rm -rf *.o *.out
