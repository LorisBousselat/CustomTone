#include <Arduino.h>

///////////////////////////////////////////////////////////////////////////
// Filename : main.cpp
// Author : Loris Bousselat
// Date : 2024-October-29
// Equipment used : ESP32   passive buzzer and a transistor S8050
// Description :
//   plays Beethoven - Für Elise
///////////////////////////////////////////////////////////////////////////

const int pin = 14;
const int resolution = 8;

enum Notes : std::int16_t
{
  A = 220,
  B = 247,
  C = 261,
  CB = 131,
  D = 293,
  E = 329,
  EB = 165,
  F = 349,
  FB = 174,
  G = 196,
  Ab = 207,
  Eb = 311
};

const Notes partition[] = {E, Eb, E, Eb, E,
                           B, D, C, A,
                           CB, EB, A, B,
                           EB, Ab, B, C,
                           EB, E, Eb, E, Eb, E,
                           B, D, C, A,
                           CB, EB, A, B,
                           EB, C, B, A,

                           E, Eb, E, Eb, E,
                           B, D, C, A,
                           CB, EB, A, B,
                           EB, Ab, B, C,
                           EB, E, Eb, E, Eb, E,
                           B, D, C, A,
                           CB, EB, A, B,
                           EB, C, B, A,

                           B, C, D, E,
                           G, F, E, D,
                           F, E, D, C,
                           EB, D, C, B,

                           E, Eb, E, Eb, E,
                           B, D, C, A,
                           CB, EB, A, B,
                           EB, C, B, A};

void playFrequencies(int frequency, int duration)
{
  ledcWriteTone(pin, frequency);
  delay(duration);
  ledcWriteTone(pin, 0);
}

void setup()
{
}

void loop()
{
  for (int i = 0; i < sizeof(partition) / sizeof(Notes); i++)
  {
    tone(pin, partition[i], 400);
    delay(100);
  }
  delay(30000);
}
