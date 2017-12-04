#ifndef GARDENER_H
#define GARDENER_H

#include  "visitor.hpp"
#include "room.hpp"
#include "foliarhouseplant.hpp"

class FoliarHousePlant;
class Room;

class Gardener: public Visitor
{

public:
	Gardener( Room & _room);

	void timeToPlantOut(FoliarHousePlant * _housePlant)override;

private:
	Room * m_room;
};



#endif // !GARDENER_H
