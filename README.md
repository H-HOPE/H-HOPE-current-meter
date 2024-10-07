<div align="right">
<img src="/res/Logo_istituzionale.png" alt="drawing" width="250"/>
</div>


# DIY hydrometric wing for measuring flow velocities 'H-HOPE current meter'
 
 
The hydrometric wing "H-HOPE current meter" was designed and developed as part of a H-HOPE project (web site https://h-hope.eu/). H-HOPE current meter measures water flow velocities on the principle of automatic recalculation of screw rotation frequencies in water velocity through the equation. H-HOPE current meter has been designed to be produced using the DIY (Do-It-Yourself) principle. All parts used for the production of H-HOPE current meter are readily available. H-HOPE current meter can be powered by 9V battery, or by external micro USB cable. H-HOPE current meter can measure water velocity from 0.1 to 5m/s. 
 


<div align="center">
<img src="./res/img2 (3).jpg" alt="drawing" width="500"/>
 
Figure. H-HOPE current meter.</div>


<div align="center">
<img src="./res/img (33).jpg" alt="drawing" width="1000"/>
 
Figure. 3D exploded model of a H-HOPE current meter.</div>

## Table of content

- [Materials and tools,](#material)
- [3D model,](#3dmodel)
- [Arduino code,](#arduino)
- [Assembly and test,](#assembly)
- [Field test.](#fieldtest)



## Material and tools used<a name="material"></a>

The project was designed in a certain way, that the material and tools necessary to build this project is widely available. Most of the parts and tools are available in local technical store or for example on online store Aliexpress. 

### Material used for this project:

- Arduino uno https://www.aliexpress.com/item/1005002707450245.html
- Connectors (XH): https://www.aliexpress.com/item/33000442968.html
- Connecting cables (XH): https://www.aliexpress.com/item/1005002160765607.html
- Micro usb socket: https://www.aliexpress.com/item/1005003730290423.html
- 9v battery holder https://www.aliexpress.com/item/32825539506.html
- 16x2 LCD with i2c header: https://www.aliexpress.com/item/32413056677.html
- Unipolar Hall sensor (SIP package, for exmaple SS443A): https://www.aliexpress.com/item/1005001522952951.html
- Magnet, size 3x1mm: https://www.aliexpress.com/item/1005005222147418.html
- 2m 3-core cable: https://www.aliexpress.com/item/1005002082473369.html
- Pushbutton / toggle ON/OFF switch: https://www.aliexpress.com/item/1005004004236347.html
- XH pin connectors: https://www.aliexpress.com/item/1005004267331222.html
- 6x M2 screws (10mm length)
- 3x M4 screws (30mm length)
- 2x M5 screws with 
- M8 screw (50mm length)
- Epoxy glue
- 9v battery
- micro usb cable
- spring
- Stick, Bar


### Tools needed for this project:

- Soldering iron
- 3D printer
- Set of Screwdrivers

## 3D printing and model of the H-HOPE current meter<a name="3dmodel"></a>

We used Prusa MK3S 3D printer to print the H-HOPE current meter plastic parts. Chosen material was PETG.

Below is the 3D exploded model of a H-HOPE current meter. H-HOPE current meter is made from two main parts. 

- assembly of a screw,
- assembly of the enclosure with LCD screen and holder. 

<div align="center">
<img src="./src/3D model/Sestav_1.png" alt="drawing" width="800"/>
 
Figure. Exploded model of the screw.</div>


<div align="center">
<img src="./src/3D model/Sestav_2.png" alt="drawing" width="800"/>
 
Figure. Exploded model of the enclosure with LCD screen and holder.</div>

Source files (step file) for printing the H-HOPE current meter are available on [Github](https://github.com/H-HOPE/DIY-Flow-meter/blob/7c3ee1f1fafccab5ecbd7b81c10c78a44afabfad/src/3D%20model/Flowmeter_assembly.stp).

<div align="center">
<img src="./res/img (31).jpg" alt="drawing" width="500"/>
 
Figure. Printing the H-HOPE current meter enclosure.</div>



<div align="center">
<img src="./res/img (15).jpg" alt="drawing" width="500"/>
 
Figure. 3D printed parts for the H-HOPE current meter holder.</div>




## Arduino code<a name="arduino"></a>

In this chapter the source code for the Arduino Uno microcontroller will be explained.

<div align="center">
<img src="./res/img (21).jpg" alt="drawing" width="300"/>
 
Figure. Arduino uno board is used for H-HOPE current meter electronics.</div>

Arduino code:
https://github.com/H-HOPE/DIY_Flow_meter/blob/e5a896e44799b07652782b1dd13d3e7614e1950c/src/Arduino/H-HOPE_Hi-wing.ino#L1-L63

Key parts of the Arduino code:
- First, we include libraries for LCD screen and I2C protocol. LCD screen library is also available [here](https://github.com/H-HOPE/DIY-Flow-meter/tree/main/src/Arduino/lib).
- Then we define an Arduino pin, where the hall sensor will be connected. In this case, this pin is number 2.
- in lines 13 through 15 we define variables. 
- In the setup section we initialize the LCD screen and configure interrupt for the hall sensor. 
Hall sensor output is connected to the Arduino Uno inetrrupt. Arduino Uno has two external interrupt pins, INT0 and INT1, which are mapped to digital pins 2 and 3 respectively. Interrupts are signals that allow a microcontroller to pause its current execution and handle an event or task that has a higher priority. 
In this case hall sensor is attached to the INT0 pin (digital pin 2).
Configure the interrupt settings using the attachInterrupt() function. This function takes three arguments: the interrupt number (in this case, 0 for INT0), the function to call when the interrupt is triggered (cnt), and the mode in which to trigger the interrupt (on FALLING EDGE).
- In the loop section, from line 38, the code to calculate the water velocity from the screw rotation speed is written. The calculated water velocity is shown on the LCD screen.
- Finally at the end of the program there is an interrupt routine, that records the time when the magnet on the wing passes hall sensor.

<div align="center">
<img src="./res/img (23).jpg" alt="drawing" width="300"/>
 
Figure. Arduino Uno microcontroller mounted in the H-HOPE current meter enclosure.</div>


## Assembly and test<a name="assembly"></a>

With all the printed parts ready and programmed Arduino, we can start the assembly of the H-HOPE current meter.

3D exploded model of a H-HOPE current meter

<div align="center">
<img src="./src/3D model/Sestav_1.png" alt="drawing" width="800"/>
 
Figure. 3D exploded model of a screw.</div>

<div align="center">
<img src="./src/3D model/Sestav_2.png" alt="drawing" width="800"/>
 
Figure. 3D exploded model of the enclosure.</div>



### Enclosure for the H-HOPE current meter electronics

<div align="center">
<img src="./res/img (25).jpg" alt="drawing" width="500"/>
 
Figure. Enclosure for the H-HOPE current meter electronics.</div>

Assembly of the screw:

Mount two bearings in the screw and put the end cap to the screw.

<div align="center">
<img src="./res/img (16).jpg" alt="drawing" width="500"/>
 
Figure. First bearing mount.</div>

<div align="center">
<img src="./res/img (17).jpg" alt="drawing" width="500"/>
 
Figure. Second bearing mount, with end cap.</div>

<div align="center">
<img src="./res/img (34).jpg" alt="drawing" width="500"/>
 
Figure. Assembly of the bar mounting tight screw</div>

<div align="center">
<img src="./res/img (18).jpg" alt="drawing" width="500"/>
 
Figure. Assembled screw holder.</div>

Next, place 1x3 mm magnet in the prefabricated hole in the screw and glue the magnet with Epoxy glue.
<div align="center">
<img src="./res/img (9).jpg" alt="drawing" width="500"/>
 
Figure. Magnet assembly on the screw.</div>


We need to solder hall sensor to the cable. Hall sensor has three pins GND, VCC and Signal

<div align="center">
<img src="./res/img (11).jpg" alt="drawing" width="500"/>
 
Figure. Pinout of the SS443a Hall sensor.</div>



Put the cable through the screw holder and glue the hall sensor, with the Epoxy glue to the screw holder.

<div align="center">
<img src="./res/img (36).jpg" alt="drawing" width="500"/>
 
Figure. Screw with bearing and end cap.</div>


Assembled Screw.
<div align="center">
<img src="./res/img (37).jpg" alt="drawing" width="500"/>
 
Figure. Assembled Screw.</div>

### Assembly of the H-HOPE current meter electronics.


Mount the Arduino Uno in the enclosure, screw the micro USB module to the enclosure with two M2 10mm screws. Connect micro USB module to Arduino Uno (5V to 5V; GND to GND).
<div align="center">
<img src="./res/img (23).jpg" alt="drawing" width="500"/>
 
Figure. Arduino Uno and micro USB module.</div>


Connect hall sensor GND, VCC and OUT to the Arduino Uno
<div align="center">
<img src="./res/img (8).jpg" alt="drawing" width="500"/>
 
Figure. Hall sensor connected to the Arduino Uno.</div>


Mount 16x2 LCD screen with 4 M2 10mm screws to the front of the enclosure. Connect the LCD screen to the Arduino, through the I2C protocol.
<div align="center">
<img src="./res/img (22).jpg" alt="drawing" width="500"/>
 
Figure. LCD screen connection.</div>


Mount 9V battery connector, make small hole for wires. Connect 9v Battery holder to Arduino Uno (+9V battery to Vin Arduino Uno pin; -9V battery to GND Arduino Uno pin)
<div align="center">
<img src="./res/img (38).jpg" alt="drawing" width="500"/>
 
Figure. 9V battery installation.</div>


Make hole on the enclosure for the external ON/OFF switch to power on the H-HOPE current meter. Connect the switch in series with positive battery wire.
<div align="center">
<img src="./res/img (5).jpg" alt="drawing" width="500"/>
 
Figure. External ON/OFF switch.</div>



Use screws to assemble the electronics enclosure of the H-HOPE current meter. 
<div align="center">
<img src="./res/img (28).jpg" alt="drawing" width="500"/>
 
Figure. Mounting screws.</div>


### Holder for the H-HOPE current meter electronics (optional)

It is also possible to mount the H-HOPE current meter electronics with the help of holder to the stick. In that case you need to print and assemble the H-HOPE current meter holder. 

<div align="center">
<img src="./res/img (1).jpg" alt="drawing" width="500"/>
 
Figure. Assembly of the holder for the H-HOPE current meter electronics.</div>


### Test hall sensor response.

Oscilloscope was used to test the output signal from the hall sensor

<div align="center">
<img src="./res/img (6).jpg" alt="drawing" width="500"/>
 
Figure. Hall sensor test setup.</div>

Hall sensor need pull-up resistor to operate properly. You can use external 10k pull-up resistor across the Vcc and hall input pin. In our case we configured Arduino to use his internal pull-up resistor. Then we test the operation of the hall sensor with an oscilloscope.



<div align="center">
<img src="./res/img (1).BMP" alt="drawing" width="500"/>
 
Figure. Hall sensor output signal on oscilloscope.</div>


## Field test<a name="fieldtest"></a>

Now you can find a waterway and measure its speed with the H-HOPE current meter water velocity sensor.


<div align="center">
<img src="./res/Field_1.jpg" alt="drawing" width="500"/>
 
 
Figure. Image of the H-HOPE current meter water velocity sensor in open channel
 
 <div align="center">
<img src="./res/Field_2.jpg" alt="drawing" width="500"/>
  
  
Figure. Measuring water velocity with the H-HOPE current meter sensor.


&nbsp;
&nbsp;
&nbsp;

<div align="center">
<img src="./res/H-HOPE_footer.JPG" alt="drawing" width="1472"/>
</div>
