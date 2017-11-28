#ifndef HOUSEPLANT_H
#define HOUSEPLANT_H

#include <string>
#include "date.hpp"
#include "messages.hpp"

class HousePlant 
{

public:
	
	HousePlant(const HousePlant &) = delete;
	HousePlant & operator = (const HousePlant &) = delete;
	virtual ~HousePlant() = default;

	const std::string  & getPlantName(); //Get plant name

	int getPlantAge() const ; //Get plant age

	int getPlantWateringAmount() const; //Get plant watering period

	const Date & getDateOfLastWatering() const; //Get last date of watering

	void setFirstWatering(const Date &_date); // Set date of fist watering plant

	virtual void makeWatering() {}; // Virtual method - make irigation of plant
	
	virtual void makeFirstWatering(const Date&) {}; //Virtual mehod - make first watering in non-init plant

	virtual void dayPassed() {}; // Update plant 

	virtual int getPassedDays() { return 0;  }; // Return a num, of passed days

private:

	std::string m_plantName;
	
	int m_plantAge;

	int m_wateringPeriod;//Period of watering plant

	Date m_dateOfLastWatering;  //Date of last watering
	
	bool m_firstWatering; // Is first watering?

protected: 

	HousePlant
	(
		const  std::string  & _plantName, 
		int _wateringPeriod , 
		int _plantAge 
	);

	void incrementWateringPeriod();
	void addDay(int _nDays);
};



#endif