#### Update 2.x:
````
with different defines_2-x.h for three different board layouts :-) 
Simply choose your layout in Inc/defines.h :-))
````


#### Update 2.1:
````
That's a fork from https://github.com/flo199213/Hoverboard-Firmware-Hack-Gen2
Compiles with Keil version 6 :-))
````

#### version/layout 2.2:
![otter](https://raw.githubusercontent.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/main/schematics%202.2/hoverboard_gen2_mosfet_pins_gd32F130C8.jpg)

The low side gate drivers each have three smd resitors connected to a PBx and the high side mosfets begin with two resistors connected to a PAx, which confirms the gate driver circuit of the original "Gen1" hoverboard schematics on page 2 of https://raw.githubusercontent.com/EFeru/hoverboard-firmware-hack-FOC/main/docs/20150722_hoverboard_sch.pdf

The pins PB15, PB14 and PA8 can easily be tested with a multimeter as they have double holes connecting to the backside layer of the circuit board.

![otter](https://raw.githubusercontent.com/RoboDurden/Hoverboard-Firmware-Hack-Gen2.x/main/schematics%202.2/hoverboard_gen2_hall_pins_gd32F130C8.jpg)

#### version/layout 2.1:
![otter](https://github.com/krisstakos/Hoverboard-Firmware-Hack-Gen2.1/blob/main/pins-board.jpg)

#### version/layout 2.0:
![otter](https://raw.githubusercontent.com/flo199213/Hoverboard-Firmware-Hack-Gen2/master/Hardware_Overview_small.png)


### Hoverboard-Firmware-Hack-Gen2.x

Hoverboard Hack Firmware Generation 2.x for the Hoverboard with the two Mainboards instead of the Sensorboards (See Pictures).

This repo contains open source firmware for generic Hoverboards with two mainboards. It allows you to control the hardware of the new version of hoverboards (like the Mainboard, Motors and Battery) with an arduino or some other steering device for projects like driving armchairs.

The structure of the firmware is based on the firmware hack of Niklas Fauth (https://github.com/NiklasFauth/hoverboard-firmware-hack/). These "new" boards are using GD32F130C6, so the project is adapted to that ic

- It's required to install [Keil](https://www.keil.com/download/product/).

---

#### Hardware

The hardware has two main boards, which are identical equipped. They are connected via USART. Additionally there are some LED PCB connected at LED1(battery indicator) and LED2(auxiliry lights). There is an programming connector for ST-Link/V2 and they break out GND, USART/I2C, 5V on a second pinhead(look at the picture).

The reverse-engineered schematics of the mainboards can be found here(GEN 2):
https://github.com/krisstakos/Hoverboard-Firmware-Hack-Gen2.1/blob/main/Schematics/HoverBoard_CoolAndFun.pdf


---

#### Flashing
The firmware is built with Keil (free up to 32KByte). To build the firmware, open the Keil project file which is includes in repository. Right to the STM32, there is a debugging header with GND, 3V3, SWDIO and SWCLK. 
**Beware that some verions/layouts have  GND, SWDIO, SWCLK, 3V3 header !** So always check GND and the 3.3V pins with a multimeter, with DIO and CLK simply try and error :-)
Connect GND, SWDIO and SWCLK to your SWD programmer, like the ST-Link found on many STM devboards.

- If you never flashed your mainboard before, the controller is locked. To unlock the flash, use STM32 ST-LINK Utility or openOCD. [instructions here](https://github.com/EFeru/hoverboard-firmware-hack-FOC/wiki/How-to-Unlock-MCU-flash).
ST-Link-Utility is out of date and needs a few old mfc42.dll files! Please open an issue when you know how to unlock flash with the STM32CubeProgrammer.
- To flash the STM32, use the STM32 ST-LINK Utility (2023: STM32CubeProgrammer) as well, ST-Flash utility or Keil by itself. I was also having 100% success rate with platform.io project from [here](https://github.com/EFeru/hoverboard-sideboard-hack-GD) just for uploading. You have to rename the output file *.axf to **firmware.elf** and move/copy it to the platform.io project, then upload. 
Bonus: Kristian Kosev (krisstakos) has  included **rename.bat** which will rename and move your output file, but you have to specify the right paths.
- Hold the powerbutton while flashing the firmware, as the controller releases the power latch and switches itself off during flashing
