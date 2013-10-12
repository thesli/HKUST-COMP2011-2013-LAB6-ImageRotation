// Took me 20 minutes in total :>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char shape[10][10] ={
		{'0','0','0','0','0','0','0','0','0','0'},
		{'0','0','0','#','#','#','#','#','#','0'},
		{'0','0','0','#','#','#','#','#','#','0'},
		{'0','0','0','#','#','#','0','0','0','0'},
		{'0','0','0','#','#','#','0','0','0','0'},
		{'0','0','0','#','#','#','0','0','0','0'},
		{'0','0','0','#','#','#','0','0','0','0'},
		{'0','0','0','#','#','#','0','0','0','0'},
		{'0','0','0','#','#','#','0','0','0','0'},
		{'0','0','0','0','0','0','0','0','0','0'}
	};

char temp[10][10];

void overLoadEqual(){
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			shape[i][j] = temp[i][j];
		}
	}
}

void FlipY();
void FlipX();
void rotateRight(){	
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			temp[i][j] = shape[j][i];
		}
	}
	overLoadEqual();
	FlipX();
}


void rotateLeft(){
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			temp[i][j] = shape[j][i];
		}
	}
	overLoadEqual();
	FlipY();
}

void FlipY(){
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			temp[i][j] = shape[i][9-j];
		}
	}
	overLoadEqual();
}

void FlipX(){
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			temp[i][j] = shape[9-i][j];
		}
	}
	overLoadEqual();
}

void Negative(){		
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			if(shape[i][j]=='#'){
				temp[i][j]='0';
			}else{
				temp[i][j]='#';
			}
		}
	}
	overLoadEqual();
}

void printShape(){
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout << shape[i][j];
		}
		cout << "\n";
	}
}

void startChoices(){

	cout << 
"1. Rotate right\n2. Rotate left\n3. Flip over x-axis\n4. Flip over y-axis\n5. Negative\n6. printShape\n7. Exit\nWhich operation would you like to perform:";
	int x;
	cin >> x;
	switch(x){
		case 1:
			rotateRight();
			break;
		case 2:
			rotateLeft();
			break;
		case 3:
			FlipX();
			break;
		case 4:
			FlipY();
			break;
		case 5:
			Negative();
			break;
		case 6:
			printShape();
			break;
		case 7:
			exit(0);
			break;
		default:
			// main();
		break;
	}
}

int main()
{	
	while(true){
		startChoices();
	}	
	return 0;
}