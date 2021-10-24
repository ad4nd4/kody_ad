#define trigPin 11
#define echoPin 12
#define buzerPin 8
#define flashPin 5
const long us2s = 1000000;
const int flash = 40; 
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzerPin, OUTPUT);
  pinMode(flashPin, OUTPUT);
 
void loop() {  
  //Serial.print(zmierzOdleglosc());
  //Serial.println(" cm");
  
    mierz();
} 
 
int zmierzOdleglosc() {
  long czas, dystans;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;
 
  return dystans;
}

void buzer(int frequency, float timeToPlay)
{
  float sumBlinked = 0;
  int stateFlash = LOW;
  float sum = 0;
  float period = 1.0/(float)frequency;
  do{  
    digitalWrite(buzerPin, HIGH);
    delayMicroseconds(round(us2s*period/2)); 
    digitalWrite(buzerPin, LOW);
    delayMicroseconds(round(us2s*period/2));
    sum += period; 
    sumBlinked += period;
    if (sumBlinked>(float)(flash)*period)
    {
      sumBlinked = 0;
      if (stateFlash == LOW)
      {
          stateFlash = HIGH;
          digitalWrite(flashPin, HIGH);
      }
      else
      {
          stateFlash = LOW;
          digitalWrite(flashPin, LOW);
      }          
    }
  } while(sum<timeToPlay);
  /*Serial.print(round(us2s*period/2));
  Serial.println(" - polokres");
  Serial.print(sum);
  Serial.println(" - sum");
  Serial.print(period);
  Serial.println(" - period");
  */
}

void mierz() {
  int jakDaleko = zmierzOdleglosc();
  Serial.print(jakDaleko);
  Serial.println(" cm");
  
  int maxFreq = 30000;
  int minFreq = 1000;
  int maxDistance = 400;
  int converter = round((float)(maxFreq-minFreq)/(float)maxDistance);
  //Serial.print(maxFreq-converter*jakDaleko);
  //Serial.println(" - czestotliwosc");
  buzer(maxFreq-converter*jakDaleko, 0.5);
  /*if ((jakDaleko > a) && (jakDaleko < b)) {
      digitalWrite(3, HIGH);
  } else {
      digitalWrite(3, LOW); 
  */
}
