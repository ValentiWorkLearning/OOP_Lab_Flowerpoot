#ifndef ROOM_H
#define ROOM_H

#include <memory>
#include <map>
#include< string >

#include "date.hpp"
#include "floweringhouseplant.hpp"

#include "messages.hpp"


class Room 
{
public:

	Room() = default;

	Room(const Room &) = delete;

	Room & operator = (const Room) = delete;
	
	~Room() = default;


	void addPlant(HousePlant * _plant);
	
	int  getFlowerAge(std::string const & _plantName);

	void pourOnFlower(std::string const & _plantName);

	void pourAllPlants();

	void passDays(int _days);

	int flowersCount();
private:
	
	Date m_currentData;

	HousePlant * findPlant(std::string const & _plantName);
	
	std::map<std::string, std::unique_ptr<HousePlant> > m_plants;

};

#endif
