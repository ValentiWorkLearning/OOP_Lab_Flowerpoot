#include "room.hpp"
#include "gardener.hpp"
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

void Room::passDays()
{
	for (auto & item : m_plants) 
	{
		item.second->dayPassed();
		//item.second->accept();
	}
	m_currentData.addDay(1);
}

int Room::flowersCount()
{
	return m_plants.size();
}

void Room::visit(FoliarHousePlant  * _housePlant)
{
}

HousePlant * Room::findPlant(std::string const & _plantName)
{
	auto it =  m_plants.find(_plantName);

	if (it == m_plants.end())
		throw std::logic_error(Messages::PlantDoesNotExist);

	return it->second.get();
}

