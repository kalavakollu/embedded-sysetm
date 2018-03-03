#define trig 2
#define echo 3
 int ledred =9;
 int ledyellow = 8;
 int ledgreen = 7;
 int buzzer = 6;
int LDR = A0;
int duration,distance,i;
unsigned int sensorValue;
int TLS=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(ledyellow, OUTPUT);
  pinMode(ledgreen, OUTPUT);
  pinMode(buzzer,OUTPUT);
  }

void loop() {
 
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
 duration = pulseIn(echo, HIGH);
 distance=(duration/2)/29.1;
 Serial.print(distance);
 Serial.println("cm");
 delay(200);
 sensorValue=analogRead(LDR);
 Serial.println(sensorValue);

 if (Serial.available() > 0) 
 {
 TLS=Serial.read();
 }
 switch (TLS)
 {
  case 'R':
  {
  regularmode();
  break;
  
  }
  
  case 'P':
 { 
  pedestrianmode();
  break;
  
 }

 case 'N':
 {
  nightmode();
  break;
  
 }
 
}
}
void regularmode()

  {
  digitalWrite(ledred,HIGH);
  delay(2000);
  digitalWrite(ledred,LOW);
  digitalWrite(ledyellow,HIGH);
  delay(1000);
  digitalWrite(ledyellow,LOW);
  digitalWrite(ledgreen,HIGH);
  delay(2000);
  digitalWrite(ledgreen,LOW);
  digitalWrite(ledyellow,HIGH);
  delay(1000);
  digitalWrite(ledyellow,LOW);
  
  }

  void pedestrianmode() 
 {  
    if(distance<10)
    {
    tone(buzzer, 250); 
    ledyellowblink();
    noTone(buzzer);
     }
   else
    {
   regularmode();
   ledyellowoff();
    }
  }
  
  
void nightmode()
  {
  if(sensorValue<200)
  {
    if(distance<10)
    {
      ledgreenon();
      digitalWrite(ledred,LOW);
    }
    else
    {
      digitalWrite(ledgreen,LOW);
      ledredon();
    }
  }
   else
  {
    regularmode();
   }
  }
    
   void ledgreenon()
   {
   digitalWrite(ledgreen,HIGH);
  
   }
  
   void ledredon()
   {
    digitalWrite(ledred,HIGH);

   }
   
   void ledyellowblink()
   {
    for(i=0;i<11;i++)
    {
      ledyellowon();
    }
   }
    
    void ledyellowon()
   {
    digitalWrite(ledyellow,HIGH);
    delay(100);
    digitalWrite(ledyellow,LOW);
   delay(100);
   }
   void ledyellowoff()
   {
    digitalWrite(ledyellow,LOW);
   }
