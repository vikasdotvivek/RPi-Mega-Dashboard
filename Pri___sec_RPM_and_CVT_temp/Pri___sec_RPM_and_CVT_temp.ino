//long unsigned int told,tnew;
float actualspeed;
/*
#include<SoftwareSerial.h>
SoftwareSerial hc(17,16);
*/
#include <OneWire.h> 
#include <DallasTemperature.h>
#define ONE_WIRE_BUS1 43
#define ONE_WIRE_BUS2 41  
OneWire oneWire1(ONE_WIRE_BUS1);
OneWire oneWire2(ONE_WIRE_BUS2); 
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);

//RPM with speed, four magnets
int sensor1 = 2; // Hall sensor at pin 2
int sensor2 = 3;
int sensor3 = 18;//speed sensor at 18

float rev=0;
int rps;
int speedk;

float rev1=0;
int rpm1;
int oldtime1=0;
int time1;

float rev2=0;
int rpm2;
int oldtime2=0;
int time2;

void isr() //interrupt service routine
{
rev++;
}

void isr1() //interrupt service routine
{
rev1++;
}
void isr2() //interrupt service routine
{
rev2++;
}
int test=0; //////////////////////
void setup() {
Serial.begin(9600);
//hc.begin(9600);
Serial2.begin(9600);
Serial3.begin(9600);
/*
pinMode(sensor1, INPUT); //Sets sensor1 as input
pinMode(sensor2, INPUT); //Sets sensor2 as input
pinMode(sensor3, INPUT);
*/

pinMode(sensor1, INPUT_PULLUP); //Sets sensor1 as input
pinMode(sensor2, INPUT_PULLUP); //Sets sensor2 as input
pinMode(sensor3, INPUT_PULLUP);

rpm1 = 0;
rpm2 = 0;

 Serial3.println("CVT temperature--------TJ DAQ 2020--------------"); 
 // Start up the library 
sensors1.begin(); 
sensors2.begin(); 
Serial3.println(" Requesting temperatures..."); 
Serial3.println("DONE "); 
Serial3.print("Temperature is: "); 
Serial3.println(" ");

}
void loop()
{
delay(500);//Update RPM every second

detachInterrupt(0);
time1=millis()-oldtime1;        //finds the time 
rpm1=(rev1/time1)*60000;         //calculates rpm
oldtime1=millis();             //saves the current time
rev1=0;
attachInterrupt(0,isr1,RISING);


detachInterrupt(1);
time2=millis()-oldtime2;        //finds the time 
rpm2=(rev2/time2)*60000;         //calculates rpm
oldtime2=millis();             //saves the current time
rev2=0;
attachInterrupt(1,isr2,RISING);



detachInterrupt(5);
rps=rev*60*2;
speedk=rps*0.0502*2;
rev=0;
attachInterrupt(5,isr,RISING);


//Serial3.print("1st   ");
Serial3.print(rpm1); //Calculated values are displayed
Serial3.print("\t\t\t");
//Serial3.print("2nd   ");
Serial3.print(rpm2);
Serial3.print("\t\t\t");



//Serial.print("1st   ");
Serial.print(rpm1); //Calculated values are displayed

Serial.print("  ");
//Serial.print("2nd   ");
Serial.print(rpm2);
//Serial.println("   ");
Serial.print("  ");


 sensors1.requestTemperatures(); // Send the command to get temperature readings 
 sensors2.requestTemperatures();
 //Serial3.print("  1st Sensor-->  ");
 Serial3.print(sensors1.getTempCByIndex(0)); 
 //Serial.print(sensors1.getTempCByIndex(0)); 
 Serial3.print("°C");
 //Serial3.print("  2nd Sensor-->  ");
 Serial3.print("\t\t\t");
 Serial3.print(sensors2.getTempCByIndex(0));
 //Serial.println(sensors2.getTempCByIndex(0));
 Serial3.print("°C");
 Serial3.print("\t\t");

/*
Serial2.print(sensors1.getTempCByIndex(0)); 
 //Serial.print(sensors1.getTempCByIndex(0)); 
 Serial2.print("°C");
 //Serial3.print("  2nd Sensor-->  ");
 Serial2.print("\t\t\t");
 Serial2.print(sensors2.getTempCByIndex(0));
 //Serial.println(sensors2.getTempCByIndex(0));
 Serial2.print("°C");
 Serial2.print("\t\t");
*/

Serial.print(sensors1.getTempCByIndex(0));
Serial.print("  ");

Serial.print(sensors2.getTempCByIndex(0));
Serial.print("  ");


 Serial2.print("Speed\t\t\t");
 actualspeed=speedk/4;
Serial2.print(actualspeed);
Serial2.println("\t\t\t");

Serial3.println(actualspeed);

Serial.println(actualspeed);

/*
Serial2.print("Speed\t\t\t");
Serial2.print(speedk/4);
Serial2.println("\t\t\t");
*/
/*
hc.print(rpm1);
hc.print("   ");
hc.print(rpm2);
hc.print("   ");
hc.print(actualspeed);


hc.print("   ");
hc.print("   ");
hc.print(sensors1.getTempCByIndex(0)); 
hc.print("   ");
hc.print("   ");
hc.println(sensors2.getTempCByIndex(0)); 
*/




 //tnew=millis();
 //Serial3.println(tnew-told);
 //delay(100); 
}
