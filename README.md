# Automatic Reverse Car Parking Alarm Sensor

An Arduino-based parking assistance prototype that uses an ultrasonic distance sensor to measure the space behind a vehicle and gives the driver an audible warning as an obstacle gets closer.

> **Project status:** Documentation and starter project structure. The GitHub repository was empty when this documentation was added. The hardware list, pin mapping, and example code below describe a common HC-SR04 + Arduino implementation. Verify them against your physical circuit before wiring or powering the project.

## Overview

Parking in a tight space can be difficult because the driver may not be able to see objects behind the vehicle. This project demonstrates a simple distance-based warning system. An ultrasonic sensor measures the distance to an object, and a buzzer changes its alert behavior according to the measured distance.

## Objectives

- Measure the distance between the rear of a vehicle and an obstacle.
- Provide an audible warning when an obstacle is within a configurable range.
- Increase the warning rate as the obstacle gets closer.
- Demonstrate embedded systems, sensor interfacing, and basic real-time feedback.

## How It Works

1. The ultrasonic sensor sends a short trigger pulse.
2. The sensor emits an ultrasonic burst and listens for its echo.
3. The Arduino measures the echo time and calculates the approximate distance.
4. The program compares the distance with warning thresholds.
5. The buzzer sounds at different rates to indicate proximity.

The example uses the speed-of-sound approximation embedded in the sketch: distance in centimetres is approximately echo duration in microseconds divided by 58.

## Hardware Requirements

| Component | Purpose |
|---|---|
| Arduino Uno or compatible 5 V board | Reads the sensor and controls the alert |
| HC-SR04 ultrasonic sensor | Measures obstacle distance |
| Piezo buzzer (active buzzer recommended for this example) | Produces audible alerts |
| Breadboard and jumper wires | Circuit connections |
| USB cable / suitable regulated supply | Powers the prototype |
| Optional LED and current-limiting resistor | Visual status indication |

**Vehicle installation note:** This is a low-voltage educational prototype, not a certified automotive safety device. Do not connect it directly to a vehicle electrical system. Automotive environments can contain voltage transients, noise, moisture, and vibration; a real installation requires suitable automotive-rated power conditioning, protection, enclosure, mounting, and validation.

## Example Wiring (Arduino Uno)

The pin assignments below match the example sketch in `arduino/parking_alarm/parking_alarm.ino`.

| HC-SR04 / Buzzer | Arduino Uno |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | Digital pin 9 |
| HC-SR04 ECHO | Digital pin 10 |
| Buzzer positive (+) | Digital pin 6 |
| Buzzer negative (-) | GND |

Use a buzzer whose current is within the Arduino pin's safe output capability. Use a transistor driver and suitable resistor/diode arrangement where required by the buzzer specification. Check the component datasheets and board limits before connecting.

## Alert Behavior in the Example

Thresholds are configurable constants in the sketch.

| Measured distance | Example alert |
|---|---|
| More than 150 cm | No alert |
| 101–150 cm | Slow beep |
| 51–100 cm | Medium-rate beep |
| 21–50 cm | Fast beep |
| 20 cm or less | Continuous alert |

These are demonstration thresholds only. Tune them for the sensor, mounting position, and intended test environment. Ultrasonic readings can be unreliable for angled, soft, narrow, or irregular surfaces.

## Software Requirements

- Arduino IDE 2.x (or a compatible Arduino build environment)
- Arduino Uno or compatible board support package
- No external Arduino library is required by the example sketch; it uses the built-in `pulseIn()`, `digitalWrite()`, and `tone()` functions.

## Setup and Run

1. Install the Arduino IDE.
2. Connect the HC-SR04 and buzzer using the pin table above, with power disconnected while wiring.
3. Open `arduino/parking_alarm/parking_alarm.ino`.
4. Select the correct board (for example, Arduino Uno) and serial port.
5. Upload the sketch.
6. Open Serial Monitor at **9600 baud** to see distance readings and status messages.
7. Test with a flat object in a clear area, moving it slowly toward and away from the sensor.

## Testing Checklist

- [ ] Confirm VCC and GND connections before powering the board.
- [ ] Confirm the sensor's TRIG and ECHO pins match the sketch.
- [ ] Confirm a stable distance is reported when no object is nearby.
- [ ] Test readings at several measured distances using a ruler.
- [ ] Confirm the buzzer is silent outside the warning range.
- [ ] Confirm the alert rate increases as the obstacle approaches.
- [ ] Test timeout / out-of-range behavior.
- [ ] Repeat tests with different object shapes and angles.
- [ ] Check that the sensor is firmly mounted and does not vibrate.

## Troubleshooting

| Issue | Things to check |
|---|---|
| No distance readings / timeout | Check sensor power, GND, TRIG/ECHO wiring, and sensor orientation. |
| Distance readings jump | Keep the sensor stable, avoid angled surfaces, and take multiple readings in a less noisy environment. |
| Buzzer does not sound | Check buzzer polarity/type, pin 6 wiring, and whether the buzzer needs a driver. |
| Buzzer sounds continuously | Check for a very close object, incorrect wiring, or an invalid sensor reading. |
| Arduino resets | Check power stability and ensure the buzzer load is not being driven directly beyond pin limits. |

## Repository Structure

```text
Automatic-Reverse-Car-Parking-Alarm-Sensor/
├── README.md
├── LICENSE
├── .gitignore
├── docs/
│   ├── COMPONENTS_AND_WIRING.md
│   └── TESTING.md
└── arduino/
    └── parking_alarm/
        └── parking_alarm.ino
```

## Limitations and Safety

- This prototype is intended for learning and tabletop testing.
- A single ultrasonic sensor has blind spots and may not detect every object.
- Water, dirt, temperature, mounting angle, object shape, and other nearby sensors can affect readings.
- Never rely on this prototype as the only means of checking behind a vehicle. Always use mirrors, cameras, direct observation, and safe driving practices.
- Do not install the prototype in a road vehicle without automotive engineering review and appropriate electrical/mechanical protection.

## Future Enhancements

- Add a display to show the measured distance.
- Add multiple sensors to reduce blind spots.
- Add filtering and sensor-fault detection.
- Add adjustable thresholds and volume control.
- Design an automotive-protected power supply and weather-resistant enclosure.
- Validate performance under realistic environmental conditions.

## Author

**Venkat Kishore**  
GitHub: [@Venkatakishore125](https://github.com/Venkatakishore125)

---

If your actual build uses a different microcontroller, sensor, display, or buzzer, update the wiring table and sketch to match that hardware.
