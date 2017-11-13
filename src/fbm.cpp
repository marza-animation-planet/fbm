#include "fbm/fbm.h"


using namespace FBM;


FBM_EXPORT Fbm::Fbm()
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

FBM_EXPORT Fbm::~Fbm()
{
    setOctaves(0);
    delete m_perlin;
    delete m_wave;
    delete m_simplex;
};

FBM_EXPORT void Fbm::setNoiseType(NoiseType t)
{
    m_type = t;
    resetNoiseType();
}

FBM_EXPORT NoiseType Fbm::getNoiseType() const
{
    return m_type;
}

FBM_EXPORT void Fbm::setOctaves(unsigned int octaves)
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

FBM_EXPORT unsigned int Fbm::getOctaves() const
{
    return m_octaves;
}

FBM_EXPORT void Fbm::setAmplitude(float amplitude)
{
    m_amplitude = amplitude;
    resetAmplitude();
}

FBM_EXPORT float Fbm::getAmplitude() const
{
    return m_amplitude;
}

FBM_EXPORT void Fbm::setFrequency(float frequency)
{
    m_frequency = frequency;
    resetFrequency();
}

FBM_EXPORT float Fbm::getFrequency() const
{
    return m_frequency;
}

FBM_EXPORT void Fbm::setLacunarity(float lacunarity)
{
    m_lacunarity = lacunarity;
    resetFrequency();
}

FBM_EXPORT float Fbm::getLacunarity() const
{
    return m_lacunarity;
}

FBM_EXPORT void Fbm::setPersistence(float persistence)
{
    m_persistence = persistence;
    resetAmplitude();
}

FBM_EXPORT float Fbm::getPersistence() const
{
    return m_persistence;
}

FBM_EXPORT void Fbm::setOffset(float offset)
{
    m_offset = offset;
    resetOffset();
}

FBM_EXPORT float Fbm::getOffset() const
{
    return m_offset;
}

FBM_EXPORT void Fbm::setOffsetOctaveScale(float scale)
{
    m_offsetOctaveScale = scale;
    resetOffset();
}

FBM_EXPORT float Fbm::getOffsetOctaveScale() const
{
    return m_offsetOctaveScale;
}

FBM_EXPORT bool Fbm::overrideAmplitude(unsigned int index, float amplitude)
{
    if (index >= m_octaves)
    {
        return false;
    }

    m_contexts[index]->setAmplitude(amplitude);

    return true;
}

FBM_EXPORT bool Fbm::overrideFrequency(unsigned int index, float frequency)
{
    if (index >= m_octaves)
    {
        return false;
    }

    m_contexts[index]->setFrequency(frequency);

    return true;
}

FBM_EXPORT bool Fbm::overrideNoiseType(unsigned int index, NoiseType type)
{
    const Noise *noise;
    if (index >= m_octaves)
    {
        return false;
    }

    switch (type)
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

    m_contexts[index]->setNoise(noise);

    return true;
}

FBM_EXPORT float Fbm::noise(float f) const
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

