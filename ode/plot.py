import numpy as np 


d = np.loadtxt("output.txt")

import matplotlib.pyplot as plt 

plt.plot(d[:,0])
plt.plot(d[:,1])
plt.show()