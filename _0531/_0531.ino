/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"
int greenPin = 6;
int redPin = 9;
int bluePin = 5;
int counter = 0;//狀態切換
// notes in the melody:
int melody[] = {
  NOTE_A5,NOTE_B5,NOTE_C5,NOTE_B5,NOTE_C5,NOTE_E5,NOTE_B5,0,NOTE_G5,NOTE_A5,NOTE_G5,NOTE_A5,NOTE_C5,NOTE_G5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8,8,2,8,4,4,2,2,4,2,8,4,4,2
};

void setup() {
  // iterate over the notes of the melody:
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  for (int thisNote = 0; thisNote < 14; thisNote++) {
     counter++;
    if(counter == 1){//點亮綠色
      analogWrite(greenPin,255);
      analogWrite(redPin,0);
      analogWrite(bluePin,0);
    }
    else if(counter == 2){//點亮紅色
      analogWrite(greenPin,0);
      analogWrite(redPin,255);
      analogWrite(bluePin,0);
    }
    else if(counter == 3){//點亮藍色
      analogWrite(greenPin,0);
      analogWrite(redPin,0);
      analogWrite(bluePin,255);
      counter = 0;//歸零
    }

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
}
}
void loop() {
  // no need to repeat the melody.
 
}
