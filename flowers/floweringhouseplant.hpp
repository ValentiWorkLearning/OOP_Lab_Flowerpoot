#ifndef FLOWERINGHOUEPLANT_H
#define FLOWERINGHOUEPLANT_H

#include "houseplant.hpp"
#include "messages.hpp"
#include "visitor.hpp"
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


	enum class FlowerState { Growing, Flowering , Fruiting};

	virtual ~FloweringHouseplant( ) = default;

	void makeWatering( );						// Watering the plant

	int getWateringPeriod( );					// Get period of watering plant 

	int getFloweringTime( ) const ;				// Get flowering time

	int getCurrentWaterings( ) const ;			// Get current waterings 

	FlowerState getFlowerStatus( );				// Get flower status  - 0 not flowering, 1 - flowering, 2 - ebd of flowering

	int getNeededSuccesfulWaterings( );			// Get needed amount of succesful flowerings 

	int getPassedDays( ) override;			    // Return the passed days from father`s class

	void dayPassed( )override ;					// In father class increment the m_passedDays, in child  - actions to chek state flower


protected:
		
	void logic_resetWateringPeriod();			// Reset the all values in watering period

	bool logic_isEndOfFlowering( );			    // Is end of flowering -  doing actions

	bool logic_needWateringToday();

	void logic_independentWatering(bool & _setUpFlag, FlowerState _triggeredState);

	void logic_setFlowerState(FlowerState  _flowerState);
	
	void logic_passedDay();
	
	void logic_resetDaysInFloweringState();
private:


	bool logic_isWateringAtTime();				//Is waterinng AT TIME, not after or before 1 day

	bool logic_isWateringBeforeAfter1Day();

	const int m_floweringTime;					// Flowering time of plant
	
	const int m_needdedSuccesfulWaterings;		// Needed value of succesful waterings

	int m_currentWaterings;						// Current value of succesful waterings 
	
	int m_nDaysInFloweringState;				// Value of days in flowering state

	bool m_isCorrectWateringInFlowering;		// Is correct watering in flowering state?

	FlowerState m_flowerStatus;					// Current flower status	
	
};

#endif