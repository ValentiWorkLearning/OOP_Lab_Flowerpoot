#ifndef FRUITING_HOUSEPLANT_H
#define FRUITING_HOUSEPLANT_H

#include"messages.hpp"
#include "houseplant.hpp"
#include "floweringhouseplant.hpp"

#include <string>

class FruitingHousePlant :public FloweringHouseplant 
{
public:
	FruitingHousePlant
	(
		const std::string & _namePlant,
		const std::string  & _fruitName,
		int _plantAge,
		int _wateringPeriod,
		int _needdedSuccesfulWaterings,
		int _floweringTime,
		int _fruitingTime
	);

	void makeWatering();

	const std::string & getFruitName()const;
	
	int getFruitingTime();
	
	FlowerState getFruitingState();

	void dayPassed()override;
private:

	std::string m_fruitName;

	const int m_fruitingTime;
	
	int m_daysInFruiting;

	bool m_isCorrectWateringInFruiting;
	
	bool logic_isEndOfFruiting();

	void logic_resetFruiting();
};

#endif
