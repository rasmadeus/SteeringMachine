/********************************************************************************
** Form generated from reading UI file 'view.ui'
**
** Created: Tue 18. Jun 08:57:33 2013
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
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_view
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *countersGB;
    QVBoxLayout *verticalLayout_3;
    QComboBox *contourType;
    QTableView *contourArgs;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *AfGroupBox;
    QVBoxLayout *AGroupBox;
    QDoubleSpinBox *aMin;
    QDoubleSpinBox *aMax;
    QDoubleSpinBox *aStep;
    QVBoxLayout *fGroupBox;
    QDoubleSpinBox *fMin;
    QDoubleSpinBox *fMax;
    QDoubleSpinBox *fStep;
    QVBoxLayout *verticalLayout_7;
    QProgressBar *AProgressBar;
    QProgressBar *fProgressBar;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *start;
    QToolButton *selectDir;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *view)
    {
        if (view->objectName().isEmpty())
            view->setObjectName(QString::fromUtf8("view"));
        view->resize(557, 242);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        view->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(view);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        countersGB = new QGroupBox(view);
        countersGB->setObjectName(QString::fromUtf8("countersGB"));
        verticalLayout_3 = new QVBoxLayout(countersGB);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(3, 3, 3, 3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        contourType = new QComboBox(countersGB);
        contourType->setObjectName(QString::fromUtf8("contourType"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(contourType->sizePolicy().hasHeightForWidth());
        contourType->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(contourType);

        contourArgs = new QTableView(countersGB);
        contourArgs->setObjectName(QString::fromUtf8("contourArgs"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(contourArgs->sizePolicy().hasHeightForWidth());
        contourArgs->setSizePolicy(sizePolicy1);
        contourArgs->setMaximumSize(QSize(200, 16777215));

        verticalLayout_3->addWidget(contourArgs);


        horizontalLayout->addWidget(countersGB);

        groupBox_2 = new QGroupBox(view);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        AfGroupBox = new QHBoxLayout();
        AfGroupBox->setObjectName(QString::fromUtf8("AfGroupBox"));
        AGroupBox = new QVBoxLayout();
        AGroupBox->setObjectName(QString::fromUtf8("AGroupBox"));
        aMin = new QDoubleSpinBox(groupBox_2);
        aMin->setObjectName(QString::fromUtf8("aMin"));
        aMin->setDecimals(3);
        aMin->setMinimum(-1e+06);
        aMin->setMaximum(1e+06);
        aMin->setValue(0.5);

        AGroupBox->addWidget(aMin);

        aMax = new QDoubleSpinBox(groupBox_2);
        aMax->setObjectName(QString::fromUtf8("aMax"));
        aMax->setDecimals(3);
        aMax->setMinimum(-1e+06);
        aMax->setMaximum(1e+06);
        aMax->setValue(2.1);

        AGroupBox->addWidget(aMax);

        aStep = new QDoubleSpinBox(groupBox_2);
        aStep->setObjectName(QString::fromUtf8("aStep"));
        aStep->setDecimals(3);
        aStep->setMinimum(-1e+06);
        aStep->setMaximum(1e+06);
        aStep->setValue(0.5);

        AGroupBox->addWidget(aStep);


        AfGroupBox->addLayout(AGroupBox);

        fGroupBox = new QVBoxLayout();
        fGroupBox->setObjectName(QString::fromUtf8("fGroupBox"));
        fMin = new QDoubleSpinBox(groupBox_2);
        fMin->setObjectName(QString::fromUtf8("fMin"));
        fMin->setDecimals(3);
        fMin->setMinimum(-1e+06);
        fMin->setMaximum(1e+06);
        fMin->setValue(1);

        fGroupBox->addWidget(fMin);

        fMax = new QDoubleSpinBox(groupBox_2);
        fMax->setObjectName(QString::fromUtf8("fMax"));
        fMax->setDecimals(3);
        fMax->setMinimum(-1e+06);
        fMax->setMaximum(1e+06);
        fMax->setValue(70);

        fGroupBox->addWidget(fMax);

        fStep = new QDoubleSpinBox(groupBox_2);
        fStep->setObjectName(QString::fromUtf8("fStep"));
        fStep->setDecimals(3);
        fStep->setMinimum(-1e+06);
        fStep->setMaximum(1e+06);
        fStep->setValue(0.5);

        fGroupBox->addWidget(fStep);


        AfGroupBox->addLayout(fGroupBox);


        verticalLayout_5->addLayout(AfGroupBox);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        AProgressBar = new QProgressBar(groupBox_2);
        AProgressBar->setObjectName(QString::fromUtf8("AProgressBar"));
        AProgressBar->setValue(0);
        AProgressBar->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(AProgressBar);

        fProgressBar = new QProgressBar(groupBox_2);
        fProgressBar->setObjectName(QString::fromUtf8("fProgressBar"));
        fProgressBar->setValue(0);
        fProgressBar->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(fProgressBar);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        start = new QPushButton(groupBox_2);
        start->setObjectName(QString::fromUtf8("start"));
        sizePolicy.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(start);

        selectDir = new QToolButton(groupBox_2);
        selectDir->setObjectName(QString::fromUtf8("selectDir"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(selectDir->sizePolicy().hasHeightForWidth());
        selectDir->setSizePolicy(sizePolicy2);
        selectDir->setMaximumSize(QSize(16777215, 23));

        horizontalLayout_4->addWidget(selectDir);


        verticalLayout_7->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);


        verticalLayout_5->addLayout(verticalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout_5);


        horizontalLayout->addWidget(groupBox_2);


        retranslateUi(view);

        QMetaObject::connectSlotsByName(view);
    } // setupUi

    void retranslateUi(QDialog *view)
    {
        view->setWindowTitle(QApplication::translate("view", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\264\320\273\321\217 \321\200\320\260\321\201\321\207\321\221\321\202\320\260 \320\220\320\244\320\247\320\245", 0, QApplication::UnicodeUTF8));
        countersGB->setTitle(QApplication::translate("view", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\272\320\276\320\275\321\202\321\203\321\200\320\260", 0, QApplication::UnicodeUTF8));
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
        start->setText(QApplication::translate("view", "\320\237\321\200\320\276\320\270\320\267\320\262\320\265\321\201\321\202\320\270 \321\200\320\260\321\201\321\207\321\221\321\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        selectDir->setToolTip(QApplication::translate("view", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\270\320\274\321\217 \321\204\320\260\320\271\320\273\320\260, \320\263\320\264\320\265 \320\261\321\203\320\264\321\203\321\202 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\321\213 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        selectDir->setStatusTip(QApplication::translate("view", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\270\320\274\321\217 \321\204\320\260\320\271\320\273\320\260, \320\263\320\264\320\265 \320\261\321\203\320\264\321\203\321\202 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\321\213 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        selectDir->setWhatsThis(QApplication::translate("view", "\320\243\320\272\320\260\320\266\320\270\321\202\320\265 \320\270\320\274\321\217 \321\204\320\260\320\271\320\273\320\260, \320\263\320\264\320\265 \320\261\321\203\320\264\321\203\321\202 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\321\213 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        selectDir->setText(QApplication::translate("view", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class view: public Ui_view {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H
