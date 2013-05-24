#include "view.h"
#include "ui_view.h"
#include "data/APFC.h"
#include "function/input/Input.h"

view::view(QWidget *parent) :
    QDialog(parent),
    apfc(new APFC()),
    in(new Input()),
    out(0),
    ui(new Ui::view)
{
    ui->setupUi(this);
    createConnections();
    loadSettings();
    setIntervalA();
    setIntervalF();
    initContour();
}

#include "../function/output/Output.h"
#include "../function/output/OutMaker.h"
#include "../function/output/Delegate.h"
void view::initContour()
{
    OutMaker::fill(ui->contourType);
    apfc->setInput(in);
    Delegate* delegate = new Delegate(ui->contourArgs);
    ui->contourArgs->setItemDelegateForColumn(0, delegate);
    connect(ui->contourArgs, SIGNAL(clicked(QModelIndex)), ui->contourArgs, SLOT(edit(QModelIndex)));
}

void view::createConnections()
{
    connect(ui->aMin,  SIGNAL(editingFinished()), this, SLOT(setIntervalA()));
    connect(ui->aMax,  SIGNAL(editingFinished()), this, SLOT(setIntervalA()));
    connect(ui->aStep, SIGNAL(editingFinished()), this, SLOT(setIntervalA()));

    connect(ui->fMin,  SIGNAL(editingFinished()), this, SLOT(setIntervalF()));
    connect(ui->fMax,  SIGNAL(editingFinished()), this, SLOT(setIntervalF()));
    connect(ui->fStep, SIGNAL(editingFinished()), this, SLOT(setIntervalF()));

    connect(ui->selectDir, SIGNAL(clicked()), this, SLOT(setReportDir()));
    connect(ui->start,     SIGNAL(clicked()), this, SLOT(start()));

    connect(ui->contourType, SIGNAL(currentIndexChanged(int)), this, SLOT(createNewContour(int)));
}

view::~view()
{
    saveSettings();
    delete in;
    delete out;
    delete apfc;
    delete ui;
}

void view::setIntervalA()
{
    apfc->setIntervalA(ui->aMin->value(), ui->aMax->value(), ui->aStep->value());
}

void view::setIntervalF()
{
    apfc->setIntervalF(ui->fMin->value(), ui->fMax->value(), ui->fStep->value());
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
    if(out && in){
        out->reset();
        apfc->save(reportDir);
    }
    isStopped();
}

#include <QSettings>
void view::saveSettings()
{
    QSettings settings;
    settings.setValue("geometry", saveGeometry());
    settings.setValue("reportDir", reportDir);
    settings.setValue("contourType", ui->contourType->currentIndex());
}


void view::createNewContour(int i)
{
    if(out) delete out;
    out = OutMaker::make((OutMaker::Type) ui->contourType->itemData(i).toInt(), this);
    ui->contourArgs->setModel(out);
    apfc->setOutput(out);
}

void view::loadSettings()
{
    QSettings settings;
    restoreGeometry(settings.value("geometry").toByteArray());
    reportDir = settings.value("reportDir").toString();
    if(ui->contourType->count()){
        int i = settings.value("contourType", 0).toInt();
        ui->contourType->setCurrentIndex(i);
    }
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

    ui->contourArgs->setEnabled(isVisible);
    ui->contourType->setEnabled(isVisible);
}
