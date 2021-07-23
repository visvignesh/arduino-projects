// C++ code
//

//enable pin A
int enA = 11;

//input pins 
int in1 = 10;
int in2 = 6;

//enable pin B
int enB = 3;

//input pins 
int in3 = 4;
int in4 = 8;

//setup function
void setup()
{
  //set modes for pins
  pinMode(enA,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  
  Serial.begin(9600);
  while (!Serial);
  
  //display options in Serial Monitor
  Serial.println("Input straight/reverse/turn right/turn left/stop");

}


//loop function
void loop()
{
  //if Serial Monitor is available
  if (Serial.available())
  {    
    //read input string
    String state = Serial.readString();
    
    if (state == "straight")
      
      {         
         //set HIGH & LOW for input pins 1 & 2 
         digitalWrite(in1, HIGH);
         digitalWrite(in2, LOW);
      
         //enable pin A set as HIGH
         digitalWrite(enA, HIGH);
      
         //set LOW & HIGH for input pins 3 & 4      
         digitalWrite(in3, LOW);
         digitalWrite(in4, HIGH);
      
         //enable pin B set as HIGH
         digitalWrite(enB, HIGH);
      
         //print status
         Serial.println("going straight..."); 
      
      }

     if (state == "reverse")
 
       {
         //reverse polarity for input pins       
         
         digitalWrite(in1, LOW);
         digitalWrite(in2, HIGH);
       
         //enable pin A set as HIGH
         digitalWrite(enA, HIGH);
      
         digitalWrite(in3, HIGH);
         digitalWrite(in4, LOW);
       
         //enable pin B set as HIGH
         digitalWrite(enB, HIGH);
       
         //print status
         Serial.println("going back...");
       
       }
    
     if (state == "turn right")

       {
         //same configuration as straight 

         digitalWrite(in1, HIGH);
         digitalWrite(in2, LOW);
       
         //enable pin A set as HIGH
         digitalWrite(enA, HIGH);
      
         digitalWrite(in3, HIGH);
         digitalWrite(in4, LOW);
       
         //enable pin B set as LOW
         digitalWrite(enB, LOW);
       
         //print status
         Serial.println("turning right...");

       }
    
    if (state == "turn left")

      {
      
         //same configuration as straight 
         digitalWrite(in1, HIGH);
         digitalWrite(in2, LOW);
      
         //enable pin A set as LOW
         digitalWrite(enA, LOW);
      
         digitalWrite(in3, LOW);
         digitalWrite(in4, HIGH);
      
         //enable pin B set as HIGH
         digitalWrite(enB, HIGH);
      
         //print status
         Serial.println("turning left...");

      }
    
    if (state == "stop")

      {
         //some configuration given to input pins for the sake 
         //of uniformity
         digitalWrite(in1, HIGH);
         digitalWrite(in2, LOW);
      
         //enable pin A set as LOW
         digitalWrite(enA, LOW);
      
         digitalWrite(in3, HIGH);
         digitalWrite(in4, LOW);
      
         //enable pin B set as LOW
         digitalWrite(enB, LOW);
      
         //print status
         Serial.println("stopped!");

      }
        
    }

}
  