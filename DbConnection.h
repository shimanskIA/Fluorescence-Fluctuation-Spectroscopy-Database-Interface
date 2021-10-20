#pragma once

#include <QtSql>
#include <QSqlDatabase>
#include <QList>

#include "DbContext.h"

class DbConnection
{
public:
	static DbConnection& GetDbConnectionInstance();
	void AddToDatabase(DbContext* dbContext);
	QSqlQuery ReadFromDatabase(QString sqlRequest);
	bool WriteToDatabase(QString sqlWriteRequest, QString tableName);
	void AddSamples(QList<SampleContext*> samples);
	void AddCharacteristicTypes(QList<CharacteristicTypeContext*> characteristic_types);
	void AddMeasurementParameters(QList<MeasurementParameterContext*> measurementParameters);
	void AddEquipmentParameters(QList<EquipmentParameterContext*> equipmentParameters);
	void AddCharacteristics(QList<CharacteristicsContext*> characteristics);

	void AddMeasuringSystem(MeasuringSystemContext* measuringSystem);

	void AddMeasurements(QList<MeasurementContext*> measurements);
	void AddEquipment(QList<EquipmentContext*> equipments);

	void AddBindings(QList<BindingContext*> bindings);

	QList<MeasurementContext*> ReadMeasurementsFromDatabase();
	QList<MeasurementContext*> ReadMeasurementsFromDatabase(int fk_sample);
	QList<SampleContext*> ReadSamplesFromDatabase();
	QList<EquipmentContext*> ReadEquipmentsFromDatabase();
	QList<CharacteristicsContext*> ReadCharacteristicsFromDatabase(int fk_measurement);
	QList<BindingContext*> ReadBindingsFromDatabase(int fk_measurement);
	QList<ParameterTableContext*> ReadParametersFromDatabase(QString majorTableName, QString minorTableName, int fk);

private:
	DbConnection();
	DbConnection(const DbConnection&) {}
	QSqlDatabase database;

	bool wasEquipmentAdded = false;
};




