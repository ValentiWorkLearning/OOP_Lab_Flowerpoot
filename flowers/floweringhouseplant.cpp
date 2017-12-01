#include "floweringhouseplant.hpp"

FloweringHouseplant::FloweringHouseplant(
	std::string const& _name,
	int _plantAge, 
	int _irregationPeriod,  
	int _needdedSuccesfulWaterings, 
	int _floweringTime )
	:
	HousePlant(_name, _irregationPeriod ,_plantAge),
	m_needdedSuccesfulWaterings(_needdedSuccesfulWaterings),
	m_floweringTime(_floweringTime)
{
	if (_needdedSuccesfulWaterings <= 0)
		throw std::logic_error(Messages::IncorrectValueSuccesfulWaterings);
	
	if (_floweringTime <= 0)
		throw std::logic_error(Messages::IncorrectFloweringTime);
		
	m_currentWaterings = 0;
	m_flowerStatus = FlowerState::Growing;
	m_isCorrectWateringInFlowering = true;
	m_nDaysInFloweringState = 0;
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
	return m_needdedSuccesfulWaterings;
}

int FloweringHouseplant::getPassedDays()
{
	return HousePlant::getPassedDays();
}

void FloweringHouseplant::makeFirstWatering(const Date& _date)
{
	HousePlant::makeFirstWatering(_date);
	m_currentWaterings++;
}

//Reset methods
void FloweringHouseplant::logic_resetWateringPeriod() 
{
	m_isCorrectWateringInFlowering = true;
	m_flowerStatus = FlowerState::Growing;
	m_currentWaterings = 0;
	m_nDaysInFloweringState = 0;
}

//Flowering logic
void FloweringHouseplant::dayPassed()
{
	HousePlant::dayPassed();

	if (getFlowerStatus() == FlowerState::Flowering) 
	{
		if (m_isCorrectWateringInFlowering) 
		{
			m_nDaysInFloweringState++;
		}
		else
		{
			logic_resetWateringPeriod();
		}
	}
	logic_isEndOfFlowering();
}

void FloweringHouseplant::makeWatering()
{
	
	if ( logic_isWateringAtTime() )
	{
		if (getFlowerStatus() == FlowerState::Flowering)
		{
			m_isCorrectWateringInFlowering = true;
		}
		else
		{
			m_currentWaterings++;
			if (m_currentWaterings == m_needdedSuccesfulWaterings) m_flowerStatus = FlowerState::Flowering;
		}
		return;

	}
	if (logic_isWateringBeforeAfter1Day())
	{
		if (getFlowerStatus() == FlowerState::Flowering)
		{
			m_isCorrectWateringInFlowering = true;
		}
		return;
	}
	else
	{
		if (getFlowerStatus() == FlowerState::Flowering)
		{
			logic_resetWateringPeriod();
		}
		else
		{
			if (m_currentWaterings)m_currentWaterings--;
		}
	}
	
}

void FloweringHouseplant::logic_isEndOfFlowering()
{

	if (getFloweringTime() == m_nDaysInFloweringState) 
	{
		std::cout << "Congratulation! Your plant name:" << getPlantName() << " has succesfully completed the flowering" << std::endl;
		incrementWateringPeriod(2);
		logic_resetWateringPeriod();
	}
}

bool FloweringHouseplant::logic_isWateringAtTime()
{
	return((getPassedDays() % getWateringPeriod()) == 0) ? true : false;
}

bool FloweringHouseplant::logic_isWateringBeforeAfter1Day()
{
	int m_passedTemp = getPassedDays();
	return ((m_passedTemp % getWateringPeriod() == 1) || (++m_passedTemp % getWateringPeriod() == 0))?true:false;
}

