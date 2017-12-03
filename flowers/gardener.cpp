#include "gardener.hpp"

#include "visitor.hpp"
#include "room.hpp"
#include "houseplant.hpp"
#include "foliarhouseplant.hpp"

Gardener::Gardener(Room & _room): m_room(&_room)
{
}

void Gardener::visit(HousePlant * _houseplant)
{
	m_room->addPlant(_houseplant);
}

void Gardener::visit(FoliarHousePlant * _houseplant)
{
	m_room->addPlant(_houseplant);
}
