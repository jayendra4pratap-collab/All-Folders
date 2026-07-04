import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import tkinter as tk
from tkinter import simpledialog

# ---------------- FIBER PARAMETERS ----------------
fiber_length = 100
fiber_height = 10

# Refractive indices
n_core = 1.5
n_cladding = 1.3

# ---------------- GET USER INPUT ----------------
root = tk.Tk()
root.withdraw()

angle_deg = simpledialog.askfloat("Input", "Enter angle (degrees):", minvalue=1, maxvalue=89)
if angle_deg is None:
    exit()

angle = np.radians(angle_deg)

# ---------------- CRITICAL ANGLE ----------------
critical_angle = np.arcsin(n_cladding / n_core)

if angle < critical_angle:
    print("⚠️ Light will escape (No Total Internal Reflection)")
else:
    print("✅ Total Internal Reflection occurs")

# ---------------- INITIAL POSITION ----------------
x = 0
y = fiber_height / 2

dx = 0.5

x_data = []
y_data = []

# ---------------- SETUP PLOT ----------------
fig, ax = plt.subplots()
ax.set_xlim(0, fiber_length)
ax.set_ylim(0, fiber_height)
ax.set_title("Optical Fiber Light Propagation (Animated)")
ax.set_xlabel("Fiber Length")
ax.set_ylabel("Fiber Core")

# Fiber boundaries
ax.hlines([0, fiber_height], xmin=0, xmax=fiber_length)

line, = ax.plot([], [], lw=2)

# ---------------- ANIMATION FUNCTION ----------------
def update(frame):
    global x, y, angle

    x += dx
    y += dx * np.tan(angle)

    # Reflection logic
    if y >= fiber_height:
        y = 2 * fiber_height - y
        angle = -angle
    elif y <= 0:
        y = -y
        angle = -angle

    # Escape condition (if not TIR)
    if abs(angle) < critical_angle:
        return line,

    x_data.append(x)
    y_data.append(y)

    line.set_data(x_data, y_data)
    return line,

# ---------------- RUN ANIMATION ----------------
ani = FuncAnimation(fig, update, frames=500, interval=30)

plt.show()
