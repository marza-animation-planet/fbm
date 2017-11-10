// http://mrl.nyu.edu/~perlin/doc/oscar.html#noise


#ifndef FBM_SIMPLEX_INCLUDED
#define FBM_SIMPLEX_INCLUDED


#include "fbm/noise.h"


namespace FBM
{
    class Simplex : public Noise
    {
        public:
            Simplex(const Context *context);
            ~Simplex();
            float noise(float t) const;

        private:
            static unsigned int m_perm[0x100];
    };
}


inline float fade(float f)
{
    return (f * f * f * (f * (f * 6 - 15) + 10));
}

inline int fastfloor(float f)
{
    return f > 0 ? (int)f : (int)(f - 1);
}

inline float gradient(unsigned int hash, float x)
{
    unsigned int h = hash & 15;
    int grad = 1 + (h & 7);
    if (h & 8)
    {
        grad *= -1;
    }

    return grad * x;
}


#endif // FBM_SIMPLEX_INCLUDED
