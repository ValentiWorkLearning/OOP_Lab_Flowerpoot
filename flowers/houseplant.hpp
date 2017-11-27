#ifndef HOUSEPLANT_H
#define HOUSEPLANT_H

#include <string>
#include "date.hpp"
#include "messages.hpp"
class HousePlant 
{

public:

	
	const std::string  & getPlantName();

	int getPlantAge() const ;

	int getPlantIrrigationPeriod() const;

	virtual void makeIrrigation() {};
	
	virtual ~HousePlant() = default;

private:

	std::string m_plantName;
	int m_plantAge;
	int m_irrigationPeriod;

	Date m_dateOfLastIrrigation;
	
	virtual void newDayIsComing() {};

protected: 

	HousePlant(const  std::string  & _plantName, int _irrigationPeriod , int _plantAge );
};

inline const std::string & HousePlant::getPlantName()
{
	return m_plantName;
}

inline int  HousePlant::getPlantAge()const 
{
	return m_plantAge;
}

inline int HousePlant::getPlantIrrigationPeriod () const
{
	return m_irrigationPeriod;
}
#endif
