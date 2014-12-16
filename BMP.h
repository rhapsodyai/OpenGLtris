//BMP.h
#ifndef __BMP_H_INCLUDED //if x.h hasn't been included yet...
#define __BMP_H_INCLUDED //#define this so the compiler knows it has been included

class BMP
{
public:
 unsigned long sizeX;  //横
 unsigned long sizeY; //縦
 char *Data;  //画像データ格納
 bool Load(char *filename);
 GLuint texture;
 void TexSet();
 BMP(char *FileName);
};


#endif
