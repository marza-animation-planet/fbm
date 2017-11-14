# http://mrl.nyu.edu/~perlin/doc/oscar.html#noise
import random
import sys


P = []
Gl = []


def scurve(t):
    return t * t * (3.0 - 2.0 * t)


def lerp(v1, v2, w):
    return v1 + w * float(v2 - v1)


def noise(x):
    t = x + 0x1000
    b0 = int(t) & 0xff
    b1 = (b0 + 1) & 0xff
    r0 = t - int(t)
    r1 = r0 - 1.0

    return lerp(r0 * Gl[P[b0]], r1 * Gl[P[b1]], scurve(r0))


def init(seed):
    global P
    global Gl
    P = []
    Gl = []
    random.seed(seed)

    P = range(256)
    inv_0x100 = 1 / 256.0
    for i in range(256):
        Gl.append(float(((random.randint(0, sys.maxint) % 512) - 256) * inv_0x100))

    for i in range(255, -1, -1):
        k = P[i]
        j = random.randint(0, sys.maxint) % 256
        P[i] = P[j]
        P[j] = k

    P = P * 2
    Gl = Gl * 2