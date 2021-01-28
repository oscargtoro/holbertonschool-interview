#!/usr/bin/python3

import sys
# import shlex

# i = 0
# codes = ['200', '301', '400', '401', '403', '404', '405', '500']
# metrics = {'200': 0,
#            '301': 0,
#            '400': 0,
#            '401': 0,
#            '403': 0,
#            '404': 0,
#            '405': 0,
#            '500': 0}
# size = 0
# try:
#     for line in sys.stdin:
#         stline = shlex.split(line)
#         if len(stline) == 7:
#             code = stline[5]
#             if code.isnumeric() and code in codes:
#                 code = stline[5]
#                 current = metrics.get(code)
#                 metrics.update({code: current + 1})
#                 size = size + int(stline[6])
#         i += 1
#         if i % 10 == 0:
#             print('File size: {}'.format(size))
#             for code in codes:
#                 print('{} {}'.format(code, metrics.get(code)))
# except KeyboardInterrupt as e:
#     print('File size: {}'.format(size))
#     for code in codes:
#         if metrics.get(code) is not 0:
#             print('{} {}'.format(code, metrics.get(code)))
