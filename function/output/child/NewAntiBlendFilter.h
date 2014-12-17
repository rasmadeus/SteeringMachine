#ifndef NEWANTIBLENDFILTER_H
#define NEWANTIBLENDFILTER_H

#include "../Output.h"

class NewAntiBlendFilter : public Output
{
public:
    explicit NewAntiBlendFilter(QObject* parent);
    ~NewAntiBlendFilter();
    double out(const double &in);
    void reset();
private:
    class LinkAvionika;
    LinkAvionika* one;
    LinkAvionika* two;
};

#endif // NEWANTIBLENDFILTER_H
