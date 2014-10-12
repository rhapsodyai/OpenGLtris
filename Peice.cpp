//Peice.cpp
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include <iostream>

#include "Peice.h"

#define BLOCK_SIZE 24

using namespace std;

//constructor
Peice::Peice() {
	//Set Color Library Default Values
	this->pastel_red.r     = 246;
	this->pastel_red.g     = 150;
	this->pastel_red.b     = 121;
	this->pastel_yellow.r  = 255;
	this->pastel_yellow.g  = 247;
	this->pastel_yellow.b  = 153;
	this->pastel_green.r   = 130;
	this->pastel_green.g   = 202;
	this->pastel_green.b   = 156;
	this->pastel_cyan.r    = 109;
	this->pastel_cyan.g    = 207;
	this->pastel_cyan.b    = 246;
	this->pastel_blue.r    = 131;
	this->pastel_blue.g    = 147;
	this->pastel_blue.b    = 202;
	this->pastel_violet.r  = 161;
	this->pastel_violet.g  = 134;
	this->pastel_violet.b  = 190;
	this->pastel_magenta.r = 244;
	this->pastel_magenta.g = 154;
	this->pastel_magenta.b = 193;

	//CHANGE ALERT!!! THIS NEEDS TO BE PASSED FROM MAIN!
	this->paneColor.r = 255;
        this->paneColor.g = 255;
        this->paneColor.b = 255;

	//Initialize this peice to a random color from the default library
	this->setPeiceColorOnInit();
	
	//Set characteristics of peice
	this->peice_x_position = 4;
        this->peice_y_position = 0;
        this->peice_type = rand() % 7 + 1;
        this->peice_orientation = this->calculatePeiceOrientation(this->peice_type);
        this->peice_height = calculatePeiceHeight(this->peice_type, this->peice_orientation);

	printPeiceData();
}

Peice::Peice(int type) {
	//Set Color Library Default Values
	this->pastel_red.r     = 246;
	this->pastel_red.g     = 150;
	this->pastel_red.b     = 121;
	this->pastel_yellow.r  = 255;
	this->pastel_yellow.g  = 247;
	this->pastel_yellow.b  = 153;
	this->pastel_green.r   = 130;
	this->pastel_green.g   = 202;
	this->pastel_green.b   = 156;
	this->pastel_cyan.r    = 109;
	this->pastel_cyan.g    = 207;
	this->pastel_cyan.b    = 246;
	this->pastel_blue.r    = 131;
	this->pastel_blue.g    = 147;
	this->pastel_blue.b    = 202;
	this->pastel_violet.r  = 161;
	this->pastel_violet.g  = 134;
	this->pastel_violet.b  = 190;
	this->pastel_magenta.r = 244;
	this->pastel_magenta.g = 154;
	this->pastel_magenta.b = 193;

	//CHANGE ALERT!!! THIS NEEDS TO BE PASSED FROM MAIN!
	this->paneColor.r = 255;
        this->paneColor.g = 255;
        this->paneColor.b = 255;

	//Initialize this peice to a random color from the default library
	this->setPeiceColorOnInit();
	
	//Set characteristics of peice
	this->peice_x_position = 4;
        this->peice_y_position = 0;
        this->peice_type = type;
        this->peice_orientation = this->calculatePeiceOrientation(this->peice_type);
        this->peice_height = calculatePeiceHeight(this->peice_type, this->peice_orientation);

	printPeiceData();
}


//Methods
int setPeiceWidthOnInit(int p_type, int p_orientation) { return 0; }
int setPeiceHeightOnInit(int p_type, int p_orientation) { return 0; }
int setPeiceOrientationOnInit(int p_type) { return 0; }
void buildPeice(int param_peice_type, int param_peice_orientation) {}
void drawPeice() {}
void printPeiceData() {}


void Peice::setPeiceColorOnInit() {
    srand(time(NULL));
    int randomColor = rand() % 7;
    switch(randomColor) {
        case 0:
            peiceColor.r = pastel_red.r;
            peiceColor.g = pastel_red.g;
            peiceColor.b = pastel_red.b;
            break;
        case 1:
            peiceColor.r = pastel_yellow.r;
            peiceColor.g = pastel_yellow.g;
            peiceColor.b = pastel_yellow.b;
            break;
        case 2:
            peiceColor.r = pastel_green.r;
            peiceColor.g = pastel_green.g;
            peiceColor.b = pastel_green.b;
            break;
        case 3:
            peiceColor.r = pastel_cyan.r;
            peiceColor.g = pastel_cyan.g;
            peiceColor.b = pastel_cyan.b;
            break;
        case 4:
            peiceColor.r = pastel_blue.r;
            peiceColor.g = pastel_blue.g;
            peiceColor.b = pastel_blue.b;
            break;
        case 5:
            peiceColor.r = pastel_violet.r;
            peiceColor.g = pastel_violet.g;
            peiceColor.b = pastel_violet.b;
            break;
        case 6:
            peiceColor.r = pastel_magenta.r;
            peiceColor.g = pastel_magenta.g;
            peiceColor.b = pastel_magenta.b;
            break;
    }
}


