# SeinfeldDoor

AVR senses when a door is opened and plays bass riff from Seinfeld.

Unfortunately I can't upload the MP3's to github for obvious reasons.

Unfortunately I don't have any schematic files for this yet.

# Bits

* ATmega328p
* HC-SR04 Ultrasonic Rangefinder
* JQ6500 MP3 Module
* 8Ω 0.5W Speaker
* Red LED
* LM7805 Regulator

# Instructions

Download this project and [AVR-Libs](https://github.com/MarcusKiwi/AVR-Libs). Recreate this folder structure:

```
base
├───AVR-Libs
│   └───project files
└───SeinfeldDoor
    └───project files
```

Run `make` from inside the SeinfeldDoor folder to build the HEX file.

Run `make install` to build it flash it to an AVR. Default programmer type is usbasp. This can be changed in the file `base/AVR-Libs/makefile`.

You'll also need to find [some sound clips](https://www.youtube.com/watch?v=ZD7PvtbkH0I) and [upload them to the JQ6500](https://www.youtube.com/watch?v=v7aHJ1TsL4o) module.