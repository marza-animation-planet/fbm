import grid


ScreenWidth = 600
ScreenHeight = 400
GridScale = 100
Amplitude = 1
Frequency = 0.01
Octaves = 1
Lacunarity = 2
Persistence = 0.1


def getOrigin():
    return (ScreenWidth * 0.5, ScreenHeight * 0.5)


def setup():
    size(ScreenWidth, ScreenHeight)


def keyPressed():
    global Octaves
    global Frequency
    global Lacunarity
    global Persistence

    if key == "1":
        if Octaves > 1:
            Octaves -= 1
    elif key == "2":
        Octaves += 1
    elif key == "3":
        if Frequency > 0.01:
            Frequency -= 0.01
    elif key == "4":
        Frequency += 0.01
    elif key == "5":
        if Lacunarity > 0.1:
            Lacunarity -= 0.1
    elif key == "6":
        Lacunarity += 0.1
    elif key == "7":
        if Persistence > 0.11:
            Persistence -= 0.1
    elif key == "8":
        Persistence += 0.1


def draw():
    noiseSeed(1)
    background(204)
    ox, oy = getOrigin()

    grid.Draw(ScreenWidth, ScreenHeight, GridScale, ox, oy)

    stroke(0, 50, 125)

    pre = None

    for x in range(ScreenWidth):
        fre = Frequency
        amp = Amplitude
        y = 0
        for i in range(Octaves):
            y += amp * noise(fre * x)
            fre *= Lacunarity
            amp *= Persistence

        y = oy - y * GridScale
        if pre and pre[1] < ScreenHeight and pre[1] > 0:
            line(pre[0], pre[1], x, y)

        pre = (x, y)

    fill(30)
    text("Octaves : %d Frequency: %f Lacunarity: %f Persistence: %f" % (Octaves, Frequency, Lacunarity, Persistence), 20, 20)
    fill(100)
    text("Octave : 1,2 Frequency 3,4 Lacunarity: 5,6 Persistence : 7,8", 20, ScreenHeight - 20)
