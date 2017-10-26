/*
Author: Ram Moore
Class: CS1428 lab
Section: Honors 2
Lab: 06
*/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

void displayWorld(char world[][COLS]);
void copyArray(char life[][COLS], char (&check)[ROWS][COLS]);
void iterateLife(char (&life)[ROWS][COLS], char check[][COLS]);

int main()
{
	//NUMBER OF ROWS AND COLUMNS
	char life[ROWS][COLS];
	char check[ROWS][COLS];

	//RANDOM NUMBER GENERATOR TO CREATE INITIAL GENERATION
	srand (time(NULL));
	int cell;

	for(int r=0; r<ROWS; r++)
	{
		for(int c =0; c<COLS;c++)
		{
			cell = rand() % 7;
			if(cell >= 5)
			{
				life[r][c] = '*';
			}
			else
			{
				life[r][c]=' ';
			}
		}
	}
	for (int i = 0; i < 10; i++){
		cout << "Generation #: " << i + 1 << endl;
		displayWorld(life);
		copyArray(life, check);
		iterateLife(life, check);
	}

	return 0;
}

void displayWorld(char world[][COLS]){
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			cout << world[r][c]<< ' ';
		}
		cout << endl;
	}
}

void copyArray(char life[][COLS], char (&check)[ROWS][COLS]){
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			check[r][c] = life[r][c];
		}
	}
}

void iterateLife(char (&life)[ROWS][COLS], char check[][COLS]){
	int sourounding = 0;
	for (int r = 0; r < ROWS; r++){
		for (int c = 0; c < COLS; c++){
			for (int sr = -1; sr < 2; sr++){
				for (int sc = -1; sc < 2; sc++){
					if (life [r][c] = '*'){
						if ((((r + sr) >= 0 && (r + sr) <= ROWS) && ((c + sc) >= 0 && (c + sc) <= COLS)) && (life [r][c] == check[r + sr][c + sc])){
							sourounding++;
						}
					}
				}
			}
			sourounding --; // accounts for including the original space in the checking
			if (life [r][c] = '*'){
				if (sourounding < 2 || sourounding > 3){
					life [r][c] = ' ';
				}
			}
			if (life [r][c] = ' ' && sourounding == 3){
				life [r][c] = '*';
			}
			sourounding = 0;
		}
	}
}
