1. Please don't check-in build artifacts: MangOH-Alcohol/AlcoholSensorService/_build_alcoholSensor or update files  		  
```
[Thong] Updated
```

2. Please provide comments in most areas, otherwise, most developers won't understand.  
```
[Thong] Updated
```

3. ma_alcoholSensor.api:  
	(a) You don't need "ma_alcoholSensor.api" filename, think "alcoholSensor.api"  
	(b) Line 19: "kiloPascals"?  
	(c) Line 27: "-"'s should line up till column 100  

```
[Thong]
	(a) Renamed ma_alcoholSensor.api to alcoholSensor.api.  
	(b) Updated to times  
	(c) udpated.
```
4. alcoholSensor.c:  
	(a) Please remove tabs - https://docs.legato.io/latest/ccodingStdsFormat.html#codingTabs  
	(b) Line 20 - 21 - please provide comments on this, even the seeedstudio example code at http://wiki.seeedstudio.com/Grove-Alcohol_Sensor/ has some, though the code there is also very poorly commented, please do better. Also, why do we need sensor_volt variable and lines 20 & 21 - can't all the math be done in one line? What does "omit *R16" mean?  
	(c) Could not the LE_ASSERT paradigm be used for the call & "if" for le_adc_ReadValue().  
```
[Thong]  
(a) Updated. removed tab and replace by space  
(b) Added comment  
(c)  
```

5. alcoholSensorToDatahub.c:  
Please review all the api routines provided by a component before coding it. This should be using the periodic sensor as most most of the code will dissappear from alcoholSensorToDatahub.c, i.e.: psensor_Create - e.g. code in YellowSensorToCloud/components/sensors/environment/environmentSensor.c  
      (a) line 133 - unsure of units of "degrees" - is this not supposed to be a ppm?  
      (b) line 148 - don't comment "set period to 1s" anf then set it to 10 sec.  
      
```
[Thong]  
(a)  updated to kohm (units of Rs)
(b)  updated to 1s
```
	
6. alcoholSensorDisplay.c  
I also think the datahub design assumes that Legato app code shouldn't be using the admin interface - this is more for the cloud control of Legato apps. I think you need for the observation you have created, please comment on the use case here.  
    	(a) We are in Nix land <CR><NL> is the standard file format in Nix land, the file is in dos format.  
    	(b) I first thought alcoholSensorDisplay.c was to send the alcohol sensor reading to an LED display.  
        Confusing?  
	
```
[Thong]  
(a) Yes we need to control by cloud. admin interface is just use to demo how to control notification.  
```
I don't see why we have a component reading the ADC, returning that to another component
who only sends to datahub - shouldn't this just be one component, i.e.
alcoholSensorToDatahub.c & alcoholSensor.c should just be 1 component. 
Please justify your design, but so far I see no reason for this decomposition.  

```
[Thong]  
In my design there are 3 apps.  
AlcoholSensorService: creates api for another app/component using. not only datahub app. It same with LedService or Battery Service that we developed before  
AlcoholSensorToDatahub: Demos how to send sensor value to datahub  
AlcoholSensorDisplay: Demos how to get data from datahub  

So we can update this design to match with Mangoh yellow.  
```

Please explain the alcohol sensor upper/lower limits - shouldn't this be just an upper
limit only - why the lower limit? Please explain.  

```
[Thong]  
Just use to demo we can set range of sensor value and the notification only appear when the sensor value in range.  
```
Also, the ALCOHOL_SENSOR_UPPER_LIMIT of 100.0 - what does this mean from the inverse voltage
point of view?  
