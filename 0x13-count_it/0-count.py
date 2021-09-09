#!/usr/bin/python3
"""Module for the method count_words
"""

import requests


def count_words(subreddit, word_list, after=None, uniq_list=[], word_count=[]):
    """Parses the title of all hot articles in reddit and prints a sorted count
    of given keywords making use of recursion

    Args.
        subreddit: name of subreddit to query
        word_list: list of words to count

    Returns.
        The count of given keywords, if word_list contains the same word
        (case-insensitive), the final count should be the sum of each duplicate
    """
    if after is None:
        word_list = [x.lower() for x in word_list]
        uniq_list = list(set(word_list))
        word_count = [0] * len(uniq_list)
    headers = {'User-Agent': 'python personal test'}
    parameters = {'after': after}
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    r = requests.get(url,
                     params=parameters,
                     headers=headers,
                     allow_redirects=False)
    if r.status_code != requests.codes.ok:
        return
    children = r.json()['data']['children']
    for post in children:
        for i in range(len(uniq_list)):
            title = post['data']['title'].lower().split()
            word_count[i] += title.count(uniq_list[i].lower())
    after = r.json()['data']['after']
    if after is not None:
        count_words(subreddit, word_list, after, uniq_list, word_count)
    else:
        lists_sorted = list(zip(word_count, uniq_list))
        lists_sorted.sort(key=lambda p: (-p[0], p[1]))
        word_count[:], uniq_list[:] = zip(*lists_sorted)

        for i in range(len(uniq_list)):
            if word_count[i] != 0:
                word = uniq_list[i]
                count = word_count[i] * word_list.count(word)
                print('{}: {}'.format(word, count))
