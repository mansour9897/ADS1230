#ifndef _ads1230_h_
#define _ads1230_h_

#include <stdio.h>

class ADS1230
{
private:
    int32_t _raw;
    uint _doutPin;
    uint _sclkPin;
    uint _pdwnPin;
    uint _gain;
    float _vref;
    uint32_t _lastTime;

public:
    ADS1230(uint dout, uint sclk, uint pdwn, uint gain, float VRef);
    ~ADS1230();
    /**********************/
    int32_t getRaw();
    void wakeUp();
    void powerDown();
    void offsetCalibratoin();
    float getMilliVolt();
};

#endif // !_ads1230_h_