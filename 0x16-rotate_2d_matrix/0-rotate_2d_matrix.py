#!/usr/bin/python3
"""Module for the method rotate_2d_matrix
"""


def rotate_2d_matrix(matrix):
    """Given an n x n 2D matrix, rotate it 90 degrees clockwise.

       Args.
           matrix: nxn matrix
    """

    matrix[:] = [list(x) for x in zip(*matrix[::-1])]
