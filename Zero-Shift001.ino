//DC MOTOR CONTROL - Damien Poirier 2018
//ARDUINO NANO

#define PWM_LEVEL 9 //USE ANY PWM PINS
#define DC_MOTOR_A 6
#define DC_MOTOR_B 7

const byte PWM_LEVEL_L1 = 80;
const byte PWM_LEVEL_L2 = 130;
const byte PWM_LEVEL_L3 = 190;
const byte PWM_LEVEL_L4 = 255;

const byte PWM_MAX = 255;

String GET_COMMAND;

void setup()
{
pinMode(PWM_LEVEL, OUTPUT);
pinMode(DC_MOTOR_A, OUTPUT);
pinMode(DC_MOTOR_B, OUTPUT);


Serial.begin(9600);

digitalWrite(DC_MOTOR_A, LOW); //SET MOTOR DRIVER TO STANDBY MODE
digitalWrite(DC_MOTOR_B, LOW);
analogWrite(PWM_LEVEL, PWM_MAX); //SET MAXIMUM DEFAULT SPEED

}



void loop()
{

serialEvent();
delay(100);

}

void serialEvent()
{
while (Serial.available() > 0)
{
char GET_SERIAL_DATA = Serial.read();
GET_COMMAND += GET_SERIAL_DATA;

if (GET_SERIAL_DATA == '#')
{

//FOCUS COMMANDS
//==============

if(GET_COMMAND.endsWith(":F+#")) //out
{
Serial.print(GET_COMMAND);
digitalWrite(DC_MOTOR_A, HIGH);
digitalWrite(DC_MOTOR_B, HIGH);
digitalWrite(DC_MOTOR_A, LOW);
}

if(GET_COMMAND.endsWith(":F-#")) //in
{
Serial.print(GET_COMMAND);
digitalWrite(DC_MOTOR_A, HIGH);
digitalWrite(DC_MOTOR_B, HIGH);
digitalWrite(DC_MOTOR_B, LOW);
}

if(GET_COMMAND.endsWith(":FQ#")) //stop
{
Serial.print(GET_COMMAND);
digitalWrite(DC_MOTOR_A, HIGH);
digitalWrite(DC_MOTOR_B, HIGH);
digitalWrite(DC_MOTOR_A, LOW);
digitalWrite(DC_MOTOR_B, LOW);
}

//SPEED COMMANDS
//==============

if(GET_COMMAND.endsWith(":F1#"))
{
Serial.print(GET_COMMAND);
analogWrite(PWM_LEVEL, PWM_LEVEL_L1);

}

if(GET_COMMAND.endsWith(":F2#"))
{
Serial.print(GET_COMMAND);
analogWrite(PWM_LEVEL, PWM_LEVEL_L2);

}

if(GET_COMMAND.endsWith(":F3#"))
{
Serial.print(GET_COMMAND);
analogWrite(PWM_LEVEL, PWM_LEVEL_L3);

}

if(GET_COMMAND.endsWith(":F4#"))
{
Serial.print(GET_COMMAND);
analogWrite(PWM_LEVEL, PWM_LEVEL_L4);

}
GET_COMMAND = "";
}
}
} 
