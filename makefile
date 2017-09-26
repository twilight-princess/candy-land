#   Honor Pledge: I  pledge that I have neither
#   given nor receieved any help on this assignment.
#
#   daelevan
#
#   Assignment #2 makefile
#   Created By: Darlene Evans

  
run: 
	g++ Candy.cpp -o Candy.o

clean: 
	rm *.o
	rm a.out

candy: Candy.o
	./Candy.o


