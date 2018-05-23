# -*- coding: utf-8 -*-

import time
import math

n = 100000
start = time.clock()
result = math.factorial(n)
end = time.clock()

print(result)
print('100000! spent time: %s Seconds'%(end-start))

'''
n = 100000
start = time.clock()
result = math.factorial(n)
end = time.clock()

print(result)
print(' 10000 spent time: %s Seconds'%(end-start))
'''
