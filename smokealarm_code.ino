float MIN=5.0,M=0.0;
int t=0;
void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
} 
void loop()
{float N;
  N=analogRead(A0);
  Serial.println(N);
  N=N/205;
  if(M!=N)
  Serial.println(N);          // printing the values on serial monitor
   
  if(t<6000)
  {
    t=millis();
    MIN=N;
  }
  else
  {
  float x1=MIN+0.14,x2=MIN+0.22,x3=MIN+0.30;  // the value of x is in accordance with the atmospherical value
  Serial.print("value of min");
  Serial.println(MIN);
   if(N>MIN && N<x1)     
   {
     digitalWrite(13,HIGH);       // 1 LED will light up  
      digitalWrite(12,LOW);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      delay(300);
     }
     else if(N>=x1 && N<x2)
      {
      digitalWrite(13,HIGH);         //2 LED's will blow up depicting the sensivity of alarm
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      delay(300);
      }
      else if(N>x2 && N<=x3)
      {
        
      digitalWrite(13,HIGH);           // 3 LED's will blow up depicting the sensivity of alarm  
      digitalWrite(12,HIGH);
      digitalWrite(11,HIGH);
      digitalWrite(10,LOW);
      
        delay(300);
      }
      else if (N>x3)                      //all LED'S will blow up
      {
        digitalWrite(13,HIGH);
        digitalWrite(12,HIGH);
        digitalWrite(11,HIGH);
        digitalWrite(10,HIGH);
      
        delay(300);
      }
      else
      { 
      digitalWrite(13,LOW);
        digitalWrite(12,LOW);
        digitalWrite(11,LOW);
        digitalWrite(10,LOW);
      
        delay(300);
        
      }
  }
 M=N;     
}

