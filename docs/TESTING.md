# Testing Plan

This is a basic bench-test plan for the example Arduino Uno + HC-SR04 + buzzer circuit in this repository.

## Test Setup

- Upload `arduino/parking_alarm/parking_alarm.ino`.
- Open Serial Monitor at 9600 baud.
- Place a flat target in front of the sensor.
- Measure target distance with a ruler or tape measure.
- Keep the sensor and target aligned during the first tests.

## Functional Tests

| Test | Procedure | Expected result |
|---|---|---|
| Power-on | Power the Arduino over USB | Serial startup message appears |
| No target / beyond range | Point sensor into an open area | No alert; serial may report no echo or a clear distance |
| Far warning | Place target around 120 cm away | Slow intermittent alert |
| Medium warning | Place target around 75 cm away | Faster intermittent alert |
| Near warning | Place target around 35 cm away | Fast intermittent alert |
| Very near | Place target around 15 cm away | Continuous buzzer alert |
| Remove target | Move target beyond 150 cm | Buzzer stops |

Thresholds are examples and can vary with sensor accuracy and mounting. Record measured distances and observed behavior during actual testing.

## Reliability Checks

- Repeat each distance test several times.
- Test large flat and narrow objects.
- Test angled surfaces and soft materials.
- Check for false readings from nearby walls or objects.
- Verify that invalid/no-echo readings do not create a false close-obstacle warning.
- Inspect wiring and supply stability if the board resets or readings fluctuate.

## Test Record Template

| Date | Target | Actual distance | Displayed distance | Alert behavior | Pass/Fail | Notes |
|---|---|---:|---:|---|---|---|
| YYYY-MM-DD | Example board |  |  |  |  |  |

## Safety

Perform tests on a stationary bench setup. Do not test by reversing a moving vehicle toward a person or obstacle. This prototype is not a substitute for a commercial parking sensor or safe driving practices.
