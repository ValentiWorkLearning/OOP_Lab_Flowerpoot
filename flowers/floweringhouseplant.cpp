#include "floweringhouseplant.hpp"

FloweringHouseplant::FloweringHouseplant(
	std::string const& _name,
	int _plantAge, 
	int _irregationPeriod,  
	int _needdedSuccesfulWaterings, 
	int _floweringTime )
	:
	HousePlant(_name, _irregationPeriod ,_plantAge)
{
	if (_needdedSuccesfulWaterings <= 0)
		throw std::logic_error(Messages::IncorrectValueSuccesfulWaterings);
	
	if (_floweringTime <= 0)
		throw std::logic_error(Messages::IncorrectFloweringTime);

	m_floweringTime = _floweringTime;
	m_needdedSuccesfulFlowerings = _needdedSuccesfulWaterings;
	m_currentWaterings = 0;


}

void FloweringHouseplant::makeWatering()
{
	
	std::cout << "Waterring..." << std::endl;
}

int FloweringHouseplant::getWateringAmount()
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

void FloweringHouseplant::resetWaterings()
{
	m_currentWaterings = 0;
}

void FloweringHouseplant::resetFloweringStatus()
{
	m_flowerStatus = 0;
}
