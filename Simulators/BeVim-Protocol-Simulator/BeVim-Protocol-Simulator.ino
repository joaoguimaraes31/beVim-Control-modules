/*
  Simulador de protocolo de comunicação BEvim - Versão 1.0.

  #Pedro henrique Gonçalves Inazawa - Criação.

*/


#include<string.h>
#include<math.h>

String str, inString;
double a = 0.0;
double ts= 0;
double f=0.0;
int stopExperiment = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("O experimento está Parado. Envie -1 para liberar/pausar o experimento");
  Serial.println("Com o experimento liberado, envie uma frequencia positiva para começar a senoide.");
}

void loop()
{

  while(Serial.available()>0){
    int inChar = Serial.read();
    
    if(isDigit(inChar) || inChar == '-'){
      inString += (char)inChar;     
      }
      
    if(inChar =='\n'){
      
      f = (double)inString.toInt();
      Serial.println(inString);
      inString="";
      break;
      }
    
  }

  if(f < 0.0 && f > -1.1){
    
    f = 0.0;
    ts = 0.0;

    if(stopExperiment == 0){
      stopExperiment =1;
      //Serial.println("Experimento Parado. Envie -1 para Iniciar");
      }
    else{
      stopExperiment =0;
      //Serial.println("Experimento Liberado.Envie uma frequencia Positiva, e ela irá mudar.");
      }
      
    
  }

  if(f < -1.1 && f > -2.1){
      
    Serial.println("S1,0,0,0,0");
  }

  if((stopExperiment==0) && f > 0.0){
//     Serial.println("Experimento OK!");
     str="";

    str+="S1,";
    str+=String(sin(a));
    str+=",";
    str+=String(sin(a));
    str+=",";
    str+=String(sin(a));
    str+=",";
    str+=String(ts);
    Serial.println(str);
    Serial.println(f);
    
    a+=PI/2.0;
  
    ts+= 250 * 1.0/f ;  

    delay(1000);
    }
    
  
  }


