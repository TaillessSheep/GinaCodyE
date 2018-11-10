import serial
import serial.tools.list_ports
import time
import flask


def get_open_comports():
    ports = [
        port for port in serial.tools.list_ports.comports() if port[2] != 'n/a'
    ]
    return ports


port = get_open_comports()[0].device
print(port)
arduino = serial.Serial(port, 9600, timeout=1)

# pos = 1000

# def move_forward():
#     global pos
#     nextPos = pos + 200
#     pos = nextPos if nextPos <= 2000 else pos
#     print(pos)
#     # arduino.flush()
#     arduino.write(str.encode(str(pos) + '\n'))
#     time.sleep(1000)

# while True:
#     try:
#         keyboard.on_press_key('d', lambda x: move_forward())
#         # if keyboard.is_pressed('d'):

#         # elif keyboard.is_pressed('a'):
#         #     nextPos = pos - 200
#         #     pos = nextPos if nextPos >= 1000 else pos
#         #     print(pos)
#         #     # arduino.flush()
#         #     arduino.write(str.encode(str(pos) + '\n'))
#     except:
#         break

app = flask.Flask(__name__)


@app.route("/")
def index():
    return flask.render_template("app.html")


# Automatic controls
@app.route("/mousedown_btn_pitch_up")
def mousedown_btn_pitch_up():
    print("Forward 1")
    arduino.write(str.encode(str(1) + '\n'))
    time.sleep(0.1)
    arduino.write(str.encode(str(100) + '\n'))
    return ""


@app.route("/mousedown_btn_pitch_down")
def mousedown_btn_pitch_down():
    print("Reverse 2")
    arduino.write(str.encode(str(2) + '\n'))
    time.sleep(0.1)
    arduino.write(str.encode(str(100) + '\n'))
    return ""


@app.route("/mousedown_btn_roll_left")
def mousedown_btn_roll_left():
    print("Left 3")
    arduino.write(str.encode(str(3) + '\n'))
    time.sleep(0.1)
    arduino.write(str.encode(str(100) + '\n'))
    return ""


@app.route("/mousedown_btn_roll_right")
def mousedown_btn_roll_right():
    print("Right 4")
    arduino.write(str.encode(str(4) + '\n'))
    time.sleep(0.1)
    arduino.write(str.encode(str(100) + '\n'))
    return ""


@app.route("/mousedown_btn_claw_open")
def mousedown_btn_claw_open():
    print("mousedown_btn_claw_open")
    return ""


@app.route("/mousedown_btn_claw_close")
def mousedown_btn_claw_close():
    print("mousedown_btn_claw_close")
    return ""


@app.route("/mousedown_btn_arm_up")
def mousedown_btn_arm_up():
    print("mousedown_btn_arm_up")
    return ""


@app.route("/mousedown_btn_arm_down")
def mousedown_btn_arm_down():
    print("mousedown_btn_arm_down")
    return ""


@app.route("/mousedown_btn_arm_left")
def mousedown_btn_arm_left():
    print("mousedown_btn_arm_left")
    return ""


@app.route("/mousedown_btn_arm_right")
def mousedown_btn_arm_right():
    print("mousedown_btn_arm_right")
    return ""


@app.route("/mousedown_btn_arm_back")
def mousedown_btn_arm_back():
    print("mousedown_btn_arm_back")
    return ""


@app.route("/mousedown_btn_arm_forward")
def mousedown_btn_arm_forward():
    print("mousedown_btn_arm_forward")
    return ""


# Manual controls
@app.route("/mousedown_btn_motor1_ccw")
def mousedown_btn_motor1_ccw():
    print("mousedown_btn_motor1_ccw")

    #
    return ""


@app.route("/mousedown_btn_motor1_cw")
def mousedown_btn_motor1_cw():
    print("/mousedown_btn_motor1_cw")

    #
    return ""


@app.route("/mousedown_btn_motor2_ccw")
def mousedown_btn_motor2_ccw():
    print("mousedown_btn_motor2_ccw")

    #
    return ""


@app.route("/mousedown_btn_motor2_cw")
def mousedown_btn_motor2_cw():
    print("mousedown_btn_motor2_cw")

    #
    return ""


@app.route("/mousedown_btn_motor3_ccw")
def mousedown_btn_motor3_ccw():
    print("mousedown_btn_motor3_ccw")

    #
    return ""


@app.route("/mousedown_btn_motor3_cw")
def mousedown_btn_motor3_cw():
    print("mousedown_btn_motor3_cw")

    #
    return ""


@app.route("/mousedown_btn_motor4_ccw")
def mousedown_btn_motor4_ccw():
    print("mousedown_btn_motor4_ccw")

    #
    return ""


@app.route("/mousedown_btn_motor4_cw")
def mousedown_btn_motor4_cw():
    print("mousedown_btn_motor4_cw")

    #
    return ""


@app.route("/mousedown_btn_motor5_ccw")
def mousedown_btn_motor5_ccw():
    print("mousedown_btn_motor5_ccw")

    #
    return ""


@app.route("/mousedown_btn_motor5_cw")
def mousedown_btn_motor5_cw():
    print("mousedown_btn_motor5_cw")

    #
    return ""


@app.route("/mousedown_btn_motor6_ccw")
def mousedown_btn_motor6_ccw():
    print("mousedown_btn_motor6_ccw")

    #
    return ""


@app.route("/mousedown_btn_motor6_cw")
def mousedown_btn_motor6_cw():
    print("mousedown_btn_motor6_cw")

    #
    return ""


app.run(
    debug=True
)  # add param `host= '0.0.0.0'` if you want to run on your machine's IP address