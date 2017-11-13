import grid


ScreenWidth = 600
ScreenHeight = 400
GridScale = 100
Amplitude = 1
Frequency = 1


def getOrigin():
    return (ScreenWidth * 0.5, ScreenHeight * 0.5)


def setup():
    size(ScreenWidth, ScreenHeight)


def draw():
    background(204)
    ox, oy = getOrigin()

    grid.Draw(ScreenWidth, ScreenHeight, GridScale, ox, oy)

    stroke(0, 50, 125)
    inv_scale = 1 / float(GridScale)

    pre = None
    for x in range(ScreenWidth):
        px = x - ox
        xpi = (px * PI)
        xfre = xpi * Frequency * inv_scale
        t = frameCount * 0.05
        y = sin(xfre)
        y += sin(xfre * 2.1 + t) * 4.5
        y += sin(xfre * 1.72 + t * 1.121) * 4.0
        y += sin(xfre * 2.221 + t * 0.437) * 5.0
        y += sin(xfre * 3.1122 + t * 4.269) * 2.5
        y = oy - (y * GridScale * Amplitude * 0.06)

        if pre and pre[1] < ScreenHeight and pre[1] > 0:
            line(pre[0], pre[1], x, y)
        pre = (x, y)