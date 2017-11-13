def Draw(nrow, ncol, row_height, col_width):
    stroke(255)
    for x in range(ncol):
        for y in range(nrow):
            fill(127 + 127 * sin(x + y))
            rect(x * col_width, y * row_height, col_width, row_height)