/*
 * GPIO.c
 *
 *  Created on: 3/2/20
 *      Author: John Curry
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"

#define PRESSED 0


#define BoosterUP BIT1 //S1 BUTTON
#define BoosterDN BIT5

#define redLaunchpad BIT0

#define boosterRGB_RED BIT6
#define boosterRGB_GREEN BIT4
#define boosterRGB_BLUE BIT6

#define launchpadRGB_RED BIT0
#define launchpadRGB_BLUE BIT2
#define launchpadRGB_GREEN BIT1

#define LaunchpadL BIT1  //P1.1
#define LaunchpadR BIT4

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    //call all the other functions

    // I just copied and pasted this from my project1
    // if it kinda worked once it should kinda work again
    void redLaunchpadON();
    void RGBredLaunchpad();
    void RGBblueLaunchpad();
    void RGBgreenLaunchpad();
    void RGBredBooster();
    void RGBgreenBooster();
    void RGBblueBooster();

    void Launchpadleft();
    void Launchpadright();

    void BoosterpackDN();
    void BoosterpackUP();
    // Launchpad S1

    // Launchpad S2

    // Boosterpack S1

    // Boosterpack S2

    // Launchpad LED1

    // Launchpad LED2 Red

    // Launchpad LED2 Green

    // Launchpad LED2 Blue

    // Boosterpack LED Red

    // Boosterpack LED Green

    // Boosterpack LED Blue


    // Turn off all LEDs at the start.
}

void RGBredLaunchpad()//p2.0

{
    P2DIR = P2DIR | launchpadRGB_RED;

}

void BoosterpackUP()
{
    P5DIR = P5DIR & ~BoosterUP;
    P5REN = P5REN | BoosterUP;
    P5OUT = P5OUT | BoosterUP;

}

void RGBredBooster()
{
    P2DIR = P2DIR | boosterRGB_RED;
   // P2OUT |= boosterRGB_RED;
}
void Launchpadleft() //down
{
    P1DIR = P1DIR & ~LaunchpadL;
    P1REN = P1REN | LaunchpadL;
    P1OUT = P1OUT | LaunchpadL;

}

void Launchpadright() //up
{
    P1DIR = P1DIR & ~LaunchpadR;
    P1REN = P1REN | LaunchpadR;
    P1OUT = P1OUT | LaunchpadR;

}


void BoosterpackDN ()
{
    P3DIR = P3DIR & ~BoosterDN;
    P3REN = P3REN | BoosterDN;
    P3OUT = P3OUT | BoosterDN;

}
void redLaunchpadON()

{
    P1DIR = P1DIR | redLaunchpad;


    //P1DIR &= ~LaunchpadL;
    //P1REN |= LaunchpadL;
    //P1OUT |= LaunchpadL;

   // P1OUT |= redLaunchpad;
}



void RGBgreenLaunchpad()//2.1

{
    P2DIR = P2DIR | launchpadRGB_GREEN;
    //P2OUT |= launchpadRGB_GREEN;
}

void RGBblueLaunchpad()//2.1
{
    P2DIR = P2DIR | launchpadRGB_BLUE;
 //   P2OUT |= launchpadRGB_BLUE;
}

void RGBgreenBooster()
{
    P2DIR = P2DIR | boosterRGB_GREEN;
   // P2OUT |= boosterRGB_GREEN;
}

void RGBblueBooster()
{
    P5DIR = P5DIR | boosterRGB_BLUE;
    //P5OUT |= boosterRGB_BLUE;
}


// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return (( P1IN & LaunchpadL) == PRESSED);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return (( P1IN & LaunchpadR) == PRESSED);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return (( P5IN & BoosterUP) != PRESSED);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return (( P3IN & BoosterDN) == PRESSED);
}

// TODO: Create a function to turn on Launchpad LED1.

//most of this is straight off my project 1 too, so it'll look familiar

void turnOn_LaunchpadLED1()
{
    P1DIR = P1DIR | redLaunchpad;


      //P1DIR &= ~LaunchpadL;
      //P1REN |= LaunchpadL;
      //P1OUT |= LaunchpadL;

      P1OUT |= redLaunchpad;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT &= redLaunchpad;

}

// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2DIR = P2DIR | launchpadRGB_RED;
       P2OUT |= launchpadRGB_RED;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{

    P2OUT &= ~launchpadRGB_RED;
}

// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2DIR = P2DIR | launchpadRGB_GREEN;
       P2OUT |= launchpadRGB_GREEN;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT &= launchpadRGB_GREEN;
}

// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2DIR = P2DIR | launchpadRGB_BLUE;
        P2OUT |= launchpadRGB_BLUE;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT &= launchpadRGB_BLUE;
}

// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2DIR = P2DIR | boosterRGB_RED;
       P2OUT |= boosterRGB_RED;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
   // P2OUT |= boosterRGB_RED;
    //P2OUT = P2OUT &~boosterRGB_RED;
    P2OUT &= boosterRGB_RED;
}

// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2DIR = P2DIR | boosterRGB_GREEN;
        P2OUT |= boosterRGB_GREEN;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
//    P2OUT |= boosterRGB_GREEN;
//    P2OUT = P2OUT &~boosterRGB_GREEN;
    P2OUT &= boosterRGB_GREEN;
}

// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5DIR = P5DIR | boosterRGB_BLUE;
    P5OUT |= boosterRGB_BLUE;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{

    P5OUT &= boosterRGB_BLUE;
}
