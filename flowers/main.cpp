#include<iostream>
#include "floweringhouseplant.hpp"
#include "room.hpp"





int main()
{

	Date data;
	//Create 0 years kikus with watering period 2, 3 succesful waterings for start Flowering  and 6 flowering time
	FloweringHouseplant kikus("Kikus", 0, 4, 2, 7);
	std::cout << kikus.getPlantAge() << std::endl;
	
	std::cout << "New plant: " << kikus.getPlantName() << " with age: " << kikus.getPlantAge() << " ,flowering time: "
		<< kikus.getFloweringTime() << " and " << kikus.getNeededSuccesfulWaterings() << " succesful waterings" << std::endl;

	kikus.makeFirstWatering(data); 

	for (int i = 0; i < 8; i++) 
	{
		for (int j = 0; j < 4; j++) 
		{
			kikus.dayPassed();
		}
		kikus.makeWatering();
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			kikus.dayPassed();
		}
		kikus.makeWatering();
	}

    return 0;
}

