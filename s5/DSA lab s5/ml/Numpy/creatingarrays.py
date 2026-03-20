import numpy as np
#1. From Python Lists
a=np.array([1,2,3,4,5])
b = np.array([[1, 2, 3], [4, 5, 6]])

#zeros
c=np.zeros((2,3))
print(c)

#one array
d=np.ones((3, 2))
print(d)

#identity matrix
e=np.eye(3)
print(e)

#5. Range-Based Arrays
f=np.arange(0,10,2)
print(f)

#6. Evenly Spaced Values
g=np.linspace(0,1,5)
print(g)

#7. Random Arrays
h=np.random.rand(2, 3)
i=np.random.randint(1, 10, (2, 3))
print(h)

#8. Custom Filled Arrays
j=np.full((2, 2), 7)
print(j)