#ifndef FOLIAR_HOUSEPLANT_H
#define  FOLIAR_HOUSEPLANT_H

#include "houseplant.hpp"
#include "messages.hpp"
#include "visitor.hpp"

class FoliarHousePlant : public HousePlant 
{
public:
	FoliarHousePlant(
		const std::string & _namePlant,
		int _wateringPeriod,
		int _plantAge,
		int _mInitialHeight
	);
	
	void dayPassed()override;
	
	int getPlantWateringPeriod() const;

	void makeWatering();

	int getPlantAge() const; 

	int getCurrentHeight();

	void accept(Visitor & _visitor)override
	{
		_visitor.visit(this);
		//m_visitor = &_visitor;
	};
	FoliarHousePlant * cuttedFoliar();
private:


	bool logic_needWateringToday();
	bool logic_isWateringCorrect();
	
	const int maxFlowerHeight = 250;
	
	int m_height;
	bool m_correctWatering;

	Visitor  * m_visitor;
};

#endif // !

