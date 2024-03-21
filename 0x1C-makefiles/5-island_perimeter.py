#!/usr/bin/python3
"""
Module defines the perimeter of an island.
"""


def island_perimeter(grid):
    """
    Return the perimeter of the island described in grid.

    The grid represents water by 0 and land by 1.

    Args:
        grid (list of list of int): Represents the island grid.

    Returns:
        int: The perimeter of the island.
    """
    if not grid or not grid[0]:
        return 0 

    perimeter = 0
    height = len(grid)
    width = len(grid[0])

    
    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter

