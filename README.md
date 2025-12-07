# Arduino Pomodoro Timer (LCD + RGB + Button)

A simple and fun **Arduino-based Pomodoro timer** that uses an LCD display, RGB LED, and a single push button to help you stay productive. The device cycles through a work period and a break period, giving clear visual feedback using both text and color. This is a beginner-friendly electronics project and a great way to learn about **timers, LCDs, and user input** on Arduino.

## Features

* Work + break countdown timer displayed on a 16x2 LCD
* RGB LED color feedback during each phase
* One-button operation (press to start a cycle)
* Idle state when timer isn’t running
* Serial debug output to monitor progress

## Hardware Used

* Arduino Uno (or compatible board)
* 16x2 LCD (HD44780 compatible, 4-bit mode)
* RGB LED (common anode or cathode)
* Push button
* Resistors + jumper wires
* Breadboard (optional but recommended)

## How It Works

Press the button to start a full Pomodoro cycle. The timer runs through the following phases:

1. Work session
2. Break session
3. Completion message

The LCD updates every second with the remaining time, while the RGB LED indicates the current mode:

* Work: 🔴 Red
* Break: 🟢 Green
* Done: 🔵 Blue

After completion, the timer resets back to idle.

## Default Timing (Testing Values)

* Work: 2 minutes
* Break: 1 minute

To switch to real Pomodoro timing (25/5 minutes), update in code:

```cpp
workTime = 25 * 60;
breakTime = 5 * 60;
```

## LCD Reference & Documentation

This project uses Arduino’s standard `LiquidCrystal` library. For wiring and LCD commands, see:
[https://docs.arduino.cc/learn/electronics/lcd-displays/](https://docs.arduino.cc/learn/electronics/lcd-displays/)

## Serial Debugging

Open the Serial Monitor to observe real-time debug messages, such as:

```
Starting Work Session...
Work Remaining: 1:59
Break Remaining: 0:58
Cycle Complete!
```

## Why Build This

This project explores timing logic, LCD interfacing, RGB color control, and basic UX on microcontrollers. The result is a small desk gadget that’s both useful and fun to build!

## Future Improvements

* Adjustable times via potentiometer or buttons
* Audible buzzer alerts
* Auto-repeat cycles
* Pause / stop functionality
* Long break after multiple sessions
* Battery-powered version

## License

MIT License. Modify, hack, and share freely.

## Acknowledgements

Thanks to the Arduino community for documentation and examples. This project was inspired by hands-on experimentation.
