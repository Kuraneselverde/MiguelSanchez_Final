import numpy as np
import matplotlib.pyplot as plt

temp = np.loadtxt("datos.dat")
lon=len(temp)
x=temp[:,0]
y=temp[:,1]


plt.figure(figsize=(10,5))
plt.plot(x,y)
plt.savefig("SanchezMiguel_final_15.pdf")