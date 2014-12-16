//Peice.h
#ifndef __PEICE_H_INCLUDED //if x.h hasn't been included yet...
#define __PEICE_H_INCLUDED //#define this so the compiler knows it has been included

#include "Peice.h"
#include "Block.h"


#define BLOCK_SIZE 24 //Pixels

class Peice {
	
enum peiceOrientation {
    RANDOM_ORIENTATION = 0,
    RIGHT_ORIENTATION = 1,
    LEFT_ORIENTATION = 2,
    UP_ORIENTATION = 3,
    DOWN_ORIENTATION = 4,
};

enum peiceType {
    LEFT_LPEICE = 1,
    RIGHT_LPEICE = 2,
    T_PEICE = 3,
    BOX_PEICE = 4,
    LINE_PEICE = 5,
    RIGHT_TETROID = 6,
    LEFT_TETROID = 7,
};
	
public:

	struct color {
    		int r;
    		int g;
    		int b;
	};

	color peiceColor;
	color paneColor;

	//peice colors
	color pastel_red;
	color pastel_yellow;
	color pastel_green;
	color pastel_cyan;
	color pastel_blue;
	color pastel_violet;
	color pastel_magenta;

	Block block1;
	Block block2;
	Block block3;
	Block block4;
	//Block eblock;

	bool movable;
        int peice_x_position;
        int peice_y_position;
        int peice_type;
        int peice_orientation;
        int peice_height;
        int peice_width;
        int peice_xoffset;
        int peice_yoffset;

	//NEEDED??
        int highest_block_position;
        int lowest_block_position;
        int leftmost_block_position;
        int rightmost_block_position;

	//Constructors
	Peice();
	Peice(int);

	//Methods	
	void setPeiceColorOnInit();
	int setPeiceWidthOnInit(int p_type, int p_orientation);
	int setPeiceHeightOnInit(int p_type, int p_orientation);
	int setPeiceOrientationOnInit(int p_type);
	void buildPeice(int param_peice_type, int param_peice_orientation);
	void drawPeice();
	void drawPeiceAtCoordinates(int, int); 
	void printPeiceData();

	int calculatePeiceOrientation(int p_type);
	int calculatePeiceHeight(int p_type,int p_orientation);
	int calculatePeiceWidth(int p_type, int p_orientation);
	void rotatePeice(int p_type, int p_orientation);

	//Peice Type Drawing Functions
	void drawLeftLPeice(int,int);
	void drawRightLPeice(int,int);
	void drawTPeice(int,int);
	void drawBoxPeice(int,int);
	void drawLinePeice(int,int);
	void drawRightTetroid(int,int);
	void drawLeftTetroid (int,int);


	//Getters & Setters
	int getPeiceXPosition();
	int getPeiceYPosition();
	int getPeiceType();
	int getPeiceOrientation();
	int getPeiceHeight();
	int getPeiceWidth();
	void setPeiceXPosition(int newValue);
	void setPeiceYPosition(int newValue);
	void setPeiceType(int newValue);
	void setPeiceOrientation(int newValue);
	void incrementPeiceX();
	void decrementPeiceX();
	void incrementPeiceY();
	void decrementPeiceY();
	void incrementPeiceOrientation();

	Block* getBlock1();
	Block* getBlock2();
	Block* getBlock3();
	Block* getBlock4();

	int getBlock1X();
	int getBlock1Y();

private:

};

#endif
