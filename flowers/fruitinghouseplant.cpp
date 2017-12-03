#include "fruitinghouseplant.hpp"


FruitingHousePlant::FruitingHousePlant
	(
	const std::string & _namePlant,
	const std::string  & _fruitName,
	int _plantAge,
	int _wateringPeriod,
	int _needdedSuccesfulWaterings,
	int _floweringTime,
	int _fruitingTime
	)
	:
	FloweringHouseplant
	(
	_namePlant
	, _plantAge
	, _wateringPeriod
	, _needdedSuccesfulWaterings
	, _floweringTime)
	,m_fruitingTime(_fruitingTime)
	,m_fruitName(_fruitName)
{
	if (_fruitName.empty()) throw std::logic_error(Messages::EmptyFruitName);
	if (_fruitingTime <= 0) throw std::logic_error(Messages::IncorrectFruitingPeriod);

	m_daysInFruiting = 0;
}
void FruitingHousePlant::makeWatering()
{
	if (logic_isEndOfFlowering())
	{
		logic_setFlowerState(FlowerState::Fruiting) ;
		logic_independentWatering(m_isCorrectWateringInFruiting, FlowerState::Fruiting);
	}
	if (getFlowerStatus() == FlowerState::Fruiting) 
	{
		logic_independentWatering(m_isCorrectWateringInFruiting, FlowerState::Fruiting);
	}
	else
	{
		FloweringHouseplant::makeWatering();
	}
}
const std::string & FruitingHousePlant::getFruitName() const
{
	return m_fruitName;
}
int FruitingHousePlant::getFruitingTime()
{
	return m_fruitingTime;
}
FruitingHousePlant::FlowerState FruitingHousePlant::getFruitingState()
{
	return getFlowerStatus();
}

void FruitingHousePlant::dayPassed()
{
	HousePlant::dayPassed();

	logic_passedDay();
	if(logic_isEndOfFlowering())
	{
		logic_setFlowerState(FlowerState::Fruiting);
		m_nDaysInFloweringState = 0;
		return;
	}
	if (!logic_needWateringToday())
	{
		if (FlowerState::Fruiting == getFlowerStatus())
		{
			m_daysInFruiting++;
		}
	}
	else 
	{
		logic_resetWateringPeriod();
		logic_resetFruiting();
	}

	if (logic_isEndOfFruiting()) 
	{
		incrementWateringPeriod(2);
		logic_resetFruiting();
	}

}
bool FruitingHousePlant::logic_isEndOfFruiting()
{
	if (getFruitingTime() == m_daysInFruiting) 
	{
		std::cout<< std::endl << "Fruit: " << getFruitName() << " has succesfuly complete the fruiting!"<<std::endl;
		return true;
	}
	return false;
}

void FruitingHousePlant::logic_resetFruiting()
{
	m_daysInFruiting = 0;
	logic_resetWateringPeriod();
}
