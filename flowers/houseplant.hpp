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

	int getPlantWateringPeriod() const; //Get plant watering period

	const Date & getDateOfLastWatering() ; //Get last date of watering

	void setDateOfLastWatering(Date _date);

	virtual void makeWatering() {}; // Virtual method - make watering of plant
	
	virtual void dayPassed() { m_daysPassed++; }; // Update plant 

	virtual int getPassedDays() { return m_daysPassed;  }; // Return a num, of passed days

private:

	std::string m_plantName;
	
	int m_plantAge;

	int m_wateringPeriod;		//Period of watering plant
	int m_daysPassed;			// Num of passed days
	Date m_dateOfLastWatering;  //Date of last watering

protected: 

	HousePlant
	(
		const  std::string  & _plantName, 
		int _wateringPeriod , 
		int _plantAge );

	void incrementWateringPeriod( int _inc);
	void addDay(int _nDays);
};



#endif