#!/usr/bin/python3
"""5-island_perimeter module"""


def island_perimeter(grid):
    """This will return the perimeter of the island described in grid"""
    c = 0
    length = len(grid) - 1
    width = len(grid[0]) - 1

    for ui, r in enumerate(grid):
        for j, n in enumerate(r):
            if n == 1:
                if ui == 0 or grid[ui - 1][j] != 1:
                    c += 1
                if j == 0 or grid[ui][j - 1] != 1:
                    c += 1
                if j == width or grid[ui][j + 1] != 1:
                    c += 1
                if ui == length or grid[ui + 1][j] != 1:
                    c += 1
    return c
