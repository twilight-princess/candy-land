#include <iostream>
#include <stdlib.h>
#include <ctime>

#define GAME_LENGTH 50
/******************************* 
void advancePlayerA(int* ptrPlayerA)
{
	int advanceA = rand() % 10;
		if (advanceA <=3){
			space[] = space[] + forwardOne;
		}else if (advanceA <=5){
			space[] = space[] + forwardTwo;
		}else if (advanceA <=6){
			space[] = space[] + mountainPass;
		}else if (advanceA <=7){
			space[] = space[] + rainbowTrail;
		}else if (advanceA <=8){
			space[] = space[] - cherryPitfalls;
		}else{
			space[] = space[] - molassesSwamp;  
	advancePlayerB();			 	 	
}
void advancePlayerB(int* ptrPlayerB)
{
	int advanceB = rand() % 10;	
    if (advanceB <=3){
      space[] = space[] + forwardOne;
    }else if (advanceB <=5){
      space[] = space[] + forwardTwo;
    }else if (advanceB <=6){
      space[] = space[] + mountainPass;
    }else if (advanceB <=7){
    }else if (advanceB <=8){
      space[] = space[] - cherryPitfalls;
    }else{
      space[] = space[] - molassesSwamp;
			
}
*/
void printPosition(int* ptrPlayerA, int* ptrPlayerB)
{
        /*char space[50];
	for (int i = 0; i < 51; i++){
		space[i] = ' ';*/
	//Ensure that players do not occupy the same space.
	int valPlayA = *ptrPlayerA;
	int valPlayB = *ptrPlayerB;

	std::cout << valPlayA << ' ' << valPlayB << std::endl;
	if (valPlayA == valPlayB) {
		valPlayA -= 1;
	}
        std::cout << valPlayA << ' ' << valPlayB << std::endl;
	std::string space (50, ' ');
	space(valPlayA) = 'A';
	space(valPlayB) = 'B';
	std::cout << space << '|' << std::endl;

}

int main()
{
	srand(time(NULL));
	int playA = 2;
	int playB = 2;
	int* ptrA = &playA;
	int* ptrB = &playB;
	printPosition(ptrA, ptrB);
	/*
	char space[50];
		for (int i = 0; i < 51; i++){
		 space[i] = ' ';
		}

	int forwardOne = 1;
	int forwardTwo = 2;
	int mountainPass = 3;
	int rainbowTrail = 5;
	int cherryPitfalls = 3;
	int molassesSwamp = 5;
	*/
	//std::cout << space << '|' << std::endl;
}
