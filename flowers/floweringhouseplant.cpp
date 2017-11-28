#include "floweringhouseplant.hpp"

FloweringHouseplant::FloweringHouseplant(
	std::string const& _name,
	int _plantAge, 
	int _irregationPeriod,  
	int _needdedSuccesfulWaterings, 
	int _floweringTime )
	:
	HousePlant(_name, _irregationPeriod ,_plantAge),
	m_needdedSuccesfulFlowerings(_needdedSuccesfulWaterings),
	m_floweringTime(_floweringTime)
{
	if (_needdedSuccesfulWaterings <= 0)
		throw std::logic_error(Messages::IncorrectValueSuccesfulWaterings);
	
	if (_floweringTime <= 0)
		throw std::logic_error(Messages::IncorrectFloweringTime);
		
	m_currentWaterings = 0;
	m_flowerStatus = 0;
	m_daysPassed = 0;
}

void FloweringHouseplant::makeWatering()
{
	
	std::cout << "Waterring..." << std::endl;
}


//Getters methods 
int FloweringHouseplant::getWateringPeriod()
{
	return HousePlant::getPlantWateringPeriod() ;
}

int FloweringHouseplant::getFloweringTime()
{
	return m_floweringTime;
}

int FloweringHouseplant::getCurrentWaterings()
{
	return m_currentWaterings;
}

int FloweringHouseplant::getFlowerStatus()
{
	return m_flowerStatus;
}

int FloweringHouseplant::getNeededSuccesfulWaterings()
{
	return m_needdedSuccesfulFlowerings;
}

int FloweringHouseplant::getPassedDays()
{
	return m_daysPassed;
}

void FloweringHouseplant::dayPassed()
{
	m_daysPassed++;
}



//Reset methods
void FloweringHouseplant::resetWaterings()
{
	m_currentWaterings = 0;
}

void FloweringHouseplant::resetFloweringStatus()
{
	m_flowerStatus = 0;
}

void FloweringHouseplant::logic_makeWatering()
{
	if (getFlowerStatus()) 
	{
		if (getWateringPeriod() == getPassedDays()) //If water period OK - add current waterings
		{
			m_currentWaterings++;
		}
		else 
		{
			if (getNeededSuccesfulWaterings() - getPassedDays() == 1) //If no good - nothing do
			{
				return;
			}
			else	//If wrong..
			{
				if (m_currentWaterings) m_currentWaterings--;
			}
		}
	}
	else 
	{
	}
}
