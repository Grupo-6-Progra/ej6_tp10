#include <stdio.h>

char user_input();

int main (void)
{
    
    
    return 0;
}

char user_input(void)
{
    int c; //variable que almacena el caracter ingresado
    
    char error = 1; //variable que indica si hubo error en el ingreso de datos
    
    char resultado;
    
    while(error == 1)
    {
        error = 0; //nop habra error hasta encontrar alguno
        
        c = getchar();
    
        if(c >= '0' && c <= '9')
        {
            if(c >= '0' && c <= '7')
            {
                resultado = c;
            }
            
            else
            {
                error = 1;
                printf("Los bits estan numerados del 0 al 7");
            }
        }
        
        else if(c == 't' || c == 'c' || c == 's' || c == 'q')
        {
            resultado = c;
        }
   
        else
        {
            error = 1; //si se ingreso otro caracter, es un error
        }
        
        if(getchar() != '/n') //si se ingreso mas de un caracter, es un error
        {
            error = 1;
        }
    }       
    
}