#ifndef FBM_CONTEXT_INCLUDED
#define FBM_CONTEXT_INCLUDED


namespace FBM
{
    class Context
    {
        public:
            Context()
                : m_octave(0), m_amplitude(0.f), m_frequency(0.f), m_offset(0.f) {};
            Context(unsigned int octave, float amplitude, float frequency, float offset)
                : m_octave(octave), m_amplitude(amplitude), m_frequency(frequency), m_offset(offset) {};
            ~Context() {};
            unsigned int octave() const
            {
                return m_octave;
            }
            float amplitude() const
            {
                return m_amplitude;
            }
            float frequency() const
            {
                return m_frequency;
            }
            float offset() const
            {
                return m_offset;
            }

        private:
            unsigned int m_octave;
            float m_amplitude;
            float m_frequency;
            float m_offset;
     };
}


#endif // FBM_CONTEXT_INCLUDED
