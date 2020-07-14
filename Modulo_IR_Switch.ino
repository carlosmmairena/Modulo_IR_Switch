/*
 * Recordar que si cambiamos de control, sin dudas tenga otros numeros hexadecimales
 */

#include <IRremote.h>
int pinIR = 8;      // PIN de entrada Digital
IRrecv recibe(pinIR);       // Objeto del receptor infrarojo.
decode_results resultados; //Para obtener el resultado del decodificador

void setup() {
  
  Serial.begin(9600);
  recibe.enableIRIn();
  Serial.println("+-----------------------+");
  Serial.println("|  Seleccione una tecla |");
  Serial.println("+-----------------------+\n");
}

void loop() {
//Si el objteto "recibe" obtiene el resultado del codificador
  if (recibe.decode(&resultados)){
    Serial.println(resultados.value,HEX);//Para ver el número hexadecimal de la tecla que se presione
    
//Según el hexadecimal que obtengamos, vamos a ejecutar diferentes instrucciones.
        switch (resultados.value){

            case 0xFFA25D:
              Serial.println("|     Ha tocado POWER   |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF6897:
              Serial.println("| Ha tocado el número 0 |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF30CF:
              Serial.println("| Ha tocado el número 1 |");
              Serial.println("+-----------------------+");
                break;                
            case 0xFF18E7:
              Serial.println("| Ha tocado el número 2 |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF7A85:
              Serial.println("| Ha tocado el número 3 |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF10EF:
              Serial.println("| Ha tocado el número 4 |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF38C7:
              Serial.println("| Ha tocado el número 5 |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF5AA5:
              Serial.println("| Ha tocado el número 6 |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF42BD:
              Serial.println("| Ha tocado el número 7 |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF4AB5:
              Serial.println("| Ha tocado el número 8 |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF52AD:
              Serial.println("| Ha tocado el número 9 |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF629D:
              Serial.println("|    Ha tocado VOL +    |");
              Serial.println("+-----------------------+");
                break;
            case 0xFFA857:
              Serial.println("|    Ha tocado VOL -    |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF906F:
              Serial.println("|    Ha tocado SUBIR    |");
              Serial.println("+-----------------------+");
                break;
            case 0xFFE01F:
              Serial.println("|    Ha tocado BAJAR    |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF02FD:
              Serial.println("| Ha tocado PLAY|PAUSE  |");
              Serial.println("+-----------------------+");
                break;
            case 0xFFC23D:
              Serial.println("|  Ha tocado ADELANTAR  |");
              Serial.println("+-----------------------+");
                break;
            case 0xFF22DD:
              Serial.println("|  Ha tocado RETRASAR   |");
              Serial.println("+-----------------------+");
                break;
                
       default://Se comenta para evitar que el usuario vea siempre un mensaje de error mientras haya interferencia
            case UNKNOWN:
              Serial.println("Tecla inválida...");
                break;
                
          }

    recibe.resume(); //Se pone a la espera de una tecla...
    delay(100);
    }
}
