# Components and Wiring

This note documents the example circuit provided in this repository. It is an assumed reference design because no original circuit diagram or source files were present when the documentation was created.

## Reference Parts

- Arduino Uno or compatible 5 V microcontroller board
- HC-SR04 ultrasonic distance sensor
- Active piezo buzzer compatible with the controller output (use a driver if needed)
- Breadboard and jumper wires
- USB power for bench testing

## Connections

| Device pin | Arduino Uno pin |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| Buzzer + | D6 |
| Buzzer - | GND |

## Wiring Guidelines

1. Disconnect USB/power before changing wiring.
2. Connect all grounds together.
3. Check the sensor voltage requirements and board logic levels.
4. Confirm the buzzer current and voltage. Do not exceed the microcontroller pin limits; use a transistor driver when the buzzer requires more current.
5. Keep sensor wiring secure and away from sources of electrical noise.

## Functional Flow

```text
Power on
   |
Initialize sensor, buzzer, serial output
   |
Send ultrasonic trigger pulse
   |
Measure echo duration
   |
Convert echo duration to distance
   |
Compare distance with warning thresholds
   |
Set buzzer alert pattern
   |
Repeat
```

## Important

The HC-SR04 and Arduino Uno wiring shown here is not a confirmed reproduction of the owner's physical build. Update this file and the sketch if the project uses another board, sensor, or pin arrangement.
