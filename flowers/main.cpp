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
	FloweringHouseplant kikus("Kikus", 10, 1, 23, 2);
	kikus.dayPassed();
	std::cout << kikus.getPlantAge() << std::endl;
	std::cout << kikus.getPassedDays() << std::endl;

	kikus.setFirstWatering(data);
    return 0;
}

