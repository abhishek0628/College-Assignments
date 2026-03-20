import numpy as np
arr=np.array([1,2,3,4])
arr2=np.array([[1,2,3],[5,6,7]])
print(arr)

# properties
shape=arr2.shape # output:(rows,column),dimension
ndim=arr2.ndim #output:Number of dimensions (axes)
size=arr.size()#output:total number of element
dtype=arr.dtype #output:data type
itemsize=arr.itemsize #output:Size (in bytes) of each element
nbytes=arr.nbytes #output:Total memory used by the array
transpose=arr2.T#output:transpose of matrix
flat=arr.flat #output:Returns a 1D iterator over all elements
data=arr.data #output:Low-level memory buffer
print(shape)