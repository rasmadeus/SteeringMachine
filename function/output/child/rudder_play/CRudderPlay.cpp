#include "CRudderPlay.h"

CRudderPlay::CRudderPlay()
{
    FreePlay = 0.0;
    PlayMin = 0.0;
    PlayMax = 0.0;
    Offset = 0.0;
    Value = 0.0;
    InterVal = 0.0;
}
CRudderPlay::CRudderPlay(double Play)
{
//implementation was removed
}

CRudderPlay::CRudderPlay(double Play, double Rudder)
{
//implementation was removed
}
CRudderPlay::~CRudderPlay()
{
}
void CRudderPlay::SetFreePlay(double Play)
{
//implementation was removed
}
void CRudderPlay::SetZeroShift(double Shift)
{
//implementation was removed
}
void CRudderPlay::SetValue(double Rudder)
{
//implementation was removed
}
#define _OSCILFREQ 0
double CRudderPlay::PlayRudder(double Rudder)
{
#ifdef _OSCILFREQ
#if _OSCILFREQ > 0
    double OscPhase = sin(_OSCILFREQ*gd_2PI*gpc_Task->bd_T);
#else
    double OscPhase = 1.0;
#endif
#else
    double OscPhase = 1.0;
#endif
//#define _TAPER 0.0038
#ifdef _TAPER
#if _TAPER > 0
    InterVal +=(Rudder - InterVal)*gpc_Task->bd_dT/_TAPER;
#else
    InterVal = Rudder;
#endif
#else
    InterVal = Rudder;
#endif

    return Value;
}
