#include "ads1230.h"
#include "pico/stdlib.h"
ADS1230::ADS1230(uint dout, uint sclk, uint pdwn)
{
    _doutPin = dout;
    _sclkPin = sclk;
    _pdwnPin = pdwn;

    gpio_init(_doutPin);
    gpio_set_dir(_doutPin, GPIO_IN);

    gpio_init(_sclkPin);
    gpio_set_dir(_sclkPin, GPIO_OUT);

    gpio_init(_pdwnPin);
    gpio_set_dir(_pdwnPin, GPIO_OUT);
}

int32_t ADS1230::getRaw()
{
    for (int i = 0; i < 20; i++)
    {
        gpio_put(_sclkPin, true);
        sleep_us(1);
        _raw <<= 1;
        _raw |= gpio_get(_doutPin);
        sleep_us(1);
        gpio_put(_sclkPin, false);
        sleep_us(2);
    }
    _raw <<= 12;
    return _raw;
}

void ADS1230::offsetCalibratoin()
{
    for (int i = 0; i < 26; i++)
    {
        gpio_put(_sclkPin, true);
        sleep_us(2);
        gpio_put(_sclkPin, false);
        sleep_us(2);
    }
}

void ADS1230::powerDown()
{
    gpio_put(_pdwnPin, false);
}

void ADS1230::wakeUp()
{
    gpio_put(_pdwnPin, true);
}

ADS1230::~ADS1230()
{
}