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
            Fbm();
            ~Fbm();

            void setNoiseType(NoiseType t);
            NoiseType getNoiseType() const;
            void setOctaves(unsigned int octaves);
            unsigned int getOctaves() const;
            void setAmplitude(float amplitude);
            float getAmplitude() const;
            void setFrequency(float frequency);
            float getFrequency() const;
            void setLacunarity(float lacunarity);
            float getLacunarity() const;
            void setPersistence(float persistence);
            float getPersistence() const;
            void setOffset(float offset);
            float getOffset() const;
            void setOffsetOctaveScale(float scale);
            float getOffsetOctaveScale() const;
            void setAbsolute(bool absolute);
            bool getAbsolute() const;
            bool overrideAmplitude(unsigned int index, float amplitude);
            bool overrideFrequency(unsigned int index, float frequency);
            bool overrideNoiseType(unsigned int index, NoiseType type);
            bool overrideOffset(unsigned int index, float offset);
            bool overrideAbsolute(unsigned int index, bool absolute);
            float noise(float f) const;

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
