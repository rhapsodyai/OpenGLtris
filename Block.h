//Block.h
#ifndef __BLOCK_H_INCLUDED //if x.h hasn't been included yet...
#define __BLOCK_H_INCLUDED //#define this so the compiler knows it has been included

class Block {

public:

	//State Variables
	int block_x_coordinate;
	int block_y_coordinate;
	int block_color;
	
	//Constructors
	Block();
	Block(int blkColor);

	//Methods
	void drawBlock(float, float, float, int);
	void drawBlockAtPosition(float, float, float, int, int, int);

	//Getters & Setters
	int getBlockXCoordinate();
	int getBlockYCoordinate();
	int getBlockColor();
	void setBlockXCoordinate(int newValue);
	void setBlockYCoordinate(int newValue);
	void setBlockColor(int newValue);

private:
	//State Variables
    
};

#endif

