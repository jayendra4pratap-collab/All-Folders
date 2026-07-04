import turtle
import numpy as np
import matplotlib.pyplot as plt

WINDOW_WIDTH = 900
WINDOW_HEIGHT = 650
GAUSSIAN_SIGMA = 70

def setup_screen():
    screen = turtle.Screen()
    screen.title("Hall Effect Sensor Simulator (Final)")
    screen.setup(width=WINDOW_WIDTH, height=WINDOW_HEIGHT, startx=50, starty=50)
    screen.bgcolor("white")
    screen.tracer(0)
    return screen

def draw_title():
    t = turtle.Turtle()
    t.hideturtle()
    t.penup()
    t.goto(0, 280)
    t.write("Hall Effect Sensor Simulation",
            align="center", font=("Arial", 16, "bold"))

def draw_magnetic_field():
    field = turtle.Turtle()
    field.hideturtle()
    field.color("lightgray")

    for x in range(-400, 401, 40):
        field.penup()
        field.goto(x, -260)
        field.pendown()
        field.goto(x, 260)

    field.penup()
    field.goto(250, -280)
    field.color("black")
    field.write("Magnetic Field Lines", align="center", font=("Arial", 11, "bold"))

def create_sensor():
    sensor = turtle.Turtle()
    sensor.shape("square")
    sensor.color("red")
    sensor.shapesize(2, 2)
    sensor.penup()
    sensor.goto(0, 0)
    return sensor

def create_object(mode):
    obj = turtle.Turtle()
    obj.shape("square")
    obj.color("black")
    obj.penup()

    if mode == "linear":
        obj.goto(250, 0)
    else:
        obj.goto(100, 0)

    return obj

def create_label(x, y):
    t = turtle.Turtle()
    t.hideturtle()
    t.penup()
    t.goto(x, y)
    return t

class MotionController:
    def __init__(self, obj, sensor, info_label, mode, sensor_label, object_label):
        self.obj = obj
        self.sensor = sensor
        self.info_label = info_label
        self.mode = mode
        self.sensor_label = sensor_label
        self.object_label = object_label

        self.angle = 0

        plt.ion()
        self.fig, self.ax = plt.subplots()

        try:
            self.fig.canvas.manager.window.wm_geometry("+1000+50")
        except:
            pass

    def compute_output(self):
        if self.mode == "linear":
            position = self.obj.xcor() - self.sensor.xcor()
            output = np.exp(-(position ** 2) / (2 * GAUSSIAN_SIGMA ** 2))
            active = abs(position) < 60
            current = position

        else:
            angle = self.angle % 360
            output = np.cos(np.radians(angle))   
            active = abs(output) > 0.3
            current = angle

        return current, output, active

  
    def update(self):
        current, output, active = self.compute_output()

    
        self.sensor.color("green" if active else "red")

        self.info_label.clear()
        self.info_label.write(
            f"{'Position' if self.mode=='linear' else 'Angle'}: {current:.1f}\n"
            f"Voltage: {output:.2f}",
            align="left", font=("Arial", 12, "normal")
        )

        self.sensor_label.clear()
        self.sensor_label.goto(self.sensor.xcor(), self.sensor.ycor() - 40)
        self.sensor_label.write("Hall Sensor",
                                align="center", font=("Arial", 10, "bold"))

        self.object_label.clear()
        self.object_label.goto(self.obj.xcor(), self.obj.ycor() - 40)
        self.object_label.write("Magnet",
                                align="center", font=("Arial", 10, "bold"))

     
        self.ax.clear()

        if self.mode == "linear":
            x = np.linspace(-400, 400, 400)
            y = np.exp(-(x**2) / (2 * GAUSSIAN_SIGMA**2))
            self.ax.plot(x, y)

           
            self.ax.scatter(current, output)

            self.ax.set_title("Gaussian Response (Linear Motion)")
            self.ax.set_xlabel("Position")

        else:
            x = np.linspace(0, 360, 360)
            y = np.cos(np.radians(x))
            self.ax.plot(x, y)

            self.ax.scatter(current, output)

            self.ax.set_title("Sinusoidal Response (Rotary Motion)")
            self.ax.set_xlabel("Angle")

        self.ax.set_ylabel("Voltage")
        self.ax.grid(True)

        plt.draw()
        plt.pause(0.01)

    def move_left(self):
        if self.mode == "linear":
            self.obj.setx(self.obj.xcor() - 15)
        else:
            self.angle += 5
            self.obj.setheading(self.angle)
        self.update()

    def move_right(self):
        if self.mode == "linear":
            self.obj.setx(self.obj.xcor() + 15)
        else:
            self.angle -= 5
            self.obj.setheading(self.angle)
        self.update()

def main():
    screen = setup_screen()
    draw_title()
    draw_magnetic_field()

    choice = screen.textinput("Mode Selection", "1: Linear\n2: Rotary")
    mode = "linear" if choice == "1" else "rotary"

    sensor = create_sensor()
    obj = create_object(mode)

    info_label = create_label(150, 220)
    sensor_label = create_label(0, 0)
    object_label = create_label(0, 0)

    controller = MotionController(obj, sensor, info_label,
                                  mode, sensor_label, object_label)

    def update_loop():
        screen.update()
        screen.ontimer(update_loop, 20)

    screen.listen()
    screen.onkey(controller.move_left, "Left")
    screen.onkey(controller.move_right, "Right")

    update_loop()
    screen.mainloop()

if __name__ == "__main__":
    main()