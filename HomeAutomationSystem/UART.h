/*
 * UART.h
 *
 * Created: 11.11.2014 21:24:05
 *  Author: Bernhard
 */ 


#ifndef UART_H_
#define UART_H_

#ifndef F_CPU
/* In neueren Version der WinAVR/Mfile Makefile-Vorlage kann
   F_CPU im Makefile definiert werden, eine nochmalige Definition
   hier wuerde zu einer Compilerwarnung fuehren. Daher "Schutz" durch
   #ifndef/#endif 
 
   Dieser "Schutz" kann zu Debugsessions f�hren, wenn AVRStudio 
   verwendet wird und dort eine andere, nicht zur Hardware passende 
   Taktrate eingestellt ist: Dann wird die folgende Definition 
   nicht verwendet, sondern stattdessen der Defaultwert (8 MHz?) 
   von AVRStudio - daher Ausgabe einer Warnung falls F_CPU
   noch nicht definiert: */
#warning "F_CPU war noch nicht definiert, wird nun nachgeholt mit 2000000"
#define F_CPU 16000000UL  // Systemtakt in Hz - Definition als unsigned long beachten 
                         // Ohne ergeben sich unten Fehler in der Berechnung
#endif
 
#define BAUD 9600UL      // Baudrate

 
// Berechnungen
#define UBRR_VAL ((F_CPU+BAUD*8)/(BAUD*16)-1)   // clever runden
#define BAUD_REAL (F_CPU/(16*(UBRR_VAL+1)))     // Reale Baudrate
#define BAUD_ERROR ((BAUD_REAL*1000)/BAUD) // Fehler in Promille, 1000 = kein Fehler.
 
#if ((BAUD_ERROR<990) || (BAUD_ERROR>1010))
#error Systematischer Fehler der Baudrate gr�sser 1% und damit zu hoch!
#endif



void setup_uart();
int uart_putc(unsigned char c);
void uart_puts (char *s);



#endif /* UART_H_ */