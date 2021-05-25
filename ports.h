/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ports.h
 * 
 * Author: Alegre, Marcos
 *         Di Sanzo, Bruno
 *         Hertter, José Iván
 *         Ibañez, Lucía
 *  
 * Created on 25 de mayo de 2021, 0:54
 */

#ifndef PORTS_H
#define PORTS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
/*
 * Función que enciende un bit de un puerto
 *      Recibe el puerto y el bit a modificar
 */
void bitSet(char, unsigned int); //

/*
 * Función que apaga un bit de un puerto
 *      Recibe el puerto y el bit a modificar
 */
void bitClr(char, unsigned int); //

/*
 * Función que devuelve el valor de un bit de un puerto
 *      Recibe el puerto y el bit a leer
 */
char bitGet(char, unsigned int); //

/*
 * Función que alterna el estado de un bit de un puerto
 *      Recibe el puerto y el bit a modificar
 */
void bitToggle(char, unsigned int); //

/*
 * Función que enciende varios bits de un puerto
 *      Recibe el puerto y los bits a modificar mediante una máscara
 */
void maskOn(char, uint16_t); //

/*
 * Función que apaga varios bits de un puerto
 *      Recibe el puerto y los bits a modificar mediante una máscara
 */
void maskOff(char, uint16_t); //

/*
 * Función que alterna el estado de varios bits de un puerto
 *      Recibe el puerto y los bits a modificar mediante una máscara
 */
void maskToggle(char, uint16_t); //


#ifdef __cplusplus
}
#endif

#endif /* PORTS_H */

