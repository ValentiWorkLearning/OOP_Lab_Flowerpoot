#include "foliarhouseplant.hpp"


FoliarHousePlant::FoliarHousePlant(const std::string & _namePlant, int _wateringPeriod, int _plantAge , int _mInitialHeight)
	:
	HousePlant(_namePlant, _wateringPeriod, _plantAge), m_height(_mInitialHeight), m_correctWatering(false)
{
	if (_mInitialHeight < 0)throw std::logic_error(Messages::IncorrectInitialHeight);
}

void FoliarHousePlant::dayPassed()
{
	HousePlant::dayPassed();
	if (m_correctWatering &&!logic_needWateringToday())
	{
		m_height++;
	}
	
	if (m_height == maxFlowerHeight) 
	{
		m_height /=2 ;
	}
}

int FoliarHousePlant::getPlantWateringPeriod() const
{
	return HousePlant::getPlantWateringPeriod();
}

void FoliarHousePlant::makeWatering()
{
	if (logic_isWateringCorrect()) 
	{
		m_correctWatering = true;
	}
	else 
	{
		m_correctWatering = false;
	}
	HousePlant::setDateOfLastWatering(Date());
}

int FoliarHousePlant::getPlantAge() const
{
	return HousePlant::getPlantAge();
}

int FoliarHousePlant::getCurrentHeight()
{
	return m_height;
}


bool FoliarHousePlant::logic_isWateringCorrect()
{
	Date dateOfLastWatering = getDateOfLastWatering();
	Date currentDate;

	currentDate.addDay(getPassedDays());

	return (dateOfLastWatering.dayDifference(currentDate) == getPlantWateringPeriod() + 1 ||
		dateOfLastWatering.dayDifference(currentDate) == getPlantWateringPeriod() - 1 ||
		dateOfLastWatering.dayDifference(currentDate) == getPlantWateringPeriod()) ? true : false;
}

bool FoliarHousePlant::logic_needWateringToday()
{
	Date currentDate;
	Date lastWatering = getDateOfLastWatering();
	currentDate.addDay(getPassedDays());

	return (lastWatering.dayDifference(currentDate) > getPlantWateringPeriod() + 1) ? true : false;
}
