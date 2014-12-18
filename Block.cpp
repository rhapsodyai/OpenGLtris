#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include "Block.h"


using namespace std;



//Constructors
Block::Block() {}
Block::Block(int blkColor) {
	//this->block_x_coordinate = 4;
	this->block_y_coordinate = 0;
}

//Starting off a block at a given position
Block::Block(int xcoordinate, int ycoordinate) {
	this->block_x_coordinate = xcoordinate;
	this->block_y_coordinate = ycoordinate;
}

//Methods
void Block::drawBlock(float R, float G, float B, int size) {
    //draw the color center
    glBegin(GL_QUADS);
    glColor3ub(R,G,B);
    glVertex2f(this->block_x_coordinate+1, this->block_y_coordinate+1);
    glVertex2f(this->block_x_coordinate+size, this->block_y_coordinate+1);
    glVertex2f(this->block_x_coordinate+size, this->block_y_coordinate+size);
    glVertex2f(this->block_x_coordinate+1, this->block_y_coordinate+size);
    glEnd();
    
    //draw the border
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(this->block_x_coordinate,this->block_y_coordinate);
    glVertex2f(this->block_x_coordinate+size,this->block_y_coordinate);
    glVertex2f(this->block_x_coordinate+size,this->block_y_coordinate+size);
    glVertex2f(this->block_x_coordinate,this->block_y_coordinate+size);
    glEnd();
    glFlush();
    
}

//Methods
void Block::drawBlockAtPosition(float R, float G, float B, int x, int y, int size) {
    //draw the color center
    glBegin(GL_QUADS);
    glColor3ub(R,G,B);
    glVertex2f(x+1, y+1);
    glVertex2f(x+size, y+1);
    glVertex2f(x+size, y+size);
    glVertex2f(x+1, y+size);
    glEnd();
    
    //draw the border
    glColor3ub(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(x+size,y);
    glVertex2f(x+size,y+size);
    glVertex2f(x,y+size);
    glEnd();
    //glFlush();
}

void Block::printBlockData() {
	cout << "This Block X position is: " << block_x_coordinate << endl;
	cout << "This Block Y position is: " << block_y_coordinate << endl;
	cout << "This Block Color is: "    << block_color << endl;
	cout << endl;
}

//Getters & Setters
int Block::getBlockXCoordinate() { return this->block_x_coordinate; }
int Block::getBlockYCoordinate() { return this->block_y_coordinate; }
int Block::getBlockColor() 	 { return this->block_color; }
void Block::setBlockXCoordinate(int newValue) { this->block_x_coordinate = newValue; }
void Block::setBlockYCoordinate(int newValue) { this->block_y_coordinate = newValue; }
void Block::setBlockColor(int newValue)       { this->block_color = newValue; }
