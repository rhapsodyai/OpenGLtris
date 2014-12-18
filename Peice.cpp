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

	block1.setBlockXCoordinate(0);
	block2.setBlockXCoordinate(0);
	block3.setBlockXCoordinate(0);
	block4.setBlockXCoordinate(0);

	block1.setBlockYCoordinate(0);
	block2.setBlockYCoordinate(0);
	block3.setBlockYCoordinate(0);
	block4.setBlockYCoordinate(0);

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
	this->peice_x_position = 0;
        this->peice_y_position = 0;
        this->peice_type = rand() % 7 + 1;
        this->peice_orientation = this->calculatePeiceOrientation(this->peice_type);
        this->peice_height = calculatePeiceHeight(this->peice_type, this->peice_orientation);
	this->peice_width = calculatePeiceWidth(this->peice_type, this->peice_orientation);

	this->setBlockCoordinatesOnInit();

	//printPeiceData();
}

Peice::Peice(int type) {

	block1.setBlockXCoordinate(0);
	block2.setBlockXCoordinate(0);
	block3.setBlockXCoordinate(0);
	block4.setBlockXCoordinate(0);

	block1.setBlockYCoordinate(0);
	block2.setBlockYCoordinate(0);
	block3.setBlockYCoordinate(0);
	block4.setBlockYCoordinate(0);
	
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
	this->peice_x_position = 0;
        this->peice_y_position = 0;
        this->peice_type = type;
        this->peice_orientation = this->calculatePeiceOrientation(this->peice_type);
        this->peice_height = calculatePeiceHeight(this->peice_type, this->peice_orientation);
	this->peice_width = calculatePeiceWidth(this->peice_type, this->peice_orientation);

	this->setBlockCoordinatesOnInit();

	//printPeiceData();
}

Peice::~Peice() {
/*
	block1.setBlockXCoordinate(4);
	block2.setBlockXCoordinate(4);
	block3.setBlockXCoordinate(4);
	block4.setBlockXCoordinate(4);

	//WHY DOES THIS NOT HAPPEN AUTOMATICALLY?
	block1.setBlockYCoordinate(0);
	block2.setBlockYCoordinate(0);
	block3.setBlockYCoordinate(0);
	block4.setBlockYCoordinate(0);
*/
}


//Methods
int setPeiceWidthOnInit(int p_type, int p_orientation) { return 0; }
int setPeiceHeightOnInit(int p_type, int p_orientation) { return 0; }
int setPeiceOrientationOnInit(int p_type) { return 0; }
void buildPeice(int param_peice_type, int param_peice_orientation) {}


