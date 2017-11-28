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

	int getWateringAmount();//Get amount of watering plant 

	int getFloweringTime(); //Get flowering time

	int getCurrentWaterings(); // Get current waterings 

	int getFlowerStatus(); // Get flower status  - 0 not flowering, 1 - flowering, 2 - ebd of flowering

protected:
	void resetWaterings();
	void resetFloweringStatus();



private:

	const int m_floweringTime; //Flowering time of plant

	int m_currentWaterings; // Current value of succesful waterings 
	
	const int m_needdedSuccesfulFlowerings; // Needed value of succesful waterings

	int m_flowerStatus; // Current flower status
	
};
#endif