import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mlt

t=[]
for i in range (1000):
  x = np.linspace(0.0,np.pi/4,i+2)
  y = 1/(1+x*x)
  dx = x[1] - x[0]
  t.append(np.sum(y*dx)-1)
  fArea = np.sum(y*dx)
  #print("Integral area:",i+2,fArea)
#print(t);
plt.plot(t);
plt.show()
