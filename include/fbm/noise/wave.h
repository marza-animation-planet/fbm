#ifndef FBM_WAVE_INCLUDED
#define FBM_WAVE_INCLUDED


#include "fbm/noise.h"


namespace FBM
{
    class Wave : public Noise
    {
        public:
            Wave();
            ~Wave();
            float noise(float t) const;
    };
}


#endif // FBM_WAVE_INCLUDED
