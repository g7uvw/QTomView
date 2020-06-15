#include "tomslicer.h"
#include <iostream>
#include <fstream>

// Define the static Singleton pointer
TOMSlicer* TOMSlicer::instance_ = NULL;

TOMSlicer* TOMSlicer::getInstance()
{
    // Accessor to the singeton
    if (instance_ == NULL) {
       instance_ = new TOMSlicer();
    }
    return(instance_);
}

const std::vector<uint8_t>& TOMSlicer::XYSlice(const std::vector<uint8_t>& vol, size_t xsize, size_t ysize, size_t Zoffset)
{
    Slice.clear();
    // XY Slice
    size_t slicesize = xsize * ysize;
    std::clog<< __FUNCTION__ << '\n';
    std::clog << "Trying to allocate vector to store XY slice."  << '\n';
    //std::vector<uint8_t> Slice;
    try {
        Slice.reserve(slicesize);
    }
    catch (std::length_error& vecerror){
        std::cerr << vecerror.what() << '\n';
        Slice.resize(0); // on error set slice size to 0 and return zero sized slice
        return Slice;
    }

    size_t SliceOffset = Zoffset * slicesize;

    std::vector<uint8_t>::const_iterator Slicebegin = vol.begin() + SliceOffset;
    std::vector<uint8_t>::const_iterator Sliceend = Slicebegin + slicesize;

    Slice.assign(Slicebegin, Sliceend);

    return Slice;
}


const std::vector<uint8_t>& TOMSlicer::XZSlice(const std::vector<uint8_t>& vol, size_t xsize, size_t ysize, size_t Yoffset, size_t zsize)
{
    Slice.clear();
     //    XZ Slice at fixed index Y
    //std::vector<uint8_t> Slice;
    std::clog<< __FUNCTION__ << '\n';
    std::clog << "Trying to allocate vector to store XZ slice."  << '\n';
    try {
        Slice.reserve(xsize * zsize);
    }
    catch (std::length_error& vecerror){
        std::cerr << vecerror.what() << '\n';
        Slice.resize(0); // on error set slice size to 0 and return zero sized slice
        return Slice;
    }


    for (size_t z = 0; z < zsize; z++)
        {
            for (size_t x = 0; x < xsize; x++)
            {
                size_t wibble = (xsize * ysize * z + xsize * Yoffset + x);
                //std::vector<uint8_t>::const_iterator wobble = Volume.begin() + wibble;
                Slice.push_back(vol.at(wibble));
            }
        }
        return Slice;
}

const std::vector<uint8_t>& TOMSlicer::YZSlice(const std::vector<uint8_t>& vol, size_t Xoffset, size_t xsize, size_t ysize, size_t zsize)
{
    Slice.clear();
    //std::vector<uint8_t> Slice;
    //    YZ Slice at fixed index X

    std::clog<< __FUNCTION__ << '\n';
    std::clog << "Trying to allocate vector to store YZ slice."  << '\n';
    try {
        Slice.reserve(ysize * zsize);
    }
    catch (std::length_error& vecerror){
        std::cerr << vecerror.what() << std::endl;
        Slice.resize(0); // on error set slice size to 0 and return zero sized slice
        return Slice;
    }

    for (uint16_t i = 0; i < zsize; i++)
        {
            for (uint16_t j = 0; j < ysize; j++)
            {
                //size_t wibble = (header.xsize * header.ysize * i) + (header.xsize * j) + Xoffset;
                size_t wibble = (xsize * ysize * i) + (xsize * j) + Xoffset;
                //YZSlice.push_back(Volume.at((header.xsize * header.ysize * z) + (header.xsize * y) + Xoffset));
                Slice.push_back(vol.at((wibble)));
            }
        }

    std::ofstream f("../YZ.raw");
            for(std::vector<uint8_t>::const_iterator i = Slice.begin(); i != Slice.end(); ++i) {
                f << *i;
            }

            f.close();

    return Slice;
}
