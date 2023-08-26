#include "tomslicer.h"
#include <iostream>
#include <fstream>

// Define the static Singleton pointer
TOMSlicer* TOMSlicer::instance_ = nullptr;

TOMSlicer* TOMSlicer::getInstance()
{
    // Accessor to the singeton
    if (instance_ == nullptr) {
       instance_ = new TOMSlicer();
    }
    return(instance_);
}


// XY Slice
const std::vector<uint8_t>& TOMSlicer::XYSlice(const std::vector<uint8_t>& vol, size_t xsize, size_t ysize, size_t Zoffset)
{
    Slice.clear();

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

   auto Slicebegin = vol.begin() + SliceOffset;
   auto Sliceend = Slicebegin + slicesize;

    Slice.assign(Slicebegin, Sliceend);

    return Slice;
}

 //XZ Slice at fixed index Y
const std::vector<uint8_t>& TOMSlicer::XZSlice(const std::vector<uint8_t>& vol, size_t xsize, size_t ysize, size_t Yoffset, size_t zsize)
{
    Slice.clear();

    std::clog<< __FUNCTION__ << '\n';
    std::clog << "Trying to allocate vector to store XZ slice."  << '\n';
    try {
        Slice.reserve(xsize * zsize);
    }
    catch (std::out_of_range& orerror){
        std::cerr << orerror.what() <<"/n";
        Slice.resize(0);
        return Slice;
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
                auto tmp = (xsize * ysize * z + xsize * Yoffset + x);
                try{
                    Slice.push_back(vol.at(tmp));
                }
                catch (std::out_of_range& orerror){
                    std::cerr << orerror.what() <<"/n";
                    Slice.resize(0);
                    return Slice;
                }

                catch (std::length_error& vecerror){
                    std::cerr << vecerror.what() << '\n';
                    Slice.resize(0); // on error set slice size to 0 and return zero sized slice
                    return Slice;
                }
            }
        }
        return Slice;
}

 //YZ Slice at fixed index X
const std::vector<uint8_t>& TOMSlicer::YZSlice(const std::vector<uint8_t>& vol, size_t Xoffset, size_t xsize, size_t ysize, size_t zsize)
{
    Slice.clear();


    std::clog<< __FUNCTION__ << '\n';
    std::clog << "Trying to allocate vector to store YZ slice."  << '\n';
    try {
        Slice.reserve(ysize * zsize);
    }
    catch (std::out_of_range& orerror){
        std::cerr << orerror.what() <<"/n";
        Slice.resize(0);
        return Slice;
    }
    catch (std::length_error& vecerror){
        std::cerr << vecerror.what() << std::endl;
        Slice.resize(0); // on error set slice size to 0 and return zero sized slice
        return Slice;
    }

    for (size_t i = 0; i < zsize; i++)
        {
            for (size_t j = 0; j < ysize; j++)
            {
                auto tmp = (xsize * ysize * i) + (xsize * j) + Xoffset;
                try{
                    Slice.push_back(vol.at(tmp));
                }
                catch (std::out_of_range& orerror){
                    std::cerr << orerror.what() <<"/n";
                    Slice.resize(0);
                    return Slice;
                }

                catch (std::length_error& vecerror){
                    std::cerr << vecerror.what() << '\n';
                    Slice.resize(0); // on error set slice size to 0 and return zero sized slice
                    return Slice;
                }
            }
        }

//uncomment to dump out vector as raw binary for testing
//    std::ofstream f("../YZ.raw");
//            for(std::vector<uint8_t>::const_iterator i = Slice.begin(); i != Slice.end(); ++i) {
//                f << *i;
//            }
//    f.close();

    return Slice;
}
