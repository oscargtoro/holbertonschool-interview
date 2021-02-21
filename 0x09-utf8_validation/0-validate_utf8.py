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

    data_len = len(data)

    for i in range(data_len):
        char = "{0:b}".format(data[i])
        if char[:4].startswith("1110") and len(data[i:]) < 3:
            return False
        if char[:4].startswith("110") and len(data[i:]) < 2:
            return False
        if char[:4].startswith("11110") and len(data[i:]) < 4:
            return False
    return True
