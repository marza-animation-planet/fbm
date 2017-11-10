#include "fbm/noise/wave.h"
#include "math.h"


using namespace FBM;


Wave::Wave(const Context *context)
    : Noise(context) {}

Wave::~Wave() {}

float Wave::noise(float t) const
{
    return m_context->amplitude() * sinf(M_PI * (t + m_context->offset()) * m_context->frequency());
}
