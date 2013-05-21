/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created: Tue 21. May 15:36:24 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_view
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *aMin;
    QDoubleSpinBox *aMax;
    QDoubleSpinBox *aStep;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *fMin;
    QDoubleSpinBox *fMax;
    QDoubleSpinBox *fStep;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QDoubleSpinBox *forsek1;
    QDoubleSpinBox *kF;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QDoubleSpinBox *K1;
    QDoubleSpinBox *T1;
    QDoubleSpinBox *T2;
    QDoubleSpinBox *ksi1;
    QDoubleSpinBox *ksi2;
    QDoubleSpinBox *Ogr;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *start;
    QToolButton *selectDir;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *view)
    {
        if (view->objectName().isEmpty())
            view->setObjectName(QString::fromUtf8("view"));
        view->resize(462, 365);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        view->setWindowIcon(icon);
        verticalLayout_4 = new QVBoxLayout(view);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_2 = new QGroupBox(view);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        aMin = new QDoubleSpinBox(groupBox_2);
        aMin->setObjectName(QString::fromUtf8("aMin"));
        aMin->setDecimals(3);
        aMin->setMinimum(-1e+06);
        aMin->setMaximum(1e+06);
        aMin->setValue(0.5);

        verticalLayout->addWidget(aMin);

        aMax = new QDoubleSpinBox(groupBox_2);
        aMax->setObjectName(QString::fromUtf8("aMax"));
        aMax->setDecimals(3);
        aMax->setMinimum(-1e+06);
        aMax->setMaximum(1e+06);
        aMax->setValue(2);

        verticalLayout->addWidget(aMax);

        aStep = new QDoubleSpinBox(groupBox_2);
        aStep->setObjectName(QString::fromUtf8("aStep"));
        aStep->setDecimals(3);
        aStep->setMinimum(-1e+06);
        aStep->setMaximum(1e+06);
        aStep->setValue(0.5);

        verticalLayout->addWidget(aStep);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        fMin = new QDoubleSpinBox(groupBox_2);
        fMin->setObjectName(QString::fromUtf8("fMin"));
        fMin->setDecimals(3);
        fMin->setMinimum(-1e+06);
        fMin->setMaximum(1e+06);
        fMin->setValue(1);

        verticalLayout_2->addWidget(fMin);

        fMax = new QDoubleSpinBox(groupBox_2);
        fMax->setObjectName(QString::fromUtf8("fMax"));
        fMax->setDecimals(3);
        fMax->setMinimum(-1e+06);
        fMax->setMaximum(1e+06);
        fMax->setValue(70);

        verticalLayout_2->addWidget(fMax);

        fStep = new QDoubleSpinBox(groupBox_2);
        fStep->setObjectName(QString::fromUtf8("fStep"));
        fStep->setDecimals(3);
        fStep->setMinimum(-1e+06);
        fStep->setMaximum(1e+06);
        fStep->setValue(1);

        verticalLayout_2->addWidget(fStep);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_4->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox_3 = new QGroupBox(view);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        forsek1 = new QDoubleSpinBox(groupBox_3);
        forsek1->setObjectName(QString::fromUtf8("forsek1"));
        forsek1->setDecimals(3);
        forsek1->setMinimum(-1e+06);
        forsek1->setMaximum(1e+06);
        forsek1->setValue(2.87);

        verticalLayout_5->addWidget(forsek1);

        kF = new QDoubleSpinBox(groupBox_3);
        kF->setObjectName(QString::fromUtf8("kF"));
        kF->setDecimals(6);
        kF->setMinimum(-1e+06);
        kF->setMaximum(1e+06);
        kF->setValue(0.0069);

        verticalLayout_5->addWidget(kF);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(view);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        K1 = new QDoubleSpinBox(groupBox);
        K1->setObjectName(QString::fromUtf8("K1"));
        K1->setMinimum(-1e+06);
        K1->setMaximum(1e+06);
        K1->setValue(36.79);

        verticalLayout_3->addWidget(K1);

        T1 = new QDoubleSpinBox(groupBox);
        T1->setObjectName(QString::fromUtf8("T1"));
        T1->setDecimals(5);
        T1->setMinimum(-1e+06);
        T1->setMaximum(1e+06);
        T1->setValue(0.002);

        verticalLayout_3->addWidget(T1);

        T2 = new QDoubleSpinBox(groupBox);
        T2->setObjectName(QString::fromUtf8("T2"));
        T2->setDecimals(5);
        T2->setMinimum(-1e+06);
        T2->setMaximum(1e+06);
        T2->setValue(0.002);

        verticalLayout_3->addWidget(T2);

        ksi1 = new QDoubleSpinBox(groupBox);
        ksi1->setObjectName(QString::fromUtf8("ksi1"));
        ksi1->setDecimals(5);
        ksi1->setMinimum(-1e+06);
        ksi1->setMaximum(1e+06);
        ksi1->setValue(0.2);

        verticalLayout_3->addWidget(ksi1);

        ksi2 = new QDoubleSpinBox(groupBox);
        ksi2->setObjectName(QString::fromUtf8("ksi2"));
        ksi2->setDecimals(5);
        ksi2->setMinimum(-1e+06);
        ksi2->setMaximum(1e+06);
        ksi2->setValue(0.2);

        verticalLayout_3->addWidget(ksi2);

        Ogr = new QDoubleSpinBox(groupBox);
        Ogr->setObjectName(QString::fromUtf8("Ogr"));
        Ogr->setMinimum(-1e+06);
        Ogr->setMaximum(1e+06);
        Ogr->setValue(240);

        verticalLayout_3->addWidget(Ogr);


        horizontalLayout->addWidget(groupBox);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        start = new QPushButton(view);
        start->setObjectName(QString::fromUtf8("start"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(start);

        selectDir = new QToolButton(view);
        selectDir->setObjectName(QString::fromUtf8("selectDir"));
        sizePolicy.setHeightForWidth(selectDir->sizePolicy().hasHeightForWidth());
        selectDir->setSizePolicy(sizePolicy);
        selectDir->setMaximumSize(QSize(16777215, 23));

        horizontalLayout_3->addWidget(selectDir);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        retranslateUi(view);

        QMetaObject::connectSlotsByName(view);
    } // setupUi

    void retranslateUi(QDialog *view)
    {
        view->setWindowTitle(QApplication::translate("view", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\264\320\273\321\217 \320\260\320\275\320\260\320\273\320\270\320\267\320\260 \320\237\320\223-22\320\234", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("view", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\262\321\205\320\276\320\264\320\275\320\276\320\263\320\276 \320\262\320\276\320\267\320\264\320\265\320\271\321\201\320\262\320\270\321\217 in = A * sin(2 * pi * f * t) / 57.3", 0, QApplication::UnicodeUTF8));
        aMin->setPrefix(QApplication::translate("view", "\320\220\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260 ", 0, QApplication::UnicodeUTF8));
        aMin->setSuffix(QApplication::translate("view", " \320\274\320\270\320\275\320\270\320\274\321\203\320\274", 0, QApplication::UnicodeUTF8));
        aMax->setPrefix(QApplication::translate("view", "\320\220\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260 ", 0, QApplication::UnicodeUTF8));
        aMax->setSuffix(QApplication::translate("view", " \320\274\320\260\320\272\321\201\320\270\320\274\321\203\320\274", 0, QApplication::UnicodeUTF8));
        aStep->setPrefix(QApplication::translate("view", "\320\220\320\274\320\277\320\273\320\270\321\202\321\203\320\264\320\260 ", 0, QApplication::UnicodeUTF8));
        aStep->setSuffix(QApplication::translate("view", " \321\210\320\260\320\263", 0, QApplication::UnicodeUTF8));
        fMin->setPrefix(QApplication::translate("view", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 ", 0, QApplication::UnicodeUTF8));
        fMin->setSuffix(QApplication::translate("view", " \320\274\320\270\320\275\320\270\320\274\321\203\320\274", 0, QApplication::UnicodeUTF8));
        fMax->setPrefix(QApplication::translate("view", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 ", 0, QApplication::UnicodeUTF8));
        fMax->setSuffix(QApplication::translate("view", " \320\274\320\260\320\272\321\201\320\270\320\274\321\203\320\274", 0, QApplication::UnicodeUTF8));
        fStep->setPrefix(QApplication::translate("view", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260 ", 0, QApplication::UnicodeUTF8));
        fStep->setSuffix(QApplication::translate("view", " \321\210\320\260\320\263", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("view", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260", 0, QApplication::UnicodeUTF8));
        forsek1->setPrefix(QApplication::translate("view", "Forsek1 = ", 0, QApplication::UnicodeUTF8));
        kF->setPrefix(QApplication::translate("view", "kF = ", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("view", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\200\321\203\320\273\320\265\320\262\320\276\320\271 \320\274\320\260\321\210\320\270\320\275\320\272\320\270", 0, QApplication::UnicodeUTF8));
        K1->setPrefix(QApplication::translate("view", "K1 = ", 0, QApplication::UnicodeUTF8));
        T1->setPrefix(QApplication::translate("view", "T1 = ", 0, QApplication::UnicodeUTF8));
        T2->setPrefix(QApplication::translate("view", "T2 = ", 0, QApplication::UnicodeUTF8));
        ksi1->setPrefix(QApplication::translate("view", "ksi1 = ", 0, QApplication::UnicodeUTF8));
        ksi2->setPrefix(QApplication::translate("view", "ksi2 = ", 0, QApplication::UnicodeUTF8));
        Ogr->setPrefix(QApplication::translate("view", "Ogr = ", 0, QApplication::UnicodeUTF8));
        start->setText(QApplication::translate("view", "\320\237\321\200\320\276\320\270\320\267\320\262\320\265\321\201\321\202\320\270 \321\200\320\260\321\201\321\207\321\221\321\202", 0, QApplication::UnicodeUTF8));
        selectDir->setText(QApplication::translate("view", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class view: public Ui_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
