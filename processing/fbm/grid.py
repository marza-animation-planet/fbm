def Draw(w, h, gridscale, ox, oy):
    stroke(0)
    strokeWeight(1)
    line(ox, 0, ox, h)
    line(0, oy, w, oy)

    stroke(175, 175, 175)
    strokeWeight(1)

    for x in range(w / gridscale / 2):
        gx = (x + 1) * gridscale 
        line(ox + gx, 0, ox + gx, h)
        line(ox - gx, 0, ox - gx, h)

    for y in range(h / gridscale / 2):
        gy = (y + 1) * gridscale 
        line(0, oy + gy, w, oy + gy)
        line(0, oy - gy, w, oy - gy)