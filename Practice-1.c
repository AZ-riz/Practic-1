/*
 * Practice-1.c
 *
 * Created: 3/4/2021 11:27:06 PM
 * Author: modar
 */

#include <io.h>
#include <delay.h>
#include <math.h>
#define condition_PushB if(PINA.0==0 || PINA.1==0 || PINA.2==0 || PINA.3==0 || PINA.4==0)return;
#define condition_SW1 if(PINA.3 == 1){PORTC=0; return;}
#define condition_SW2 if(PINA.4 == 1){PORTC=0; return;}

void model_1_PushB(void);
void model_2_PushB(void);
void model_3_PushB(void);
void model_4_SW1(void);
void model_5_SW2(void);

int i;
int j;
void main(void)
{ 
 

 DDRA=0b00000000;
 PORTA=255;
 DDRC=255;
 PORTC=0;

while(1)
    {   
   
    
       if(PINA.0==0)
       model_1_PushB(); 
       
       if(PINA.1==0)
       model_2_PushB();
       
       if(PINA.2==0)
       model_3_PushB();
       
       if(PINA.3==0)
       model_4_SW1();  
       
       if(PINA.4==0)
       model_5_SW2();
       
       
    }
}                          


void model_1_PushB(void)
{
   
       while(1)   
       { 
          
       for( i=0 ; i< 4; i++)
        { 
         PORTC = pow(2,i) + pow(2,7-i); 
          condition_PushB;
          delay_ms(50); 
          
          for(j=i+1 ; j<=6-i ; j++ )
         { 
           PORTC = pow(2,i) + pow(2,7-i)+pow(2,j);
           condition_PushB;
           delay_ms(50); 
           
           } 
             

           for(j=6-i ; j>=i+1 ; j--)
           {
            PORTC = pow(2,i) + pow(2,7-i)+pow(2,j);
            condition_PushB;
            delay_ms(50);
            
            } 
            
            
         }
        
        
       }
}


void model_2_PushB(void)
{
  while(1)
   {
     PORTC=170; 
     delay_ms(30);
     condition_PushB;
     PORTC=85; 
     delay_ms(30); 
     condition_PushB;
   }

}

void model_3_PushB(void) 
{   PORTC=0;
   while(1)
   { 
   
     for(i=0  ; i<8 ; i++)
      {
        PORTC = PORTC + pow(2,i);  
        condition_PushB;
        delay_ms(50);
      } 
      
      for(i=0  ; i<8 ; i++)
      {
        PORTC = PORTC - pow(2,i); 
        condition_PushB;
        delay_ms(50);
      }
   }
}


void model_4_SW1(void)
{
 while(1)
 { 
  PORTC =0 ;
  
  for(i=0 ; i<8 ; i++)
  {  
    PORTC=PORTC*2;
    
     condition_SW1;
     delay_ms(70);
     
     
    for(j=0 ; j<=i ; j++)
    {
     PORTC=PORTC*2+1;
     
     condition_SW1;
     delay_ms(70);
    }
    
   
  }
     
 }
}

void model_5_SW2(void)
{
  while(1)
  {  int t =50;
    
    while(t>1)
    {
    PORTC = 153;
    
    condition_SW2;
    delay_ms(t);
    
    PORTC = 102;
    
    condition_SW2;
    delay_ms(t); 
    
    t=t-3;
    
    }
  }
}