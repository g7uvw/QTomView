//
//  TOMSlicer.h
//  VectorSlicesTest
//
//  Created by David Mills on 23/04/2020.
//  Copyright © 2020 webshed.org. All rights reserved.
//
#include "TomHeader.h"
#include <iostream>
#include <vector>

#ifndef TOMSlicer_h
#define TOMSlicer_h

class TOMSlicer
{
private:
    static TOMSlicer* instance_;
    TOMSlicer() {};    // Private constructor so we can use singeton idea to make sure only one existance of this class occurs.
    TOMSlicer(const TOMSlicer&);            // dissalow copy
    TOMSlicer& operator=(const TOMSlicer&); //disallow assignment
    
public:
    static TOMSlicer* getInstance();    // public accessor for the singleton
    //thead header;
    std::vector<uint8_t> Slice;
    const std::vector<uint8_t>& XYSlice(const std::vector<uint8_t>& vol, size_t x, size_t y, size_t Zoffset);
    const std::vector<uint8_t>& XZSlice(const std::vector<uint8_t>& vol, size_t x, size_t ysize, size_t Yoffset, size_t z);
    const std::vector<uint8_t>& YZSlice(const std::vector<uint8_t>& vol, size_t Xoffset, size_t xsize, size_t y, size_t z);

};




#endif /* TOMSlicer_h */
