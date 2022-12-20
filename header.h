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
* adc_read: L�ser av insignalen p� angiven analog pin och returnerar motsvarande
*           digitala v�rde mellan 0 - 1023.
*
*           - pin: Den analoga pin som ska l�sas av.
********************************************************************************/
uint16_t adc_read(const uint8_t pin);  
                                         

/********************************************************************************
* adc_get_pwm_values: L�ser av angiven analog pin och ber�knar sedan on- och
*                     off-tid f�r PWM-generering via angiven periodtid.
*                     Ber�knade v�rden sparas p� angivna adresser och indikerar
*                     tiden som lysdioden ska vara t�nd respektive sl�ckt.
*
*                     - pin          : Den analoga pin A0 - A5 som ska l�sas av.
*                     - pwm_period_us: Periodtid f�r PWM i mikrosekunder.
*                     - pwm_on_us    : Pekare till variabel d�r on-tiden ska
*                                      lagras i mikrosekunder.
*                     - pwm_off_us   : Pekare till variabel d�r off-tiden ska
*                                      lagras i mikrosekunder.
********************************************************************************/
void adc_get_pwm_values (const uint8_t pin,
const uint16_t period_us,
uint16_t* on_time_us,
uint16_t* off_time_us ); 

/********************************************************************************
* pwm_run: Kontrollerar ljusstyrkan p� en lysdiod med PWM-generering under en
*          period via avl�sning av angiven potentiometer.
*
*          - pot_pin  : Analog pin A0 - A5 som potentiometern �r ansluten till.
*          - period_us: Periodtid f�r PWM i mikrosekunder.
********************************************************************************/
void pwm_run(const uint8_t pot_pin,
           const uint16_t period_us);

/********************************************************************************
* delay_us: Genererar f�rdr�jning m�tt i mikrosekunder.
*
*           - delay_time_us: Pekare till f�rdr�jningstiden i mikrosekunder.
********************************************************************************/
void delay_us(const volatile uint16_t* delay_time_us); 




/* Definition av globala variabler: */
extern volatile bool led1_enabled; /* Inkluderar ifall lysdioden �r aktiverad eller inte */
extern volatile bool led2_enabled; /* Inkluderar ifall lysdioden �r aktiverad eller inte */
extern volatile bool led3_enabled; /* Inkluderar ifall lysdioden �r aktiverad eller inte */
extern volatile bool led4_enabled; /* Inkluderar ifall lysdioden �r aktiverad eller inte */
extern volatile bool led5_enabled; /* Inkluderar ifall lysdioden �r aktiverad eller inte */



#endif
