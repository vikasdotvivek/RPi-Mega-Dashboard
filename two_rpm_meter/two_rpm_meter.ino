//RPM Tester

//float value=0;
float rev=0;
int rps;
int oldtime=0;
int time;
int speedk;
float rev1=0;
int rpm1;
int oldtime1=0;
int time1;
//int pin=7;

void isr() //interrupt service routine
{
rev++;
}
void isr1() //interrupt service routine
{
rev1++;
}


void setup()
{
  
  Serial.begin(9600);
  /*
pinMode(4,OUTPUT);
digitalWrite(4,HIGH);

pinMode(5,OUTPUT);
digitalWrite(5,HIGH);
*/
  attachInterrupt(4,isr,RISING);  //attaching the interrupt
 attachInterrupt(1,isr1,RISING);//attaching the interrupt
}

void loop()
{
delay(200);
detachInterrupt(4);  //detaches the interrupt
//Serial.print( " time ");
//Serial.print(  time );
time=millis()-oldtime;        //finds the time 
rps=(rev/time)*60000;         //calculates rpm
oldtime=millis();
//speedk = ((2* 3.1415926536 *0.2795 * rps * 3.6)/4);//saves the current time
rev=0;

Serial.print("  rpm = ");
Serial.println(  rps/4  );

//Serial.print("  primary rpm = ");
//Serial.print(  rps  );
attachInterrupt(4,isr,RISING);
detachInterrupt(1);
//detaches the interrupt

//Serial.print(time1);
time1=millis()-oldtime1;        //finds the time 
rpm1=(rev1/time1)*60000;         //calculates rpm
oldtime1=millis();             //saves the current time
rev1=0;
Serial.print(" , ");

//Serial.println();
//Serial.print(" secondary rpm =");
Serial.print(  rpm1  );
Serial.println();
//Serial.println("*****UPDATED*****");

attachInterrupt(1,isr1,RISING);





}
