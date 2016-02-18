#include "rpsfield.h"

#include "RPSField.h"

RPSField::RPSField(QWidget *parent)
    : QWidget(parent)
{
        //Allgemeine Parametereinstellungen (Matrixgröße usw.)
        arrSize = 100;
        rectSize = 1;
        stepSize = 10;
        countIteration = 0;
        countReproduction = 0;
        countExchange = 0;
        countSelection = 0;
        intervall = 0;
        fileNumber = 0;
        timeSamples = 0;
        countSamples = 0;
        output = false;


        //Rateneinstellung für die Raten der verschiedenen Reaktionen
        //für 20 * 20
        /*exchangeQueue[0] = 8.0000e-04;
        exchangeQueue[1] = 1.2990e-03;
        exchangeQueue[2] = 2.1093e-03;
        exchangeQueue[3] = 3.4251e-03;
        exchangeQueue[4] = 5.5615e-03;
        exchangeQueue[5] = 9.0307e-03;
        exchangeQueue[6] = 1.4664e-02;
        exchangeQueue[7] = 2.3811e-02;
        exchangeQueue[8] = 3.8663e-02;
        exchangeQueue[9] = 6.2781e-02;
        exchangeQueue[10] = 1.0194e-01;
        exchangeQueue[11] = 1.6553e-01;
        exchangeQueue[12] = 2.6879e-01;
        exchangeQueue[13] = 4.3645e-01;
        exchangeQueue[14] = 7.0869e-01;
        exchangeQueue[15] = 1.1508e+00;
        exchangeQueue[16] = 1.8686e+00;
        exchangeQueue[17] = 3.0342e+00;
        exchangeQueue[18] = 4.9268e+00;
        exchangeQueue[19] = 8.0000e+00;
        exchangeQueueIndex = 0;*/

        //für 30 * 30
        /*exchangeQueue[0] = 1.8000e-03;
        exchangeQueue[1] = 2.9228e-03;
        exchangeQueue[2] = 4.7460e-03;
        exchangeQueue[3] = 7.7064e-03;
        exchangeQueue[4] = 1.2513e-02;
        exchangeQueue[5] = 2.0319e-02;
        exchangeQueue[6] = 3.2994e-02;
        exchangeQueue[7] = 5.3574e-02;
        exchangeQueue[8] = 8.6993e-02;
        exchangeQueue[9] = 1.4126e-01;
        exchangeQueue[10] = 2.2937e-01;
        exchangeQueue[11] = 3.7244e-01;
        exchangeQueue[12] = 6.0477e-01;
        exchangeQueue[13] = 9.8201e-01;
        exchangeQueue[14] = 1.5946e+00;
        exchangeQueue[15] = 2.5892e+00;
        exchangeQueue[16] = 4.2043e+00;
        exchangeQueue[17] = 6.8268e+00;
        exchangeQueue[18] = 1.1085e+01;
        exchangeQueue[19] = 1.8000e+01;
        exchangeQueueIndex = 0;*/

        //für 40 * 40
        /*exchangeQueue[0] = 3.2000e-03;
        exchangeQueue[1] = 5.1961e-03;
        exchangeQueue[2] = 8.4373e-03;
        exchangeQueue[3] = 1.3700e-02;
        exchangeQueue[4] = 2.2246e-02;
        exchangeQueue[5] = 3.6123e-02;
        exchangeQueue[6] = 5.8655e-02;
        exchangeQueue[7] = 9.5243e-02;
        exchangeQueue[8] = 1.5465e-01;
        exchangeQueue[9] = 2.5112e-01;
        exchangeQueue[10] = 4.0777e-01;
        exchangeQueue[11] = 6.6212e-01;
        exchangeQueue[12] = 1.0751e+00;
        exchangeQueue[13] = 1.7458e+00;
        exchangeQueue[14] = 2.8348e+00;
        exchangeQueue[15] = 4.6030e+00;
        exchangeQueue[16] = 7.4743e+00;
        exchangeQueue[17] = 1.2137e+01;
        exchangeQueue[18] = 1.9707e+01;
        exchangeQueue[19] = 3.2000e+01;
        exchangeQueueIndex = 0;*/

        //für 50 * 50
        /*exchangeQueue[0] = 5.0000e-03;
        exchangeQueue[1] = 8.1189e-03;
        exchangeQueue[2] = 1.3183e-02;
        exchangeQueue[3] = 2.1407e-02;
        exchangeQueue[4] = 3.4760e-02;
        exchangeQueue[5] = 5.6442e-02;
        exchangeQueue[6] = 9.1649e-02;
        exchangeQueue[7] = 1.4882e-01;
        exchangeQueue[8] = 2.4165e-01;
        exchangeQueue[9] = 3.9238e-01;
        exchangeQueue[10] = 6.3714e-01;
        exchangeQueue[11] = 1.0346e+00;
        exchangeQueue[12] = 1.6799e+00;
        exchangeQueue[13] = 2.7278e+00;
        exchangeQueue[14] = 4.4293e+00;
        exchangeQueue[15] = 7.1922e+00;
        exchangeQueue[16] = 1.1679e+01;
        exchangeQueue[17] = 1.8963e+01;
        exchangeQueue[18] = 3.0792e+01;
        exchangeQueue[19] = 5.0000e+01;
        exchangeQueueIndex = 0;*/

        //für 100 * 100
        exchangeQueue[0] = 2.0000e-02;
        exchangeQueue[1] = 3.2476e-02;
        exchangeQueue[2] = 5.2733e-02;
        exchangeQueue[3] = 8.5627e-02;
        exchangeQueue[4] = 1.3904e-01;
        exchangeQueue[5] = 2.2577e-01;
        exchangeQueue[6] = 3.6660e-01;
        exchangeQueue[7] = 5.9527e-01;
        exchangeQueue[8] = 9.6659e-01;
        exchangeQueue[9] = 1.5695e+00;
        exchangeQueue[10] = 2.5485e+00;
        exchangeQueue[11] = 4.1383e+00;
        exchangeQueue[12] = 6.7196e+00;
        exchangeQueue[13] = 1.0911e+01;
        exchangeQueue[14] = 1.7717e+01;
        exchangeQueue[15] = 2.8769e+01;
        exchangeQueue[16] = 4.6714e+01;
        exchangeQueue[17] = 7.5854e+01;
        exchangeQueue[18] = 1.2317e+02;
        exchangeQueue[19] = 2.0000e+02;
        exchangeQueueIndex = 0;

        exchangeRate = exchangeQueue[0];
        /*exchangeRate = 50;
        exchangeRate2 = 100;
        exchangeRate3 = 150;
        exchangeRate4 = 200;*/
        selectionRate = 1.0;
        reproductionRate = 1.0;
        dieRate = 1.0;
        mobility = exchangeRate / (arrSize * arrSize * 2);

        //Farb- und Groesseneinstellungen für das Ausgabebild
        red = qRgb(255, 0, 0);
        blue = qRgb(0, 0, 255);
        yellow = qRgb(255, 255, 0);
        black = qRgb(0, 0, 0);

        timer = new QTimer(this);

        speciesArray.resize(arrSize * arrSize);
        speciesTempArray.resize(arrSize * arrSize);
        speciesQueue.resize(arrSize * arrSize);

        //Matrizen füllen mit Inhalt (Normale Matrix, Temp Matrix und Warteschlange

        for (int i = 0; i < arrSize * arrSize; i++)
                speciesQueue[i] = i;

        for(int i=0; i < arrSize; i++)
                for(int k=0; k < arrSize; k++)
                        setSpecies(i, k, qrand() % 4, speciesArray);

        speciesTempArray.fill(0);

        connect(timer, SIGNAL(timeout()), this, SLOT(iterate()));

        update();
}

