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
 * Author: Alegre, Marcos
 *         Di Sanzo, Bruno
 *         Hertter, José Iván
 *         Ibañez, Lucía
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

/*
 * Declaración de la estructura de los puertos A y B
 *      Aparecen en este orden por simularse el programa en un sistema little-endian. De esta forma, el puerto B guarda la parte 
 *      menos significativa del puerto B
 */
typedef struct
{
    int8_t B;
    int8_t A;
    
}doubleReg;

/*
 * Declaración de la unión entre el puerto D y los puertos A y B
 */
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
        /*
         Aplicación de la máscara para cambiar el estado del bit recibido a 1
         */
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
        default:
        {
            break;
        }
    }
}

/**************************************************************************/

void bitClr (char nombre, unsigned int nro)
{
    int16_t mascara = ~(1 << nro);//inicialización de una variable que sirve de máscara con todos sus bits en 1 menos el que se desea apagar
    
    switch (nombre)
    {
        /*
         Aplicación de la máscara para cambiar el estado del bit recibido a 0
         */
        case 'D':
        {             
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
        default:
        {
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
            proceso análogo al anterior pero en resultado se guarda un unico Byte correspondiente al puerto recibido
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
        default:
        {
            break;
        }
    }
}

/**************************************************************************/

void bitToggle(char nombre, unsigned int nro)
{
    int16_t mascara = (1 << nro);//inicialización de una variable que sirve de máscara con todos sus bits en 0 menos el que se desea modificar
    
    switch (nombre)
    {
        /*
         * Aplicación de la mascara al puerto recibido mediante el operador OR EXCLUSIVO (que en este caso alterna el valor del bit "encendido"
         * en la máscara, y deja todos los demás como estaban
         */
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
        default:
        {
            break;
        }
    }
}

/*********************************************************************************/

void maskOn(char nombre, uint16_t mascara)
{
    switch (nombre)
    {
        /*
         *Aplicación de la máscara recibida al puerto recibido mediante el operador OR, que encenderá en el puerto todos los bits que estén 
         * encendidos en la máscara, y no modificará los bits que estén en "0" en la máscara.
         */
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
        default:
        {
            break;
        }
    }
}

/********************************************************************************/

void maskOff(char nombre, uint16_t mascara)
{
    switch (nombre)
    {
        /*
         *Aplicación de la máscara recibida negada al puerto recibido mediante el operador AND bit a bit, que apagará en el puerto todos los bits  
         *que estén encendidos en la máscara original, y no modificará los bits que estén en "0" en la misma.
         */
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
        default:
        {
            break;
        }
    }
}

/*********************************************************************************/

void maskToggle(char nombre, uint16_t mascara)
{
    switch (nombre)
    {
        /*
         *Aplicación de la máscara recibida al puerto recibido mediante el operador OR EXCLUSIVO bit a bit, que cambiará el estado en el   
         *puerto todos los bits que estén encendidos en la máscara original, y no modificará los bits que estén en "0" en la misma.
         */
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
        default:
        {
            break;
        }
    }
}