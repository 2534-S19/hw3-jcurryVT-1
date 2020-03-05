#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"

int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    unsigned char history = 0xff;

    // Stops the Watchdog timer.
    initBoard();
    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();
    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);
    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);

    while (1)
    {
        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);
        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c

        if (timer0Expired())
        {
            count0 = ((count0 + 1) % 8);
        }
        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if (timer1Expired())
        {
            history = ((history << 1) | checkStatus_BoosterpackS1());
        }

        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.

        bool check = fsmBoosterpackButtonS1(history);

        //// TODO: If a completed, debounced button press has occurred, increment count1.

        if (check)
        {
            (count1++ );
        }

    }
}
//fsm for debouncing in notes
//
void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}

// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count0) //can i switch to count0 or count1

//this and other case would be same FSM cases w/ different things calling them IE a button vs a timer
{

    switch (count0)
    //what's switch based on
    {
        case 0:  //off
               turnOff_LaunchpadLED2Red();
               turnOff_LaunchpadLED2Green();
               turnOff_LaunchpadLED2Blue();
               break;
        case 1: //state 1 red
            //callred LED
            turnOn_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            break;
        case 2: // green
            turnOff_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            break;
        case 3:  //yellow
            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOff_LaunchpadLED2Blue();
            break;
        case 4:  // blue
            turnOff_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();
            break;
        case 5:  //pink
            turnOn_LaunchpadLED2Red();
            turnOff_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();
            break;
        case 6:   //light blue
            turnOff_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();
            break;
        case 7: //white
            turnOn_LaunchpadLED2Red();
            turnOn_LaunchpadLED2Green();
            turnOn_LaunchpadLED2Blue();
            break;

    }
}

// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count1)
{
    //it's calling colors wrong
    switch ((count1)%8)
    //what's switch based on
    {

    case 0: //state 1 red

        turnOn_BoosterpackLEDRed();
        turnOff_BoosterpackLEDBlue();
        turnOff_BoosterpackLEDGreen();
        break;
    case 1: // green
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        break;
    case 2:  //yellow
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOff_BoosterpackLEDBlue();
        break;
    case 3:  //  blue
        turnOff_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
        break;
    case 4://pink
        turnOn_BoosterpackLEDRed();
        turnOff_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
        break;
    case 5:  //lightblue
        turnOff_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
        break;
    case 6: //white
        turnOn_BoosterpackLEDRed();
        turnOn_BoosterpackLEDGreen();
        turnOn_BoosterpackLEDBlue();
        break;
    case 7:  //off

        turnOff_BoosterpackLEDRed();
                turnOff_BoosterpackLEDBlue();
                turnOff_BoosterpackLEDGreen();
                break;
    }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned char buttonhistory) //what is buttonhistory is that counting button presses so i can switch colors
{

    // do i want my fsm here
    //or do I want to debounce here
    //or boffa
//button hist to know where or no

    //use pull down

    // in summary part of slides

    bool pressed = false;

    static enum
    {
        up, down
    }

    state = up;
    switch (state)
    {
    case up:
        if (buttonhistory == 0xff) //why doesn't it work w/1 mess with this later
        {
            state = down;
            pressed = true;
        }
        break;

    case down:
        if (buttonhistory != 0xff)
        {
            state = up;
            pressed = false;
        }
        break;

    }

    buttonhistory = state; //this so it loops
    return pressed;
}
