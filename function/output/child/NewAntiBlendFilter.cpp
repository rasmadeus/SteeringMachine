#include "NewAntiBlendFilter.h"
#include "../../../data/Data.h"
class NewAntiBlendFilter::LinkAvionika: public Function{
    public:
        LinkAvionika(double T1, double ksi1, double ksi2)
        {
            reset(T1, ksi1, ksi2);
        }

        double out(const double& in){
           //implementation was removed
            Q_UNUSED(in)
            return 0;
        }

        void reset(double T1, double ksi1, double ksi2){
            z = y1 = 0;
            setWorks(T1, ksi1, ksi2);
        }

    private:

        double z, y1;
        double work_a, work_b, work_c, work_d, work_e, work_f;

        void setWorks(double T1, double ksi1, double ksi2){
            work_a = T1 * T1;
            work_b = T1 * ksi1 * 2.0;
            work_c = 1.0;
            work_d = T1 * T1;
            work_e = T1 * ksi2 * 2.0;
            work_f = 1.0;
        }
};

NewAntiBlendFilter::NewAntiBlendFilter(QObject* parent):
    Output(parent),
    one(new LinkAvionika(0, 0, 0)),
    two(new LinkAvionika(0, 0, 0))
{
    args <<
        QPair<QString, double>("T1",   0) <<
        QPair<QString, double>("ksi1", 0)   <<
        QPair<QString, double>("ksi2", 0)    <<
        QPair<QString, double>("T2",   0) <<
        QPair<QString, double>("ksi3", 0)   <<
        QPair<QString, double>("ksi4", 0);
}

NewAntiBlendFilter::~NewAntiBlendFilter()
{
    delete one;
    delete two;
}

double NewAntiBlendFilter::out(const double& in)
{
    return one->out(two->out(in));
}

void NewAntiBlendFilter::reset()
{
    one->reset(args[0].second, args[1].second, args[2].second);
    two->reset(args[3].second, args[4].second, args[5].second);
}


