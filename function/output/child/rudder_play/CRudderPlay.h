#ifndef CRUDDERPLAY_H
#define CRUDDERPLAY_H

class CRudderPlay
{
public:
    CRudderPlay();
    CRudderPlay(double);
    CRudderPlay(double, double);
    ~CRudderPlay();
    void SetFreePlay(double);
    void SetZeroShift(double);
    void SetValue(double);
    double PlayRudder(double);
private:
    double FreePlay;
    double PlayMin, PlayMax;
    double Offset;
    double Value;
    double InterVal;
};

#endif // CRUDDERPLAY_H
