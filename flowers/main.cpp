#include<iostream>
#include "floweringhouseplant.hpp"
#include "room.hpp"





int main()
{
	

	//Room currentRoom;
	//
	//currentRoom.addFloweringPlant("Kikus", 10, 1, 23, 2);
	//
	//std::cout << currentRoom.getFlowerAge("Kikus")<<std::endl;
	//
	//currentRoom.pourOnFlower("Kikus");
	Date data;
	//Create 0 years kikus with watering period 2, 3 succesful waterings for start Flowering  and 6 flowering time
	FloweringHouseplant kikus("Kikus", 0, 2, 3, 6);
	std::cout << kikus.getPlantAge() << std::endl;
	
	std::cout << "New plant: " << kikus.getPlantName() << " with age: " << kikus.getPlantAge() << " ,flowering time: "
		<< kikus.getFloweringTime() << " and " << kikus.getNeededSuccesfulWaterings() << " succesful waterings" << std::endl;

	kikus.makeFirstWatering(data); 
	
	kikus.dayPassed();
	kikus.dayPassed();

	kikus.makeWatering();

	kikus.dayPassed();
	kikus.dayPassed();

	kikus.makeWatering();
	
	kikus.dayPassed();
	kikus.dayPassed();

	kikus.makeWatering();

	kikus.dayPassed();
	kikus.dayPassed();

	kikus.makeWatering();

	kikus.dayPassed();
	kikus.dayPassed();

	kikus.makeWatering();
	kikus.dayPassed();
	kikus.dayPassed();

	kikus.makeWatering();
	kikus.dayPassed();
	kikus.dayPassed();

    return 0;
}

