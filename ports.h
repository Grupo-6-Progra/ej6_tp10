/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ports.h
 * Author: ivan
 *
 * Created on 25 de mayo de 2021, 0:54
 */

#ifndef PORTS_H
#define PORTS_H

#ifdef __cplusplus
extern "C" {
#endif

void bitSet(char, unsigned int);
void bitClr(char, unsigned int);
char bitGet(char, unsigned int);
void bitToggle(char, unsigned int);
void maskOn(char, uint16_t);
void maskOff(char, uint16_t);
void maskToggle(char, uint16_t);


#ifdef __cplusplus
}
#endif

#endif /* PORTS_H */

