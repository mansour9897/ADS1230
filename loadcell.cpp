#include "loadcell.h"

loadcell::loadcell(ADS1230 pAds,
                   float pCapacity /* Loadcell capacity */,
                   float pVExc, /* Excitation voltage */
                   float pMvPerVolt /* loadcell mv/v */)
{
    ads = pAds;
    capacity = pCapacity;
    vExc = pVExc;
    mvPerVolt = pMvPerVolt;
}

float loadcell::getValue()
{
    float load = 0.0;
    load = (ads.getMilliVolt() * capacity) / (vExc * mvPerVolt);
    return load;
}

loadcell::~loadcell()
{
}