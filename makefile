CFLAGS=-Wall -O2 -ansi
fib: main_fib.o fib.o bmp.o timing.o
	$(CXX) -o fib $?
clean:
	@rm -rf fib *.o *bmp
