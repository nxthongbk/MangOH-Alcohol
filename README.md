# Integrate Grove Alcohol Sensor with MangoH and Grove IoT Exapansion Card

This project demonstrates how to integrate Grove Alcohol Sensor with MangoH and Grove IoT Exapansion Card.


## Prerequisites

* A mangOH Red board.
* A Grove IoT Expansion card.
* Grove Alcohol sensor: See detail of sensor on wiki page: http://wiki.seeedstudio.com/Grove-Alcohol_Sensor/ 

Grove Alcohol Sensor
------------------
Grove - Alcohol Sensor is built with MQ303A semiconductor alcohol sensor. It has good sensitivity and fast response to alcohol. It is suitable for making Breathalyzer. This Grove implements all the necessary circuitry for MQ303A like power conditioning and heater power supply. This sensor outputs a voltage inversely proportional to the alcohol concentration in air.

<img src="https://user-images.githubusercontent.com/17214533/57901066-94949c80-788d-11e9-8ec1-f391d388d850.jpg" width="350" alt="accessibility text"> 

Legato Application
------------------
There are 3 legato applications:
* ```AlcoholSensorService```: provides api for reading alcohol sensor.
* ```AlcoholSensorToDatahub```: push alcohol sensor value in period time to datahub.
* ```AlcoholSensorDisplay```: register for notification of value updates, create observation (filter) for alcohol sensor and display the alcohol sensor value.



## Setup
1. Insert Grove IoT Expansion card into Mangoh Red
1. Jump 5V Pin on Grove IoT Card
1. Connect Grove Alcohol Sensor with A0 connector on Grove card



## How To Run

1. Build the AlcoholSensorService app by running ```mkapp -t wp85 alcoholSensor.adef``` in AlcoholSensorService directory.
1. Run ```instapp alcoholSensor.wp85.update 192.168.2.2``` to install the app.
1. Build the AlcoholSensorToDatahub app by running ```mkapp -t wp85 AlcoholSensorToDatahub.adef``` in AlcoholSensorToDatahub directory.
1. Run ```instapp AlcoholSensorToDatahub.wp85.update 192.168.2.2``` to install the app.
1. Build the AlcoholSensorDisplay app by running ```mkapp -t wp85 AlcoholSensorDisplay.adef``` in AlcoholSensorDisplay directory.
1. Run ```instapp AlcoholSensorDisplay.wp85.update 192.168.2.2``` to install the app.

## How to get get the concentration of gas.
The concentration of gas is calulated by ratio: ```RS_gas/RS_air```.
- ```RA_air``` is value of sensor returned in clean air.
- ```RS_gas``` is value of sensor returned in alcohol condition.

<img src="https://user-images.githubusercontent.com/17214533/58239849-0e3bf700-7d74-11e9-9657-35f5769a79ab.png" width="350" alt="accessibility text"> 
According to the figure, we can see that the minimum concentration we can test is 20ppm and the maximum is 10000ppm, in a other word, we can get a concentration of gas between 0.002% and 1%. However, we can't provide a formula because the relation between ratio and concentration is nonlinear.