int RPSField::getSpecies(int col, int row, const QVector<int> &array)
{
    return array[(row * arrSize) + col];
}

int RPSField::getSpecies(int col, int row)
{
    return speciesArray[(row * arrSize) + col];
}

int RPSField::getMaxSteps()
{
    return arrSize * arrSize * stepSize;
}

void RPSField::setSpecies(int col, int row, int species, QVector<int> &array)
{
    array[(row * arrSize) + col] = species;
}

int RPSField::getMatrixSize()
{
        return arrSize;
}

double RPSField::getTime()
{
        return (countSelection + countReproduction + countExchange) / (arrSize * arrSize);
}

double RPSField::getMobility()
{
        return mobility;
}

double RPSField::getExchangeRate()
{
        return exchangeRate;
}

void RPSField::setExchangeRate(double size)
{
        exchangeRate = size;
        mobility = exchangeRate / (arrSize * arrSize * 2);
        emit mobilityChanged(mobility);
}

bool RPSField::getOutput()
{
        return output;
}

void RPSField::setOutput(int onOff)
{
        if (onOff == 0)
                output = false;
        else if (onOff == 2)
                output = true;
        else
                return;
}

void RPSField::setMatrixSize(int size)
{
        if (size == 0)
                return;

        arrSize = size;

        reset();
}

