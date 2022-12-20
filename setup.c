/********************************************************************************
* setup.c: Innehåller initieringsrutiner.
********************************************************************************/
#include "header.h"

/* Statiska funktioner: */
static inline void init_ports(void);
static inline void init_interrupts(void);

/* Definition av globala variabler: */
volatile bool led1_enabled = false; /* Lysdioden inaktiverad vid start. */
volatile bool led2_enabled = false;
volatile bool led3_enabled = false;
volatile bool led4_enabled = false;
volatile bool led5_enabled = false;

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar, PCI-avbrott samt AD-omvandlare.       
********************************************************************************/
void setup(void)
{
init_ports();
init_interrupts();
(void)adc_read(POT1);
return;
}

/********************************************************************************
* init_ports: Initerar mikrodatorns I/O-portar.
********************************************************************************/
static inline void init_ports(void)
{
	set(DDRD, LED1);
	set(PORTD, BUTTON1);
	
	set(DDRD, LED2);
	set(PORTD, BUTTON2);
	
	set(DDRB, LED3);
	set(PORTB, BUTTON3);
	
	set(DDRB, LED4);
	set(PORTB, BUTTON4);
	
	set(DDRB, LED5);
	set(PORTB, BUTTON5);
	return;
}

/********************************************************************************
* init_interrupts: 
********************************************************************************/
static inline void init_interrupts(void)
{
	set(PCICR, PCIE2);
	set(PCMSK2, BUTTON1);
	set(PCMSK2, BUTTON2);
	
	set(PCICR, PCIE0);
	set(PCMSK0, BUTTON3);
	set(PCMSK0, BUTTON4);
	set(PCMSK0, BUTTON5);
	
	asm("SEI");
	return;
}