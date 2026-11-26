# Project Report: Automatic Reverse Car Parking Alarm Sensor

## 1. Introduction

The Automatic Reverse Car Parking Alarm Sensor is an embedded-system project intended to assist a driver while reversing a vehicle. It detects obstacles behind the vehicle using ultrasonic sensing and gives an audible warning through a buzzer. The alert pattern changes according to the measured distance, helping the driver understand when an object is getting closer.

This report describes the project concept and a reference implementation. The original repository did not contain the team's original circuit, source code, photographs or measured results. Therefore, the Arduino Uno and HC-SR04 details in the example implementation should be treated as a reference until they are checked against the actual prototype.

## 2. Problem Statement

While reversing, the driver may have limited visibility of objects located behind the vehicle. Estimating the remaining distance can be difficult, particularly in narrow parking spaces. A simple distance-sensing and audible-alert system can provide an additional indication of nearby obstacles.

## 3. Project Objectives

- Detect obstacles in the sensor's detection area.
- Estimate the distance to a detected obstacle.
- Provide audible alerts at selected distance ranges.
- Increase the alert frequency as the obstacle gets closer.
- Develop and test an embedded-system prototype.
- Plan and coordinate the work as a team.

## 4. Proposed System

The system consists of an ultrasonic sensor, a microcontroller and a buzzer module. The sensor measures the time taken for an ultrasonic pulse to travel to an object and return as an echo. The controller converts this time into an approximate distance and selects an alert pattern based on configured thresholds.

## 5. Working Principle

1. The controller sends a trigger pulse to the ultrasonic sensor.
2. The sensor transmits an ultrasonic signal.
3. The signal reflects from an obstacle and returns to the sensor.
4. The controller measures the echo duration.
5. The distance is estimated using the speed of sound.
6. The controller compares the distance with warning thresholds.
7. The buzzer gives the selected audible alert.

## 6. Hardware and Software

### Suggested hardware for the reference circuit

- Arduino Uno or compatible microcontroller
- HC-SR04 ultrasonic distance sensor
- Active buzzer module
- Breadboard and jumper wires
- USB cable and regulated bench power

### Software and technologies

- Arduino IDE
- Embedded C/C++
- Ultrasonic distance measurement
- Project planning and management tools

Confirm the actual component models and quantities against the team's built circuit before using this list as a final bill of materials.

## 7. Reference Connections

| Component | Arduino Uno connection |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| Buzzer positive | D6 |
| Buzzer negative | GND |

These are the pin assignments used by the sample sketch in this repository. They are not a verified record of the original team circuit.

## 8. Example Alert Logic

The sample program uses adjustable distance ranges:

| Distance | Example alert |
|---|---|
| Above 150 cm | No alert |
| 101–150 cm | Slow beeping |
| 51–100 cm | Medium beeping |
| 21–50 cm | Fast beeping |
| 20 cm or less | Continuous tone |

These values are example settings. The team should record the thresholds and results from its actual testing.

## 9. Team Role and Responsibilities

**Role: Team Leader**

- Coordinated team activities and task allocation.
- Developed and maintained project plans and schedules.
- Helped plan the project budget and component requirements.
- Followed up on design, development and integration work.
- Coordinated testing and helped resolve project issues.
- Monitored progress against planned activities.

## 10. Testing Plan

Testing should be completed on a stationary bench setup. Place a target at known distances, compare the sensor reading with a ruler, and observe the buzzer response at each threshold. Repeat the test with different target shapes and angles.

Record actual test data in the testing document. Do not report accuracy percentages or successful vehicle trials unless those tests were actually performed and documented.

## 11. Limitations

- Ultrasonic sensors may not detect all object shapes and materials reliably.
- Sensor angle, mounting, vibration and environmental conditions can affect readings.
- A limited number of sensors can leave blind spots.
- The sample implementation is a basic educational reference and requires further engineering for real vehicle use.

## 12. Future Scope

- Use multiple sensors for wider coverage.
- Add an LCD/OLED distance display.
- Add filtering to reduce unstable readings.
- Add configurable alert thresholds and sound levels.
- Design a protected PCB and enclosure.
- Carry out documented tests under different environmental conditions.

## 13. Conclusion

The project demonstrates how ultrasonic sensing and a microcontroller can be combined to create a basic reverse-parking warning prototype. By translating measured distance into audible alerts, the system can provide an additional indication of nearby obstacles. Further testing, hardware validation and automotive protection would be required before any real-vehicle deployment.
