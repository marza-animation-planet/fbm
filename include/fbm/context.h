#ifndef FBM_CONTEXT_INCLUDED
#define FBM_CONTEXT_INCLUDED


#include "fbm/noise.h"


namespace FBM
{
    class Context
    {
        public:
            Context(unsigned int octave)
                : m_absolute(false), m_octave(0), m_amplitude(0), m_frequency(0), m_offset(0), m_noise(0) {};
            Context(unsigned int octave, const Noise *noise, float amplitude, float frequency, float offset, bool absolute)
                : m_absolute(absolute), m_octave(octave), m_amplitude(amplitude), m_frequency(frequency), m_offset(offset), m_noise(noise) {};
            ~Context() {};

            unsigned int getOctave() const;
            float getAmplitude() const;
            float getFrequency() const;
            float getOffset() const;
            bool getAbsolute() const;
            void setAmplitude(float f);
            void setFrequency(float f);
            void setOffset(float f);
            void setNoise(const Noise *noise);
            void setAbsolute(bool abs);
            float noise(float f) const;

        private:
            bool m_absolute;
            unsigned int m_octave;
            float m_amplitude;
            float m_frequency;
            float m_offset;
            const Noise *m_noise;
     };
}


#endif // FBM_CONTEXT_INCLUDED