int RPSField::getStepSize()
{
        return stepSize;
}

void RPSField::setStepSize(int size)
{
        if (size == 0)
                stopIteration();

        stepSize = size;
}

int RPSField::getRectSize()
{
        return rectSize;
}

void RPSField::setRectSize(int size)
{
        if (size == 0)
                return;

        rectSize = size;
        update();
}

int RPSField::getTimeSamples()
{
        return timeSamples;
}

void RPSField::setTimeSamples(int size)
{
        timeSamples = size;
}

void RPSField::startIteration()
{
        timer->start(intervall);
}

void RPSField::stopIteration()
{
        timer->stop();
}

void RPSField::reset()
{
        speciesArray.resize(arrSize * arrSize);
        speciesTempArray.resize(arrSize * arrSize);
        speciesQueue.resize(arrSize * arrSize);

        for(int i = 0; i < arrSize; i++)
                for(int k = 0; k < arrSize; k++)
                        setSpecies(i,k,rand() % 4, speciesArray);

        for (int i = 0; i < arrSize * arrSize; i++)
                speciesQueue[i] = i;

        speciesTempArray.fill(0);
        countIteration = 0;
        fileNumber = 0;
        countSelection = 0;
        countExchange = 0;
        countReproduction = 0;

        emit timeChanged(getTime());
        emit mobilityChanged(exchangeRate / (arrSize * arrSize * 2));
        emit speciesBlackChanged(getSpeciesCount(0));
        emit speciesRedChanged(getSpeciesCount(1));
        emit speciesBlueChanged(getSpeciesCount(2));
        emit speciesYellowChanged(getSpeciesCount(3));

        update();
}

