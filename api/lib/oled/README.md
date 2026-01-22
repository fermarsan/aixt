 #  QUICK GUIDE OLED LIBRARY

 This is an implementation of a library dedicated to OLED screens, providing support for various microcontrollers.

 ##  SUMMARY

 An OLED screen (Organic Light-Emitting Diode) is a type of display that uses organic diodes to emit light when an electric current is applied. Unlike LCD screens, OLEDs do not require backlighting, as each pixel lights up independently.

The device supported by this library is based on the SSD1316 controller, which is designed to control monochromatic OLED screens, generally of small size. Its main features are:  

*  Supported resolution up to 128x64 pixels.  
*  Color mode: Monochromatic (white, blue, or yellow, depending on the OLED panel model).  
*  Communication interface: Compatible with I2C and SPI, allowing flexible communication with various microcontrollers.  
*  Low power consumption.  
*  Integrated graphic controller: Enables drawing text and images without the need for external memory.  

##  USES

OLED screens with the SSD1316 controller are widely used in electronic projects and embedded systems due to their low power consumption, high readability, and ease of integration.

**IoT Devices (Internet of Things)**  
* Data visualization in temperature, humidity, pressure sensors, etc.  
* Energy consumption monitors in smart homes.  
* Control panels in automation systems.  

**Embedded Systems and Microcontrollers**  
* Indicators in Arduino, ESP32, Raspberry Pi, STM32, etc.  
* Graphic interfaces for DIY or industrial projects.  
* Status monitors in robots and drones.  

**Wearables and Portable Devices**  
* Smartwatches with low-power monochromatic displays.  
* Health monitoring devices (heart rate, blood oxygen, etc.).  

**Industrial and Measurement Equipment**  
* Information displays in oscilloscopes, multimeters, and signal analyzers.  
* Operation indicators in 3D printers.  
* Interfaces in machinery control systems.  

**Home Appliances and Gadgets**  
* Displays in coffee machines, air purifiers, and smart ovens.  
* Audio controls in amplifiers and equalizers.  
* Retro gaming consoles with monochromatic OLED screens.  

## SUPPORTED FUNCTIONS FOR TRANSPILATION**

| Functions in C                                           | Functions in V                                           |
| -------------------------------------------------------- | -------------------------------------------------------- |
| `display.begin (TYPE, ADDRESS)`                          | `DISPLAY_SETUP (TYPE, ADDRESS)`                          |
| `display.clearDisplay ()`                                | `DISPLAY_CLEARDISPLAY ()`                                |
| `display.setTextSize (NUMBERS)`                          | `DISPLAY_SETTEXTSIZE (NUMBERS)`                          |
| `display.setTextColor (CHARACTER)`                       | `DISPLAY_SETTEXTCOLOR(CHARACTER)`                        |
| `display.println (MESASAGE)`                             | `DISPLAY_PRINTLN (MESSAGE)`                              |
| `display.display ()`                                     | `DISPLAY_DISPLAY ()`                                     |
| `display.DrawPixel (X,Y,COLOR)`                          | `DISPLAY_DRAWPIXEL(X,Y,COLOR)`                           |
| `display.drawRect(X,Y,WIDTH,HEIGHT,COLOR)`               | `DISPLAY_DRAWRECT(X,Y,WIDTH,HEIGHT,COLOR)`               |
| `display.fillRect(X,Y,WIDTH,HEIGHT,COLOR)`               | `DISPLAY_FILLRECT(X,Y,WIDTH,HEIGHT,COLOR)`               |
| `display.drawCircle(X,Y,RADIO,COLOR)`                    | `DISPLAY_DRAWCICRLE(X,Y,RADIO,COLOR)`                    |
| `display.fillCircle(X,Y,RADIO,COLOR)`                    | `DISPLAY_FILLCIRCLE(X,Y,RADIO,COLOR)`                    |
| `display.drawBitmap(X,Y,ARRAY_IMAGE,WIDTH,HEIGHT,COLOR)` | `DISPLAY_DRAWBITMAP(X,Y,ARRAY_IMAGE,WIDTH,HEIGHT,COLOR)` |

**Support Code for Functions in V Language** 

```v

    fn C.DISPLAY_BEGIN(type_ any , address any) bool
    fn C.DISPLAY_CLEARDISPLAY(any) 
    fn C.DISPLAY_SETTEXTSIZE(number any)
    fn C.DISPLAY_TEXTCOLOR(character any)
    fn C.DISPLAY_SETCURSOR(x any , y any)
    fn C.DISPLAY_PRINTLN(message any)
    fn C.DISPLAY_DISPLAY(any) 
    fn C.DISPLAY_DRAWPIXEL(x any , y any , color any)
    fn C.DISPLAY_DRAWRECT(x any , y any , width any , height any , color any)
    fn C.DISPLAY_FILLRECT(x any , y any , width any , height any , color any)
    fn C.DISPLAY_DRAWCIRCLE(x any , y any , radio any , color any)
    fn C.DISPLAY_FILLCIRCLE(x any , y any , radio any , color any) 
    fn C.DISPLAY_DRAWBITMAP(x any , y any , array_image any , width any , height any , color any)  

```
