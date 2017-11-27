#include<iostream>
#include "floweringhouseplant.hpp"
#include "room.hpp"





int main()
{
	

	Room currentRoom;

	currentRoom.addFloweringPlant("Kikus", 10, 1, 23, 2);
	
	std::cout << currentRoom.getFlowerAge("Kikus")<<std::endl;
	
	currentRoom.pourOnFlower("Kikus");
    return 0;
}

