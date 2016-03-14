//Minimalist sound detector
#define PIN_ANALOG_IN A0

void setup()
{
  Serial.begin(9600);
}

void loop()
{
 Serial.println(analogRead(PIN_ANALOG_IN));
 delay(1000);
}
