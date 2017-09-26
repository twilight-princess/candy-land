#include <iostream>
#include <stdlib.h>
#include <ctime>
#define GAME_LENGTH 50

#define FORWARDONE 1
#define FORWARDTWO 2
#define MOUNTAINPASS 3
#define RAINBOWTRAIL 5
#define CHERRYPITFALLS -3
#define MOLASSESSWAMP -5

char* board[50];

void advancePlayerA(int* ptrPlayerA);
void advancePlayerB(int* ptrPlayerB);
void printPosition(int* ptrPlayerA, int* ptrPlayerB);


void advancePlayerA(int* ptrPlayerA){
	
 	srand(time(NULL));	
	int x = rand() % 10;
	int jump;
	if (x <=3){
		jump = FORWARDONE;
	}else if (x <=5){
		jump = FORWARDTWO;
	}else if (x <=6){
		jump = MOUNTAINPASS;
	}else if (x <=7){
		jump = RAINBOWTRAIL;
	}else if (x <=8){
		jump = CHERRYPITFALLS;
	}else{
		jump = MOLASSESSWAMP;
	}  
	if (board[&ptrPlayerA + jump] == "B"){ 
		jump -= 1;
	}
	&ptrPlayerA += jump;	
} 

void advancePlayerB(int* ptrPlayerB){

 	srand(time(NULL));	
	int x = rand() % 10;
	int jump;
	if (x <=2){
		jump = FORWARDONE;
	}else if (x <=3){
		jump = FORWARDTWO;
	}else if (x <=5){
		jump = MOUNTAINPASS;
	}else if (x <=6){
		jump = RAINBOWTRAIL;
	}else if (x <=8){
		jump = CHERRYPITFALLS;
	}else{
		jump = MOLASSESSWAMP;
	}  
	if (&board[&ptrPlayerB + jump] == "A"){ 
		jump -= 1;
	}
	&ptrPlayerB += jump;	
}
void printPosition(int* ptrPlayerA, int* ptrPlayerB){

  for (int i = 0; i <= GAME_LENGTH; i++){
		if (i == &ptrPlayerA){
			std::cout << "A";
		}else if (i == &ptrPlayerB){
			std::cout << "B";
		}else{
			std::cout << " ";
		}
	}
	std::cout << "|"; 
}

int main()
{
	int positionPlayerA = 0;
	int positionPlayerB = 0;
	bool endGame = &board[GAME_LENGTH-1] != " ";
	while (!endGame){
		advancePlayerA(&positionPlayerA);
		advancePlayerB(&positionPlayerB);
		printPosition(positionPlayerA, positionPlayerB);
		endGame = &board[GAME_LENGTH-1] != " ";
	} 
	if (&board[GAME_LENGTH-1] == "A"){
		std::cout << "You won!" << std::endl;
	}else{
		std::cout << "Your friend won!" << std::endl;
	}
}