void Peice::drawRightLPeice(int x, int y, int orientation) {
	//ORIENTATION
	switch(orientation) {
		case 1:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE,BLOCK_SIZE);
			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y+BLOCK_SIZE, BLOCK_SIZE);
			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y, BLOCK_SIZE);
			break;
		case 2:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y,BLOCK_SIZE);
			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+(BLOCK_SIZE*2), BLOCK_SIZE);
			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+(BLOCK_SIZE*2), BLOCK_SIZE);
			break;
		case 3:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y,BLOCK_SIZE);
			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y, BLOCK_SIZE);
			break;
		case 4:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y,BLOCK_SIZE);
			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+(BLOCK_SIZE*2), BLOCK_SIZE);
			break;
	}
}

/* not completely implemented! */
void Peice::eraseRightLPeice(int x, int y, int orientation)  {
	//ORIENTATION
	switch(orientation) {
		case 1:
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x, y, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+(BLOCK_SIZE*2), (y-BLOCK_SIZE), BLOCK_SIZE);
			break;
	}
}

void Peice::drawLeftLPeice(int x, int y, int orientation)  {
	//ORIENTATION
	switch(orientation) {
		case 1:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y+BLOCK_SIZE, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
			break;
		case 2:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+(BLOCK_SIZE*2), BLOCK_SIZE);
			break;
		case 3:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y, BLOCK_SIZE);
			break;
		case 4:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+(BLOCK_SIZE*2), BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+(BLOCK_SIZE*2), BLOCK_SIZE);
			break;
	}
}

/* not completely implemented! */
void Peice::eraseLeftLPeice(int x, int y, int orientation) {
	//ORIENTATION
	switch(orientation) {
		case 1:
			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x, y-BLOCK_SIZE, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+(BLOCK_SIZE*2), (y-BLOCK_SIZE), BLOCK_SIZE);
			break;
	}
}

void Peice::drawTPeice(int x, int y, int orientation)  {
	//ORIENTATION
	switch(orientation) {
		case 1:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y,BLOCK_SIZE);
			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE,BLOCK_SIZE);
			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+(BLOCK_SIZE*2),BLOCK_SIZE);
			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
			break;
		case 2:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y+BLOCK_SIZE, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE), y, BLOCK_SIZE);
			break;
		case 3:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+(BLOCK_SIZE*2), BLOCK_SIZE);
			break;
		case 4:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y, BLOCK_SIZE);
			break;
	}
}

/* not completely implemented! */
void Peice::eraseTPeice(int x, int y, int orientation) {
	//ORIENTATION
	switch(orientation) {
		case 1:
			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x, y, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+(BLOCK_SIZE*2), y, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+(BLOCK_SIZE), (y-BLOCK_SIZE), BLOCK_SIZE);
			break;
	}
}

// XX
// XX
void Peice::drawBoxPeice(int x, int y) {
	block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    	block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    	block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    	block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
}

/* not completely implemented! */
void Peice::eraseBoxPeice(int x, int y) {
	eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x, y, BLOCK_SIZE);
	eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
}

// XXXX
void Peice::drawLinePeice(int x, int y, int orientation) {
	//ORIENTATION
	switch(orientation) {
		case 1:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*3), y, BLOCK_SIZE);
			break;
		case 2:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+(BLOCK_SIZE*2), BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+(BLOCK_SIZE*3), BLOCK_SIZE);
			break;
	}
}

/* not completely implemented! */
void Peice::eraseLinePeice(int x, int y, int orientation) {
	//ORIENTATION
	switch(orientation) {
		case 1:
			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x, y, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+BLOCK_SIZE*2, y, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+BLOCK_SIZE*3, y, BLOCK_SIZE);
			break;

	}
}


//  XX
// XX
void Peice::drawRightTetroid(int x, int y, int orientation) {
	//ORIENTATION
	switch(orientation) {
		case 1:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+(BLOCK_SIZE*2), BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
			break;
		case 2:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y+BLOCK_SIZE, BLOCK_SIZE);
			break;
	}

}

