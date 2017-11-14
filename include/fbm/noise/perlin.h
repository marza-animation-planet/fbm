// http://mrl.nyu.edu/~perlin/doc/oscar.html#noise


#ifndef FBM_PERLIN_INCLUDED
#define FBM_PERLIN_INCLUDED


#include "fbm/noise.h"


namespace FBM
{
    class Perlin : public Noise
    {
        public:
            Perlin();
            Perlin(unsigned int seed);
            ~Perlin();
            float noise(float t) const;

        private:
            void init();
            unsigned int m_perm[0x100];
            float m_grad[0x100];
            unsigned int m_seed;
    };

    inline float sCurve(float t)
    {
        return t * t * (3. - 2. * t);
    };
}


#endif // FBM_PERLIN_INCLUDED
