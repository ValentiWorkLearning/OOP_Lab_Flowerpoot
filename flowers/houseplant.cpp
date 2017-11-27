#include "houseplant.h"

HousePlant::HousePlant(const std::string & _plantName, int _irrigationPeriod , int _plantAge )
{
	if (_plantName.empty())
		throw std::logic_error(Messages::EmptyPlantName);

	if (_irrigationPeriod <= 0)
		throw
		std::logic_error(Messages::IncorrectIrrigationPeriod);

	if (_plantAge < 0)
		throw std::logic_error(Messages::IncorrectPlantAge);

	m_irrigationPeriod = _irrigationPeriod;
	m_plantName = _plantName;
	m_plantAge = _plantAge;

}
