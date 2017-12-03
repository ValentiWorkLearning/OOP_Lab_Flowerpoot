#ifndef GARDENER_H
#define GARDENER_H

#include  "visitor.hpp"

class FoliarHousePlant;
class HousePlant;
class Room;

class Gardener: public Visitor
{

public:
	Gardener(Room & _room);

	void visit(HousePlant *_houseplant)override;
	void visit(FoliarHousePlant * _houseplant)override;
	void Gardener::visit(Room * _room)override;
private:
	Room * m_room;
};



#endif // !GARDENER_H
