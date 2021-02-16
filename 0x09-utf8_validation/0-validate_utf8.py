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
    for i in data:
        if i.bit_length() > 8:
            return False
    return True
