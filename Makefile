#Makefile
all:sum-nbo

sum-nbo:
	g++ main.cpp -o sum-nbo
clean:
	rm -f sum-nbo