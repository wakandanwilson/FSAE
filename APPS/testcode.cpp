

const int signal1 = A0;
const int signal2 = A1;

void setup(){
    Serial.begin(9600);
    pinmode(signal1, INPUT);
    pinmode(signal2, INPUT);

    digitalWrite(signal1, HIGH);
    digitalWrite(signal2, HIGH);

    int minVolt = 0;
    int maxVolt = 5;

    Serial.println("APPS monitoring starting");
}

void loop(){
    //read raw analog values
    int analogSignal1 = analogRead(signal1);
    int analogSignal2 = analogRead(signal2);

    //convert bit values voltage values (0-5v)
    float voltSignal1 = map(analogSignal1,0,1023,0,5000)/1000.0;
    float voltSignal2 = map(analogSignal2,0,1023,0,5000)/1000.0;

    //print voltage values
    Serial.print("Signal 1: ");
    Serial.print(voltSignal1);
    Serial.print("V");
    Serial.print(", Signal 2: ");
    Serial.print(voltSignal2);
    Serial.println("V");
}