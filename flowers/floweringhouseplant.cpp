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
	m_flowerStatus = FlowerState::Growing;
	m_daysPassed = 0;
	m_daysInFloweringSchedule = 0;
}

void FloweringHouseplant::makeWatering()
{
	
	std::cout << "Waterring..." << std::endl;
	logic_makeWatering();
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

FloweringHouseplant::FlowerState FloweringHouseplant::getFlowerStatus()
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
	m_flowerStatus = FlowerState::Growing;
}

void FloweringHouseplant::logic_makeWatering()
{
	
	switch (getFlowerStatus())
	{
	case FlowerState::Growing:
		if (getWateringPeriod() == getPassedDays()) 
		{
			m_daysPassed = 0;
			m_currentWaterings++;

			if (m_currentWaterings == getNeededSuccesfulWaterings()) 
			{
				m_flowerStatus = FlowerState::Flowering;
				m_currentWaterings = 0;
			}
			break;
		}
		if (std::abs((getWateringPeriod() - getPassedDays()) == 1)) 
		{
			return;
		}
		else 
		{
			if (m_currentWaterings)m_currentWaterings--;
		}
		break;

	case FlowerState::Flowering:
		if (getWateringPeriod() == getPassedDays()) 
		{
			std::cout << "Great Job.. In Flowering process..." << getPlantName() << std::endl;
			m_daysInFloweringSchedule++;
			m_daysPassed = 0;
			if (m_daysInFloweringSchedule == getFloweringTime()) 
			{

				m_flowerStatus = FlowerState::EndFlowering;
				break;
			}
		}
	break;
	
	case FlowerState::EndFlowering: 
	{
		std::cout << "Congratulation! Your plant name:" << getPlantName() << " has succesfully completed the flowering";
		incrementWateringPeriod(2);
		m_daysInFloweringSchedule = 0;
		m_flowerStatus = FlowerState::Growing;

	}
	default:
		break;
	}
}