void RPSField::iterate()
{
        signed int randRow = 0, randCol = 0;
        signed int col = 0, row = 0;
        signed int rowNeighbor = 0, colNeighbor = 0;
        int randNeighbor = 0;
        double randPossibility = 0.0;
        double possExchange = 0.0, possSelection = 0.0, possReproduction = 0.0;
        //double GaussExchangeRate = 0.0;
        //double possDie = 0.0;

        // Dateiausgabe an? Dann mache es...
        if(output) outputMatrix();

        for (int k = 0; k < arrSize * arrSize * stepSize; k++)
        {
                /*if (getTime() == arrSize * arrSize)
                {
                        if (countSamples >= timeSamples) {
                                timer->stop();
                                countSamples = 0;
                                break;
                        } else {
                                reset();
                        }

                        bool coexist;
                        if (getSpeciesCount(1) == arrSize * arrSize
                                || getSpeciesCount(2) == arrSize * arrSize
                                || getSpeciesCount(3) == arrSize * arrSize)
                                coexist = false;
                        else
                                coexist = true;

                        //Datei anlegen um Ergebnisse zu speichern
                        char timeFileName[50];
                        sprintf(timeFileName, "output/S%dE%f.txt", arrSize, exchangeRate);
                        QFile timeFile(timeFileName);
                        timeFile.open(QIODevice::ReadWrite);
                        timeFile.seek(timeFile.size());

                        //Inhalt für die Ausgabedatei formatieren und reinschreiben
                        char timeChar[2];

                        if(coexist) sprintf (timeChar, "%d ", 1);
                        else sprintf(timeChar, "%d ", 0);

                        timeFile.write(timeChar);
                        countSamples++;

                }*/
                //Sind zwei Spezies ausgelöscht? Wenn ja, breche Schleife ab. (Rechenaufwendig)
                if(getTime() > arrSize * arrSize && timeSamples != 0)
                {
                        update();
                        char timeFileName[50];
                        sprintf(timeFileName, "output/S%dE%f.txt", arrSize, exchangeRate);
                        QFile timeFile(timeFileName);
                        timeFile.open(QIODevice::ReadWrite);

                        char timeChar[50];

                        if(getSpeciesCount(1) == arrSize * arrSize
                           || getSpeciesCount(2) == arrSize * arrSize
                           || getSpeciesCount(3) == arrSize * arrSize)
                        {
                                sprintf (timeChar, "%d ", 0);
                        } else {
                                sprintf (timeChar, "%d ", 1);
                        }

                        timeFile.seek(timeFile.size());
                        timeFile.write(timeChar);
                        countSamples++;

                        if (countSamples >= timeSamples) {
                                countSamples = 0;
                                exchangeQueueIndex++;
                                if (exchangeQueueIndex <= 19)
                                {
                                        setExchangeRate(exchangeQueue[exchangeQueueIndex]);
                                        emit mobilityChanged(exchangeRate / (arrSize * arrSize * 2));
                                        reset();
                                        k=0;
                                }
                                else
                                {
                                        timer->stop();
                                        exchangeQueueIndex = 0;
                                        break;
                                }
                        } else {
                                reset();
                                k = 0;
                        }
                }

                randPossibility = qrand() % 1000000001 / 1000000000.0;

                //Ein zufälliges Feld in der Matrix suchen
                row = qrand() % arrSize;
                col = qrand() % arrSize;

                // Zufallsnachbar generieren (1 = links, 2 = oben, 3 = rechts, 4 = unten)

                randNeighbor = qrand() % 4 + 1;

                if (randNeighbor == 1) randRow = 0, randCol = -1;
                else if (randNeighbor == 2) randRow = -1, randCol = 0;
                else if (randNeighbor == 3) randRow = 0, randCol = 1;
                else if (randNeighbor == 4) randRow = 1, randCol = 0;
                else return;

                rowNeighbor = row + randRow;
                colNeighbor = col + randCol;

                // Gucken ob man am Ender der Matrix ist (Periodische Randbedingungen)

                if (rowNeighbor < 0) rowNeighbor = arrSize-1;
                if (colNeighbor < 0 ) colNeighbor = arrSize-1;
                if (rowNeighbor > arrSize - 1) rowNeighbor = 0;
                if (colNeighbor > arrSize - 1) colNeighbor = 0;

                /*GaussExchangeRate = ( - exp(- 1.0 / 50000.0 * ( (row - arrSize / 2) * (row - arrSize / 2) + (col - arrSize / 2) * (col - arrSize / 2) ) ) * exchangeRate ) + exchangeRate + 20;
                //GaussExchangeRate = row * exchangeRate;
                possExchange = GaussExchangeRate / (GaussExchangeRate + selectionRate + reproductionRate);
                possSelection = possExchange + selectionRate / (GaussExchangeRate + selectionRate + reproductionRate);
                possReproduction = possSelection + reproductionRate / (GaussExchangeRate + selectionRate + reproductionRate);*/

                /*if (row < arrSize / 2 && col < arrSize / 2){
                        possExchange = exchangeRate / (exchangeRate + selectionRate + reproductionRate);
                        possSelection = possExchange + selectionRate / (exchangeRate + selectionRate + reproductionRate);
                        possReproduction = possSelection + reproductionRate / (exchangeRate + selectionRate + reproductionRate);
                } else if (row < arrSize / 2 && col >= arrSize / 2) {
                        possExchange = exchangeRate2 / (exchangeRate2 + selectionRate + reproductionRate);
                        possSelection = possExchange + selectionRate / (exchangeRate2 + selectionRate + reproductionRate);
                        possReproduction = possSelection + reproductionRate / (exchangeRate2 + selectionRate + reproductionRate);
                } else if (row >= arrSize / 2 && col < arrSize / 2) {
                        possExchange = exchangeRate3 / (exchangeRate3 + selectionRate + reproductionRate);
                        possSelection = possExchange + selectionRate / (exchangeRate3 + selectionRate + reproductionRate);
                        possReproduction = possSelection + reproductionRate / (exchangeRate3 + selectionRate + reproductionRate);
                } else {
                        possExchange = exchangeRate4 / (exchangeRate4 + selectionRate + reproductionRate);
                        possSelection = possExchange + selectionRate / (exchangeRate4 + selectionRate + reproductionRate);
                        possReproduction = possSelection + reproductionRate / (exchangeRate4 + selectionRate + reproductionRate);
                }*/

                /*possExchange = exchangeRate / (exchangeRate + selectionRate + reproductionRate + dieRate);
                possSelection = possExchange + selectionRate / (exchangeRate + selectionRate + reproductionRate + dieRate);
                possReproduction = possSelection + reproductionRate / (exchangeRate + selectionRate + reproductionRate + dieRate);
                possDie = possReproduction + dieRate / (exchangeRate + selectionRate + reproductionRate + dieRate);*/

                possExchange = exchangeRate / (exchangeRate + selectionRate + reproductionRate);
                possSelection = possExchange + selectionRate / (exchangeRate + selectionRate + reproductionRate);
                possReproduction = possSelection + reproductionRate / (exchangeRate + selectionRate + reproductionRate);

                if (randPossibility >= 0 && randPossibility < possExchange) // Austausch
                {
                        randNeighbor = getSpecies(colNeighbor, rowNeighbor, speciesArray);
                        setSpecies(colNeighbor, rowNeighbor, getSpecies(col, row, speciesArray), speciesArray);
                        setSpecies(col, row, randNeighbor, speciesArray);
                        //countExchange++;
                }

                if (randPossibility >= possExchange && randPossibility < possSelection) // Selektion
                {
                        // Gucken ob man selber verliert
                        if ((getSpecies(col, row, speciesArray) == 2 && getSpecies(colNeighbor, rowNeighbor, speciesArray) == 1)
                                ||  (getSpecies(col, row, speciesArray) == 3 && getSpecies(colNeighbor, rowNeighbor, speciesArray) == 2)
                                ||  (getSpecies(col, row, speciesArray) == 1 && getSpecies(colNeighbor, rowNeighbor, speciesArray) == 3))
                        {
                                setSpecies(col, row, 0, speciesArray);
                                //countSelection++;
                        }
                        // Gucken ob der Nachbar verliert
                        if((getSpecies(col, row, speciesArray) == 1 && getSpecies(colNeighbor, rowNeighbor, speciesArray) == 2)
                                || (getSpecies(col, row, speciesArray) == 2 && getSpecies(colNeighbor, rowNeighbor, speciesArray) == 3)
                                || (getSpecies(col, row, speciesArray) == 3 && getSpecies(colNeighbor, rowNeighbor, speciesArray) == 1))
                        {
                                setSpecies(colNeighbor, rowNeighbor, 0, speciesArray);
                                //countSelection++;
                        }
                        countSelection++;
                }

                if (randPossibility >= possSelection && randPossibility < possReproduction) // Reproduktion
                {
                        // Gucken ob man sich selber reproduzieren soll
                        if (getSpecies(colNeighbor, rowNeighbor, speciesArray) == 0 && getSpecies(col, row, speciesArray) != 0)
                                //&& getSpeciesNeighborCount(col, row, getSpecies(col, row, speciesArray)) > 1)
                        {
                                setSpecies(colNeighbor, rowNeighbor, getSpecies(col, row, speciesArray), speciesArray);
                                //countReproduction++;
                        }
                        // Gucken ob sich der andere reproduziert
                        if (getSpecies(col, row, speciesArray) == 0 && getSpecies(colNeighbor, rowNeighbor, speciesArray) != 0)
                                //&& getSpeciesNeighborCount(colNeighbor, rowNeighbor, getSpecies(colNeighbor, rowNeighbor, speciesArray)) > 1)
                        {
                                setSpecies(col, row, getSpecies(colNeighbor, rowNeighbor, speciesArray), speciesArray);
                                //countReproduction++;
                        }
                        countReproduction++;
                }

                /*if (randPossibility >= possReproduction && randPossibility < possDie) // Aussterben
                {
                        setSpecies(col, row, 0, speciesArray);
                        countSelection++;
                }*/
        }

        update();
        emit timeChanged(getTime());
        emit speciesBlackChanged(getSpeciesCount(0));
        emit speciesRedChanged(getSpeciesCount(1));
        emit speciesBlueChanged(getSpeciesCount(2));
        emit speciesYellowChanged(getSpeciesCount(3));
}

