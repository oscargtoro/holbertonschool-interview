#!/usr/bin/env python3
"""
Module for the function(s)
    makeChange(coins, total)
"""


def makeChange(coins, total):
    """
    Determines the fewest number of coins needed to meet a given amount total.

    Args.
        coins: list of the values of the coins in your
            possession (assume infinite number).
        total: number to determine number of coins needed.

    Returns.
        the fewest number of coins needed to meet total.
    """

    if total <= 0:
        return 0
    coins.sort(reverse=True)
    count = 0
    for coin in coins:
        if total // coin > 0:
            count += total // coin
            total -= (coin * (total // coin))
        else:
            continue

    if total != 0:
        return -1
    return count
