
#ifndef DHT_TAI_H_
#define DHT_TAI_H_

#ifdef __cplusplus
extern "C"{
#endif

uint8_t DHT_read(uint8_t _pin, float *humi,float *tem);

#ifdef __cplusplus
} // extern "C"
#endif

#endif