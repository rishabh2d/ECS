paint.out: main.o add.o create_canvas.o delete.o diagonal.o horizontal.o resize.o saveLoad.o
	gcc -g -Wall -Werror -o paint.out main.o add.o create_canvas.o delete.o diagonal.o horizontal.o resize.o saveLoad.o

main.o: main.c add.h create_canvas.h delete.h diagonal.h horizontal.h resize.h saveLoad.h
	gcc -g -Wall -Werror -c main.c

add.o: add.c add.h create_canvas.h
	gcc -g -Wall -Werror -c add.c

create_canvas.o: create_canvas.c create_canvas.h
	gcc -g -Wall -Werror -c create_canvas.c

delete.o: delete.c delete.h create_canvas.h
	gcc -g -Wall -Werror -c delete.c

diagonal.o: diagonal.c diagonal.h
	gcc -g -Wall -Werror -c diagonal.c

horizontal.o: horizontal.c horizontal.h
	gcc -g -Wall -Werror -c horizontal.c

resize.o: resize.c resize.h
	gcc -g -Wall -Werror -c resize.c

saveLoad.o: saveLoad.c saveLoad.h resize.h
	gcc -g -Wall -Werror -c saveLoad.c

clean:
	rm -f *.o *.out