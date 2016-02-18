#ifndef RPSFIELD_H
#define RPSFIELD_H

#include <QWidget>
#include <QTimer>
#include <QVector>
#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <QString>
#include <QFile>
#include <QImageWriter>

#include <math.h>
#include <iostream>

class RPSField : public QWidget
{
    Q_OBJECT

public:
    RPSField(QWidget *parent = 0);
    ~RPSField();
    QVector<double> timeStack;
public slots:
    void startIteration();
    void stopIteration();
    void reset();
    void iterate();

    int getRectSize();
    int getMatrixSize();
    int getStepSize();
    int getMaxSteps();
    double getTime();
    double getExchangeRate();
    double getMobility();
    int getSpecies(int col, int row, const QVector<int> &array);
    int getSpecies(int col, int row);
    int getSpeciesCount(int species);
    int getSpeciesNeighborCount(int col, int row, int species);
    bool getOutput();
    int getTimeSamples();

    void setMatrixSize(int size);
    void setStepSize(int size);
    void setSpecies(int row, int column, int species, QVector<int> &array);
    void setRectSize(int size);
    void setOutput(int onOff);
    void setExchangeRate(double size);
    void setTimeSamples(int size);

signals:
    void speciesBlackChanged(int newValue);
    void speciesRedChanged(int newValue);
    void speciesBlueChanged(int newValue);
    void speciesYellowChanged(int newValue);
    void timeChanged(double newValue);
    void mobilityChanged(double newValue);
    void currentStepChanged(int newValue);

protected:
    void paintEvent(QPaintEvent *event);
    void outputMatrix();

private:
    int arrSize;
    QVector<int> speciesArray;
    QVector<int> speciesTempArray;
    QVector<int> speciesQueue;
    QRgb red, blue, yellow, black;
    double exchangeQueue[20];
    int exchangeQueueIndex;

    int freeNeighbor(int col, int row);
    void shuffleArray(QVector<int> &array);

    int fileNumber;
    bool output;

    int intervall;
    int stepSize;
    int countIteration;
    int countSelection;
    int countReproduction;
    int countExchange;
    int rectSize;
    int timeSamples;
    int countSamples;
    double mobility;
    double exchangeRate;
    double exchangeRate2;
    double exchangeRate3;
    double exchangeRate4;
    double selectionRate;
    double dieRate;
    double reproductionRate;
    double time;

    QTimer *timer;
};

#endif // RPSFIELD_H
