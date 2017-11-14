#ifndef FBM_NOISE_INCLUDED
#define FBM_NOISE_INCLUDED


namespace FBM
{
    enum NoiseType
    {
        kPerlin = 0,
        kSimplex,
        kWave
    };

    class Noise
    {
        public:
            Noise() {};
            virtual ~Noise() {};
            virtual float noise(float t) const { return t; };
    };
}


inline float lerp(float a, float b, float w)
{
    return a + w * (b - a);
};


#endif // FBM_NOISE_INCLUDED
