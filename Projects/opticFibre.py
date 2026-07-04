import matplotlib.pyplot as plt
import numpy as np
from matplotlib.lines import Line2D

plt.style.use('dark_background')

# -----------------------------
# Refractive indices
# -----------------------------
n1 = 1.5
n2 = 1.45

acceptance_angle = np.degrees(np.arcsin(np.sqrt(n1**2 - n2**2)))
critical_angle = np.degrees(np.arcsin(n2 / n1))

print(f"Acceptance Angle ≈ {acceptance_angle:.2f}°")
print(f"Critical Angle ≈ {critical_angle:.2f}°")

# -----------------------------
# USER INPUT
# -----------------------------
fiber_type = input("Enter fiber type (step / graded): ").lower()
base_angle_deg = float(input("Enter launch angle: "))

# -----------------------------
# Fiber parameters
# -----------------------------
core_radius = 1.0
cladding_radius = 2.0
ds = 0.05
steps = 2000

# -----------------------------
# Wavelength + Modes
# -----------------------------
wavelength = 0.5

V = (2 * np.pi * core_radius / wavelength) * np.sqrt(n1**2 - n2**2)

if fiber_type == "step":
    modes = int(V**2 / 2)
else:
    modes = int(V**2 / 4)

# -----------------------------
# Loss
# -----------------------------
reflection_loss = 0.97
scattering_loss = 0.999

# -----------------------------
# Reflection Counter
# -----------------------------
total_reflections = 0

# -----------------------------
# Beam setup (WITH GAP)
# -----------------------------
num_rays = 7
angles = np.linspace(base_angle_deg - 5, base_angle_deg + 5, num_rays)

gap = 0.25
offsets = np.linspace(-gap, gap, num_rays)

ray_data = []

# -----------------------------
# Create rays
# -----------------------------
for i, angle_deg in enumerate(angles):

    angle = np.radians(angle_deg)

    if angle_deg <= acceptance_angle:
        ray_type = "Guided"
        color = "green"
    else:
        ray_type = "Misguided"
        color = "red"

    ray_data.append({
        "x": 0.0,
        "y": offsets[i],
        "dx": np.cos(angle),
        "dy": np.sin(angle),
        "type": ray_type,
        "color": color,
        "intensity": 1.0,
        "x_vals": [0.0],
        "y_vals": [offsets[i]],
        "escaped": False
    })

# Grazing ray
grazing_ray = {
    "x": 0.0,
    "y": gap + 0.2,
    "dx": np.cos(np.radians(base_angle_deg)),
    "dy": np.sin(np.radians(base_angle_deg)),
    "type": "Grazing",
    "color": "blue",
    "intensity": 1.0,
    "x_vals": [0.0],
    "y_vals": [gap + 0.2],
    "escaped": False,
    "parallel_mode": False
}

ray_data.append(grazing_ray)

# -----------------------------
# Plot setup
# -----------------------------
fig, ax = plt.subplots(figsize=(12, 6))
x_pipe = np.linspace(0, 30, 300)

legend_elements = [
    Line2D([0], [0], color='green', lw=3, label='Guided'),
    Line2D([0], [0], color='red', lw=3, label='Misguided'),
    Line2D([0], [0], color='blue', lw=3, label='Grazing')
]

plt.show(block=False)

# -----------------------------
# Simulation loop
# -----------------------------
for _ in range(steps):

    plt.cla()

    # Fiber
    ax.fill_between(x_pipe, core_radius, -core_radius, color='cyan', alpha=0.3)
    ax.fill_between(x_pipe, cladding_radius, core_radius, color='gray', alpha=0.2)
    ax.fill_between(x_pipe, -core_radius, -cladding_radius, color='gray', alpha=0.2)

    ax.axhline(core_radius, linestyle="--")
    ax.axhline(-core_radius, linestyle="--")

    # Info
    ax.text(1, 2.2, f"Critical Angle = {critical_angle:.2f}°", color="violet")
    ax.text(1, 2.0, f"Acceptance Angle = {acceptance_angle:.2f}°", color="lime")

    ax.text(20, 2.2, f"V = {V:.2f}", color="white")
    ax.text(20, 2.0, f"Modes ≈ {modes}", color="cyan")

    # 🔥 Reflection Counter Display
    ax.text(20, 1.8, f"Total Reflections = {total_reflections}", color="yellow")

    # Source
    ax.scatter(0, 0, color='yellow', edgecolors='white', s=80)

    for ray in ray_data:

        if not ray["escaped"]:

            x, y = ray["x"], ray["y"]
            dx, dy = ray["dx"], ray["dy"]

            if fiber_type == "step":

                x += dx * ds
                y += dy * ds

                if abs(y) >= core_radius:

                    if ray["type"] in ["Guided", "Grazing"]:

                        if ray["type"] == "Grazing":

                            if not ray["parallel_mode"]:
                                ray["parallel_mode"] = True
                                dx, dy = 1.0, 0.0
                                y = np.sign(y) * core_radius

                        else:
                            normal = np.array([0, np.sign(y)])
                            v = np.array([dx, dy])
                            v_reflected = v - 2 * np.dot(v, normal) * normal
                            dx, dy = v_reflected / np.linalg.norm(v_reflected)

                            ray["intensity"] *= reflection_loss
                            y = np.sign(y) * core_radius

                            # 🔥 COUNT REFLECTION
                            total_reflections += 1

                    else:
                        ray["escaped"] = True

            else:

                x += dx * ds
                y += dy * ds

                dy -= 0.02 * y

                norm = np.sqrt(dx**2 + dy**2)
                dx /= norm
                dy /= norm

                if abs(y) > cladding_radius:
                    ray["escaped"] = True

            ray["intensity"] *= scattering_loss

            ray["x"], ray["y"] = x, y
            ray["dx"], ray["dy"] = dx, dy

            ray["x_vals"].append(x)
            ray["y_vals"].append(y)

        # Draw ray
        I = ray["intensity"]
        linewidth = 1 + 4 * I
        alpha = max(0.2, I)

        ax.plot(ray["x_vals"], ray["y_vals"],
                color=ray["color"],
                linewidth=linewidth,
                alpha=alpha)

        ax.text(ray["x"], ray["y"] + 0.15,
                ray["type"], fontsize=7, color=ray["color"])

        ax.text(ray["x"], ray["y"] - 0.25,
                f"I={I:.2f}", fontsize=7, color=ray["color"])

    ax.legend(handles=legend_elements, loc='upper right')

    ax.set_xlim(-1, 30)
    ax.set_ylim(-2.5, 2.5)

    ax.set_title("LIGHT PROPAGATION THROUGH OPTICAL FIBER CABLE")

    ax.grid(color='white', alpha=0.1)

    plt.pause(0.001)

plt.show()