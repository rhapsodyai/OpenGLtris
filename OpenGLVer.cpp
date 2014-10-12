//
//  OpenGLVer.h
//  OpenGLtris (Tetris implemented with OpenGL)
//
//  Created by Melissa Lynn Auclaire on 6/11/14.
//  Copyright (c) 2014 Melissa Lynn Auclaire. All rights reserved.
//


#include <GL/glut.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "SoundEngine.h"
#include "Block.h"
#include "Peice.h"

#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 576
#define BLOCK_SIZE 24 //Pixels

using namespace std;

//global variables
//int currentPeiceX = 0;
//int currentPeiceY = 0;
//int currentPeiceID = 0;
//int currentPeiceType = rand() % 7 + 1;
//int currentPeiceOrientation = 1;
int score = 0;

char* scoreString = "Score: ";

//Block block1;

Peice *currentPeice = new Peice();
Peice curPeice;
Peice nextPeice;
SoundEngine se;


//OpenGLtris board
int opengltrisBoardVertical[24][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
};

struct color {
    int r;
    int g;
    int b;
};



//colors
struct color bgRightColor;  //Right side
struct color bgPaneColor;   //Left side
struct color neon;

struct color peiceColorMain; 

//peice colors
struct color pastel_red_main;
struct color pastel_yellow_main;
struct color pastel_green_main;
struct color pastel_cyan_main;
struct color pastel_blue_main;
struct color pastel_violet_main;
struct color pastel_magenta_main;


// *** BEGIN FUNCTION PROTOTYPES *** //

//glut special functions
void display();
void init();
void idle();
void keyboard();


//self-written functions
void sleep(int);
void drawString(float, float, const char*);
void drawStringFont(float, float, const char*, int);


//draw the different types of squares
void drawSingleSquareWithoutBorder(float, float, float, int, int, int);
void drawSingleSquareColor(float,float,float,int,int,int);
void drawRectangle(float,float,float,float);

//draw the different types of peices
void drawLeftLPeiceMain(int,int);
void drawRightLPeiceMain(int,int);
void drawTPeiceMain(int, int);
void drawBoxPeiceMain(int,int);
void drawLinePeiceMain(int,int);
void drawRightTetroidMain(int,int);
void drawLeftTetroidMain(int,int);

//erase the trails from the different peices
void eraseLeftLPeiceMain(int,int);
void eraseRightLPeiceMain(int,int);
void eraseTPeiceMain(int,int);
void eraseBoxPeiceMain(int,int);
void eraseLinePeiceMain(int,int);
void eraseRightTetroidMain(int,int);
void eraseLeftTetroidMain(int,int);

//draw the grid
void drawGrid();
void drawBoard();
void drawDivider();
void drawNextPeice();
void drawWindowPane();
void setColor();





//*** BEGIN GLUT FUNCTIONS ***//
void init() {
    //initialize colors
    bgPaneColor.r = 255;
    bgPaneColor.g = 255;
    bgPaneColor.b = 255;
    bgRightColor.r = 0;
    bgRightColor.g = 0;
    bgRightColor.b = 0;
    
    neon.r = 57;
    neon.g = 255;
    neon.b = 220;
    
    //initialize peice color library
    pastel_red_main.r     = 246;
    pastel_red_main.g     = 150;
    pastel_red_main.b     = 121;
    pastel_yellow_main.r  = 255;
    pastel_yellow_main.g  = 247;
    pastel_yellow_main.b  = 153;
    pastel_green_main.r   = 130;
    pastel_green_main.g   = 202;
    pastel_green_main.b   = 156;
    pastel_cyan_main.r    = 109;
    pastel_cyan_main.g    = 207;
    pastel_cyan_main.b    = 246;
    pastel_blue_main.r    = 131;
    pastel_blue_main.g    = 147;
    pastel_blue_main.b    = 202;
    pastel_violet_main.r  = 161;
    pastel_violet_main.g  = 134;
    pastel_violet_main.b  = 190;
    pastel_magenta_main.r = 244;
    pastel_magenta_main.g = 154;
    pastel_magenta_main.b = 193;
    
    //initialize random colors
    srand(time(NULL));
    peiceColorMain.r = rand() % 255 + 1;
    peiceColorMain.g = rand() % 255 + 1;
    peiceColorMain.b = rand() % 255 + 1;
    //currentPeiceID = rand() % 7;
    
    glClearColor(bgRightColor.r, bgRightColor.g, bgRightColor.b, 0); // moved this line to be in the init function
    glDisable(GL_DEPTH_TEST);
    
    // next four lines are new
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, WINDOW_WIDTH-1, WINDOW_HEIGHT-1, 0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

void idle() {
    glutPostRedisplay();
    //cout << currentPeice->getPeiceHeight() << endl;
    if(((currentPeice->getPeiceYPosition()-4) + currentPeice->getPeiceHeight()) < 24) {
        currentPeice->incrementPeiceY();
    }
    else { //rollback
        if(currentPeice)
		delete currentPeice;
        currentPeice = new Peice();
        //currentPeiceID = rand() % 7;
	//currentPeice->setPeiceType(rand() % 7 + 1);


	switch(currentPeice->getPeiceType()) {
		case 1:
			currentPeice->setPeiceOrientation(rand() % 4 + 1);
			break;
		case 2:
			currentPeice->setPeiceOrientation(rand() % 4 + 1);
			break;
		case 3:
			currentPeice->setPeiceOrientation(rand() % 4 + 1);
			break;
		case 4:
			break;
		case 5:
			currentPeice->setPeiceOrientation(rand() % 2 + 1);
			break;
		case 6:
			currentPeice->setPeiceOrientation(rand() % 2 + 1);
			break;
		case 7:
			currentPeice->setPeiceOrientation(rand() % 2 + 1);
			break;
	}
 
        //setColor();
	//se.playSound("Classical.wav");        
    }
    sleep(1000);
    //glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y) {
switch(key) {
	case 'q':
		_exit(0);
		break;
	//Rotate key
	case 'z':

		break;
	}
}

void specialKeyboard(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_LEFT:
            if(currentPeice->getPeiceXPosition() > 0)
                currentPeice->decrementPeiceX();
            score++;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            if(currentPeice->getPeiceXPosition() < 8)
                currentPeice->incrementPeiceX();
            score++;
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            if(currentPeice->getPeiceYPosition() > 0)
                currentPeice->decrementPeiceY();
            score++;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            if(currentPeice->getPeiceYPosition() < 22)
                currentPeice->incrementPeiceY();
            score++;
            glutPostRedisplay();
            break;
            
        case GLUT_KEY_F1:
            break;
        case GLUT_KEY_F2:
            break;
        case GLUT_KEY_F3:
            break;
        case GLUT_KEY_F4:
            break;
        case GLUT_KEY_F5:
            break;
        case GLUT_KEY_F6:
            break;
        case GLUT_KEY_F7:
            break;
        case GLUT_KEY_F8:
            break;
        case GLUT_KEY_F9:
            break;
        case GLUT_KEY_F10:
            break;
        case GLUT_KEY_F11:
            break;
        case GLUT_KEY_F12:
            break;
        case GLUT_KEY_PAGE_UP:
            break;
        case GLUT_KEY_PAGE_DOWN:
            break;
        case GLUT_KEY_HOME:
            break;
        case GLUT_KEY_END:
            break;
    }
}

