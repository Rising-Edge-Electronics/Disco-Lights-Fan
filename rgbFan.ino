/*
 * Author: Priyath Fonseka
 * July 2020
 * Neo Pixel VU meter shield for Arduino UNO
 * 
 * Pin: 8 - LED strip data pin
 * Pin 10 - button pin
 * A0 - audio in
 * 
 */




#include <Adafruit_NeoPixel.h>

#define PIN 3


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

byte blade1[]={0,1,2,3,4,5,6,7};
byte blade2[]={8,9,10,11,12,13,14,15};
byte blade3[]={16,17,18,19,20,21,22,23};

byte r[] = {255,255,255,0,0,75,143};
byte g[]={0,127,255,255,0,0,0};
byte b[]={0,0,0,0,255,130,255};


byte roll[]={0,1,2,3,4,5,6,7};

int brightness=100;


void setup() {

pinMode(PIN,OUTPUT);
}

void loop() {       
pattern1();
pattern2();
}



void pattern1()
{
  int c=0;

for(int k=0;k<10;k++)
{
  
for(int i=0;i<8;i++)
{
  if(c==7)
  c=0;
  
  pixels.setPixelColor(blade1[i],pixels.Color(r[c],g[c],b[c]));
  pixels.setPixelColor(blade2[i],pixels.Color(r[c],g[c],b[c]));
  pixels.setPixelColor(blade3[i],pixels.Color(r[c],g[c],b[c]));
  pixels.setBrightness(brightness);
  pixels.show();
  delay(100);
  pixels.setPixelColor(blade1[i],pixels.Color(0,0,0));
  pixels.setPixelColor(blade2[i],pixels.Color(0,0,0));
  pixels.setPixelColor(blade3[i],pixels.Color(0,0,0));
  pixels.show();
    delay(100);
}

c+=1;
}

}

void pattern2()
{
  
for(int k=0;k<10;k++)
for(int i=0;i<8;i++)
{
  if(roll[i]==8)
  {
    roll[i]=0;
  }
  pixels.setPixelColor(blade1[roll[i]],pixels.Color(r[i],g[i],b[i]));
  pixels.setPixelColor(blade2[roll[i]],pixels.Color(r[i],g[i],b[i]));
  pixels.setPixelColor(blade3[roll[i]],pixels.Color(r[i],g[i],b[i]));
  pixels.setBrightness(brightness);
  pixels.show();
  delay(100);

  roll[i]+=1;
}


}

  
