def DrawSin(w, h, ox, oy, gridscale, frequency, amplitude, func):
    inv_scale = 1 / float(gridscale)

    pre = (0, oy + (amplitude * gridscale * func((-ox * PI) * inv_scale * frequency)))
    for ix in range(w):
        x = ix - ox

        y = oy - (amplitude * gridscale * func((x * PI) * inv_scale * frequency))

        if pre[1] < h and pre[1] > 0:
            line(pre[0], pre[1], ix, y)
        pre = (ix, y)