void display() {  
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    drawDivider();
    //drawBoard();   
    drawNextPeice();
    drawWindowPane();
    drawGrid();
    

    /* Code to draw peices */


    //Peice nextPeice = new Peice();
    nextPeice.drawLeftLPeice(325,150,1);
    
    switch(currentPeice->getPeiceType()) {
	    case 1:
		currentPeice->drawLeftLPeice(currentPeice->getPeiceXPosition()*BLOCK_SIZE,currentPeice->getPeiceYPosition()*BLOCK_SIZE,currentPeice->getPeiceOrientation());
		break;
	    case 2:
		currentPeice->drawRightLPeice(currentPeice->getPeiceXPosition()*BLOCK_SIZE,currentPeice->getPeiceYPosition()*BLOCK_SIZE,currentPeice->getPeiceOrientation());
		break;
	    case 3:
		currentPeice->drawTPeice(currentPeice->getPeiceXPosition()*BLOCK_SIZE,currentPeice->getPeiceYPosition()*BLOCK_SIZE,currentPeice->getPeiceOrientation());
		break;
	    case 4:
		currentPeice->drawBoxPeice(currentPeice->getPeiceXPosition()*BLOCK_SIZE,currentPeice->getPeiceYPosition()*BLOCK_SIZE);
		break;
	    case 5:
		currentPeice->drawLinePeice(currentPeice->getPeiceXPosition()*BLOCK_SIZE,currentPeice->getPeiceYPosition()*BLOCK_SIZE,currentPeice->getPeiceOrientation());
		break;
	    case 6:
		currentPeice->drawRightTetroid(currentPeice->getPeiceXPosition()*BLOCK_SIZE,currentPeice->getPeiceYPosition()*BLOCK_SIZE,currentPeice->getPeiceOrientation());
		break;
	    case 7:
		currentPeice->drawLeftTetroid(currentPeice->getPeiceXPosition()*BLOCK_SIZE,currentPeice->getPeiceYPosition()*BLOCK_SIZE,currentPeice->getPeiceOrientation());
		break;
    }

    //currentPeice.eraseLeftLPeice(0,24,1);
    //currentPeice.eraseRightLPeice(0,2,1);
    //currentPeice.eraseTPeice(0,24,1);
    //currentPeice.eraseBoxPeice(0,24,1);
    //currentPeice.eraseLinePeice(0,24,1);
    //currentPeice.eraseRightTetroid(0,24,1);
    //currentPeice.eraseLeftTetroid (0,24,1);
    
    glColor3ub(255.0,255.0,255.0);
    score+=10;
    char* score_string;
    sprintf(score_string, "%d", score);
    drawString(300,20, scoreString);
    drawString(400,20, score_string);

    //currentPeiceY++;

    glFlush(); // added this line
    glutSwapBuffers(); // removed this line
}

