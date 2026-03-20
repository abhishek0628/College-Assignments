import numpy as np

a = np.array([1, 2, 3, 4])
#1. Basic Aggregation Functions
np.sum(a)    # 10
np.mean(a)   # 2.5
np.min(a)    # 1
np.max(a)    # 4
np.std(a)    # standard deviation
np.var(a)    # variance

#2. Axis-Based Operations
b = np.array([[1,2,3],
              [4,5,6]])
np.sum(b, axis=0)   # [5 7 9] (column-wise)
np.sum(b, axis=1)   # [6 15]  (row-wise)

c = np.array([1,4,9])
#3. Element-wise Math Functions
np.sqrt(c)     # [1. 2. 3.]
np.exp(c)      # e^x
np.log(c)      # natural log
np.abs(c)      # absolute value
np.sin(c)
np.cos(c)
np.tan(c)

#5. Rounding Functions
d = np.array([1.2, 2.7, 3.5])

np.round(d)   # [1. 3. 4.]
np.floor(d)   # [1. 2. 3.]
np.ceil(d)    # [2. 3. 4.]

#6. Cumulative Functions
e = np.array([1,2,3,4])

np.cumsum(e)   # [1 3 6 10]
np.cumprod(e)  # [1 2 6 24]

#7. Statistical Functions
np.median(a)
np.percentile(a, 50)

#8. Comparison Functions
f = np.array([1,2,3])

f > 2     # [False False True]
f == 2    # [False True False]