#Makefile
all:sum_nbo

sum_nbo:
	g++ main.cpp -o sum_nbo
clean:
	rm -f sum_nbo