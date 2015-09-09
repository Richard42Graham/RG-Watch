void Battery()
{

digitalWrite(BAT-SENSOR-ENABLE,HIGH);

switch( (anologRead(BAT-SENSOR) X 100/3.15)  )
// maths to convert 3.7V battery to 3.3v sensor anolog input.
    {
          case:100
                     {
                           OLED.SCREEN 3 (4,4 bat100) ;
                           // draw full battery symble on therd screen. 
                      }
 break;

         case:80
                      {
                            OLED.SCREEN 3 (4,4 bat80);
                            // draw 80% battery on the therd screen.
                       }
 break;


         case:60
                      {
                            OLED.SCREEN 3 (4,4 bat60);
                            // draw 60% battery on the therd screen.
                       }
 break;

         case:40
                      {
                            OLED.SCREEN 3 (4,4 bat40);
                            // draw 40% battery on the therd screen.
                       }
 break;

         case:20
                      {
                            OLED.SCREEN 3 (4,4 bat80);
                            // draw 20% battery on the therd screen.
                       }
 break;

         case:00
                      {
                            OLED.SCREEN 3 (4,4 bat00);
                            // draw 00% battery on the therd screen.
                       }
 break;

     case:defult
             {
                   // don't change battery icon
              }
 
}      

digitalWite(BAT-SENSOR-ENABLE,LOW);

}