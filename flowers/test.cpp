// (C) 2013-2016, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

/*****************************************************************************/

#include "floweringhouseplant.hpp"
#include "ArtificialHousePlant.h"
#include "fruitinghouseplant.hpp"
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

}

DECLARE_OOP_TEST(test_create_and_actions_in_artificial_houseplant) 
{
	ArtificialHousePlant artificial("Decor Element");

	ASSERT_THROWS(artificial.getDateOfLastWatering(), Messages::ArtificialError);
	ASSERT_THROWS(artificial.setDateOfLastWatering(Date()), Messages::ArtificialError);
	ASSERT_THROWS(artificial.makeWatering(), Messages::ArtificialError);
	ASSERT_THROWS(artificial.getPlantWateringPeriod(), Messages::ArtificialError);

}

DECLARE_OOP_TEST(test_fruiting_house_plant) 
{
	FruitingHousePlant m_fruit("Lemon tree", "Lemon",0,2,2,2,4);
	assert(m_fruit.getFruitName() == "Lemon");
	assert(m_fruit.getPlantName() == "Lemon tree");
	assert(m_fruit.getFruitingTime() == 4);
}

DECLARE_OOP_TEST(test_fruiting_house_plant_with_empty_fruit_name)
{
	ASSERT_THROWS(FruitingHousePlant("Lemon tree", "", 0, 1, 2, 3, 4),Messages::EmptyFruitName);
}

DECLARE_OOP_TEST(test_fruiting_house_plant_with_invalid_fruiting_period)
{
	ASSERT_THROWS(FruitingHousePlant("Lemon tree", "orange", 0, 1, 2, 3, -4), Messages::IncorrectFruitingPeriod);
}

DECLARE_OOP_TEST(test_fruititng_houseplant_correct_fruiting) 
{
	FruitingHousePlant m_fruit("Lemon tree", "Lemon", 0, 2, 2, 2, 5);

	int prevWateringPeriod = m_fruit.getPlantWateringPeriod();

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 2; j++) 
		{
			m_fruit.dayPassed();
		}
		m_fruit.makeWatering();
	}

	m_fruit.dayPassed();
	m_fruit.dayPassed();
	//In fruiting state now
	assert(m_fruit.getFlowerStatus() == FloweringHouseplant::FlowerState::Fruiting);
	
	m_fruit.makeWatering();
	m_fruit.dayPassed();
	m_fruit.dayPassed();

	m_fruit.makeWatering();
	m_fruit.dayPassed();
	assert(m_fruit.getFlowerStatus() == FloweringHouseplant::FlowerState::Growing);
	assert(m_fruit.getPlantWateringPeriod() == (prevWateringPeriod += 2));
}

/*****************************************************************************/

