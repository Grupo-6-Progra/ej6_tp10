#include <stdio.h>
#include "ports.h"

char user_input();

int main (void)
{
    char ingreso;
    
    while ((ingreso = user_input())!= 'q') //Mientras no se ingrese solo una q, no se sale del programa 
    {
        if(ingreso <= '7' && ingreso >= '0')
        {
            bitSet('A', ingreso - '0'); //prendo solo el bit indicado al recibir un número del 0 al 7
        }
        
        else if(ingreso == 't')
        {
            maskToggle('A', 0xFF); //cambio de estado todos los LEDS al recibir una "t"
        }
        
        else if(ingreso == 'c')
        {
           maskOff('A',0xFF); //apago todos los bits al recibir una "c"
        }
        
        else if(ingreso == 's')
        {
            maskOn('A', 0xFF); // enciendo todos los bits al recibir una "s"
        }
        
        //ahora, imprimimos el valor del puerto A:
        
        printf("Puerto A: ");
        int i;
        for(i = 0; i < 8; i++)
        {
            printf("%d", bitGet('A', 7 - i)); 
        }
        printf("\n\n");
       
    }
    
    return 0;
}

char user_input(void)
{
    int c; //variable que almacena el caracter ingresado
    
    char error = 1; //variable que indica si hubo error en el ingreso de datos
    
    char resultado;
    
    while(error == 1)
    {
        error = 0; //no habra error hasta encontrar alguno
        
        printf("•Ingrese:  el  número  del  0  al  7  del  LED  que  se  desea prender\n");
        printf("•La letra 't' para cambiar todos los LEDs al estado opuesto\n");
        printf("•La letra 'c', para apagar todos y la letra 's', para prender todos.\n");
        printf("•La letra 'q', para finalizar el programa.\n");
        
        c = getchar();
    
        if(c >= '0' && c <= '9')
        {
            if(c >= '0' && c <= '7')
            {
                resultado = c;
                if((c = getchar() )!= '\n') //si se ingreso mas de un caracter, es un error
                {
                    error = 1;
                }
            }
            
            else
            {
                error = 1;
                printf("Los bits estan numerados del 0 al 7\n");
            }
        }
        
        else if(c == 't' || c == 'c' || c == 's' || c == 'q')
        {
            resultado = c;
            
            if((c = getchar() )!= '\n') //si se ingreso mas de un caracter, es un error
            {
                error = 1;
            }
        }
   
        else
        {
            error = 1; //si se ingreso otro caracter, es un error
        }
        
        if (error == 1)
        {
            
            while(c!='\n') //vaciamos el buffer de entrada
            {
                c = getchar();
            }
            
            printf("Ingreso invalido. Ingrese nuevamente.\n\n");
        }
        
    }
    
    return resultado;
    
}