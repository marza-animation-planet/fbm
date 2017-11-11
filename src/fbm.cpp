#include "fbm/fbm.h"


using namespace FBM;


Fbm::Fbm()
    : m_type(kPerlin), m_octaves(0), m_amplitude(1), m_frequency(1), m_lacunarity(2), m_persistence(0.5), m_offset(0), m_offsetOctaveScale(1)
{
    m_perlin = new Perlin();
    m_wave = new Wave();
    m_simplex = new Simplex();

    for (std::vector<Context *>::iterator it = m_contexts.begin(); it != m_contexts.end(); ++it)
    {
        delete *it;
    }

    m_contexts.clear();
};

Fbm::~Fbm()
{
    setOctaves(0);
    delete m_perlin;
    delete m_wave;
    delete m_simplex;
};

void Fbm::setNoiseType(NoiseType t)
{
    m_type = t;
    resetNoiseType();
}

NoiseType Fbm::getNoiseType() const
{
    return m_type;
}

void Fbm::setOctaves(unsigned int octaves)
{
    if (m_octaves > octaves)
    {
        for (std::vector<Context *>::iterator it = m_contexts.begin() + octaves; it != m_contexts.end(); ++it)
        {
            delete (*it);
        }

        m_contexts.erase(m_contexts.begin() + octaves, m_contexts.end());
    }
    else if (octaves > m_octaves)
    {
        for (unsigned int i = 0; i < (octaves - m_octaves); ++i)
        {
            m_contexts.push_back(new Context(m_octaves + i));
        }
    }

    m_octaves = octaves;
    resetNoiseType();
    resetAmplitude();
    resetFrequency();
    resetOffset();
}

unsigned int Fbm::getOctaves() const
{
    return m_octaves;
}

void Fbm::setAmplitude(float amplitude)
{
    m_amplitude = amplitude;
    resetAmplitude();
}

float Fbm::getAmplitude() const
{
    return m_amplitude;
}

void Fbm::setFrequency(float frequency)
{
    m_frequency = frequency;
    resetFrequency();
}

float Fbm::getFrequency() const
{
    return m_frequency;
}

void Fbm::setLacunarity(float lacunarity)
{
    m_lacunarity = lacunarity;
    resetFrequency();
}

float Fbm::getLacunarity() const
{
    return m_lacunarity;
}

void Fbm::setPersistence(float persistence)
{
    m_persistence = persistence;
    resetAmplitude();
}

float Fbm::getPersistence() const
{
    return m_persistence;
}

void Fbm::setOffset(float offset)
{
    m_offset = offset;
    resetOffset();
}

float Fbm::getOffset() const
{
    return m_offset;
}

void Fbm::setOffsetOctaveScale(float scale)
{
    m_offsetOctaveScale = scale;
    resetOffset();
}

float Fbm::getOffsetOctaveScale() const
{
    return m_offsetOctaveScale;
}

float Fbm::noise(float f) const
{
    if (!m_contexts.size())
    {
        return f;
    }

    float result = 0;
    for (std::vector<Context *>::const_iterator it = m_contexts.begin(); it != m_contexts.end(); ++it)
    {
        result += (*it)->noise(f);
    }

    return result;
}

void Fbm::resetNoiseType()
{
    const Noise *noise;

    switch (m_type)
    {
        case kPerlin:
            noise = m_perlin;
            break;
        case kSimplex:
            noise = m_simplex;
            break;
        default:
            noise = m_wave;
            break;
    }

    for (std::vector<Context *>::iterator it = m_contexts.begin(); it != m_contexts.end(); ++it)
    {
        (*it)->setNoise(noise);
    }
}

void Fbm::resetAmplitude()
{
    float amp = m_amplitude;

    for (std::vector<Context *>::iterator it = m_contexts.begin(); it != m_contexts.end(); ++it)
    {
        (*it)->setAmplitude(amp);
        amp *= m_persistence;
    }
}

void Fbm::resetFrequency()
{
    float freq = m_frequency;

    for (std::vector<Context *>::iterator it = m_contexts.begin(); it != m_contexts.end(); ++it)
    { 
        (*it)->setFrequency(freq);
        freq *= m_lacunarity;
    }
}

void Fbm::resetOffset()
{
    float offset = m_offset;

    for (std::vector<Context *>::iterator it = m_contexts.begin(); it != m_contexts.end(); ++it)
    {
        (*it)->setOffset(offset);
        offset *= m_offsetOctaveScale;
    }
}