int getRandomOrientation(int p_type) {

}

// *** BEGIN SELF-WRITTEN *** //

void drawGrid() {
    glColor3ub(neon.r,neon.g,neon.b);
    glBegin(GL_LINES);
    
    //draw the vertical lines
    for(int i = 0; i < (WINDOW_WIDTH/2)/BLOCK_SIZE; i++) {
        glVertex2f(i*24, 0);
        glVertex2f(i*24, WINDOW_HEIGHT);
    }
    
    //draw the horizontal lines
    for(int i = 0; i < (WINDOW_HEIGHT)/BLOCK_SIZE; i++) {
        glVertex2f(0, i*24);
        glVertex2f(WINDOW_WIDTH/2, i*24);
    }
    glEnd();
}

void drawDivider() {
	glLineWidth(3.0);
	glColor3ub(255,255,255);
	
	glBegin(GL_LINES);
	glVertex2f(WINDOW_WIDTH/2, 0);
	glVertex2f(WINDOW_WIDTH/2, WINDOW_HEIGHT);
	glEnd();
	
	glLineWidth(1.0);
}

void drawNextPeice() {
	glLineWidth(5.0);
	glColor3ub(255,255,255);
	
	drawString(320,100, "NEXT PEICE");
	glBegin(GL_LINE_STRIP);
	glVertex2f(300, 120);
	glVertex2f(425, 120);
	glVertex2f(425, 245);
	glVertex2f(300, 245);
	glVertex2f(300, 120); //Needed?
	glEnd();
	
	glLineWidth(1.0);

}


void drawWindowPane() {

	glBegin(GL_QUADS);
	glVertex2f(0.0f,0.0f);
	glVertex2f(WINDOW_WIDTH/2,0.0f);
	glVertex2f(WINDOW_WIDTH/2,WINDOW_HEIGHT);
	glVertex2f(0.0f,WINDOW_HEIGHT);
	glVertex2f(0.0f,0.0f);
	glEnd();
}


void drawBoard() {
    /*
     for(int i = 0; i < WINDOW_WIDTH; i++) {
     for(int j = 0; j < WINDOW_HEIGHT; j++) {
     if(tetrisBoardVertical[j][i] == 1) {
     drawSingleSquareColor(255,50,0,i*BLOCK_SIZE,j*BLOCK_SIZE,BLOCK_SIZE);
     }
     }
     }
     */
}

/*
 * Draws a rectangle to the screen. lw_x is the lower left x coordinate, lw_y is the lower left y coordinate, ur_x is the upper right x coordinate, ur_y is the upper right y coordinate.
 */
void drawRectangle(float lw_x, float lw_y, float ur_x, float ur_y) {
    glBegin(GL_QUADS);
    glVertex2f(lw_x,lw_y);
    glVertex2f(lw_x,ur_y);
    glVertex2f(ur_x,ur_y);
    glVertex2f(ur_x,lw_y);
    glVertex2f(lw_x,lw_y);
    glEnd();
}
/*
 Draw a single peice
 */
void drawSingleSquareColor(float R, float G, float B, int x, int y, int size) {
    
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
    glFlush();
    
}

void drawSingleSquareWithoutBorder(float R, float G, float B, int x, int y, int size) {
    //draw the color center
    glBegin(GL_QUADS);
    glColor3ub(R,G,B);
    glVertex2f(x+1, y+1);
    glVertex2f(x+size, y+1);
    glVertex2f(x+size, y+size);
    glVertex2f(x+1, y+size);
    glEnd();
    
}





//Open GL Font engine
void drawString(float x, float y, const char* string) {
    char* p = (char*) string;
    glRasterPos3f(x, y, 0.0f);
    
    while (*p != '\0') {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *p++);
    }
}


/*GLUT Fonts Reference
 GLUT_BITMAP_8_BY_13        //monospace
 GLUT_BITMAP_9_BY_15        //monospace
 GLUT_BITMAP_TIMES_ROMAN_10 //monospace
 GLUT_BITMAP_TIMES_ROMAN_24 //monospace
 GLUT_BITMAP_HELVETICA_10
 GLUT_BITMAP_HELVETICA_12
 GLUT_BITMAP_HELVETICA_18
 */
void drawStringFont(float x, float y, const char* string, int font) {
    char* p = (char*) string;
    glRasterPos3f(x, y, 0.0f);
    
    while (*p != '\0') {
        switch(font) {
            case 0:
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *p++);
                break;
            case 1:
                glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *p++);
                break;
            case 2:
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *p++);
                break;
            case 3:
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *p++);
                break;
            case 4:
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *p++);
                break;
            case 5:
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p++);
                break;
            case 6:
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
                break;
            default:
                break;
        }
    }
}

//self written sleep method
void sleep(int cnt) {
    int ContinueSwitch = 0;
    double counter = 0.0;
    while(true){
        counter++;
        if(ContinueSwitch == 1)
            break;
        
        else if(counter == cnt*10000.0)
            ContinueSwitch = 1;
    }
}




int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("OpenGLtris");
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyboard);
    init(); // changed the init function to come directly before display function
    glutIdleFunc(idle);
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}