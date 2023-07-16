import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backend_bases import LocationEvent
from matplotlib.patches import Circle, Rectangle

d = 175
A = np.array([-d, d])
B = np.array([d, d])
C = np.array([d, -d])
D = np.array([-d, -d])
Ps = {"A": A, "B": B, "C": C, "D": D}
O = np.array([0, 0])
RW, RH = 10., 10.

fig, ax = plt.subplots()
def draw_target():
    ax.set_aspect(1.)
    ax.scatter(A[0], A[1], 30, "r", "o")
    ax.scatter(B[0], B[1], 30, "r", "o")
    ax.scatter(C[0], C[1], 30, "r", "o")
    ax.scatter(D[0], D[1], 30, "r", "o")
    ax.hlines(0, -d, d, "gray", "dashdot")
    ax.vlines(0, -d, d, "gray", "dashdot")
    for i in range(11):
        r = i * 15
        arto = Circle(O, i * 15, fill=False)
        ax.add_artist(arto)

def dist(p1:np.ndarray, p2:np.ndarray):
    return np.sqrt(np.sum(np.power(p2 - p1, 2)))

def onclick(event:LocationEvent):
    if event.inaxes:
        P = np.array([event.xdata, event.ydata])
        arto = Rectangle(xy=[P[0] + RW / 2, P[1] - RH / 2], width=RW, height=RH, angle=45, facecolor="g")
        ax.add_artist(arto)
        plt.draw()
        for name, p in Ps.items():
            print(f"to {name}:{dist(p, P)}")
        print()
    else:
        ax.cla()
        draw_target()
        print("clear")
        plt.draw()

cid = fig.canvas.mpl_connect('button_press_event', onclick)
draw_target()
plt.show()