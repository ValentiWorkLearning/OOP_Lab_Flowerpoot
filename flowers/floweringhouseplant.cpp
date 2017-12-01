#include "floweringhouseplant.hpp"

FloweringHouseplant::FloweringHouseplant(
	std::string const& _name,
	int _plantAge, 
	int _irregationPeriod,  
	int _needdedSuccesfulWaterings, 
	int _floweringTime )
	:
	HousePlant(_name, _irregationPeriod ,_plantAge),
	m_needdedSuccesfulFlowerings(_needdedSuccesfulWaterings),
	m_floweringTime(_floweringTime)
{
	if (_needdedSuccesfulWaterings <= 0)
		throw std::logic_error(Messages::IncorrectValueSuccesfulWaterings);
	
	if (_floweringTime <= 0)
		throw std::logic_error(Messages::IncorrectFloweringTime);
		
	m_currentWaterings = 0;
	m_flowerStatus = FlowerState::Growing;
	m_daysInFloweringSchedule = 0;
}

//Getters methods 
int FloweringHouseplant::getWateringPeriod()
{
	return HousePlant::getPlantWateringPeriod() ;
}

int FloweringHouseplant::getFloweringTime()
{
	return m_floweringTime;
}

int FloweringHouseplant::getCurrentWaterings()
{
	return m_currentWaterings;
}

FloweringHouseplant::FlowerState FloweringHouseplant::getFlowerStatus()
{
	return m_flowerStatus;
}

int FloweringHouseplant::getNeededSuccesfulWaterings()
{
	return m_needdedSuccesfulFlowerings;
}

int FloweringHouseplant::getPassedDays()
{
	return HousePlant::getPassedDays();
}

void FloweringHouseplant::dayPassed()
{
	if (getFlowerStatus() == FlowerState::Flowering) 
	{
		m_daysInFloweringSchedule++;

		if (m_daysInFloweringSchedule == m_floweringTime) 
		{
			m_flowerStatus = FlowerState::EndFlowering;
			incrementWateringPeriod(2);
		}
	}
	HousePlant::dayPassed();
}

void FloweringHouseplant::makeFirstWatering(const Date& _date)
{
	HousePlant::makeFirstWatering(_date);
	m_currentWaterings++;
}

//Reset methods
void FloweringHouseplant::resetWaterings()
{
	m_currentWaterings = 0;
}

void FloweringHouseplant::resetFloweringStatus()
{
	m_flowerStatus = FlowerState::Growing;
}

//Flowering logic

void FloweringHouseplant::makeWatering()
{
	//logic_makeWatering();
	//logic_endOfFlowering();
	//addDay(getPassedDays());
	//resetPassedDays();
	logic_watering();
	if (m_currentWaterings == getNeededSuccesfulWaterings() || m_flowerStatus == FlowerState::Flowering) 
	{
		logic_flowering();
		logic_endOfFlowering();
	}
}


void FloweringHouseplant::logic_makeWatering()
{
	int m_passedTemp = getPassedDays();
	switch (getFlowerStatus())
	{
	case FlowerState::Growing:
	std::cout << "Waterring..." << std::endl;
		if ( ( getPassedDays() % getWateringPeriod() )== 0)
		{
			m_currentWaterings++;
	
			if (m_currentWaterings == getNeededSuccesfulWaterings()) 
			{
				m_flowerStatus = FlowerState::Flowering;
				m_currentWaterings = 0;
			}
			break;
		}
		if( (m_passedTemp % getWateringPeriod() == 1) ||(++m_passedTemp% getWateringPeriod() == 0) )
		{
			return;
		}
		else 
		{
			if (m_currentWaterings)m_currentWaterings--;
		}
		break;
	
	case FlowerState::Flowering:
		if ((m_passedTemp % getWateringPeriod() == 1) || (++m_passedTemp % getWateringPeriod() == 0) || (getPassedDays() % getWateringPeriod()) == 0)
			{
				std::cout << "Great Job.. In Flowering process..." << getPlantName() << std::endl;
				m_daysInFloweringSchedule++;

				if (m_daysInFloweringSchedule == getFloweringTime())
				{
					m_flowerStatus = FlowerState::EndFlowering;
					break;
				}

				return;
			}
			else
			{
				m_daysInFloweringSchedule = 0;
				resetFloweringStatus();
			}
	break;

	default:
		break;
	}
}


void FloweringHouseplant::logic_watering()
{
	int m_passedTemp = getPassedDays();

	if ((getPassedDays() % getWateringPeriod()) == 0)
	{
		m_currentWaterings++;
		return;

	}
	if ((m_passedTemp % getWateringPeriod() == 1) || (++m_passedTemp % getWateringPeriod() == 0))
	{
		return;
	}
	else
	{
		if (m_currentWaterings)m_currentWaterings--;
	}

}

void FloweringHouseplant::logic_endOfFlowering()
{

	if (m_flowerStatus == FlowerState::EndFlowering) 
	{
		std::cout << "Congratulation! Your plant name:" << getPlantName() << " has succesfully completed the flowering" << std::endl;
		incrementWateringPeriod(2);
		m_daysInFloweringSchedule = 0;
		m_flowerStatus = FlowerState::Growing;
	}
}



void FloweringHouseplant::logic_flowering()
{
	int m_passedTemp = getPassedDays();

	switch (getFlowerStatus())
	{

	case FlowerState::Growing:
		{
		m_flowerStatus = FlowerState::Flowering;
		m_currentWaterings = 0;
		break;
		}
	case FlowerState::EndFlowering: 
	{
		m_flowerStatus = FlowerState::Growing;
		break;
	}
	case FlowerState::Flowering: 
	{
		if ((m_passedTemp % getWateringPeriod() == 1) || (++m_passedTemp% getWateringPeriod() == 0) || (m_passedTemp % getWateringPeriod() == 0)) 
		{
			//m_daysInFloweringSchedule++;
			m_neededWateringInFlowering++;
		}
	}
	default:
		break;
	}

}
