![![](http://upload.wikimedia.org/wikipedia/commons/thumb/8/8c/Partybooth.jpg/256px-Partybooth.jpg)](http://commons.wikimedia.org/wiki/File:Partybooth.jpg)

The first time I saw the Big Dome Push Button on sparkfun.com, I immediately thought of this application.

You see, one of my client is a photography studio. One service provided by the studio during events is what they call the ["PhotoMate"](http://www.studiocasagrande.com/html/events/animation/index.php?lang=en), which is a box containing a DSLR, a MacBook Pro, and a remote shutter release.

The event's attendants can press the remote's button, then go to their place and smile. The camera's self-timer will wait five seconds and take the shot.

## The Hardware ##

![http://partybooth.googlecode.com/svn/wiki/partybooth.png](http://partybooth.googlecode.com/svn/wiki/partybooth.png)
I thought that it would be great to replace the remote with a Big Dome Button, because it's huge, and because it has a light bulb in it (recent models now have an LED instead) that can be used to provide a feedback to the user. I also included a buzzer for an additional feedback.

I started gathering the parts, did a few tests with an Arduino and a breadboard, then I drew the schematics in Eagle.

I then routed the PCB layout, and sent it to three manufacturers. This is my first hardware project since 1985, so I had some catch-up to do.

About a week later, I received the first boards. I could start soldering.

That was pretty straightforward. I managed to solder the buzzer in reverse though.

![![](http://upload.wikimedia.org/wikipedia/commons/thumb/3/3f/Partybooth_board.jpg/800px-Partybooth_board.jpg)](http://commons.wikimedia.org/wiki/File:Partybooth_board.jpg)
![http://partybooth.googlecode.com/svn/wiki/kit.jpg](http://partybooth.googlecode.com/svn/wiki/kit.jpg)

## The Firmware ##

I chose the ATtiny13 as microcontroller because I had played with Arduinos, and because it's the smallest and simplest AVR available.

I wanted a five second delay between the moment the button is pressed, and the moment the shutter is released. A brief flash of light and a brief sound would start the first four seconds, and then the light and the sound would last the whole fifth second (see diagram).

![http://partybooth.googlecode.com/svn/wiki/timeline.png](http://partybooth.googlecode.com/svn/wiki/timeline.png)

## Sources ##

![http://partybooth.googlecode.com/svn/wiki/oshw-logo-100-px.png](http://partybooth.googlecode.com/svn/wiki/oshw-logo-100-px.png)

This is an open-source project, and all the sources can be found here. The souces include:

  * The Eagle schematic file
  * The Eagle board layout
  * The bill of material
  * The firmware sources