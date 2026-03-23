# 🐼 Pandas Series - Complete One File Cheat Sheet

import pandas as pd
import numpy as np

# ================================

# 🔹 1. Creating Series

# ================================

s1 = pd.Series([10, 20, 30])
s2 = pd.Series([10, 20, 30], index=["a", "b", "c"])
s3 = pd.Series({"x": 100, "y": 200})

print("Create:\n", s1, "\n", s2, "\n", s3)

# ================================

# 🔹 2. Accessing Elements

# ================================

print("Access by index:", s2["a"])
print("Access by position:", s1[0])

# ================================

# 🔹 3. Attributes

# ================================

print("Index:", s1.index)
print("Values:", s1.values)
print("Data type:", s1.dtype)
print("Shape:", s1.shape)
print("Size:", s1.size)

# ================================

# 🔹 4. Mathematical Operations

# ================================

print("Add:", s1 + 5)
print("Multiply:", s1 * 2)

s4 = pd.Series([1, 2, 3])
s5 = pd.Series([4, 5, 6])
print("Series + Series:\n", s4 + s5)

# ================================

# 🔹 5. Index Alignment

# ================================

s6 = pd.Series([1, 2], index=["a", "b"])
s7 = pd.Series([3, 4], index=["b", "c"])
print("Alignment:\n", s6 + s7)

# ================================

# 🔹 6. Filtering

# ================================

print("Filter >15:\n", s1[s1 > 15])

# ================================

# 🔹 7. Missing Data

# ================================

s8 = pd.Series([1, np.nan, 3])
print("Is null:\n", s8.isnull())
print("Drop NA:\n", s8.dropna())
print("Fill NA:\n", s8.fillna(0))

# ================================

# 🔹 8. Apply Function

# ================================

print("Apply square:\n", s1.apply(lambda x: x**2))

# ================================

# 🔹 9. Sorting

# ================================

print("Sort values:\n", s1.sort_values(ascending=False))
print("Sort index:\n", s2.sort_index())

# ================================

# 🔹 10. Unique / Value Counts

# ================================

s9 = pd.Series([1, 2, 2, 3, 3, 3])
print("Unique:", s9.unique())
print("Value counts:\n", s9.value_counts())

# ================================

# 🔹 11. String Operations

# ================================

s10 = pd.Series(["apple", "banana", "cherry"])
print("Upper:\n", s10.str.upper())
print("Contains 'a':\n", s10.str.contains("a"))

# ================================

# 🔹 12. Statistical Operations

# ================================

print("Mean:", s1.mean())
print("Sum:", s1.sum())
print("Max:", s1.max())
print("Min:", s1.min())
print("Std:", s1.std())

# ================================

# 🔹 13. Index Operations

# ================================

s11 = s2.copy()
s11.index = ["p", "q", "r"]
print("New index:\n", s11)

# ================================

# 🔹 14. Boolean Operations

# ================================

print("Greater than 15:\n", s1 > 15)

# ================================

# 🔹 15. Combine Series

# ================================

print("Add with fill value:\n", s6.add(s7, fill_value=0))

# ================================

# 🔹 16. Conversion

# ================================

print("To list:", s1.tolist())
print("To numpy:", s1.to_numpy())
print("To DataFrame:\n", s1.to_frame())

# ================================

# 🔹 17. Slicing

# ================================

print("Slice:\n", s1[0:2])

# ================================

# 🔹 18. Rename

# ================================

s12 = s1.rename("Numbers")
print("Renamed:\n", s12)

# ================================

# 🔹 19. Check Conditions

# ================================

print("All >5:", s1.gt(5).all())
print("Any >25:", s1.gt(25).any())

# ================================

# 🔹 20. Head / Tail

# ================================

print("Head:\n", s1.head())
print("Tail:\n", s1.tail())

# ================================

# 🔹 END

# ================================

print("Done with Series operations 🚀")
