#ifndef FLOWERINGHOUEPLANT_H
#define FLOWERINGHOUEPLANT_H

#include "houseplant.hpp"
#include "messages.hpp"

class FloweringHouseplant : public HousePlant
{
public:

	FloweringHouseplant(std::string const& _name, int _plantAge, int _irregationPeriod, int _needdedSuccesfulFlowerings, int _floweringTime);

	void makeIrrigation();

private:

	int m_floweringTime;

	int m_currentSuccesfulFlowerings;
	
	int m_needdedSuccesfulFlowerings;

	
};
#endif