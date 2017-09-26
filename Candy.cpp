#include <iostream>
#include <stdlib.h>
#include <ctime>
#define GAME_LENGTH 50

// They options for spaced to jump do not change so they can be saved globally
#define FORWARDONE 1
#define FORWARDTWO 2
#define MOUNTAINPASS 3
#define RAINBOWTRAIL 5
#define CHERRYPITFALLS -3
#define MOLASSESSWAMP -5

// Tells main which functions are going to exist and what they will return 
void advancePlayerA(int* ptrPlayerA);
void advancePlayerB(int* ptrPlayerB);
void printPosition(int* ptrPlayerA, int* ptrPlayerB);

// This function takes a turn for player A
void advancePlayerA(int* ptrPlayerA){		
	// x receives a random integer and passes out probabilities. Then it assigns a variable jump and add it to player A's position  
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
	*ptrPlayerA += jump;
	// Does not let player A get moved behind 0 or above 50
	if (*ptrPlayerA < 0){
		*ptrPlayerA = 0;
	}else if (*ptrPlayerA > 50){
		*ptrPlayerA = 50;
	}
} 

// This function takes a turn for player B
void advancePlayerB(int* ptrPlayerB){
	// x receives a random integer and passes out probabilities. Then it assigns a variable jump and add it to player B's position
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
	*ptrPlayerB += jump;
	// Does not let player B get moved behind 0 or above 50
	if (*ptrPlayerB < 0){
		*ptrPlayerB = 0;
	}else if (*ptrPlayerB > 50){
		*ptrPlayerB = 50;
	}
}

// This function will print the board
void printPosition(int* ptrPlayerA, int* ptrPlayerB){
	// Since player A takes a turn first, if B lands on 50 after A, B will have to move back one space
	if (*ptrPlayerB == 50 && *ptrPlayerA == 50){ 
		*ptrPlayerB -=1;
	// if player A and B are on the same space, player A must move back one
	}else if (*ptrPlayerA == *ptrPlayerB){
		*ptrPlayerA -=1;
	}
	if (*ptrPlayerA < 0){
		*ptrPlayerA = 0;
	}
	// sets a string for the board of 50 empty spaces
	std::string board(51, ' ');
	// sets the value at ptrPlayerA(or B) to fill the space in the string
	board[*ptrPlayerA] = 'A';
	board[*ptrPlayerB] = 'B';
	std::cout << board << "|" << std::endl;
}

int main(){
	// assigns variables and pointers
	srand(time(NULL));
	int positionPlayerA = 0;
	int positionPlayerB = 0;
	int* ptrToA = &positionPlayerA;
	int* ptrToB = &positionPlayerB;
	int keepGoing = 0;
	
	// keeps the game going until a player reaches space 50
	while (keepGoing < 50){
		advancePlayerA(ptrToA);
		advancePlayerB(ptrToB);
		printPosition(ptrToA, ptrToB);
		// gets position of A and B
		positionPlayerA = *ptrToA;
		positionPlayerB = *ptrToB;
		// uses place of whichever is higher to keepGoing
		if (positionPlayerA > positionPlayerB){
			keepGoing = positionPlayerA;
		}else{
			keepGoing = positionPlayerB;
		}	
	} 
	// prints winner
	if (positionPlayerA == 50){
		std::cout << "You won!" << std::endl;
	}else if (positionPlayerB == 50){
		std::cout << "Your friend won!" << std::endl;
	}
}

