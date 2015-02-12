#ifndef TOMHEADER_H
#define TOMHEADER_H
#include "stdint.h"
struct thead
{
    uint16_t xsize,ysize,zsize,lmarg,rmarg,tmarg,bmarg,tzmarg,bzmarg,\
    num_samples,num_proj,num_blocks,num_slices,bin,gain,speed,pepper,issue,num_frames,spare_int[13]__attribute__((packed));
    float scale,offset,voltage,current,thickness,pixel_size,distance,exposure,\
    mag_factor,filterb,correction_factor,spare_float[2]__attribute__((packed));
    uint32_t z_shift,z,theta __attribute__((packed));
    char time[26],duration[12],owner[21],user[5],specimen[32],scan[32],\
    comment[64],spare_char[192];
};

#endif // TOMHEADER_H
