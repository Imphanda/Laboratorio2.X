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



#ifndef ADC_H
#define	ADC_H

#include <xc.h>
#include<stdint.h>

void InicioADC(void);

void InicioADC(void){
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
    return;
    
}

#endif	/* ADC_H */

