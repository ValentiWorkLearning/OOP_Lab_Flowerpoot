#include "room.hpp"

void Room::addFloweringPlant(std::string const & _plantName, int _plantAge, int _irregationPeriod, int _needdedSuccesfulFlowerings, int _floweringTime)
{
	m_plants.insert({ _plantName,std::make_unique<FloweringHouseplant>(_plantName,_plantAge,_irregationPeriod, 
		_needdedSuccesfulFlowerings, _floweringTime)  } ) ;
}

int Room::getFlowerAge(std::string const & _plantName)
{
	return findPlant(_plantName)->getPlantAge();
}

void Room::pourOnFlower(std::string const & _plantName)
{
	findPlant(_plantName)->makeIrrigation();
}

HousePlant * Room::findPlant(std::string const & _plantName)
{
	auto it =  m_plants.find(_plantName);

	if (it == m_plants.end())
		throw std::logic_error(Messages::PlantDoesNotExist);

	return it->second.get();
}

