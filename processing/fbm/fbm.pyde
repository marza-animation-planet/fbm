import grid
import simplex
import perlin


ScreenWidth = 900
ScreenHeight = 500
GridScale = 100
Amplitude = 1
Frequency = 1
Octaves = 1
Lacunarity = 2
Persistence = 0.5
InvScale = 1 / float(GridScale)
CurrentMode = "wave"
Offset = 0
OffsetPhaseScale = 1


def getOrigin():
    return (ScreenWidth * 0.5, ScreenHeight * 0.5)


def setup():
    perlin.init(0)
    size(ScreenWidth, ScreenHeight)


def keyPressed():
    global Octaves
    global Frequency
    global Lacunarity
    global Persistence
    global Amplitude
    global CurrentMode
    global Offset
    global OffsetPhaseScale

    if key == "w":
        CurrentMode = "wave"
    elif key == "s":
        CurrentMode = "simplex"
    elif key == "p":
        CurrentMode = "perlin"
    elif key == "1":
        if Amplitude > 0.11:
            Amplitude -= 0.1
    elif key == "2":
        Amplitude += 0.1
    elif key == "3":
        if Frequency > 0.11:
            Frequency -= 0.1
    elif key == "4":
        Frequency += 0.1
    elif key == "5":
        if Octaves > 1:
            Octaves -= 1
    elif key == "6":
        Octaves += 1
    elif key == "7":
        if Lacunarity > 1:
            Lacunarity -= 0.1
    elif key == "8":
        Lacunarity += 0.1
    elif key == "9":
        if Persistence > 0.11:
            Persistence -= 0.1
    elif key == "0":
        Persistence += 0.1
    elif key == "+":
        Offset += 0.05
    elif key == "-":
        Offset -= 0.05
    elif key == "]":
        OffsetPhaseScale += 0.05
    elif key == "[":
        if OffsetPhaseScale > 0.051:
            OffsetPhaseScale -= 0.05

    elif key == "r":
        Amplitude = 1
        Frequency = 1
        Octaves = 1
        Lacunarity = 2
        Persistence = 0.5
        CurrentMode = "wave"
        Offset = 0
        OffsetPhaseScale = 1


def funcSin(x, fre):
    return sin(x * fre * PI * InvScale)


def funcSimplex(x, fre):
    return simplex.noise(x * fre * InvScale)


def funcPerlin(x, fre):
    return perlin.noise(x * fre * InvScale)


def draw():
    noiseSeed(1)
    background(204)
    ox, oy = getOrigin()

    grid.Draw(ScreenWidth, ScreenHeight, GridScale, ox, oy)

    stroke(0, 50, 125)

    pre = None

    if CurrentMode == "wave":
        func = funcSin
    elif CurrentMode == "perlin":
        func = funcPerlin
    else:
        func = funcSimplex

    for x in range(ScreenWidth):
        offset = Offset
        fre = Frequency
        amp = Amplitude
        y = 0

        for i in range(Octaves):
            y += amp * func(x + (offset * GridScale), fre)
            fre *= Lacunarity
            amp *= Persistence
            offset *= OffsetPhaseScale


        y = oy - y * GridScale
        if pre and pre[1] < ScreenHeight and pre[1] > 0:
            line(pre[0], pre[1], x, y)

        pre = (x, y)

    fill(30)
    text("Amplitude : %f Frequency: %f Offset: %f" % (Amplitude, Frequency, Offset), 20, 20)
    text("Octaves : %d Lacunarity: %f Persistence: %f OffsetPhaseScale : %f" % (Octaves, Lacunarity, Persistence, OffsetPhaseScale), 20, 40)
    fill(100)
    text("Mode : 'w' to wave, 'p' to perlin 's' to simplex, reset : 'r'", 20, ScreenHeight - 40)
    text("Amplitude 1,2 Frequency 3,4 Octave : 5,6 Lacunarity: 7,8 Persistence : 9,0 Offset : -,+ OffsetPhaseScale: [,]", 20, ScreenHeight - 20)
