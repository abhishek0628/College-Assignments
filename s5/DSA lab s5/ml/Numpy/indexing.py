import numpy as np
a=np.array([1,2,3,4])
for i in range(len(a)):
    print(a[i])

m=np.array([[1,2,3,4],[9,3,1,8]])
for i in range(2):
    for j in range(4):
        print(m[i][j],end=" ")
    print(end=" ")

a = np.array([10, 20, 30, 40, 50])
a[1:4]    # [20 30 40]
a[:3]     # [10 20 30]
a[2:]     # [30 40 50]
a[::2]    # [10 30 50]
a[::-1]   # reverse array
m = np.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
])
m[0:2, :]
# [[1 2 3]
#  [4 5 6]]
m[:, 1]
# [2 5 8]
m[0:2, 1:3]
# [[2 3]
#  [5 6]]