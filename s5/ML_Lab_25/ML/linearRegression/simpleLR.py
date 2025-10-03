import numpy as np
import matplotlib.pyplot as plt
x=np.array([1,2,3,4,5,6])
y=np.array([2,4,5,2,6,7])
x_mean=np.mean(x)
y_mean=np.mean(y)
numerator=np.sum((x-x_mean)*(y-y_mean))
denomenator=np.sum((x-x_mean)**2)
w=numerator/denomenator
b=y_mean-w*x_mean
y_pred=w*x+b
plt.scatter(x,y)
plt.plot(x,y_pred,color="r")
plt.show()