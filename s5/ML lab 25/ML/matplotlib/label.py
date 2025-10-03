# import matplotlib.pyplot as plt
# import numpy as np
# x=np.array([1,2,3,4,5])
# y=np.array([6,7,8,9,10])
# plt.xlabel("x-axis")
# plt.ylabel("y-axis")
# plt.title("demo")
# plt.plot(x,y)
# plt.show()

import numpy as np
import matplotlib.pyplot as plt

x = np.array([80, 85, 90, 95, 100, 105, 110, 115, 120, 125])
y = np.array([240, 250, 260, 270, 280, 290, 300, 310, 320, 330])

font1 = {'family':'serif','color':'blue','size':20}
font2 = {'family':'serif','color':'darkred','size':15}

plt.title("Sports Watch Data", fontdict = font1)
plt.xlabel("Average Pulse", fontdict = font2)
plt.ylabel("Calorie Burnage", fontdict = font2)

plt.plot(x, y)
# plt.grid()
plt.grid(color = 'green', linestyle = '--', linewidth = 0.5)
plt.show()