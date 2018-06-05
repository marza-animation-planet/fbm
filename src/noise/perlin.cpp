#include "fbm/noise/perlin.h"


using namespace FBM;


static unsigned long int rand_next = 1;


int PERLIN::rand(void)
{
   rand_next = rand_next * 1103515245 + 12345;
   return (unsigned int)(rand_next / 65536) % 32768;
}


void PERLIN::srand(unsigned int seed)
{
   rand_next = seed + 1;
}


Perlin::Perlin()
    : Noise(), m_seed(0)
{
    init();
}

Perlin::Perlin(unsigned int seed)
    : Noise(), m_seed(seed)
{
    init();
}

Perlin::~Perlin() {}

float Perlin::noise(float f) const
{
    int b0, b1;
    float r0, r1, t;

    t = f + 0x1000;
    b0 = (int)t & 0xff;
    b1 = (b0 + 1) & 0xff;
    r0 = t - (int)t;
    r1 = r0 - 1.0;

    return lerp(r0 * m_grad[m_perm[b0]], r1 * m_grad[m_perm[b1]], sCurve(r0));
}

void Perlin::init()
{
    int i, j, k;
    float inv_f = 1 / (float)0x100;

    PERLIN::srand(m_seed);

    for (i = 0; i < 0x100; ++i)
    {
        m_perm[i] = i;
        m_grad[i] = ((PERLIN::rand() % 0x200) - 0x100) * inv_f;
    }

    while (--i)
    {
        k = m_perm[i];
        m_perm[i] = m_perm[j = PERLIN::rand() % 0x100];
        m_perm[j] = k;
    }
}