int RPSField::getSpeciesCount(int species)
{
        int countSpecies = 0;
        for(int i=0; i < arrSize; i++)
                for(int k=0; k < arrSize; k++)
                        if(getSpecies(i, k, speciesArray) == species)
                                countSpecies++;

        return countSpecies;
}

int RPSField::getSpeciesNeighborCount(int col, int row, int species)
{
        int countSpecies = 0;
        int leftNeighbor = col - 1;
        int	topNeighbor = row - 1;
        int	rightNeighbor = col + 1;
        int	bottomNeighbor = row + 1;

        if (getSpecies(col, row, speciesArray) == species)
                countSpecies++;

        //Periodische Randbedingungen
        if (row - 1 < 0) topNeighbor = arrSize - 1;
        if (col - 1 < 0) leftNeighbor = arrSize - 1;
        if (row + 1 > arrSize - 1) bottomNeighbor = 0;
        if (col + 1 > arrSize - 1) rightNeighbor = 0;

        if (getSpecies(leftNeighbor, row, speciesArray) == species)
                countSpecies++;
        if (getSpecies(col, topNeighbor, speciesArray) == species)
                countSpecies++;
        if (getSpecies(rightNeighbor, row, speciesArray) == species)
                countSpecies++;
        if (getSpecies(col, bottomNeighbor, speciesArray) == species)
                countSpecies++;

        return countSpecies;
}

