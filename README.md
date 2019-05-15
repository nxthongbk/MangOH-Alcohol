# Integrate Grove Alcohol Sensor With MangoH and Grove IoT Exapansion Card

This project demonstrates how to integrate Grove Alcohol Sensor With MangoH and Grove IoT Exapansion Card.


Grove Alcohol Sensor
------------------
Grove - Alcohol Sensor is built with MQ303A semiconductor alcohol sensor. It has good sensitivity and fast response to alcohol. It is suitable for making Breathalyzer. This Grove implements all the necessary circuitry for MQ303A like power conditioning and heater power supply. This sensor outputs a voltage inversely proportional to the alcohol concentration in air.


## Prerequisites

* A mangOH Red board.
* A Grove IoT Expansion card.
* Grove Alcohol sensor: See detail of sensor on wiki page: http://wiki.seeedstudio.com/Grove-Alcohol_Sensor/ 

## Setup
1. Insert Grove IoT Expansion card to Mangoh Red
1. Jump 5V Pin on Grove IoT Card
1. Connect Grove Alcohol Sensor with A0 connector on Grove card



## How To Run

1. Modify `mangOH/targetDefs.mangoh` to set `export SDEF_TO_USE =
   $(MANGOH_ROOT)/samples/Demos/containerTracking.sdef`
1. Build the system: run `make wp85` from inside the legato folder.
1. Run `instlegato wp85 192.168.2.2` to install the system update.
1. Press the power button on edge of the SensorTag
1. On the mangOH, run the command `hcitool lescan` to identify the MAC address of the SensorTag
1. Press `ctrl + c` to end scanning
1. On the mangOH, run the command `config set bleSensorInterface:/sensorMac <MAC>` to set the MAC
   address discovered previously
1. On the mangOH run `app start bleSensorInterface` to start the bluetooth app



1. Make the following changes to `littlevLegatoComponent/littlevgl/lv_conf.h`:
   1. At the top of the file, change the `#if 0` to `#if 1` to enable the file
   1. Update logical dimension of screen for waveshare eink 2.13 Inch:
      ```c
      #define LV_HOR_RES          (128)
      #define LV_VER_RES          (250)
      ```
   1. Update default font type to use monochome font:
      ```c
      #define LV_FONT_DEFAULT        &lv_font_monospace_8
      ```
   1. Enable font size 8 for monochome display and disable unsupported font:
      ```c
      #define USE_LV_FONT_DEJAVU_10              0
      #define USE_LV_FONT_DEJAVU_10_LATIN_SUP    0
      #define USE_LV_FONT_DEJAVU_10_CYRILLIC     0
      #define USE_LV_FONT_SYMBOL_10              0

      #define USE_LV_FONT_DEJAVU_20              0
      #define USE_LV_FONT_DEJAVU_20_LATIN_SUP    0
      #define USE_LV_FONT_DEJAVU_20_CYRILLIC     0
      #define USE_LV_FONT_SYMBOL_20              0

      #define USE_LV_FONT_DEJAVU_30              0
      #define USE_LV_FONT_DEJAVU_30_LATIN_SUP    0
      #define USE_LV_FONT_DEJAVU_30_CYRILLIC     0
      #define USE_LV_FONT_SYMBOL_30              0

      #define USE_LV_FONT_DEJAVU_40              0
      #define USE_LV_FONT_DEJAVU_40_LATIN_SUP    0
      #define USE_LV_FONT_DEJAVU_40_CYRILLIC     0
      #define USE_LV_FONT_SYMBOL_40              0

      #define USE_LV_FONT_MONOSPACE_8            1
      ```
   1. Update Color Depth to be 1:
      ```c
      #define LV_COLOR_DEPTH     1                     /*Color depth: 1/8/16/32*/
      ```
1. Make the following changes to `littlevLegatoComponent/littlevgl/lv_drv_conf.h`:
   1. At the top of the file, change the `#if 0` to `#if 1` to enable the file
   1. Update USE_FBDEV to 1 for using framebuffer device
      ```c
      #define USE_FBDEV         1
      ```
