import numpy as np

data = np.array([[2,-1,2,-2,-2,1],
                 [1,1,-2,-1,2,-1],
                 [-1,-1,2,1,-2,1]])

Cn = np.identity(6) - 1/6*np.ones(6)

E = 1/6 * data@Cn@np.transpose(data)
avg = 1/6 * np.ones([1,6]) @ np.transpose(data)

print(E)
print(avg)