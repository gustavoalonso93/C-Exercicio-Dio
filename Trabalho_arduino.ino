#define STMP A0
#define S_vent 13

void setup()
   {
    pinMode(STMP, INPUT);
    pinMode(S_vent, OUTPUT);
	Serial.begin(9600);
	}

 double erro = 0;
 double utemp;
 double setPoint = 35;
 int controlePwm = 0;
 double P=0, I=0, D=0;
 double PID = 0;
 double kp=10, ki=1, kd=0.1;
 long T;
 double temperatura=0;
 double convert=0;

void loop(){

     //leitura de temperatura
    convert = ((analogRead(STMP))/1023.0)*5.0;
    temperatura = (convert-0.5)*100;
  
  
  //implementação do PID
   erro = setPoint - temperatura;
   float deltatime = (millis() - T)/1000.0;
   T = millis();

   //P
   P = erro * kp;

   //I
   I += (erro * ki)* deltatime;

   //D
   D = (utemp - temperatura)*kd;
   utemp = temperatura;

   //PID
   PID = P + I + D;
   
   //converte p/ controle
   controlePwm = (PID *(-1.0));
   
   //saida do controle
   analogWrite(S_vent, controlePwm);
   Serial.println(PID);
   Serial.println(temperatura);
   delay(100);
}
   
   
   
   
   
   
   
   
   