#!/usr/bin/python3
"""Module for the method rain.
"""

def rain(walls):
    """Calculate how many square units of water will be retained after it rains.

    Args.
        walls: list of non-negative integers.

    Returns.
    Integer indicating total amount of rainwater retained, 0 on empty list.
    """
    n = len(walls)
    water = 0

    # For every element of walls
    for i in range(1, n - 1):
        # Max element on its left
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        # Max element on its right
        right = walls[i]
        for k in range(i + 1, n):
            right = max(right, walls[k])

        # Update the maximum water
        water += min(left, right) - walls[i]

    return water
