#include "view.h"
#include "ui_view.h"
#include "data/APFC.h"
#include "function/input/Input.h"
#include "APFCThread.h"

view::view(QWidget *parent) :
    QDialog(parent),
    apfc(new APFC(parent)),
    in(new Input()),
    out(0),
    thread(new APFCThread(parent)),
    ui(new Ui::view)
{
    ui->setupUi(this);

    thread->setAPFC(apfc);
    thread->setInput(in);
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

    connect(thread, SIGNAL(started()), this, SLOT(threadWasStarted()));
    connect(thread, SIGNAL(finished()), this, SLOT(threadWasFinished()));
    connect(thread, SIGNAL(terminated()), this, SLOT(threadWasFinished()));

    connect(apfc, SIGNAL(wasAmplitudeStep(int)), ui->AProgressBar, SLOT(setValue(int)));
    connect(apfc, SIGNAL(wasFrequencyStep(int)), ui->fProgressBar, SLOT(setValue(int)));

}

view::~view()
{
    if(thread->isRunning()){
        thread->terminate();
    }
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
    QString dir = QFileDialog::getExistingDirectory(this, tr("Укажите директорию для отчёта"), thread->getReportDir());
    if(dir.isEmpty()) return;
    thread->setReportDir(dir);
}

void view::start()
{
    if(thread->isRunning()){
        thread->terminate();
    }
    else{
        if(thread->reportDirIsEmpty()){
            setReportDir();
        }
        thread->start();
    }
}

void view::threadWasStarted()
{
   setElementsEnabled(false, tr("Прервать расчёт АФЧХ"));
}

void view::threadWasFinished()
{
    setElementsEnabled(true, tr("Произвести расчёт АФЧХ"));
    ui->AProgressBar->setValue(0);
    ui->fProgressBar->setValue(0);
}

#include <QSettings>
void view::saveSettings()
{
    QSettings settings;
    settings.setValue("geometry", saveGeometry());
    thread->saveReportDir(settings);
    settings.setValue("contourType", ui->contourType->currentIndex());
}


void view::createNewContour(int i)
{
    if(out) delete out;
    out = OutMaker::make((OutMaker::Type) ui->contourType->itemData(i).toInt(), this);
    thread->setOutput(out);
    ui->contourArgs->setModel(out);
    apfc->setOutput(out);    
}

void view::loadSettings()
{
    QSettings settings;
    restoreGeometry(settings.value("geometry").toByteArray());
    thread->restoreReportDir(settings);
    if(ui->contourType->count()){
        int i = settings.value("contourType", 0).toInt();
        ui->contourType->setCurrentIndex(i);
    }
}

void view::setElementsEnabled(bool is, const QString& text)
{
    ui->countersGB->setEnabled(is);
    ui->selectDir->setEnabled(is);
    ui->start->setText(text);
    ui->aMax->setEnabled(is);
    ui->aMin->setEnabled(is);
    ui->aStep->setEnabled(is);
    ui->fMax->setEnabled(is);
    ui->fMin->setEnabled(is);
    ui->fStep->setEnabled(is);
}

