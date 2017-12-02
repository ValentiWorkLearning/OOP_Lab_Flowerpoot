#include "houseplant.hpp"

//Constructor 
HousePlant::HousePlant
	(
		const std::string & _plantName, 
		int _wateringPeriod , 
		int _plantAge 
	)
{
	if (_plantName.empty())
		throw std::logic_error(Messages::EmptyPlantName);

	if (_wateringPeriod <= 0)
		throw
		std::logic_error(Messages::IncorrectIrrigationPeriod);

	if (_plantAge < 0)
		throw std::logic_error(Messages::IncorrectPlantAge);

	m_wateringPeriod = _wateringPeriod;
	m_plantName = _plantName;
	m_plantAge = _plantAge;
	m_daysPassed = 0;
	m_dateOfLastWatering = Date();

}

//Increment methods 
void HousePlant::incrementWateringPeriod( int _inc)
{
	m_wateringPeriod+=_inc;
}

void HousePlant::addDay(int _nDays)
{
	m_dateOfLastWatering.addDay(_nDays);
}

//Getters methods
const std::string & HousePlant::getPlantName()
{
	return m_plantName;
}

int  HousePlant::getPlantAge()const
{
	return m_plantAge;
}

int HousePlant::getPlantWateringPeriod() const
{
	return m_wateringPeriod;
}

void HousePlant::resetPassedDays()
{
	m_daysPassed = 0;
}

const Date & HousePlant::getDateOfLastWatering() 
{
	return m_dateOfLastWatering;
}

void HousePlant::setDateOfLastWatering(Date _date)
{
	_date.addDay(getPassedDays());
	m_dateOfLastWatering = _date;
}
