#include "fbm/noise/wave.h"
#include "math.h"


using namespace FBM;


Wave::Wave()
    : Noise() {}

Wave::~Wave() {}

float Wave::noise(float t) const
{
    return sinf(t);
}
