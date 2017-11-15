#include "fbm/context.h"


using namespace FBM;


unsigned int Context::getOctave() const
{
    return m_octave;
}

float Context::getAmplitude() const
{
    return m_amplitude;
}

float Context::getFrequency() const
{
    return m_frequency;
}

float Context::getOffset() const
{
    return m_offset;
}

bool Context::getAbsolute() const
{
    return m_absolute;
}

void Context::setAmplitude(float f)
{
    m_amplitude = f;
}
void Context::setFrequency(float f)
{
    m_frequency = f;
}
void Context::setOffset(float f)
{
    m_offset = f;
}

void Context::setNoise(const Noise *noise)
{
    m_noise = noise;
}

void Context::setAbsolute(bool absolute)
{
    m_absolute = absolute;
}

float Context::noise(float f) const
{
    float result = m_amplitude * m_noise->noise((f + m_offset) * m_frequency);
    if (m_absolute && result < 0.f)
    {
        result *= -1;
    }

    return result;
}