# Project Plan and Team Responsibilities

## Project Goal

Develop a prototype that detects obstacles behind a vehicle and provides an audible warning based on the measured distance.

## Suggested Work Plan

| Phase | Activities | Deliverable |
|---|---|---|
| 1. Planning | Define the problem, project scope, tasks, timeline and component needs | Project plan |
| 2. Component selection | Review controller, ultrasonic sensor, buzzer and power requirements | Component list |
| 3. Circuit design | Prepare the wiring plan and connect the components on a bench | Working prototype circuit |
| 4. Programming | Read sensor values, calculate distance and implement alert ranges | Microcontroller code |
| 5. Integration | Connect the sensor, controller and buzzer and check the complete flow | Integrated prototype |
| 6. Testing | Test at measured distances and record readings and alert behavior | Test record |
| 7. Review | Review issues, changes, project progress and final documentation | Final project report |

This is a suggested plan. Replace it with the team's actual dates and milestones if they are available.

## Team Leader Responsibilities

The team leader role included coordinating the group and helping manage the project plan, schedule and budget. Typical activities include:

- Agreeing on tasks and responsibilities with team members.
- Tracking progress and following up on pending work.
- Coordinating component selection and resource requirements.
- Organizing circuit integration and testing activities.
- Recording issues and helping the team agree on next steps.
- Reviewing project documentation before submission.

## Budget Tracking Template

Fill in actual supplier prices and quantities. Do not use estimated values as final project expenses.

| Component | Quantity | Unit cost | Total cost | Supplier / notes |
|---|---:|---:|---:|---|
| Microcontroller board |  |  |  |  |
| Ultrasonic sensor(s) |  |  |  |  |
| Buzzer module |  |  |  |  |
| Wires / breadboard |  |  |  |  |
| Power supply / cable |  |  |  |  |
| Other parts |  |  |  |  |
| **Total** |  |  |  |  |

## Schedule Tracking Template

| Task | Owner | Planned date | Actual date | Status / notes |
|---|---|---|---|---|
| Project planning |  |  |  |  |
| Component selection |  |  |  |  |
| Circuit assembly |  |  |  |  |
| Programming |  |  |  |  |
| Integration |  |  |  |  |
| Testing |  |  |  |  |
| Documentation |  |  |  |  |

## Risks and Mitigation

| Risk | Possible impact | Suggested response |
|---|---|---|
| Unstable sensor readings | Incorrect distance estimate | Secure the sensor, check wiring and repeat measurements |
| Buzzer load exceeds pin capability | Controller instability or damage | Check datasheet and use a suitable driver circuit |
| Component availability | Schedule delay | Confirm parts early and identify compatible alternatives |
| Limited sensor coverage | Obstacles may not be detected | Review sensor placement and consider additional sensors |
| Vehicle electrical noise / transients | Damage or unreliable behavior | Keep prototype bench-powered; use automotive-rated protection for any engineered vehicle installation |

## Completion Review

Before calling the project complete, confirm that the circuit, source code, actual component list, test observations and project photographs are saved in the repository. Record any known limitations honestly.
