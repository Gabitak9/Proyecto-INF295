all:myprogram.o mylib.o
        g++ main.cpp –o main
clean:
        $(RM) main