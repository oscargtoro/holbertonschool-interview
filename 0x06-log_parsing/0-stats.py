#!/usr/bin/python3
'''Reads stdin line by line and computes metrics.
'''

import sys


def data_print(codes, size, metrics):
    '''Handles metrics printing
    '''

    print('File size: {}'.format(size))
    for code in codes:
        if metrics.get(code) is not 0:
            print('{}: {}'.format(code, metrics.get(code)))


if __name__ == "__main__":
    i = 0
    codes = ['200', '301', '400', '401', '403', '404', '405', '500']
    metrics = {'200': 0,
               '301': 0,
               '400': 0,
               '401': 0,
               '403': 0,
               '404': 0,
               '405': 0,
               '500': 0}
    size = 0
    try:
        for line in sys.stdin:
            line.strip('\n')
            stline = line.split()
            if len(stline) == 9:
                code = stline[7]
                if code.isnumeric() and code in codes:
                    current = metrics.get(code)
                    metrics.update({code: current + 1})
                    size = size + int(stline[8])
            i += 1
            if i % 10 == 0:
                data_print(codes, size, metrics)
        data_print(codes, size, metrics)
    except KeyboardInterrupt:
        data_print(codes, size, metrics)
        raise
