#include "room.hpp"

void Room::addPlant(HousePlant * _plant)
{
	m_plants.insert({ _plant->getPlantName(),std::unique_ptr<HousePlant>(_plant) });
}

int Room::getFlowerAge(std::string const & _plantName)
{
	return findPlant(_plantName)->getPlantAge();
}

void Room::pourOnFlower(std::string const & _plantName)
{
	findPlant(_plantName)->makeWatering();
}

void Room::pourAllPlants()
{
	for (auto & item  : m_plants) 
	{
		item.second->makeWatering();
	}
}

void Room::passDays(int _days)
{
	for (auto & item : m_plants) 
	{
		item.second->dayPassed();
	}
}

int Room::flowersCount()
{
	return m_plants.size();
}

HousePlant * Room::findPlant(std::string const & _plantName)
{
	auto it =  m_plants.find(_plantName);

	if (it == m_plants.end())
		throw std::logic_error(Messages::PlantDoesNotExist);

	return it->second.get();
}

