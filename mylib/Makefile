%.o : %.c mylib.h
	gcc -c $<

libmylib.a:  load.o search.o
	ar -rs $@ $^