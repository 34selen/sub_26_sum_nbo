#Makefile
all:sum-nbo

sum_nbo:
	g++ main.cpp -o sum-nbo
clean:
	rm -f sum-nbo