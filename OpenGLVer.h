//
//  OpenGLVer.h
//  Pasteltris
//
//  Created by Melissa Auclaire on 6/11/14.
//  Copyright (c) 2014 MLA. All rights reserved.
//

#ifndef __OPENGLTRIS_H_INCLUDED //if x.h hasn't been included yet...
#define __OPENGLTRIS_H_INCLUDED //#define this so the compiler knows it has been included


const int texture_width = 256;
const int texture_height = 256;
GLubyte texture_image[256][256][3];


void generate_texture()
{
    for(int i=0; i<texture_width; i++)
        for(int j=0; j<texture_width; j++)
        {
            texture_image[i][j][0] = 255;
            texture_image[i][j][1] = 255*(i & 0x04);
            texture_image[i][j][2] = 255*(j & 0x04);
        }
}
#endif
