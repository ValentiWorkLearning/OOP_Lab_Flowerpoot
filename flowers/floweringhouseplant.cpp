#include "floweringhouseplant.hpp"

FloweringHouseplant::FloweringHouseplant(
	std::string const& _name
	,int _plantAge
	,int _irregationPeriod
	,int _needdedSuccesfulWaterings
	,int _floweringTime )
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

int FloweringHouseplant::getFloweringTime()const 
{
	return m_floweringTime;
}

int FloweringHouseplant::getCurrentWaterings()const 
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
	HousePlant::dayPassed(); //Pass the day 
	
	logic_passedDay();

	if (logic_isEndOfFlowering()) 
	{
		incrementWateringPeriod(2);
		logic_resetWateringPeriod();
	}
}

void FloweringHouseplant::makeWatering()
{
	logic_independentWatering(m_isCorrectWateringInFlowering, FlowerState::Flowering);
}

bool FloweringHouseplant::logic_isEndOfFlowering()
{

	if (getFloweringTime() == m_nDaysInFloweringState) 
	{
		std::cout << "Congratulation! Your plant name:" << getPlantName() << " has succesfully completed the flowering" << std::endl;
		return true;
	}
	return false;
}

bool FloweringHouseplant::logic_isWateringAtTime()
{
	Date dateOfLastWatering = getDateOfLastWatering();
	Date currentDate;
	
	currentDate.addDay(getPassedDays());

	return (dateOfLastWatering.dayDifference( currentDate ) == getPlantWateringPeriod() ) ? true:false;
}

bool FloweringHouseplant::logic_isWateringBeforeAfter1Day()
{
	Date dateOfLastWatering = getDateOfLastWatering();
	Date currentDate;

	currentDate.addDay(getPassedDays());

	return (dateOfLastWatering.dayDifference(currentDate) == getPlantWateringPeriod() + 1 || 
		dateOfLastWatering.dayDifference(currentDate) == getPlantWateringPeriod() -1) ? true : false;
}

bool FloweringHouseplant::logic_needWateringToday()
{
	Date currentDate;
	Date lastWatering = getDateOfLastWatering();
	currentDate.addDay(getPassedDays());

	return ( lastWatering.dayDifference(currentDate) > getPlantWateringPeriod()+1) ? true:false;
}

void FloweringHouseplant::logic_independentWatering(bool _setUpFlag, FlowerState _triggeredState)
{

	if (logic_isWateringAtTime())
	{
		if (getFlowerStatus() == _triggeredState)
		{
			_setUpFlag = true;
		}
		else
		{
			m_currentWaterings++;
			if (m_currentWaterings == m_needdedSuccesfulWaterings) m_flowerStatus = FlowerState::Flowering;
		}
		HousePlant::setDateOfLastWatering(Date());
		return;

	}
	if (logic_isWateringBeforeAfter1Day())
	{
		if (getFlowerStatus() == _triggeredState)
		{
			_setUpFlag = true;
		}
		HousePlant::setDateOfLastWatering(Date());
		return;
	}
	else
	{
		if (getFlowerStatus() == _triggeredState) //If flowering process - reset the corrects waterings 
		{
			_setUpFlag = false;
		}
		else
		{
			if (m_currentWaterings)m_currentWaterings--;
		}
	}
	HousePlant::setDateOfLastWatering(Date());


}

void FloweringHouseplant::logic_setFlowerState(FlowerState  _flowerState)
{
	m_flowerStatus = _flowerState;
}

void FloweringHouseplant::logic_passedDay()
{
	if (getFlowerStatus() == FlowerState::Flowering)
	{
		if (m_isCorrectWateringInFlowering && !logic_needWateringToday())
		{
			m_nDaysInFloweringState++;
		}
		else
		{
			logic_resetWateringPeriod();
		}
	}
}




