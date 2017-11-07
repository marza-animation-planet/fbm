import constants
import drawGrid


def setup():
    size(constants.ScreenWidth, constants.ScreenHeight)
    background(0)
    row_height = constants.ScreenHeight / float(constants.NRow)
    col_width = constants.ScreenWidth / float(constants.NCol)
    drawGrid.Draw(constants.NRow, constants.NCol, row_height, col_width)