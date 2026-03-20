import numpy as np

#Matrix Representation
A = np.array([[1, 2],
              [3, 4]])

#Transpose
A.T
# [[1 3]
#  [2 4]]

#Matrix Multiplication
np.dot(A, A)
# or
A @ A

#Determinant
np.linalg.det(A)

#Inverse
np.linalg.inv(A)

#Eigenvalues & Eigenvectors
np.linalg.eig(A)

#Solving Linear Equations
# Ax = b
A = np.array([[2, 3],
              [1, 2]])

b = np.array([5, 3])

x = np.linalg.solve(A, b)

#Norms (Vector Length)
np.linalg.norm(A)