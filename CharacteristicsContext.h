#pragma once

#include <QString>

#include "CharacteristicTypeContext.h"
#include "TableContext.h"

class CharacteristicsContext : public TableContext
{
public:
	CharacteristicsContext(QString stateFilePath);
	CharacteristicsContext();
	void SetChannel(QString);
	void SetWeight(double weight);
	void SetBinTime(double binTime);
	void SetX(QString x);
	void SetY(QString y);
	void SetNumberOfPoints(int numberOfPoints);
	void AddNewXCoordinate(QString x);
	void AddNewYCoordinate(QString y);
	void SetFKMeasurement(int fk_measurement);
	void SetFKCharacteristicType(CharacteristicTypeContext* fk_characteristic_type);

	QString GetChannel();
	int GetNumberOfPoints();
	QString GetX();
	QString GetY();
	double GetWeight();
	double GetBinTime();
	int GetFKCharacteristicType();
	int GetFKMeasurement();

private:
	QString channel = "";
	QString x = "";
	QString y = "";
	double weight = 0.0;
	double binTime = 0.0;
	int numberOfPoints = 0;
	int fk_measurement = 0;
	CharacteristicTypeContext* fk_characteristic_type = nullptr;
};