void RPSField::shuffleArray(QVector<int> &array)
{
        int randIndex = 0;
        int length = array.size();

        QVector<int> tempArr;
        tempArr.resize(length);

        for(int i = 0; i < length; i++)
        {
                randIndex = qrand() % (length - i);
                tempArr[i] = array[randIndex];
                array.remove(randIndex);
        }

        array.resize(length);

        for (int i = 0; i < length; i++)
        {
                array[i] = tempArr[i];
        }
}

int RPSField::freeNeighbor(int col, int row)
{
        int leftCol = 0, topRow = 0, rightCol = 0, bottomRow = 0;
        QVector<int> freeNeighborArr;
        freeNeighborArr.resize(0);

        leftCol = col - 1;
        topRow = row - 1;
        rightCol = col + 1;
        bottomRow = row + 1;

        //Periodische Randbedingungen
        if (row - 1 < 0) topRow = arrSize - 1;
        if (col - 1 < 0 ) leftCol = arrSize - 1;
        if (row + 1 > arrSize - 1) bottomRow = 0;
        if (col + 1 > arrSize - 1) rightCol = 0;

        if (getSpecies(leftCol, row, speciesArray) == 0) freeNeighborArr.append(1);
        else if (getSpecies(col, topRow, speciesArray) == 0) freeNeighborArr.append(2);
        else if (getSpecies(rightCol, row, speciesArray) == 0) freeNeighborArr.append(3);
        else if (getSpecies(col, bottomRow, speciesArray) == 0) freeNeighborArr.append(4);
        else
                return 0;

        return freeNeighborArr[qrand() % freeNeighborArr.size()];
}

void RPSField::outputMatrix()
{
        char fileName[50];
        sprintf (fileName, "output/%d_%d.png", arrSize, fileNumber);

        QImage speciesImage(arrSize, arrSize, QImage::Format_RGB32);
        QImageWriter writer(fileName, "png");

        for(int i=0; i < arrSize; i++)
        {
                for(int k=0; k < arrSize; k++)
                {
                        if (getSpecies(i,k, speciesArray) == 0)
                                speciesImage.setPixel(i, k, black);
                        else if (getSpecies(i,k, speciesArray) == 1)
                                speciesImage.setPixel(i, k, red);
                        else if (getSpecies(i,k, speciesArray) == 2)
                                speciesImage.setPixel(i, k, blue);
                        else if (getSpecies(i,k, speciesArray) == 3)
                                speciesImage.setPixel(i, k, yellow);
                        else
                                return;
                }
        }
        writer.write(speciesImage);
        fileNumber++;
}

void RPSField::paintEvent(QPaintEvent *)
{
        QPainter painter(this);
        painter.setPen(Qt::NoPen);
        painter.setRenderHint(QPainter::Antialiasing);

        for(int i=0; i < arrSize; i++)
        {
                for(int k=0; k < arrSize; k++)
                {
                        if (getSpecies(i,k, speciesArray) == 0)
                                painter.setBrush(Qt::black);
                        else if (getSpecies(i,k, speciesArray) == 1)
                                painter.setBrush(Qt::red);
                        else if (getSpecies(i,k, speciesArray) == 2)
                                painter.setBrush(Qt::blue);
                        else if (getSpecies(i,k, speciesArray) == 3)
                                painter.setBrush(Qt::yellow);
                        else if (getSpecies(i,k, speciesArray) == 4)
                                painter.setBrush(Qt::green);
                        else
                                return;
                        painter.drawRect(i*rectSize,k*rectSize,rectSize,rectSize);
                }
        }

        /*
        for(int i=0; i < arrSize; i++)
        {
                for(int k=0; k < arrSize; k++)
                {
                        if (getSpecies(i, k, speciesTempArray) == 1)
                                painter.setBrush(Qt::green);
                        if (getSpecies(i, k, speciesTempArray) == 0)
                                painter.setBrush(Qt::black);
                        painter.drawRect((arrSize * rectSize) + 10 + (i * rectSize), k * rectSize, rectSize, rectSize);
                }
        }
        speciesTempArray.fill(0);*/
}

RPSField::~RPSField()
{

}
