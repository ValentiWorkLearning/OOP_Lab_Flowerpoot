#include "gardener.hpp"

Gardener::Gardener( Room & _room)
{
	m_room = &_room;
}

void Gardener::timeToPlantOut(FoliarHousePlant * _housePlant)
{
	m_room->addPlant(_housePlant);
}
