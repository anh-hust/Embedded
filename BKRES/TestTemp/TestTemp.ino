//Thermometer with thermistor

/*thermistor parameters:
 * RT0: 10 000 Ω
 * B: 3977 K +- 0.75%
 * T0:  25 C
 * +- 5%
 */

//These values are in the datasheet
#define RT0 100000   // Ω
#define B 3977      // K
//--------------------------------------


#define VCC 5    //Supply voltage
#define R 10000  //R=10KΩ

String wday[8] = {"", "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

char temp[5];
//Variables
  float RT, VR, ln, TX, T0, VRT;

void setup() {
  Serial.begin(9600);
  T0 = 25 + 273.15;                 //Temperature T0 from datasheet, conversion from Celsius to kelvin
}

void loop() {
  VRT = analogRead(A0);              //Acquisition analog value of VRT
  VRT = (5.00 / 1023.00) * VRT;      //Conversion to voltage
  VR = VCC - VRT;
  RT = VRT / (VR / R);               //Resistance of RT

  ln = log(RT / RT0);
  TX = (1 / ((ln / B) + (1 / T0))); //Temperature from thermistor

  TX = TX - 273.15;                 //Conversion to Celsius

  sprintf(temp, "%02d.%02d", (int) temp);
  Serial.println(wday[1]);
  Serial.print("  Temperature: ");
  Serial.print("\t");
  Serial.print(TX);
  Serial.print("C\t\t");
  Serial.print("Resistor: ");
  Serial.print(RT);
  Serial.println();
  delay(1000);

}
