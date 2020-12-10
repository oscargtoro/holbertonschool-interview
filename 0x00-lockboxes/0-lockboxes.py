#!/usr/bin/python3
'''Determines if all the boxes can be opened.
'''


def unlock(boxes, keys, bOpened):
    '''Checks if key already used
    '''
    for key in keys:
        if key in bOpened:
            continue
        else:
            bOpened[key] = 'true'
            unlock(boxes, boxes[key], bOpened)


def canUnlockAll(boxes):
    '''Determines if all the boxes can be opened.
    Args:
        boxes: list of lists.
    Returns:
        True if all boxes can be opened, else returns false
    '''

    bOpened = {0: 'true'}
    unlock(boxes, boxes[0], bOpened)
    for box in range(len(boxes)):
        if box not in bOpened:
            return False
    return True
