#ifndef FBM_NOISE_INCLUDED
#define FBM_NOISE_INCLUDED


#include "fbm/context.h"


namespace FBM
{
    class Noise
    {
        public:
            Noise(const Context *context) : m_context(context) {};
            virtual ~Noise() {};
            virtual float noise(float t) const = 0;

        protected:
            const Context *m_context;
    };
}


inline float sCurve(float t)
{
    return t * t * (3. - 2. * t);
};

inline float lerp(float a, float b, float w)
{
    return a + w * (b - a);
};


#endif // FBM_NOISE_INCLUDED
