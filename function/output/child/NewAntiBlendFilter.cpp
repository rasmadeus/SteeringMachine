#include "NewAntiBlendFilter.h"

class NewAntiBlendFilter::LinkAvionika: public Function{
    public:
        LinkAvionika(double T1, double ksi1, double ksi2)
        {
            reset(T1, ksi1, ksi2);
        }

        double out(const double& in){
            for(int i =0; i < 2; i++){
                z  += ( in - ( work_e * z + work_f * y1 ) / work_d ) * 0.0005;
                y1 +=  z * 0.0005;
            }
            return  (work_a / work_d) *
                    (in + (work_b / work_a - work_e / work_d) * z +
                          (work_c / work_a - work_f / work_d) * y1 );
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
    Output(
        QVector<QPair<QString, double> > ()             <<
                QPair<QString, double>("T1",   0.00307) <<
                QPair<QString, double>("ksi1", 0.025)   <<
                QPair<QString, double>("ksi2", 0.25)    <<
                QPair<QString, double>("T2",   0.00273) <<
                QPair<QString, double>("ksi3", 0.025)   <<
                QPair<QString, double>("ksi4", 0.75),
        parent
    ),
    one(new LinkAvionika(0.00307, 0.025, 0.25)),
    two(new LinkAvionika(0.00273, 0.025, 0.75))
{
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


