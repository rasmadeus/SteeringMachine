#include "view.h"
#include "ui_view.h"

view::view(QWidget *parent) :
    QDialog(parent),
    apfc(&in, &out),
    ui(new Ui::view)
{
    ui->setupUi(this);
    loadSettings();
    setRM();
    setAlgorithmsArg();
    setIntervalA();
    setIntervalF();
    createConnections();
}

void view::createConnections()
{
    connect(ui->aMin,  SIGNAL(editingFinished()), this, SLOT(setIntervalA()));
    connect(ui->aMax,  SIGNAL(editingFinished()), this, SLOT(setIntervalA()));
    connect(ui->aStep, SIGNAL(editingFinished()), this, SLOT(setIntervalA()));

    connect(ui->fMin,  SIGNAL(editingFinished()), this, SLOT(setIntervalF()));
    connect(ui->fMax,  SIGNAL(editingFinished()), this, SLOT(setIntervalF()));
    connect(ui->fStep, SIGNAL(editingFinished()), this, SLOT(setIntervalF()));

    connect(ui->K1,   SIGNAL(editingFinished()), this, SLOT(setRM()));
    connect(ui->T1,   SIGNAL(editingFinished()), this, SLOT(setRM()));
    connect(ui->T2,   SIGNAL(editingFinished()), this, SLOT(setRM()));
    connect(ui->ksi1, SIGNAL(editingFinished()), this, SLOT(setRM()));
    connect(ui->ksi2, SIGNAL(editingFinished()), this, SLOT(setRM()));
    connect(ui->Ogr,  SIGNAL(editingFinished()), this, SLOT(setRM()));

    connect(ui->forsek1, SIGNAL(editingFinished()), this, SLOT(setAlgorithmsArg()));
    connect(ui->kF,      SIGNAL(editingFinished()), this, SLOT(setAlgorithmsArg()));

    connect(ui->selectDir, SIGNAL(clicked()), this, SLOT(setReportDir()));
    connect(ui->start,     SIGNAL(clicked()), this, SLOT(start()));
}

view::~view()
{
    saveSettings();
    delete ui;
}

void view::setIntervalA()
{
    apfc.setIntervalA(ui->aMin->value(), ui->aMax->value(), ui->aStep->value());
}

void view::setIntervalF()
{
    apfc.setIntervalF(ui->fMin->value(), ui->fMax->value(), ui->fStep->value());
}

void view::setRM()
{
    out.setK1(ui->K1->value());
    out.setT1(ui->T1->value());
    out.setT2(ui->T2->value());
    out.setKsi1(ui->ksi1->value());
    out.setKsi2(ui->ksi2->value());
    out.setOgr(ui->Ogr->value());
}

void view::setAlgorithmsArg()
{
    out.setForsek1(ui->forsek1->value());
    out.setKf(ui->kF->value());
}

#include <QFileDialog>
void view::setReportDir()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Укажите директорию для отчёта"), reportDir);
    if(dir.isEmpty()) return;
    reportDir = dir;
}

void view::start()
{
    if(reportDir.isEmpty()) setReportDir();
    isStarting();
    apfc.save(reportDir);
    isStopped();
}

#include <QSettings>
void view::saveSettings()
{
    QSettings settings;
    settings.setValue("geometry", saveGeometry());
    settings.setValue("reportDir", reportDir);
}

void view::loadSettings()
{
    QSettings settings;
    restoreGeometry(settings.value("geometry").toByteArray());
    reportDir = settings.value("reportDir").toString();
}

void view::isStarting()
{
    setVisibleElements(false);
    ui->start->setText(tr("Ждите - идёт расчёт"));
}

void view::isStopped()
{
    ui->start->setText(tr("Произвести расчёт"));
    setVisibleElements(true);
}

void view::setVisibleElements(bool isVisible)
{
    ui->aMin->setEnabled(isVisible);
    ui->aMax->setEnabled(isVisible);
    ui->aStep->setEnabled(isVisible);
    ui->fMin->setEnabled(isVisible);
    ui->fMax->setEnabled(isVisible);
    ui->fStep->setEnabled(isVisible);

    ui->K1->setEnabled(isVisible);
    ui->T1->setEnabled(isVisible);
    ui->T2->setEnabled(isVisible);
    ui->ksi1->setEnabled(isVisible);
    ui->ksi2->setEnabled(isVisible);
    ui->Ogr->setEnabled(isVisible);

    ui->forsek1->setEnabled(isVisible);
    ui->kF->setEnabled(isVisible);
}
