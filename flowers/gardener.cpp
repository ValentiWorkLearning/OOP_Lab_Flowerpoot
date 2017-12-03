#include "gardener.hpp"

#include "visitor.hpp"
#include "room.hpp"
#include "houseplant.hpp"
#include "foliarhouseplant.hpp"
#include "room.hpp"
Gardener::Gardener(Room & _room): m_room(&_room)
{
}

void Gardener::visit(HousePlant * _houseplant)
{
	
}

void Gardener::visit(FoliarHousePlant * _houseplant)
{
	m_room->addPlant(_houseplant);
}

void Gardener::visit(Room * _room) 
{
	
}
