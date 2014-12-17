#include "CRudderPlay.h"
#include <qglobal.h>

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
    Q_UNUSED(Play);
}

CRudderPlay::CRudderPlay(double Play, double Rudder)
{
//implementation was removed
    Q_UNUSED(Play);
    Q_UNUSED(Rudder);
}
CRudderPlay::~CRudderPlay()
{
}
void CRudderPlay::SetFreePlay(double Play)
{
//implementation was removed
    Q_UNUSED(Play);
}
void CRudderPlay::SetZeroShift(double Shift)
{
//implementation was removed
    Q_UNUSED(Shift);
}
void CRudderPlay::SetValue(double Rudder)
{
//implementation was removed
    Q_UNUSED(Rudder);
}
#define _OSCILFREQ 0
double CRudderPlay::PlayRudder(double Rudder)
{
#ifdef _OSCILFREQ
#if _OSCILFREQ > 0
    double OscPhase = sin(_OSCILFREQ*gd_2PI*gpc_Task->bd_T);
#else
    double OscPhase = 1.0;
    Q_UNUSED(OscPhase);
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
