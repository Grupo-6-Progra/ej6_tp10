/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: ivan
 *
 * Created on 24 de mayo de 2021, 18:16
 */

#include <stdio.h>
#include <stdlib.h>
#include "ports.h"
/*
 *******************************************************************************
 *              typedefs
 * *****************************************************************************
 */

typedef struct
{
    int8_t B;
    int8_t A;
    
}doubleReg;

typedef union
{
    doubleReg AB;
    uint16_t D;
}port;
 /*
  ********************************************************************
  * definicion de variables "globales statics"
  * ******************************************************************
  */
static port puerto;
/*
 ***********************************************************************
 * Definicion de funciones
 * ********************************************************************
 */
void bitSet(char nombre, unsigned int nro)
{
    int16_t mascara = (1 << nro);//declaración de una variable que sirve de máscara
    
    switch (nombre)
    {
        case 'D':
        {
             /*   En el caso de modificar el puerto D, se aplica una máscara de 16 bits al conjunto
             *  del puerto A y B*/
             
            puerto.D = puerto.D | mascara;
            break;
        }
       
        case 'A':
        {
            puerto.AB.A = puerto.AB.A | mascara;
            break;
        }
        
        case 'B':
        {
            puerto.AB.B = puerto.AB.B | mascara;
            break;
        }    
    }
}

/**************************************************************************/

void bitClr (char nombre, unsigned int nro)
{
    int16_t mascara = ~(1 << nro);//declaración de una variable que sirve de máscara
    
    switch (nombre)
    {
        case 'D':
        {
             /*   En el caso de modificar el puerto D, se aplica una máscara de 16 bits al conjunto
             *  del puerto A y B*/
             
            puerto.D = puerto.D & mascara;
            break;
        }
       
        case 'A':
        {
            puerto.AB.A = puerto.AB.A & mascara;
            break;
        }
        
        case 'B':
        {
            puerto.AB.B = puerto.AB.B & mascara;
            break;
        }    
    }
}

/******************************************************************************/

char bitGet(char nombre, unsigned int nro)
/*
 * Devuelve el valor de un bit de un puerto recibido
 * debe recibir el caracter del puerto para su correcto funcionamiento
*/ 
{
    uint16_t resultado; //definición de variable auxiliar
    switch(nombre)
    {
        case 'D':    
        {
            /*
             En caso de tratarse del puerto D, cargo en "resultado" ambos bytes desde el
             * comienzo de la estructura (puerto A y B), y shifteo a la izquierda hasta
             * que el bit deseado quede en la posición 0, para obtener su valor aplico
             * el operador módulo con 2.
             */
            resultado = (puerto.D >> nro); 
            return resultado % 2;
            break;
        }
        case 'A':
        {
            /*
            proceso análogo al anterior pero en resultado se guarda un unico Byte
            * desde la posición apuntada por el puntero recibido como parámetro.
            */
            resultado = (puerto.AB.A >> nro);
            return resultado % 2;
            break;
        }
        case 'B':
        {
            resultado = (puerto.AB.B >> nro);
            return resultado % 2;
            break;
        }
    }
}

/**************************************************************************/

void bitToggle(char nombre, unsigned int nro)
{
    int16_t mascara = (1 << nro);//declaración de una variable que sirve de máscara
    
    switch (nombre)
    {
        case 'D':
        {
            
            /*  En el caso de modificar el puerto D, se aplica una máscara de 16 bits al conjunto
            *   del puerto A y B*/
            
            puerto.D = puerto.D ^ mascara;
            break;
        }
        case 'A':
        {
            
            /*  En el caso de modificar el puerto D, se aplica una máscara de 16 bits al conjunto
            *   del puerto A y B*/
            
            puerto.AB.A = puerto.AB.A ^ mascara;
            break;
        }
        case 'B':
        {
            
            /*  En el caso de modificar el puerto D, se aplica una máscara de 16 bits al conjunto
            *   del puerto A y B*/
            
            puerto.AB.B = puerto.AB.B ^ mascara;
            break;
        }
    }
}

/*********************************************************************************/

void maskOn(char nombre, uint16_t mascara)
{
    switch (nombre)
    {
        case 'D':
        {
            puerto.D = puerto.D | mascara;
            break;
        }
        case 'A':
        {
            puerto.AB.A = puerto.AB.A | mascara;
            break;
        }
        case 'B':
        {
            puerto.AB.B = puerto.AB.B | mascara;
            break;
        }
    }
}

/********************************************************************************/

void maskOff(char nombre, uint16_t mascara)
{
    switch (nombre)
    {
        case 'D':
        {
            puerto.D = puerto.D & ~mascara;
            break;
        }
        case 'A':
        {
            puerto.AB.A = puerto.AB.A & ~mascara;
            break;
        }
        case 'B':
        {
            puerto.AB.B = puerto.AB.B & ~mascara;
            break;
        }
    }
}

/*********************************************************************************/

void maskToggle(char nombre, uint16_t mascara)
{
    switch (nombre)
    {
        case 'D':
        {
            puerto.D = puerto.D ^ mascara;
            break;
        }
        case 'A':
        {
            puerto.AB.A = puerto.AB.A ^ mascara;
            break;
        }
        case 'B':
        {
            puerto.AB.B = puerto.AB.B ^ mascara;
            break;
        }
    }
}