def Draw(w, h):
    for x in range(w):
        for y in range(h):
            stroke(int(random(255)))
            rect(x, y, 10, 10)

    