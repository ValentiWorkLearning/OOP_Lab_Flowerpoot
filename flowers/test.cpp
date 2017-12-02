// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "floweringhouseplant.hpp"
#include "messages.hpp"

#include "testslib.hpp"

/*****************************************************************************/



/*****************************************************************************/


DECLARE_OOP_TEST(test_create_flowering_houseplant_correct)
{

	FloweringHouseplant kikus("Kikus", 0, 2, 2, 4);
	assert(kikus.getPlantName() == "Kikus");
	assert(kikus.getPlantAge() == 0);
	assert(kikus.getPlantWateringPeriod() == 2);
	assert(kikus.getNeededSuccesfulWaterings() == 2);
	assert(kikus.getFloweringTime() == 4);
	assert(kikus.getFlowerStatus() == FloweringHouseplant::FlowerState::Growing);
}

DECLARE_OOP_TEST(test_create_flowering_houseplant_with_empty_name)
{
	ASSERT_THROWS(FloweringHouseplant("", 2, 2, 2, 4), Messages::EmptyPlantName);
}

DECLARE_OOP_TEST(test_create_flowering_houseplant_with_invalid_age)
{
	ASSERT_THROWS(FloweringHouseplant("kikus", -1, 2, 2, 4), Messages::IncorrectPlantAge);
}

DECLARE_OOP_TEST(test_create_flowering_houseplant_with_invalid_watering_period)
{
	ASSERT_THROWS(FloweringHouseplant("kikus", 0, -2, 2, 4), Messages::IncorrectIrrigationPeriod);
}

DECLARE_OOP_TEST(test_create_flowering_houseplant_with_invalid_needed_succesful_waterings)
{
	ASSERT_THROWS(FloweringHouseplant("kikus", 0, 2, -1, 4), Messages::IncorrectValueSuccesfulWaterings);
}

DECLARE_OOP_TEST(test_create_flowering_houseplant_with_invalid_flowering_time)
{
	ASSERT_THROWS(FloweringHouseplant("kikus", 0, 2, 1, -4), Messages::IncorrectFloweringTime);
}

DECLARE_OOP_TEST(test_succesful_1_flowering_period)
{
	FloweringHouseplant kikus("Kikus", 0, 2, 2, 2);
	
	int prevWateringPeriod = kikus.getPlantWateringPeriod();
	
	kikus.dayPassed();
	kikus.dayPassed();
	kikus.makeWatering();

	kikus.dayPassed();
	kikus.dayPassed();
	kikus.makeWatering();

	assert(kikus.getCurrentWaterings() == kikus.getNeededSuccesfulWaterings());
	assert(kikus.getFlowerStatus() == FloweringHouseplant::FlowerState::Flowering);

	kikus.dayPassed();
	kikus.dayPassed();
	assert(kikus.getPlantWateringPeriod() == (prevWateringPeriod += 2));
}

DECLARE_OOP_TEST(test_succesful_2_flowering_periods)
{
	FloweringHouseplant kikus("Kikus", 0, 2, 2, 2);

	int prevWateringPeriod = kikus.getPlantWateringPeriod();

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 2; j++) 
		{
			kikus.dayPassed();
		}
		kikus.makeWatering();
	}
	assert(kikus.getPlantWateringPeriod() == (prevWateringPeriod += 2));
		
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			kikus.dayPassed();
		}
		kikus.makeWatering();
	}
	assert(kikus.getPlantWateringPeriod() == (prevWateringPeriod += 2));	
}

DECLARE_OOP_TEST(test_succesful_invariants_test) 
{
	FloweringHouseplant kikus("Kikus", 0, 2, 2, 4);

	int prevWateringPeriod = kikus.getPlantWateringPeriod();

	kikus.dayPassed();
	kikus.dayPassed();
	kikus.makeWatering();

	kikus.dayPassed();
	kikus.dayPassed();
	kikus.makeWatering();

	kikus.dayPassed();
	kikus.dayPassed();
	kikus.dayPassed();
	kikus.dayPassed();

	assert(kikus.getFlowerStatus() == FloweringHouseplant::FlowerState::Growing);

	kikus.makeWatering();
	
	kikus.dayPassed();
	kikus.dayPassed();
	kikus.makeWatering();

	kikus.dayPassed();
	kikus.dayPassed();
	kikus.makeWatering();
	assert(kikus.getFlowerStatus() == FloweringHouseplant::FlowerState::Flowering);
	
	kikus.dayPassed();
	kikus.dayPassed();
	kikus.dayPassed();
	kikus.makeWatering();
	kikus.dayPassed();

	assert(kikus.getPlantWateringPeriod() == (prevWateringPeriod += 2));

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			kikus.dayPassed();
		}
		kikus.makeWatering();
	}
	kikus.dayPassed();
	kikus.dayPassed();
	kikus.makeWatering();
	kikus.dayPassed();
	kikus.dayPassed();
	kikus.makeWatering();

	assert(kikus.getPlantWateringPeriod() == (prevWateringPeriod += 2));
}
/*****************************************************************************/

