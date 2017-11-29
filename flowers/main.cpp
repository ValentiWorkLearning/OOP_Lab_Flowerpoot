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
	//Create 10 years kikus with watering period 2, flowering time 3 and 3 succesful waterings for start Flowering
	FloweringHouseplant kikus("Kikus", 10, 2, 2, 3);
	kikus.dayPassed();
	std::cout << kikus.getPlantAge() << std::endl;
	std::cout << kikus.getPassedDays() << std::endl;

	kikus.setFirstWatering(data); 
	
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

