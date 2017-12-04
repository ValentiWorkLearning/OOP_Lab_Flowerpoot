#ifndef FOLIAR_HOUSEPLANT_H
#define  FOLIAR_HOUSEPLANT_H

#include "houseplant.hpp"
#include "messages.hpp"
#include "gardener.hpp"

class Gardener;
class FoliarHousePlant : public HousePlant 
{
public:
	FoliarHousePlant(
		const std::string & _namePlant,
		int _wateringPeriod,
		int _plantAge,
		int _mInitialHeight,
		Gardener & _gardener
	);
	
	void dayPassed()override;
	
	int getPlantWateringPeriod() const;

	void makeWatering();

	int getPlantAge() const; 

	int getCurrentHeight();

private:


	bool logic_needWateringToday();
	bool logic_isWateringCorrect();
	
	const int maxFlowerHeight = 250;
	
	int m_height;
	bool m_correctWatering;

	Gardener  & m_gardener;
};

#endif // !

