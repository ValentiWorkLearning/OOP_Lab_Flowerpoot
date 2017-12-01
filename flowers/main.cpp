#include<iostream>
#include "floweringhouseplant.hpp"
#include "room.hpp"





int main()
{

	Date data;
	//Create 0 years kikus with watering period 2, 3 succesful waterings for start Flowering  and 6 flowering time
	FloweringHouseplant kikus("Kikus", 0, 2, 2, 3);
	std::cout << kikus.getPlantAge() << std::endl;
	
	std::cout << "New plant: " << kikus.getPlantName() << " with age: " << kikus.getPlantAge() << " ,flowering time: "
		<< kikus.getFloweringTime() << " and " << kikus.getNeededSuccesfulWaterings() << " succesful waterings" << std::endl;

	kikus.makeFirstWatering(data); 
	
	kikus.dayPassed();
	kikus.dayPassed();
	
	//Тут он расцвел

	kikus.makeWatering();

	kikus.dayPassed();
	kikus.dayPassed();

	kikus.makeWatering();

	kikus.dayPassed();
	//Тут увеличился период полива после окончания цветения

	//kikus.dayPassed();
	//kikus.dayPassed();
	//kikus.dayPassed();
	//
	//kikus.makeWatering();
	//
	//kikus.dayPassed();
	//kikus.dayPassed();
	//kikus.dayPassed();
	//kikus.dayPassed();
	//
	//kikus.makeWatering();
	//
	//kikus.dayPassed();
	//kikus.dayPassed();
	////Тут упало?
	//kikus.dayPassed();
	//kikus.dayPassed();
	//
	//kikus.makeWatering();

	kikus.dayPassed();
	kikus.dayPassed();
	kikus.dayPassed();
	kikus.dayPassed();
	
	kikus.makeWatering();
    return 0;
}

