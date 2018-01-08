#ifndef FBM_FBM_INCLUDED
#define FBM_FBM_INCLUDED


#include "fbm/config.h"
#include "fbm/noise/wave.h"
#include "fbm/noise/perlin.h"
#include "fbm/noise/simplex.h"
#include "fbm/context.h"
#include <vector>


namespace FBM
{
    class Fbm
    {
        public:
            FBM_EXPORT Fbm();
            FBM_EXPORT ~Fbm();

            FBM_EXPORT void setNoiseType(NoiseType t);
            FBM_EXPORT NoiseType getNoiseType() const;
            FBM_EXPORT void setOctaves(unsigned int octaves);
            FBM_EXPORT unsigned int getOctaves() const;
            FBM_EXPORT void setAmplitude(float amplitude);
            FBM_EXPORT float getAmplitude() const;
            FBM_EXPORT void setFrequency(float frequency);
            FBM_EXPORT float getFrequency() const;
            FBM_EXPORT void setLacunarity(float lacunarity);
            FBM_EXPORT float getLacunarity() const;
            FBM_EXPORT void setPersistence(float persistence);
            FBM_EXPORT float getPersistence() const;
            FBM_EXPORT void setOffset(float offset);
            FBM_EXPORT float getOffset() const;
            FBM_EXPORT void setOffsetOctaveScale(float scale);
            FBM_EXPORT float getOffsetOctaveScale() const;
            FBM_EXPORT void setAbsolute(bool absolute);
            FBM_EXPORT bool getAbsolute() const;
            FBM_EXPORT bool overrideAmplitude(unsigned int index, float amplitude);
            FBM_EXPORT bool overrideFrequency(unsigned int index, float frequency);
            FBM_EXPORT bool overrideNoiseType(unsigned int index, NoiseType type);
            FBM_EXPORT bool overrideOffset(unsigned int index, float offset);
            FBM_EXPORT bool overrideAbsolute(unsigned int index, bool absolute);
            FBM_EXPORT float noise(float f) const;

        private:
            void resetNoiseType();
            void resetAmplitude();
            void resetFrequency();
            void resetOffset();
            void resetAbsolute();

        private:
            bool m_absolute;
            NoiseType m_type;
            unsigned int m_octaves;
            float m_amplitude;
            float m_frequency;
            float m_lacunarity;
            float m_persistence;
            float m_offset;
            float m_offsetOctaveScale;
            const Perlin *m_perlin;
            const Simplex *m_simplex;
            const Wave *m_wave;
            std::vector<Context *> m_contexts;
    };

}


#endif // FBM_FBM_INCLUDED
