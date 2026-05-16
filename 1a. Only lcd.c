 #include<lpc214x.h>
 #define RS 1<<20
 #define EN 1<<21
 void delay(unsigned char time){
 unsigned i,j;
 for(i=0;i<time;i++)
 for(j=0;j<5000;j++);
 }
 void LCD_data(unsigned char ch)
 {
 IOCLR0=0x000FF000;
 IOSET0=ch<<12;
 IOSET1=RS;
 IOSET1=EN;
 delay(100);
 IOCLR1=EN;
 }

 void LCD_cmd(unsigned char ch)
 {
 IOCLR0=0x000FF000;
 IOSET0=ch<<12;
 IOCLR1=RS;
 IOSET1=EN;
 delay(100);
 IOCLR1=EN;

 }

 void LCD_init()
 {
 IODIR0=0x000FF000;
 IODIR1=RS | EN;
 LCD_cmd(0X38);
 LCD_cmd(0X06);
 LCD_cmd(0X0C);
 LCD_cmd(0x01);
 
 }

 int main(void){
 unsigned char *ch1 ="SCOE ";
 unsigned char *ch2 ="E&TC 304B003";
 LCD_init();
 PINSEL0=0x00000000;
 IODIR0=0x000FF0F0;
 IOSET0=0x000000F0;
 LCD_cmd(0x80);
 while(*ch1)
 LCD_data(*ch1++);
 
 LCD_cmd(0xc0);
 while(*ch2)
 LCD_data(*ch2++);
return 0;
}

