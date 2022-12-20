#ifndef HEADER_H_
#define HEADER_H_

 #include "misc.h"

#define LED1 D6  /* Pin 6 */
#define LED2 D7  /* Pin 7 */
#define LED3 B0  /* Pin 8 */ 
#define LED4 B1  /* Pin 9 */
#define LED5 B2  /* Pin 10 */

#define BUTTON1 D2  /* Pin 2 */
#define BUTTON2 D3  /* Pin 3 */ 
#define BUTTON3 B3  /* Pin 11 */ 
#define BUTTON4 B4  /* Pin 12 */
#define BUTTON5 B5  /* Pin 13 */

#define POT1 C0    /* Pin A0 */

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar, PCI-avbrott samt AD-omvandlare.
********************************************************************************/
void setup(void);

/********************************************************************************
* adc_read: Läser av insignalen på angiven analog pin och returnerar motsvarande
*           digitala värde mellan 0 - 1023.
*
*           - pin: Den analoga pin som ska läsas av.
********************************************************************************/
uint16_t adc_read(const uint8_t pin);  
                                         

/********************************************************************************
* adc_get_pwm_values: Läser av angiven analog pin och beräknar sedan on- och
*                     off-tid för PWM-generering via angiven periodtid.
*                     Beräknade värden sparas på angivna adresser och indikerar
*                     tiden som lysdioden ska vara tänd respektive släckt.
*
*                     - pin          : Den analoga pin A0 - A5 som ska läsas av.
*                     - pwm_period_us: Periodtid för PWM i mikrosekunder.
*                     - pwm_on_us    : Pekare till variabel där on-tiden ska
*                                      lagras i mikrosekunder.
*                     - pwm_off_us   : Pekare till variabel där off-tiden ska
*                                      lagras i mikrosekunder.
********************************************************************************/
void adc_get_pwm_values (const uint8_t pin,
const uint16_t period_us,
uint16_t* on_time_us,
uint16_t* off_time_us ); 

/********************************************************************************
* pwm_run: Kontrollerar ljusstyrkan på en lysdiod med PWM-generering under en
*          period via avläsning av angiven potentiometer.
*
*          - pot_pin  : Analog pin A0 - A5 som potentiometern är ansluten till.
*          - period_us: Periodtid för PWM i mikrosekunder.
********************************************************************************/
void pwm_run(const uint8_t pot_pin,
           const uint16_t period_us);

/********************************************************************************
* delay_us: Genererar fördröjning mätt i mikrosekunder.
*
*           - delay_time_us: Pekare till fördröjningstiden i mikrosekunder.
********************************************************************************/
void delay_us(const volatile uint16_t* delay_time_us); 




/* Definition av globala variabler: */
extern volatile bool led1_enabled; /* Inkluderar ifall lysdioden är aktiverad eller inte */
extern volatile bool led2_enabled; /* Inkluderar ifall lysdioden är aktiverad eller inte */
extern volatile bool led3_enabled; /* Inkluderar ifall lysdioden är aktiverad eller inte */
extern volatile bool led4_enabled; /* Inkluderar ifall lysdioden är aktiverad eller inte */
extern volatile bool led5_enabled; /* Inkluderar ifall lysdioden är aktiverad eller inte */



#endif
