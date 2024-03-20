#!/usr/bin/python3
"""
Module for perimeter of island
"""


def island_perimeter(grid):
    """
    Return the perimeter of the island described in grid.


    Args:
        grid (list of list of int): Represents the island grid.


    Returns:
        int: The perimeter of the island.
    """
    if not grid or not grid[0]:
        return 0 

    height = len(grid)
    width = len(grid[0])
    edges = 0
    size = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                if j > 0 and grid[i][j - 1] == 1:
                    edges += 1
                if i > 0 and grid[i - 1][j] == 1:
                    edges += 1
    return size * 4 - edges * 2
