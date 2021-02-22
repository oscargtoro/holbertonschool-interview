#!/usr/bin/python3
"""Module for the function validUTF8
"""


def validUTF8(data):
    """Determines if a given data set represents a valid UTF-8 encoding

    Args:
        data: dataset to evaluate.

    Returns:
        True if data is a valid UTF-8 encoding, else return False
    """

    nbytes = 0
    for number in data:
        mask = 1 << 7
        if nbytes == 0:
            while mask & number:
                nbytes += 1
                mask = mask >> 1
            if nbytes == 0:
                continue
            if nbytes == 1 or nbytes > 4:
                return False
        else:
            if not (number & mask and not (number & (1 << 6))):
                return False
        nbytes -= 1
    return nbytes == 0
