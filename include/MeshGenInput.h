#ifndef _MESHGENINPUT_H_
#define _MESHGENINPUT_H_

#include "Loop.h"

struct MeshGenInput
{
    MeshGenInput() : desiredElementSize(1) {}
    double desiredElementSize;
    Loop2d boundary;
};


#endif // _MESHGENINPUT_H_
