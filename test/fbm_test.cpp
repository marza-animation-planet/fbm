#include "fbm/fbm.h"
#include <iostream>


using namespace FBM;


int main(int argc, char **argv)
{
    if (argc == 1)
    {
        Fbm fbm;
        fbm.setAmplitude(1);
        fbm.setFrequency(1);
        fbm.setPersistence(0.5);
        fbm.setLacunarity(2);
        fbm.setOffset(0);
        fbm.setOffsetOctaveScale(1);
        fbm.setNoiseType(kWave);
        fbm.setOctaves(2);

        fbm.overrideAmplitude(1, 1);
        fbm.overrideFrequency(1, 1);
        fbm.overrideNoiseType(1, kPerlin);

        std::cout << fbm.noise(0.5) << std::endl;

        return 0;
    }
    // type, octaves, amplitude, frequency, persistence, lacunarity, offset, offsetOctaveScale value;
    if (argc != 10)
    {
        std::cout << "fbm_test type(0-2) octaves amplitude frequency persistence lacunarity offset offsetOctaveScale value\n";
        return 1;
    }

    int t = atoi(argv[1]);

    NoiseType type;

    switch (t)
    {
        case 0:
            type = kPerlin;
            std::cout << "perlin";
            break;
        case 1:
            type = kSimplex;
            std::cout << "simplex";
            break;
        default:
            std::cout << "wave";
            type = kWave;
            break;
    }

    int octaves = atoi(argv[2]);
    float amplitude = atof(argv[3]);
    float frequency = atof(argv[4]);
    float persistence = atof(argv[5]);
    float lacunarity = atof(argv[6]);
    float offset = atof(argv[7]);
    float offsetscale = atof(argv[8]);
    float v = atof(argv[9]);

    Fbm fbm;
    fbm.setAmplitude(amplitude);
    fbm.setFrequency(frequency);
    fbm.setLacunarity(lacunarity);
    fbm.setPersistence(persistence);
    fbm.setOffset(offset);
    fbm.setOffsetOctaveScale(offsetscale);
    fbm.setNoiseType(type);
    fbm.setOctaves(octaves);
    std::cout << " oct : " << octaves << " amp : " << amplitude << " freq : " << frequency << " lac : " << lacunarity << " per : " << persistence << " off : " << offset << " os : " << offsetscale << std::endl;
    float r = fbm.noise(v);
    std::cout << " > " << r << std::endl;
    return 0;
}