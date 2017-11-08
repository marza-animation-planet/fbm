import grid
import trigonometryFunc

ScreenWidth = 600
ScreenHeight = 400
GridScale = 100
Amplitude = 1
Frequency = 1
Modes = {"sin": sin, "cos": cos, "tan": tan}
CurrenMode = "sin"


def getOrigin():
    return (ScreenWidth * 0.5, ScreenHeight * 0.5)


def setup():
    size(ScreenWidth, ScreenHeight)


def keyPressed():
    global CurrenMode
    global Amplitude
    global Frequency

    if key == "s":
        CurrenMode = "sin"
    elif key == "c":
        CurrenMode = "cos"
    elif key == "t":
        CurrenMode = "tan"
    elif key == "1":
        Amplitude -= 0.1
        if Amplitude < 0:
            Amplitude = 0
    elif key == "2":
        Amplitude += 0.1
    elif key == "3":
        Frequency -= 0.1
        if Frequency < 0:
            Frequency = 0
    elif key == "4":
        Frequency += 0.1
    elif key == "r":
        CurrenMode = "sin"
        Frequency = 1
        Amplitude = 1


def draw():
    global Frequency
    background(204)
    ox, oy = getOrigin()
    grid.Draw(ScreenWidth, ScreenHeight, GridScale, ox, oy)
    
    ox, oy = getOrigin()
    stroke(0, 50, 125)
    trigonometryFunc.DrawSin(ScreenWidth, ScreenHeight, ox, oy, GridScale, Frequency, Amplitude, Modes.get(CurrenMode))

    fill(30)
    text("Mode : %s, Amplitude : %f, Frequency : %f" % (CurrenMode, Amplitude, Frequency), 20, 20)
    fill(100)
    text("reset : 'r'. mode : 's' sin, 'c' cos, 't' tan. Amplitude - or + : '1', '2'. Frequency - or + : '3', '4'", 20, ScreenHeight - 20)
