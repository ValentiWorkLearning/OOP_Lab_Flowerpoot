#ifndef ARTIFICIALHOUSEPLANT_H
#define ARTIFICIALHOUSEPLANT_H
#include "houseplant.hpp"
#include <string>

class ArtificialHousePlant final : public HousePlant 
{
public :
	ArtificialHousePlant(const std::string & _name);

	void dayPassed() override;

	int getPlantWateringPeriod() const { throw std::logic_error(Messages::ArtificialError); }; //Get plant watering period

	const Date & getDateOfLastWatering()   { throw std::logic_error(Messages::ArtificialError); } 

	void setDateOfLastWatering(Date _date) { throw std::logic_error(Messages::ArtificialError); }

	void makeWatering() { throw std::logic_error(Messages::ArtificialError); }

	int getPassedDays() { return HousePlant::getPassedDays(); };


};

ArtificialHousePlant::ArtificialHousePlant(const std::string & _name) : HousePlant(_name, 1,1)
{
}

inline void ArtificialHousePlant::dayPassed() 
{ 
	return; 
}
#endif