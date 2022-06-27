#ifndef _loadcell_h_
#define _loadcell_h_

#include "ads1230.h"

class loadcell
{
private:
    ADS1230 ads;
    float capacity;
    float vExc;
    float mvPerVolt;

public:
    loadcell(ADS1230 pAds,
             float pCapacity /* Loadcell capacity */,
             float pVExc, /* Excitation voltage */
             float pMvPerVolt /* loadcell mv/v */);
    ~loadcell();

    float getValue();
};

#endif // !_loadcell_h_