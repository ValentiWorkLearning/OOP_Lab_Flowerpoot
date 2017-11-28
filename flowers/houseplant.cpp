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
	m_firstWatering = false;
	m_dateOfLastWatering = Date(1, 1, 1);

}

//Increment methods 
void HousePlant::incrementWateringPeriod()
{
	m_wateringPeriod++;
}

void HousePlant::addDay(int _nDays)
{
	m_dateOfLastWatering.addDay(_nDays);
}

void HousePlant::setFirstWatering(const Date & _date)
{
	if (m_firstWatering)
		throw std::logic_error(Messages::RepeatInitOfFirstWatering);
	
	m_firstWatering = true;
	m_dateOfLastWatering = _date;
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

const Date & HousePlant::getDateOfLastWatering() const
{
	return m_dateOfLastWatering;
}