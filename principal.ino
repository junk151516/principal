
int pinEnvioLuz=9;
String marcadorInicio="1011";
String marcadorFinal="0100";
//
int congelador = -16;

int conservador  = 2;

int tAcomuladoCong = 16; 

int tAcomuladoPuerta = 500; 
String trama = "";

void setup() {

  pinMode(pinEnvioLuz, OUTPUT);
    //
    Serial.begin(9600);
    trama = organizarDatosAEnviar(congelador,conservador,tAcomuladoCong,tAcomuladoPuerta);
}

void loop() {

  enviarDatosLuz(trama);
//enviarDatosLuz(organizarDatosAEnviar(congelador,conservador,tAcomuladoCong,tAcomuladoPuerta));
//digitalWrite(9, HIGH); 
//Serial.println(s);
 //delay(1000); 
    
}




void enviarDatosLuz(String entrada)
{
  
for(int i=0;i<entrada.length();i++)
{
if(entrada.charAt(i)=='1')
{
  digitalWrite(pinEnvioLuz, HIGH);  
              
}else{
  digitalWrite(pinEnvioLuz,LOW); 
}
    //delay(1000/5); 
  //delay(1); 
 // delayMicroseconds(500);              // wait for a second
    delayMicroseconds(300);              // wait for a second

}


  
}


String organizarDatosAEnviar(int cong, int cons, int tAcCong, int tAcPuer){//los datos se envian en bloques de 20 

   if(cong > 11){
     cong = 11;
   }     
   if(cons > 11){
      cons = 11;
   }    
   if(tAcCong > 32767){
      tAcCong = 32767;
   } 
   if(tAcPuer > 32767){
      tAcPuer = 32767;
   } 
   
  String resultado="";      
  String sCong = String(tAcCong,BIN); 
  String congelador = String(cong+52,BIN);
  String conservador = String(cons+52,BIN);
  String tACongelador = String(tAcCong+32767,BIN);
  String tAcPuerta = String(tAcPuer+32767,BIN);

   
    while(congelador.length()<6){    
    congelador = "0"+congelador;
   }  
   while(conservador.length()<6){    
    conservador = "0"+conservador;
   }
   while(conservador.length()<6){    
    conservador = "0"+conservador;
   }
   while(tACongelador.length()<16){    
    tACongelador = "0"+tACongelador;
   }
   while(tAcPuerta.length()<16){    
    tAcPuerta = "0"+tAcPuerta;
   }
   resultado = marcadorInicio + "0" + congelador + tACongelador + marcadorFinal;    
   resultado = resultado + marcadorInicio + "1" + conservador + tAcPuerta + marcadorFinal; 
   Serial.println(resultado);
   return resultado;
}

