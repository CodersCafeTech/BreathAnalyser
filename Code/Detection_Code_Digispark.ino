 
float sensorValue;  //variable to store sensor value
bool flag = true; // Control loop 
void setup() 
{
  delay(2000); // allow the MQ3 to warm up
  pinMode(0,OUTPUT); // P0 -- buzzer
  pinMode(1,OUTPUT); // P1 -- common anode red
  pinMode(4,OUTPUT); // P4 -- common anode green 
  pinMode(2,INPUT);  // P2 -- Sensor
}

void loop() 
{
  sensorValue = analogRead(1); // read analog input pin P2
  digitalWrite(4,LOW);
  digitalWrite(1,HIGH);
  if(sensorValue > 400)
  {
   if(flag == true)
   {
        for (int i = 0; i <= 6; i++) 
       {
          digitalWrite(4,HIGH);
          digitalWrite(0,HIGH);
          digitalWrite(1,LOW);
          delay(100);        // ...for 100 micro sec
          digitalWrite(0,LOW);
          digitalWrite(1,HIGH);
          delay(100);        // ...for 100 micro sec
       }
       flag = false;
    }
  }
  else
  {
      flag = true ;
      delay(1000);
  }
}
