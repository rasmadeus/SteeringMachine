#ifndef OUTMAKER_H
#define OUTMAKER_H

class Output;
class QObject;
class QComboBox;

class OutMaker
{
public:

    enum Type{
        STEERING_MACHINE,
        NEW_ANTIBLEND_FILTER,
        WITH_BACK_LINK,
        WITHOUT_BACK_LINK,
        WITHOUT_BACK_LINK_SAVE,
        OSCILLARY_LINK
    };

    static Output* make(Type type, QObject* parent);
    static void fill(QComboBox* cb);
};

#endif // OUTMAKER_H
