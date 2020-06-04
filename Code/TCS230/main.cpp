 #include "mbed.h"
 #include "TCS3200.h"
 
 
 #include "LCD_DISCO_F746NG.h"
LCD_DISCO_F746NG lcd;
 
 
 Serial pc(USBTX, USBRX);
 
 DigitalOut led(LED1) ;
 
 TCS3200 color(D0,   D9,  D2,   D3,   D4);  //Create a TCS3200 object 
 //            S0    S1    S2   S3    OUT
 
 int main() {
     
     //Set the scaling factor to 100%
     color.SetMode(TCS3200::SCALE_20);    
     
     float red, green, blue, clear, somme;
     
     char buffer[50];
     
        lcd.DisplayStringAt(0,  LINE(0),  (uint8_t  *) "#######",CENTER_MODE);
        lcd.DisplayStringAt(0,  LINE(2),  (uint8_t  *) "#######",CENTER_MODE);
        lcd.DisplayStringAt(0,  LINE(10),  (uint8_t  *) "Primera 0.1",RIGHT_MODE);
      
 
     while(1){
         //Read the HIGH pulse width in uS for each color.
         //The lower the value, the more of that color is detected 
         red = color.ReadRed();
         green = color.ReadGreen();
         blue = color.ReadBlue();
         //clear = color.ReadClear();
         
         green = green * 0.8;
         
         
         somme = red + green + blue;
         
         red = red/somme;
         green = green/somme;
         blue = blue/somme;
         
         //red = 100*red;
         //green = 100*green;
         //blue = 100*blue;
 
         pc.printf("RED: %f   GREEN: %f   BLUE: %f   \n", red, green, blue);
         //pc.printf("Hello world");
         
         if (red < 0.20 && (abs(green - blue)< 0.05)){
             //pc.printf("ROUGE !!");
             sprintf (buffer, "Rouge__");}
         else if (red<0.20 && green<0.40 && blue >0.42){
             //pc.printf("ORANGe!!!!!");
             sprintf (buffer, "Orange_");}
         else if (red<0.20 && blue<0.40 && green>0.42){
             //pc.printf("ROSE!!!!");
             sprintf (buffer, "Rose___");}
         else if (green <0.29) {
             //pc.printf("VERT !!!!");
             sprintf (buffer, "Vert___");}
         else if (blue<0.28 && red<0.36 && green>0.38){
             //pc.printf("Magenta");
             sprintf (buffer, "Magenta");}
         else if ((blue < 0.28) && (red>0.30) && (green>0.30)) {
             //pc.printf("BLEU !!!");
             sprintf (buffer, "Bleu___");}
         else {
             pc.printf("RAS!!");
             sprintf (buffer, "RAS____");}
         
         
        lcd.DisplayStringAt(0,  LINE(1),  (uint8_t  *) buffer,CENTER_MODE);
        //lcd.DisplayStringAt(0,  LINE(0),  (uint8_t  *) "########",CENTER_MODE);
        //lcd.DisplayStringAt(0,  LINE(2),  (uint8_t  *) "#######",CENTER_MODE);
         
         
         
         
         
         //led =1;
            
         wait(0.1);
     }
 }
