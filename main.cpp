#include "rpsfield.h"
#include <QApplication>
#include <QFont>
#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
#include <QFormLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QProgressBar>

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = 0);
};

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
        RPSField *rpsField = new RPSField;

        //---------------------------------Menu---------------------------------------------------------------

        QGroupBox *menuGroupBox = new QGroupBox(tr("Menu"));
        QVBoxLayout *menuLayout = new QVBoxLayout;
        QPushButton *quit = new QPushButton(tr("Beenden"));
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
        QPushButton *stop = new QPushButton(tr("Stopp"));
    connect(stop, SIGNAL(clicked()), rpsField, SLOT(stopIteration()));
        QPushButton *go = new QPushButton(tr("Los"));
        connect(go, SIGNAL(clicked()), rpsField, SLOT(startIteration()));
        QPushButton *step = new QPushButton(tr("Schritt"));
        connect(step, SIGNAL(clicked()), rpsField, SLOT(iterate()));
        QPushButton *reset = new QPushButton(tr("Reset"));
        connect(reset, SIGNAL(clicked()), rpsField, SLOT(reset()));
        menuLayout->addWidget(go);
        menuLayout->addWidget(stop);
        menuLayout->addWidget(step);
        menuLayout->addWidget(reset);
        menuLayout->addWidget(quit);
        menuGroupBox->setLayout(menuLayout);

        //---------------------------------Einstellungen-------------------------------------------------------

        QGroupBox *settingsGroupBox = new QGroupBox(tr("Einstellungen"));

        QSpinBox *matrixSize = new QSpinBox();
        matrixSize->setMaximum(10000);
        matrixSize->setValue(rpsField->getMatrixSize());

        QSpinBox *stepSize = new QSpinBox();
        stepSize->setMaximum(10000);
        stepSize->setValue(rpsField->getStepSize());

        QSpinBox *rectSize = new QSpinBox();
        rectSize->setMaximum(1000);
        rectSize->setValue(rpsField->getRectSize());

        QSpinBox *timeSamples = new QSpinBox();
        timeSamples->setMaximum(2000);
        timeSamples->setValue(rpsField->getTimeSamples());

        QDoubleSpinBox *exchangeRate = new QDoubleSpinBox();
        exchangeRate->setMaximum(1000.0);
        exchangeRate->setValue(rpsField->getExchangeRate());
        exchangeRate->setDecimals(10);

        QCheckBox *ausgabe = new QCheckBox();

        // Alle Einstellungselemente connecten
        connect(matrixSize, SIGNAL(valueChanged(int)), rpsField, SLOT(setMatrixSize(int)));
        connect(stepSize, SIGNAL(valueChanged(int)), rpsField, SLOT(setStepSize(int)));
        connect(rectSize, SIGNAL(valueChanged(int)), rpsField, SLOT(setRectSize(int)));
        connect(timeSamples, SIGNAL(valueChanged(int)), rpsField, SLOT(setTimeSamples(int)));
        connect(ausgabe, SIGNAL(stateChanged(int)), rpsField, SLOT(setOutput(int)));
        connect(exchangeRate, SIGNAL(valueChanged(double)), rpsField, SLOT(setExchangeRate(double)));

        QFormLayout *settingLayout = new QFormLayout;
        settingLayout->addRow(tr("&Matrix:"), matrixSize);
        settingLayout->addRow(tr("&Schrittweite:"), stepSize);
        settingLayout->addRow(tr("&Rasterweite:"), rectSize);
        settingLayout->addRow(tr("&Zeitsamples:"), timeSamples);
        settingLayout->addRow(tr("&Austauschrate:"), exchangeRate);
        settingLayout->addRow(tr("&Dateiausgabe:"), ausgabe);
        settingsGroupBox->setLayout(settingLayout);

        //---------------------------------Info---------------------------------------------------------------

        QGroupBox *infoGroupBox = new QGroupBox(tr("Info"));
        QVBoxLayout *infoLayout = new QVBoxLayout;

        QHBoxLayout *layoutRed = new QHBoxLayout;
        QLabel *labRed = new QLabel(tr("Rot:"));
        QLabel *speciesCountRed = new QLabel();
        connect(rpsField, SIGNAL(speciesRedChanged(int)), speciesCountRed, SLOT(setNum(int)));
        speciesCountRed->setNum(rpsField->getSpeciesCount(1));
        layoutRed->addWidget(labRed);
        layoutRed->addWidget(speciesCountRed);

        QHBoxLayout *layoutBlue = new QHBoxLayout;
        QLabel *labBlue = new QLabel(tr("Blau:"));
        QLabel *speciesCountBlue = new QLabel();
        connect(rpsField, SIGNAL(speciesBlueChanged(int)), speciesCountBlue, SLOT(setNum(int)));
        speciesCountBlue->setNum(rpsField->getSpeciesCount(2));
        layoutBlue->addWidget(labBlue);
        layoutBlue->addWidget(speciesCountBlue);

        QHBoxLayout *layoutYellow = new QHBoxLayout;
        QLabel *labYellow = new QLabel(tr("Gelb:"));
        QLabel *speciesCountYellow = new QLabel();
        connect(rpsField, SIGNAL(speciesYellowChanged(int)), speciesCountYellow, SLOT(setNum(int)));
        speciesCountYellow->setNum(rpsField->getSpeciesCount(3));
        layoutYellow->addWidget(labYellow);
        layoutYellow->addWidget(speciesCountYellow);

        QHBoxLayout *layoutBlack = new QHBoxLayout;
        QLabel *labBlack = new QLabel(tr("Schwarz:"));
        QLabel *speciesCountBlack = new QLabel();
        connect(rpsField, SIGNAL(speciesBlackChanged(int)), speciesCountBlack, SLOT(setNum(int)));
        speciesCountBlack->setNum(rpsField->getSpeciesCount(0));
        layoutBlack->addWidget(labBlack);
        layoutBlack->addWidget(speciesCountBlack);

        QHBoxLayout *layoutTime = new QHBoxLayout;
        QLabel *labTime = new QLabel(tr("Zeit:"));
        QLabel *countTime = new QLabel();
        connect(rpsField, SIGNAL(timeChanged(double)), countTime, SLOT(setNum(double)));
        countTime->setNum(0.0);
        layoutTime->addWidget(labTime);
        layoutTime->addWidget(countTime);

        QHBoxLayout *layoutMobility = new QHBoxLayout;
        QLabel *labMobility = new QLabel(tr("Diffusion:"));
        QLabel *mobility = new QLabel();
        connect(rpsField, SIGNAL(mobilityChanged(double)), mobility, SLOT(setNum(double)));
        mobility->setNum(rpsField->getMobility());
        layoutMobility->addWidget(labMobility);
        layoutMobility->addWidget(mobility);

        infoLayout->addLayout(layoutRed);
        infoLayout->addLayout(layoutBlue);
        infoLayout->addLayout(layoutYellow);
        infoLayout->addLayout(layoutBlack);
        infoLayout->addLayout(layoutTime);
        infoLayout->addLayout(layoutMobility);
        infoLayout->setAlignment(Qt::AlignTop);
        infoGroupBox->setLayout(infoLayout);

        //---------------------------------RPSField----------------------------------------------------------

        QGroupBox *simGroupBox = new QGroupBox(tr("Simulation"));
        QVBoxLayout *simLayout = new QVBoxLayout;
        simLayout->addWidget(rpsField);
        simGroupBox->setLayout(simLayout);

        //---------------------------------Layout Box---------------------------------------------------------------

        QGridLayout *layout = new QGridLayout;
        layout->setColumnStretch (0, 0);
        layout->setColumnStretch (1, 1);
        layout->setRowStretch (0, 0);
        layout->setRowStretch (1, 1);
        layout->setColumnMinimumWidth (1, 650);
        layout->setColumnMinimumWidth (0, 150);
        layout->addWidget(menuGroupBox,0,0);
        layout->addWidget(settingsGroupBox,1,0);
        layout->addWidget(simGroupBox,0,1,3,1);
        layout->addWidget(infoGroupBox,2,0);

        setLayout(layout);

        setWindowTitle(tr("Stein-Papier-Schere Simulation"));
}


int main(int argc, char *argv[])
{
    qsrand(time(NULL));
    QApplication a(argc, argv);
    MyWidget w;
    w.show();

    return a.exec();
}
