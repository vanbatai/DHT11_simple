#include <Arduino.h>
#include <DHT_TAI.h>

uint8_t DHT_read(uint8_t _pin, float *humi, float *tem)
{
  uint8_t buffer[5] = {0, 0, 0, 0, 0};
  uint8_t checksum;

  pinMode(_pin, 1);   // set la cong ra
  digitalWrite(_pin, 1);
  delayMicroseconds(60);
  digitalWrite(_pin, 0);
  delay(25); // it nhat 18ms
  digitalWrite(_pin, 1);
  pinMode(_pin, INPUT_PULLUP);   // set la cong ra
  delayMicroseconds(60);
  if (digitalRead(_pin) == 1)
    return 0;
  else while (digitalRead(_pin) == 0); //Doi DaTa len 1
  delayMicroseconds(60);
  if (digitalRead(_pin) == 0) return 0;
  else while (digitalRead(_pin) == 1); //Doi Data ve 0
  //Bat dau doc du lieu
  for (uint8_t i = 0; i < 5; i++)
  {
    for (uint8_t j = 0; j < 8; j++)
    {
      while (digitalRead(_pin) == 0); //Doi Data len 1
      delayMicroseconds(50);
      if (digitalRead(_pin) == 1)
      {
        buffer[i] |= (1 << (7 - j));
        while (digitalRead(_pin) == 1); //Doi Data xuong 0
      }
    }
  }
  //Tinh toan check sum
  checksum = buffer[0] + buffer[1] + buffer[2] + buffer[3];
  //Kiem tra check sum
  if ((checksum) != buffer[4]) return 0;
  //Lay du lieu
  *tem  = buffer[2];
  *humi = buffer[0];
  return 1;
}