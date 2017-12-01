#ifndef ARTIFICIALHOUSEPLANT_H
#define ARTIFICIALHOUSEPLANT_H
#include "houseplant.hpp"
#include <string>

class ArtificialHousePlant final : public HousePlant 
{
public :
	ArtificialHousePlant(const std::string & _name);

	void makeWatering() override;
	void dayPassed() override;
	void  makeFirstWatering(const Date& _date )override;
};

ArtificialHousePlant::ArtificialHousePlant(const std::string & _name) : HousePlant(_name, 0,1)
{
}
inline void ArtificialHousePlant::makeWatering()
{
	std::cout << "Error! You cant watering this plant!";
}

inline void ArtificialHousePlant::dayPassed() 
{ 
	return; 
}

inline void ArtificialHousePlant::makeFirstWatering(const Date& _date )
{
	return;
}
#endif