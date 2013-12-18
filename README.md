This is a candle flicker animation for Adafruit NeoPixel LEDs run from an Arduino device.
The LED library is at: https://github.com/adafruit/Adafruit_NeoPixel

There are two versions, for one pixel and eight pixels.

Adjustable variables appear at the top of the sketch: RGB mix for candle color, and cycle duration for flicker speed. The NeoPixel color mix changes for 3.3v or 5v, so recommended values are included for each.

The animation is created in the loop() by calling animation patterns and setting how long you want each one to run.

Blog writeup at http://timbartlett.net/ledcandle/

Tim Bartlett
December, 2013 