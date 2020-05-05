#include "tomslicer.h"

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

const std::vector<uint8_t>& TOMSlicer::XYSlice(const std::vector<uint8_t>& vol, size_t x, size_t y, size_t z)
{
    // XY Slice
    size_t slicesize = x * y;
    //std::cout<< __FUNCTION__ << std::endl;
    std::cout << "Trying to allocate vector to store XY slice."  << std::endl;
    //std::vector<uint8_t> Slice;
    try {
        Slice.reserve(slicesize);
    }
    catch (std::length_error& vecerror){
        std::cerr << vecerror.what() << std::endl;
        Slice.resize(0); // on error set slice size to 0 and return zero sized slice
        return Slice;
    }

    size_t SliceOffset = z * slicesize;

    std::vector<uint8_t>::const_iterator Slicebegin = vol.begin() + SliceOffset;
    std::vector<uint8_t>::const_iterator Sliceend = Slicebegin + slicesize;

    Slice.assign(Slicebegin, Sliceend);

    return Slice;
}


const std::vector<uint8_t>& TOMSlicer::XZSlice(const std::vector<uint8_t>& vol, size_t x, size_t Yoffset, size_t z)
{
     //    XZ Slice at fixed index Y
    //std::vector<uint8_t> Slice;
    std::cout<< __FUNCTION__ << std::endl;
    std::cout << "Trying to allocate vector to store XZ slice."  << std::endl;
    try {
        Slice.reserve(x * z);
    }
    catch (std::length_error& vecerror){
        std::cerr << vecerror.what() << std::endl;
        Slice.resize(0); // on error set slice size to 0 and return zero sized slice
        return Slice;
    }

    for (uint16_t z = 0; z < header.zsize; z++)
    {
        for (uint16_t x = 0; x < header.xsize; x++)
        {
            size_t wibble = (header.xsize * header.ysize * z) + (header.xsize * Yoffset) + x;
            //std::vector<uint8_t>::const_iterator wobble = Volume.begin() + wibble;
            Slice.push_back(vol.at(wibble));
        }
    }

    return Slice;
}

const std::vector<uint8_t>& TOMSlicer::YZSlice(const std::vector<uint8_t>& vol, size_t x, size_t y, size_t z)
{
    //std::vector<uint8_t> Slice;
    //    YZ Slice at fixed index X

    uint16_t Xoffset = x;
    std::cout<< __FUNCTION__ << std::endl;
    std::cout << "Trying to allocate vector to store YZ slice."  << std::endl;
    try {
        Slice.reserve(y*z);
    }
    catch (std::length_error& vecerror){
        std::cerr << vecerror.what() << std::endl;
        Slice.resize(0); // on error set slice size to 0 and return zero sized slice
        return Slice;
    }

    for (uint16_t z = 0; z < header.zsize; z++)
    {
        for (uint16_t y = 0; y < header.ysize; y++)
        {
            size_t wibble = (header.xsize * header.ysize * z) + (header.xsize * y) + Xoffset;
            //YZSlice.push_back(Volume.at((header.xsize * header.ysize * z) + (header.xsize * y) + Xoffset));
            Slice.push_back(vol.at((wibble)));
        }
    }

    return Slice;
}