void Peice::setPeiceColorOnInit() {
    srand(time(NULL));
    int randomColor = rand() % 7;
    
    block1.setBlockColor(randomColor+1);
    block2.setBlockColor(randomColor+1);
    block3.setBlockColor(randomColor+1);
    block4.setBlockColor(randomColor+1);
    
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
/*
drawLeftTetroid (int x, int y) {
	//ORIENTATION
	switch(this->peice_orientation) {
		case 1:

			break;
		case 2:

			break;
	}

*/
void Peice::setBlockCoordinatesOnInit() {
	switch(this->peice_type) {
	    case 1: //LeftLPeice
		switch(this->peice_orientation) {
			case 1:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position+1);
				block3.setBlockXCoordinate(this->peice_x_position+2);
				block4.setBlockXCoordinate(this->peice_x_position);

				block1.setBlockYCoordinate(this->peice_y_position+1);
				block2.setBlockYCoordinate(this->peice_y_position+1);
				block3.setBlockYCoordinate(this->peice_y_position+1);
				block4.setBlockYCoordinate(this->peice_y_position);
				break;

			case 2:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position);
				block3.setBlockXCoordinate(this->peice_x_position);
				block4.setBlockXCoordinate(this->peice_x_position+1);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position+1);
				block3.setBlockYCoordinate(this->peice_y_position+2);
				block4.setBlockYCoordinate(this->peice_y_position);
				break;

			case 3:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position+1);
				block3.setBlockXCoordinate(this->peice_x_position+2);
				block4.setBlockXCoordinate(this->peice_x_position+2);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position);
				block3.setBlockYCoordinate(this->peice_y_position);
				block4.setBlockYCoordinate(this->peice_y_position+1);
				break;

			case 4:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position+1);
				block3.setBlockXCoordinate(this->peice_x_position+1);
				block4.setBlockXCoordinate(this->peice_x_position+1);

				block1.setBlockYCoordinate(this->peice_y_position+2);
				block2.setBlockYCoordinate(this->peice_y_position);
				block3.setBlockYCoordinate(this->peice_y_position+1);
				block4.setBlockYCoordinate(this->peice_y_position+2);
				break;
		}
		break;
		
		case 2: //RightLPeice
		switch(this->peice_orientation) {
			case 1:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position+1);
				block3.setBlockXCoordinate(this->peice_x_position+2);
				block4.setBlockXCoordinate(this->peice_x_position+2);

				block1.setBlockYCoordinate(this->peice_y_position+1);
				block2.setBlockYCoordinate(this->peice_y_position+1);
				block3.setBlockYCoordinate(this->peice_y_position+1);
				block4.setBlockYCoordinate(this->peice_y_position);
				break;

			case 2:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position);
				block3.setBlockXCoordinate(this->peice_x_position);
				block4.setBlockXCoordinate(this->peice_x_position+1);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position+1);
				block3.setBlockYCoordinate(this->peice_y_position+2);
				block4.setBlockYCoordinate(this->peice_y_position+2);
				break;

			case 3:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position);
				block3.setBlockXCoordinate(this->peice_x_position+1);
				block4.setBlockXCoordinate(this->peice_x_position+2);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position+1);
				block3.setBlockYCoordinate(this->peice_y_position);
				block4.setBlockYCoordinate(this->peice_y_position);
				break;

			case 4:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position+1);
				block3.setBlockXCoordinate(this->peice_x_position+1);
				block4.setBlockXCoordinate(this->peice_x_position+1);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position);
				block3.setBlockYCoordinate(this->peice_y_position+1);
				block4.setBlockYCoordinate(this->peice_y_position+2);
				break;
		}
		break;

		case 3: //TPeice
		switch(this->peice_orientation) {
			case 1:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position);
				block3.setBlockXCoordinate(this->peice_x_position);
				block4.setBlockXCoordinate(this->peice_x_position+1);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position+1);
				block3.setBlockYCoordinate(this->peice_y_position+2);
				block4.setBlockYCoordinate(this->peice_y_position+1);
				break;

			case 2:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position+1);
				block3.setBlockXCoordinate(this->peice_x_position+2);
				block4.setBlockXCoordinate(this->peice_x_position+1);

				block1.setBlockYCoordinate(this->peice_y_position+1);
				block2.setBlockYCoordinate(this->peice_y_position+1);
				block3.setBlockYCoordinate(this->peice_y_position+1);
				block4.setBlockYCoordinate(this->peice_y_position);
				break;

			case 3:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position+1);
				block3.setBlockXCoordinate(this->peice_x_position+1);
				block4.setBlockXCoordinate(this->peice_x_position+1);

				block1.setBlockYCoordinate(this->peice_y_position+1);
				block2.setBlockYCoordinate(this->peice_y_position);
				block3.setBlockYCoordinate(this->peice_y_position+1);
				block4.setBlockYCoordinate(this->peice_y_position+2);
				break;

			case 4:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position+1);
				block3.setBlockXCoordinate(this->peice_x_position+1);
				block4.setBlockXCoordinate(this->peice_x_position+2);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position);
				block3.setBlockYCoordinate(this->peice_y_position+1);
				block4.setBlockYCoordinate(this->peice_y_position);
				break;
		}
		break;

		case 4: //BoxPeice
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position);
				block3.setBlockXCoordinate(this->peice_x_position+1);
				block4.setBlockXCoordinate(this->peice_x_position+1);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position+1);
				block3.setBlockYCoordinate(this->peice_y_position);
				block4.setBlockYCoordinate(this->peice_y_position+1);
				break;


		case 5: //LinePeice
		switch(this->peice_orientation) {
			case 1:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position+1);
				block3.setBlockXCoordinate(this->peice_x_position+2);
				block4.setBlockXCoordinate(this->peice_x_position+3);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position);
				block3.setBlockYCoordinate(this->peice_y_position);
				block4.setBlockYCoordinate(this->peice_y_position);
				break;

			case 2:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position);
				block3.setBlockXCoordinate(this->peice_x_position);
				block4.setBlockXCoordinate(this->peice_x_position);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position+1);
				block3.setBlockYCoordinate(this->peice_y_position+2);
				block4.setBlockYCoordinate(this->peice_y_position+3);
				break;

		}
		break;

		case 6: //RightTetroid
		switch(this->peice_orientation) {
			case 1:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position);
				block3.setBlockXCoordinate(this->peice_x_position+1);
				block4.setBlockXCoordinate(this->peice_x_position+1);

				block1.setBlockYCoordinate(this->peice_y_position+1);
				block2.setBlockYCoordinate(this->peice_y_position+2);
				block3.setBlockYCoordinate(this->peice_y_position);
				block4.setBlockYCoordinate(this->peice_y_position+1);
				break;

			case 2:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position+1);
				block3.setBlockXCoordinate(this->peice_x_position+1);
				block4.setBlockXCoordinate(this->peice_x_position+2);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position);
				block3.setBlockYCoordinate(this->peice_y_position+1);
				block4.setBlockYCoordinate(this->peice_y_position+1);
				break;
		}
		break;

		case 7: //LeftTetroid
		switch(this->peice_orientation) {
			case 1:
				block1.setBlockXCoordinate(this->peice_x_position);
				block2.setBlockXCoordinate(this->peice_x_position);
				block3.setBlockXCoordinate(this->peice_x_position+1);
				block4.setBlockXCoordinate(this->peice_x_position+1);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position+1);
				block3.setBlockYCoordinate(this->peice_y_position+1);
				block4.setBlockYCoordinate(this->peice_y_position+2);
				break;

			case 2:
				block1.setBlockXCoordinate(this->peice_x_position+1);
				block2.setBlockXCoordinate(this->peice_x_position+2);
				block3.setBlockXCoordinate(this->peice_x_position);
				block4.setBlockXCoordinate(this->peice_x_position+1);

				block1.setBlockYCoordinate(this->peice_y_position);
				block2.setBlockYCoordinate(this->peice_y_position);
				block3.setBlockYCoordinate(this->peice_y_position+1);
				block4.setBlockYCoordinate(this->peice_y_position+1);
				break;
		}
		break;
	}
}

