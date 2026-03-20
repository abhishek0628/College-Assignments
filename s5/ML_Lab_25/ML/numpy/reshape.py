import numpy as np
a=np.array([1,2,3,4,5,6])
a.reshape(2,-1)
a.reshape(2,3)# rows*column=no of element
print(a)