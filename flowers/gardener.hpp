#ifndef GARDENER_H
#define GARDENER_H

#include  "visitor.hpp"

class FoliarHousePlant;
class HousePlant;
class Room;

class Gardener: public FlowersVisitor
{

public:
	Gardener(Room & _room);

	void visit(HousePlant *_houseplant)override;
	void visit(FoliarHousePlant * _houseplant)override;
private:
	Room * m_room;
};



#endif // !GARDENER_H
