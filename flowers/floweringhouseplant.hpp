#ifndef FLOWERINGHOUEPLANT_H
#define FLOWERINGHOUEPLANT_H

#include "houseplant.hpp"
#include "messages.hpp"

class FloweringHouseplant : public HousePlant
{
public:

	FloweringHouseplant
	(
		std::string const& _name, 
		int _plantAge, 
		int _wateringPeriod, 
		int _needdedSuccesfulWaterings, 
		int _floweringTime
	);


	virtual ~FloweringHouseplant() = default;

	void makeWatering(); //Watering the plant

	int getWateringPeriod();//Get period of watering plant 

	int getFloweringTime(); //Get flowering time

	int getCurrentWaterings(); // Get current waterings 

	int getFlowerStatus(); // Get flower status  - 0 not flowering, 1 - flowering, 2 - ebd of flowering



private:

	int m_floweringTime;

	int m_currentWaterings;
	
	int m_needdedSuccesfulFlowerings;

	int m_flowerStatus;
	
};
#endif