void Peice::drawPeice() {

    switch(this->peice_type) {
	    case 1:
		this->drawLeftLPeice(this->peice_x_position*BLOCK_SIZE,this->peice_y_position*BLOCK_SIZE);
		break;
	    case 2:
		this->drawRightLPeice(this->peice_x_position*BLOCK_SIZE,this->peice_y_position*BLOCK_SIZE);
		break;
	    case 3:
		this->drawTPeice(this->peice_x_position*BLOCK_SIZE,this->peice_y_position*BLOCK_SIZE);
		break;
	    case 4:
		this->drawBoxPeice(this->peice_x_position*BLOCK_SIZE,this->peice_y_position*BLOCK_SIZE);
		break;
	    case 5:
		this->drawLinePeice(this->peice_x_position*BLOCK_SIZE,this->peice_y_position*BLOCK_SIZE);
		break;
	    case 6:
		this->drawRightTetroid(this->peice_x_position*BLOCK_SIZE,this->peice_y_position*BLOCK_SIZE);
		break;
	    case 7:
		this->drawLeftTetroid(this->peice_x_position*BLOCK_SIZE,this->peice_y_position*BLOCK_SIZE);
		break;
    }

}


void Peice::drawPeiceAtCoordinates(int x, int y) {

    switch(this->peice_type) {
	    case 1:
		this->drawLeftLPeice(x*BLOCK_SIZE,y*BLOCK_SIZE);
		break;
	    case 2:
		this->drawRightLPeice(x*BLOCK_SIZE,y*BLOCK_SIZE);
		break;
	    case 3:
		this->drawTPeice(x*BLOCK_SIZE,y*BLOCK_SIZE);
		break;
	    case 4:
		this->drawBoxPeice(x*BLOCK_SIZE,y*BLOCK_SIZE);
		break;
	    case 5:
		this->drawLinePeice(x*BLOCK_SIZE,y*BLOCK_SIZE);
		break;
	    case 6:
		this->drawRightTetroid(x*BLOCK_SIZE,y*BLOCK_SIZE);
		break;
	    case 7:
		this->drawLeftTetroid(x,y*BLOCK_SIZE);
		break;
    }

}

void Peice::drawLeftLPeice(int x, int y)  {
	//ORIENTATION
	switch(this->peice_orientation) {
		case 1:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y+BLOCK_SIZE, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
			break;
		case 2:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+(BLOCK_SIZE*2), BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
			break;
		case 3:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+(BLOCK_SIZE*2), y+BLOCK_SIZE, BLOCK_SIZE);
			break;
		case 4:
			block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+(BLOCK_SIZE*2), BLOCK_SIZE);
    			block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    			block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
    			block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+(BLOCK_SIZE*2), BLOCK_SIZE);
			break;
	}
}


