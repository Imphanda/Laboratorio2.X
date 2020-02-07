//------------------------------------------------------------------------------
//                                                                             *
//    Filename:      LaboratorioContador                                       *
//    Fecha:         04/02/2020                                                *
//    Version:       v.2                                                       *
//    Author:        Nancy Alejandra Mazariegos                                *
//    Carnet:        17227                                                     *
//    Description:   Laboratorio 2                                             *
//                                                                             *
//------------------------------------------------------------------------------
// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
<<<<<<< Updated upstream
<<<<<<< Updated upstream
#define _XTAL_FREQ 8000000
#include<stdint.h>

=======
#define _XTAL_FREQ 4000000//Reloj interno 4Mhz
#include<stdint.h>

=======
#define _XTAL_FREQ 4000000//Reloj interno 4Mhz
#include<stdint.h>

>>>>>>> Stashed changes


uint8_t referencia;//variable para contador de referencia
uint8_t banderaS;//bandera boton de suma
uint8_t banderaR;//bandera boton de resta
uint8_t Control;
uint8_t Control2;
<<<<<<< Updated upstream
uint8_t Hexadecimal[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,0x77,0x7C,0x39,0x5E,0x79,0x71};
uint8_t Hexadecimal2[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,0x77,0x7C,0x39,0x5E,0x79,0x71};//Numeros para el display
=======
uint8_t Control3;
uint8_t Hexadecimal[16]={63,6,91,79,102,109,125,7,127,103,119,124,57,94,121,113};
uint8_t Hexadecimal2[16]={63,6,91,79,102,109,125,7,127,103,119,124,57,94,121,113};//Numeros para el display
>>>>>>> Stashed changes
uint8_t Unidades;
uint8_t Decenas;

void InDisplay(void);
void inicio(void);
void puertos(void);
void botones(void);
void Alarma(void);
<<<<<<< Updated upstream
=======
void Cambio(void);
>>>>>>> Stashed changes

void __interrupt() isr(void){//direccion 0x04 siempre en la interrupcion
    if(RBIF == 1){
        
    //--------------------------SUMA-------------------------------------------
    if (PORTBbits.RB0==0&&banderaS==1){//condicion que se debe cumplir
        referencia++;//realiza la suma
        banderaS=0;//apaga la bandera
        RBIF = 0;
    }
    
    
    //-----------------------RESTA---------------------------------------------
    else if (PORTBbits.RB1==0&&banderaR==1){
        referencia--;//realiza la resta
        banderaR=0;//apaga la bandera
        RBIF = 0;
    }
    else{
        RBIF =0;
    }
    }
    //--------------------------------TMR0--------------------------------------
    if(TMR0IF==1){
<<<<<<< Updated upstream
        TMR0=100;
        PORTDbits.RD6=~PORTDbits.RD6;
        PORTDbits.RD7=~PORTDbits.RD7;
        TMR0IF=0;
        return;
=======
        Cambio();
        TMR0=6;
        TMR0IF=0;
        
>>>>>>> Stashed changes
    }
    //--------------------------------ADC---------------------------------------
    if(ADCON0bits.GO_DONE==0){
        PIR1bits.ADIF=0;
        Control=ADRESH;
        Control2=ADRESH;
<<<<<<< Updated upstream
        PORTDbits.RD5=1;
        ADCON0bits.GO_DONE=1;
        RBIF =0;
    }
    
=======
        ADCON0bits.GO_DONE=1;
        RBIF =0;
    }
    TMR0IF=0;
>>>>>>> Stashed changes
    
    
}

void main(void){
        inicio();//Puerto y configuracion de inicio
        banderaS=0;//botones habilitados desde el inicio
        banderaR=0;
        referencia=0;
<<<<<<< Updated upstream
        PORTDbits.RD7=1;
        PORTDbits.RD6=0;
=======
        Control3=1;
>>>>>>> Stashed changes
    while(1){
        botones();
        puertos();
        Alarma();
        __delay_ms(1);
        InDisplay();
    }    
        
}



void inicio(void){// Se definen los puertos de entrada y salida
    //----------------------------------4Mhz------------------------------------
    OSCCON=0b1100001;
    
    //--------------------------------ADC --------------------------------------
    ADCON0bits.ADCS1 = 0;
    ADCON0bits.ADCS0 =1;
    ADCON0bits.CHS3 = 1;//PORTB 2
    ADCON0bits.CHS2 = 0;
    ADCON0bits.CHS1 = 0;
    ADCON0bits.CHS0 = 0;
    ADCON0bits.GO_DONE =1;
    ADCON0bits.ADON = 1; //ADC Puerto de Entrada AN8
    ADCON1bits.ADFM=0;
    ADCON1bits.VCFG0=0;
    ADCON1bits.VCFG1=0;//Justificado izquierda
    ANSEL=0;
    ANSELH = 0b00000001;
    
    
    //-----------------------------PUERTOS--------------------------------------
    
    TRISA = 0;//Referencia
    TRISB = 0b00000111;//Botones y Potenciometro
    TRISC = 0;//Salida Display
    TRISD = 0;//Salida Alerta y Multiplexor
    TRISE = 0;//Entrada pot
    
    //---------------------------INTERRUP---------------------------------------
    INTCON= 0b11101100;//Habilitar Interrupciones**
    PIE1bits.ADIE=1;
    PIR1bits.ADIF=0;
    IOCB = 0b00000111;
    
    //--------------------------TMR0--------------------------------------------
    OPTION_REG=0b00000000;//**

    
    
    PORTA=0;
    PORTB=0;
    PORTC=0;
    PORTD=0;
<<<<<<< Updated upstream
    TMR0=100;
=======
    TMR0=6;
>>>>>>> Stashed changes
}


void InDisplay(void){
<<<<<<< Updated upstream
    Unidades=Control & 0x0F;
    Decenas=((Control2 & 0xF0)/16);
    if(PORTDbits.RD6==1){
        PORTC=~Hexadecimal[Unidades];
    }
    if(PORTDbits.RD7==1){
        PORTC=~Hexadecimal2[Decenas];
    }
=======
    Unidades=Control/16;
    Decenas=Control2%16;
    if(Control3==0){
        PORTC=~Hexadecimal[Unidades];
        PORTDbits.RD6=1;
        PORTDbits.RD7=0;
//        PORTDbits.RD5=0;
    }
    if(Control3==1){
        PORTC=~Hexadecimal2[Decenas];
        PORTDbits.RD6=0;
        PORTDbits.RD7=1;
//        PORTDbits.RD5=1;
    }

>>>>>>> Stashed changes
    return;

}

void Alarma(void){
    if(Control>=referencia){
        PORTDbits.RD4=1;
    }
    else{
        PORTDbits.RD4 =0;
    }
}

void botones(void){//unicamente habilita las banderas
     if(PORTBbits.RB0==1&&banderaS==0)//Estado al presionar boton inicio
    {
        banderaS=1;
    }
    if(PORTBbits.RB1==1&&banderaR==0)//Estado al presionar boton inicio
    {
        banderaR=1;
    }
}
void puertos(void){
    PORTA=referencia;
}

<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
void Cambio(void){
    if(Control3==0){
        Control3=1;
    }
    else{
        Control3=0;   
    }
    return;
}

>>>>>>> Stashed changes