/* not completely implemented! */
void Peice::eraseRightTetroid(int x, int y, int orientation) {
	//ORIENTATION
	switch(orientation) {
		case 1:
			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
   			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+BLOCK_SIZE*2, y, BLOCK_SIZE);
			break;
	}
}


// XX
//  XX
void Peice::drawLeftTetroid (int x, int y, int orientation) {
	//ORIENTATION
	switch(orientation) {
		case 1:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+(BLOCK_SIZE*2), BLOCK_SIZE);
			break;
		case 2:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE*2, y, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
			break;
	}
}


/* not completely implemented! */
void Peice::eraseLeftTetroid (int x, int y, int orientation) {
	//ORIENTATION
	switch(orientation) {
		case 1:
			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x, y, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			eblock.drawBlockAtPosition(paneColor.r, paneColor.g, paneColor.b, x+BLOCK_SIZE*2, y+BLOCK_SIZE, BLOCK_SIZE);
			break;
	}
}

int Peice::calculatePeiceOrientation(int p_type) {
	srand(time(NULL)); //Needed???
	switch(p_type) {
	case 1:
		return rand() % 4 + 1;
		break;
	case 2:
		return rand() % 4 + 1;
		break;
	case 3:
		return rand() % 4 + 1;
		break;
	case 4:
		return 1;
		break;
	case 5:
		return rand() % 2 + 1;
		break;
	case 6:
		return rand() % 2 + 1;
		break;
	case 7:
		return rand() % 2 + 1;
		break;
	}
	return -1;
}

int Peice::calculatePeiceHeight(int p_type, int p_orientation) {
	//1 (5,1)
	if(p_type == 5 && p_orientation == 1)
		return 1;
	//2 (1,1),(1,3),(2,1),(2,3),(3,2),(3,4),(4),(6,2),(7,2)
	if( (p_type == 1 && p_orientation == 1) || (p_type == 1 && p_orientation == 3) || (p_type == 2 && p_orientation == 1) || 
	(p_type == 2 && p_orientation == 3) || (p_type == 3 && p_orientation == 2) || (p_type == 3 && p_orientation == 4) || 
	(p_type == 4) || (p_type == 6 && p_orientation == 2) || (p_type == 7 && p_orientation == 2))
		return 2;

	//3 (1,2),(1,4),(2,2),(2,4),(3,1),(3,3),(6,1),(7,1)
	if( (p_type == 1 && p_orientation == 2) || (p_type == 1 && p_orientation == 4) || (p_type == 2 && p_orientation == 2) || 
	(p_type == 2 && p_orientation == 4) || (p_type == 3 && p_orientation == 1) || (p_type == 3 && p_orientation == 3) || 
	(p_type == 6 && p_orientation == 1) || (p_type == 7 && p_orientation == 1))
		return 3;

	//4 (5,4)
	if(p_type == 5 && p_orientation == 2)
		return 4;
	
	return -1;
}

void Peice:: printPeiceData() {
	cout << "This Peice X position is: " << peice_x_position << endl;
	cout << "This Peice Y position is: " << peice_y_position << endl;
	cout << "This Peice Type is: " << peice_type << endl;
	cout << "This Peice Orientation is: " << peice_orientation << endl;
	cout << "This Peice Height is: " << peice_height << endl;
	cout << "This Peice Width is: " << peice_width << endl;
	cout << "This Peice X Offset is: " << peice_xoffset << endl;
	cout << "This Peice Y Offset is: " << peice_yoffset << endl;
	cout << endl;
}


void rotatePeice(int p_type, int p_orientation) {}

//Getters
int Peice::getPeiceXPosition()   { return this->peice_x_position; }
int Peice::getPeiceYPosition()   { return this->peice_y_position; }
int Peice::getPeiceType()        { return this->peice_type;  }
int Peice::getPeiceOrientation() { return this->peice_orientation; }
int Peice::getPeiceHeight()      { return this->peice_height; }
//Setters
void Peice::setPeiceType(int newValue)        { this->peice_type = newValue; }
void Peice::setPeiceXPosition(int newValue)   { this->peice_x_position = newValue; }
void Peice::setPeiceYPosition(int newValue)   { this->peice_x_position = newValue; }
void Peice::setPeiceOrientation(int newValue) { this->peice_orientation = newValue; }
void Peice::incrementPeiceX() { this->peice_x_position += 1; }
void Peice::decrementPeiceX() { this->peice_x_position -= 1; }
void Peice::incrementPeiceY() { this->peice_y_position += 1; }
void Peice::decrementPeiceY() { this->peice_y_position -= 1; }


