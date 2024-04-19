//Universidad de Guadalajara
//Centro Universitario de Ciencias Exactas e Ingenierias
//Aguilar Rodriguez Carlos Adolfo 215860049
//Seminario de Solucion de Problemas de Sensores y Acondicionamiento de Señal D-09
//Practica 8 Sensor Piroelectrico
// ----------------------Configuracion del LCD-------------------------
#define LCD_RS_PIN PIN_D0
#define LCD_RW_PIN PIN_D1
#define LCD_ENABLE_PIN PIN_D2
#define LCD_DATA4 PIN_D3
#define LCD_DATA5 PIN_D4
#define LCD_DATA6 PIN_D5
#define LCD_DATA7 PIN_D6
// ------------------Configuraciones de Microcontrolador---------------
#include<18f4550.h>
#fuses HS NOWDT NOBROWNOUT NOLVP CPUDIV1
#use delay(clock=8Mhz)
#include <lcd.c>

void main(){

set_tris_B(0x00);
set_tris_A(0xFF);
output_B(0x00);
//Inicializacion del LCD
lcd_init ();
lcd_putc('\f');
lcd_gotoxy (1, 1);
lcd_putc("AguilarRodriguez");
lcd_gotoxy (5, 2);
lcd_putc("215860049");
delay_ms (3000);
lcd_putc('\f');
lcd_gotoxy (4, 1);
lcd_putc("Practica 8");
lcd_gotoxy (2, 2);
lcd_putc("Sensor Piroelectrico");
delay_ms (3000);
lcd_putc('\f');

output_B(0x01);
delay_ms(1000);
while(true)
{
 if(input(pin_A0)==1)
 {
 
 lcd_gotoxy (1, 1);
 printf(lcd_putc,"Sensor Activo");
 output_B(0x01);
 delay_ms(3000);
 lcd_putc('\f');
 }
 else
 lcd_gotoxy (1, 1);
 printf(lcd_putc,"Sensor Inactivo");
 output_B(0x00);
}
}
 
 
