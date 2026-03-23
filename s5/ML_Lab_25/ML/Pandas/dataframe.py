# 🐼 Pandas DataFrame - Complete One File Cheat Sheet

import pandas as pd
import numpy as np

# ================================

# 🔹 1. Creating DataFrame

# ================================

df1 = pd.DataFrame({
"Name": ["Abhi", "Rahul", "Priya"],
"Marks": [90, 85, 88]
})

df2 = pd.DataFrame(np.random.randint(1, 100, (3, 3)), columns=["A", "B", "C"])

print("Create:\n", df1, "\n", df2)

# ================================

# 🔹 2. Inspecting Data

# ================================

print("Head:\n", df1.head())
print("Tail:\n", df1.tail())
print("Info:")
print(df1.info())
print("Describe:\n", df1.describe())
print("Shape:", df1.shape)
print("Columns:", df1.columns)

# ================================

# 🔹 3. Selecting Data

# ================================

print("Single column:\n", df1["Name"])
print("Multiple columns:\n", df1[["Name", "Marks"]])
print("Row (iloc):\n", df1.iloc[0])
print("Row (loc):\n", df1.loc[0])

# ================================

# 🔹 4. Filtering

# ================================

print("Marks > 85:\n", df1[df1["Marks"] > 85])

# ================================

# 🔹 5. Adding / Modifying Columns

# ================================

df1["Passed"] = df1["Marks"] > 40
df1["Marks"] = df1["Marks"] + 5
print("Modified:\n", df1)

# ================================

# 🔹 6. Dropping Data

# ================================

df_temp = df1.copy()
print("Drop column:\n", df_temp.drop("Passed", axis=1))
print("Drop row:\n", df_temp.drop(0))

# ================================

# 🔹 7. Missing Data

# ================================

df3 = pd.DataFrame({
"A": [1, np.nan, 3],
"B": [4, 5, np.nan]
})

print("Is null:\n", df3.isnull())
print("Drop NA:\n", df3.dropna())
print("Fill NA:\n", df3.fillna(0))

# ================================

# 🔹 8. Apply Function

# ================================

print("Apply:\n", df1["Marks"].apply(lambda x: x * 2))

# ================================

# 🔹 9. Sorting

# ================================

print("Sort by Marks:\n", df1.sort_values(by="Marks", ascending=False))

# ================================

# 🔹 10. GroupBy

# ================================

df4 = pd.DataFrame({
"Dept": ["IT", "HR", "IT", "HR"],
"Salary": [50000, 60000, 55000, 65000]
})

print("GroupBy:\n", df4.groupby("Dept")["Salary"].mean())

# ================================

# 🔹 11. Merge / Join

# ================================

df5 = pd.DataFrame({"ID": [1, 2], "Name": ["A", "B"]})
df6 = pd.DataFrame({"ID": [1, 2], "Marks": [90, 80]})

print("Merge:\n", pd.merge(df5, df6, on="ID"))

# ================================

# 🔹 12. Concatenate

# ================================

print("Concat:\n", pd.concat([df5, df6], axis=1))

# ================================

# 🔹 13. Pivot Table

# ================================

df7 = pd.DataFrame({
"Region": ["East", "West", "East"],
"Sales": [100, 200, 150]
})

print("Pivot:\n", pd.pivot_table(df7, values="Sales", index="Region"))

# ================================

# 🔹 14. Index Operations

# ================================

df1.set_index("Name", inplace=True)
print("Set index:\n", df1)

df1.reset_index(inplace=True)
print("Reset index:\n", df1)

# ================================

# 🔹 15. String Operations

# ================================

df1["Name"] = df1["Name"].str.upper()
print("Upper:\n", df1)

# ================================

# 🔹 16. Statistical Operations

# ================================

print("Mean:\n", df1["Marks"].mean())
print("Sum:\n", df1["Marks"].sum())

# ================================

# 🔹 17. Iteration (avoid if possible)

# ================================

for index, row in df1.iterrows():
 print(index, row["Name"], row["Marks"])

# ================================

# 🔹 18. Export Data

# ================================

df1.to_csv("output.csv", index=False)

# ================================

# 🔹 END

# ================================

print("Done with DataFrame operations 🚀")
