import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# -------------------------------
# PARAMETERS
# -------------------------------
L = 1.0              # Thickness of heat shield
nx = 60              # Number of spatial points
dx = L / nx

alpha = 0.005        # Thermal diffusivity (LOW = good insulation)
dt = 0.0005          # Time step
nt = 300             # Number of time steps

# Stability condition
r = alpha * dt / dx**2

# -------------------------------
# INITIAL CONDITIONS
# -------------------------------
T = np.zeros(nx)

# Boundary conditions
T[0] = 1200      # Outer surface temperature (very hot)
T[-1] = 0        # Inner surface (cool)

# Store results
results = []

# -------------------------------
# FINITE DIFFERENCE METHOD
# -------------------------------
for t in range(nt):
    T_new = T.copy()
    
    for i in range(1, nx - 1):
        T_new[i] = T[i] + r * (T[i+1] - 2*T[i] + T[i-1])
    
    # Apply boundary conditions
    T_new[0] = 1200
    T_new[-1] = 0
    
    T = T_new
    results.append(T.copy())

# -------------------------------
# PLOT STATIC GRAPHS
# -------------------------------
x = np.linspace(0, L, nx)

plt.figure()
for i in range(0, nt, 60):
    plt.plot(x, results[i], label=f"t={i}")

plt.xlabel("Depth (x)")
plt.ylabel("Temperature")
plt.title("Heat Distribution in Spacecraft Heat Shield")
plt.legend()
plt.grid()
plt.show()

# -------------------------------
# ANIMATION (MOVING GRAPH)
# -------------------------------
fig, ax = plt.subplots()
line, = ax.plot(x, results[0])

ax.set_xlim(0, L)
ax.set_ylim(0, 1200)
ax.set_xlabel("Depth (x)")
ax.set_ylabel("Temperature")
ax.set_title("Heat Penetration Over Time")

def update(frame):
    line.set_ydata(results[frame])
    ax.set_title(f"Heat Penetration (Time step = {frame})")
    return line,

ani = animation.FuncAnimation(fig, update, frames=nt, interval=40)

plt.show()