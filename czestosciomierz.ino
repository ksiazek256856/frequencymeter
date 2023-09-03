#include <LiquidCrystal.h>

const int rs = 12, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;  

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Przypisanie numeracji pinów wyświetlacza, które wykorzystano do przesyłu danych

int p = 16; // Inicjalizacja zmiennych potrzebnych do wykonywania odpowiednich pomiarów

int analogInput = 0;  

int i = 0;  

float srednia = 0; 

float pomiary[10]; 

float a1 = 0.3445;  

float b1 = -68.255;  

float a2=11.072;  

float b2=-790.52;  

void setup()  

{ 

 lcd.NoBlink(); // wyłączenie migania podczas resetowania wyświetlacza 

 lcd.begin(16, 2); // ustawienie ilości kolumn i wierszy do wyświetlania danych. 

 pinMode(7,OUTPUT); // przypisanie 7 pinu jako wyjście 

 digitalWrite(7, LOW); // przypisanie stanu 7 pinu jako niski 

 pinMode(analogInput, INPUT); // przypisanie pinu analogowego jako wejście. 

} 

void loop()  // Instrukcja w pętli głównej zabezpieczająca przed wyświetlaniem zbyt małych wartości. 

{ 

   delay(10); 

   value = analogRead(analogInput);  

   if (value<100)  

    { 

     value=0.0; 

    } 

pomiary[i]=value;  // Tworzenie tablicy pomiarów, uśrednianie jej w pętli oraz deklaracja funkcji liniowych, odpowiedzialnych za wyświetlenie prawidłowych wartości. 

i++; 

i=i%p; 

for(int j=0; j<p; j++) 

{ 

 srednia+= pomiary[j]; 

} 

srednia/=p;  

y1 =(int)(a1*srednia+b1); 

y2 = (int)(a2*srednia+b2); 

if(digitalRead(7) == HIGH) // nstrukcja wyświetlająca tryb pomiaru częstotliwości, pod warunkiem wpięcia 7 pinu  mikrokontrolera na stan wysoki. 

{ 

    if(i==0)  

    { 

    	lcd.clear(); 

   	lcd.setCursor(0, 0); 

    	lcd.print("Func2:"); 

    unsigned int len = sizeof(srednia); 

    	len = len +1; 

    lcd.print(" "); 

    lcd.print("y2, 1"); 

    }  

} 

else // Instrukcja wyświetlająca tryb pomiaru wartości analogowej w wypadku stanu piny nr 7 jako niski.

  { 

    lcd.clear(); 

    lcd.setCursor(0, 0); 

    lcd.print("Func1:"); 

    unsigned int len = sizeof(srednia); 

    len = len +1; //  

    if(i==0) 

    { 

      lcd.print(" "); 

      lcd.print(y1, 1); 

     }  

  } 

} 