void Peice::drawRightLPeice(int x, int y) {
	//ORIENTATION
	switch(this->peice_orientation) {
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


void Peice::drawTPeice(int x, int y)  {
	//ORIENTATION
	switch(this->peice_orientation) {
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


// XX
// XX
void Peice::drawBoxPeice(int x, int y) {
	block1.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y, BLOCK_SIZE);
    	block2.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x, y+BLOCK_SIZE, BLOCK_SIZE);
    	block3.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y, BLOCK_SIZE);
    	block4.drawBlockAtPosition(peiceColor.r, peiceColor.g, peiceColor.b, x+BLOCK_SIZE, y+BLOCK_SIZE, BLOCK_SIZE);
}

// XXXX
void Peice::drawLinePeice(int x, int y) {
	//ORIENTATION
	switch(this->peice_orientation) {
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


//  XX
// XX
void Peice::drawRightTetroid(int x, int y) {
	//ORIENTATION
	switch(this->peice_orientation) {
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

// XX
//  XX
void Peice::drawLeftTetroid (int x, int y) {
	//ORIENTATION
	switch(this->peice_orientation) {
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
	else if( (p_type == 1 && p_orientation == 1) || (p_type == 1 && p_orientation == 3) || (p_type == 2 && p_orientation == 1) || 
	(p_type == 2 && p_orientation == 3) || (p_type == 3 && p_orientation == 2) || (p_type == 3 && p_orientation == 4) || 
	(p_type == 4) || (p_type == 6 && p_orientation == 2) || (p_type == 7 && p_orientation == 2))
		return 2;

	//3 (1,2),(1,4),(2,2),(2,4),(3,1),(3,3),(6,1),(7,1)
	else if( (p_type == 1 && p_orientation == 2) || (p_type == 1 && p_orientation == 4) || (p_type == 2 && p_orientation == 2) || 
	(p_type == 2 && p_orientation == 4) || (p_type == 3 && p_orientation == 1) || (p_type == 3 && p_orientation == 3) || 
	(p_type == 6 && p_orientation == 1) || (p_type == 7 && p_orientation == 1))
		return 3;

	//4 (5,4)
	else if(p_type == 5 && p_orientation == 2)
		return 4;
	else
		return -1;
}

int Peice::calculatePeiceWidth(int p_type, int p_orientation) {
	//1 (5,2)
	if(p_type == 5 && p_orientation == 2)
		return 1;
	//2 (1,2),(1,4),(2,2),(2,4),(3,1),(3,3),(6,1),(7,1)
	else if( (p_type == 1 && p_orientation == 2) || (p_type == 1 && p_orientation == 4) || (p_type == 2 && p_orientation == 2) || 
	(p_type == 2 && p_orientation == 4) || (p_type == 3 && p_orientation == 1) || (p_type == 3 && p_orientation == 3) || 
	(p_type == 4) || (p_type == 6 && p_orientation == 1) || (p_type == 7 && p_orientation == 1))
		return 2;

	//3 (1,1),(1,3),(2,1),(2,3),(3,2),(3,4),(6,2),(7,2)
	else if( (p_type == 1 && p_orientation == 1) || (p_type == 1 && p_orientation == 3) || (p_type == 2 && p_orientation == 1) || 
	(p_type == 2 && p_orientation == 3) || (p_type == 3 && p_orientation == 2) || (p_type == 3 && p_orientation == 4) || 
	(p_type == 6 && p_orientation == 2) || (p_type == 7 && p_orientation == 2))
		return 3;

	//4 (5,1)
	else if(p_type == 5 && p_orientation == 1)
		return 4;
	else
		return -1;
}

void Peice::printPeiceData() {
	cout << "This Peice X position is: " << peice_x_position << endl;
	cout << "This Peice Y position is: " << peice_y_position << endl;
	cout << "This Peice Type is: "        << peice_type << endl;
	cout << "This Peice Orientation is: " << peice_orientation << endl;
	cout << "This Peice Height is: "      << peice_height << endl;
	cout << "This Peice Width is: "       << peice_width << endl;
	cout << "This Peice X Offset is: "    << peice_xoffset << endl;
	cout << "This Peice Y Offset is: "    << peice_yoffset << endl;
	cout << endl;
}

void Peice::incrementPeiceOrientation() {
	if(this->peice_type == 1 || this->peice_type == 2 || this->peice_type == 3) {
		if(this->peice_orientation < 4) {
			this->peice_orientation++;
			this->setBlockCoordinatesOnInit();
			this->calculatePeiceHeight(this->peice_type,this->peice_orientation);
			this->calculatePeiceWidth(this->peice_type,this->peice_orientation);
		}
		else {
			this->peice_orientation = 1;
			this->setBlockCoordinatesOnInit();
			this->calculatePeiceHeight(this->peice_type,this->peice_orientation);
			this->calculatePeiceWidth(this->peice_type,this->peice_orientation);
		}
	}

	if(this->peice_type == 5 || this->peice_type == 6 || this->peice_type == 7) {
		if(this->peice_orientation < 2) {
			this->peice_orientation++;
			this->setBlockCoordinatesOnInit();
			this->calculatePeiceHeight(this->peice_type,this->peice_orientation);
			this->calculatePeiceWidth(this->peice_type,this->peice_orientation);
		}
		else {
			this->peice_orientation = 1;
			this->setBlockCoordinatesOnInit();
			this->calculatePeiceHeight(this->peice_type,this->peice_orientation);
			this->calculatePeiceWidth(this->peice_type,this->peice_orientation);
		}
	}
}



//Getters
int Peice::getPeiceXPosition()   { return this->peice_x_position; }
int Peice::getPeiceYPosition()   { return this->peice_y_position; }
int Peice::getPeiceType()        { return this->peice_type;  }
int Peice::getPeiceOrientation() { return this->peice_orientation; }
int Peice::getPeiceHeight()      { return this->peice_height; }
int Peice::getPeiceWidth()       { return this->peice_width; }

Block* Peice::getBlock1() { return &block1; }
Block* Peice::getBlock2() { return &block2; }
Block* Peice::getBlock3() { return &block3; }
Block* Peice::getBlock4() { return &block4; }


//temp getters for blocks NOT NEEDED
int Peice::getBlock1X() { return block1.getBlockXCoordinate(); }
int Peice::getBlock1Y() { return block1.getBlockYCoordinate(); }
int Peice::getBlock2X() { return block2.getBlockXCoordinate(); }
int Peice::getBlock2Y() { return block2.getBlockYCoordinate(); }
int Peice::getBlock3X() { return block3.getBlockXCoordinate(); }
int Peice::getBlock3Y() { return block3.getBlockYCoordinate(); }
int Peice::getBlock4X() { return block4.getBlockXCoordinate(); }
int Peice::getBlock4Y() { return block4.getBlockYCoordinate(); }

//Setters
void Peice::setPeiceType(int newValue)        { this->peice_type = newValue; }
void Peice::setPeiceXPosition(int newValue)   { this->peice_x_position = newValue; }
void Peice::setPeiceYPosition(int newValue)   { this->peice_x_position = newValue; }
void Peice::setPeiceOrientation(int newValue) { this->peice_orientation = newValue; }

void Peice::incrementPeiceX() { this->peice_x_position += 1;
				
				//setting the block values when updating the peice value 
				this->block1.setBlockXCoordinate(block1.getBlockXCoordinate()+1);
				this->block2.setBlockXCoordinate(block2.getBlockXCoordinate()+1);
				this->block3.setBlockXCoordinate(block3.getBlockXCoordinate()+1);
				this->block4.setBlockXCoordinate(block4.getBlockXCoordinate()+1);
}
void Peice::decrementPeiceX() { this->peice_x_position -= 1; 

				//setting the block values when updating the peice value 
				this->block1.setBlockXCoordinate(block1.getBlockXCoordinate()-1);
				this->block2.setBlockXCoordinate(block2.getBlockXCoordinate()-1);
				this->block3.setBlockXCoordinate(block3.getBlockXCoordinate()-1);
				this->block4.setBlockXCoordinate(block4.getBlockXCoordinate()-1);

}
void Peice::incrementPeiceY() { this->peice_y_position += 1; 

				//setting the block values when updating the peice value 
				this->block1.setBlockYCoordinate(block1.getBlockYCoordinate()+1);
				this->block2.setBlockYCoordinate(block2.getBlockYCoordinate()+1);
				this->block3.setBlockYCoordinate(block3.getBlockYCoordinate()+1);
				this->block4.setBlockYCoordinate(block4.getBlockYCoordinate()+1);

}
void Peice::decrementPeiceY() { this->peice_y_position -= 1; 

				//setting the block values when updating the peice value 
				this->block1.setBlockYCoordinate(block1.getBlockYCoordinate()-1);
				this->block2.setBlockYCoordinate(block2.getBlockYCoordinate()-1);
				this->block3.setBlockYCoordinate(block3.getBlockYCoordinate()-1);
				this->block4.setBlockYCoordinate(block4.getBlockYCoordinate()-1);
}
