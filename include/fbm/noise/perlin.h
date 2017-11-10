// http://mrl.nyu.edu/~perlin/doc/oscar.html#noise


#ifndef FBM_PERLIN_INCLUDED
#define FBM_PERLIN_INCLUDED


#include "fbm/noise.h"


namespace FBM
{
    class Perlin : public Noise
    {
        public:
            Perlin(const Context *context);
            ~Perlin();
            float noise(float t) const;

        private:
            void init();
            static unsigned int m_perm[0x100];
            static float m_grad[0x100];
            static bool m_initialized;
    };
}


#endif // FBM_PERLIN_INCLUDED
