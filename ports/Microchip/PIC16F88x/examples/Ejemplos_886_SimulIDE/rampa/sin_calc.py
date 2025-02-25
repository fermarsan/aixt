import numpy as np

t = np.linspace(0, 2*np.pi, 35)

yy = np.int32((np.sin(t) +1)*127.99)

for y in yy:
    print(y, end=', ')
