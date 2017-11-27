#include "floweringhouseplant.h"

FloweringHouseplant::FloweringHouseplant(std::string const& _name,int _plantAge, int _irregationPeriod,  int _needdedSuccesfulFlowerings, int _floweringTime )
	:
	HousePlant(_name, _irregationPeriod ,_plantAge)
{
	if (_needdedSuccesfulFlowerings <= 0)
		throw std::logic_error(Messages::IncorrectValueSuccesfulFlowerings);
	
	if (_floweringTime <= 0)
		throw std::logic_error(Messages::IncorrectFloweringTime);

	m_floweringTime = _floweringTime;
	m_needdedSuccesfulFlowerings = _needdedSuccesfulFlowerings;
	m_currentSuccesfulFlowerings = 0;

}

void FloweringHouseplant::makeIrrigation()
{
	
	std::cout << "Waterring..." << std::endl;
}
