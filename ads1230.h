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

public:
    ADS1230(/* args */);
    ~ADS1230();
    /**********************/
    int32_t getRaw();
    void wakeUp();
    void powerDown();
    void offsetCalibratoin();
};

ADS1230::ADS1230(/* args */)
{
}

ADS1230::~ADS1230()
{
}

#endif // !_ads1230_h_