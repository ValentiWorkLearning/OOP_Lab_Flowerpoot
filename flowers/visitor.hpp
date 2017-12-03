#ifndef VISITOR_H
#define VISITOR_H

class HousePlant;
class FoliarHousePlant;

class Room;

class Visitor 
{
public:

	virtual ~Visitor() = default;
	
	virtual void visit(HousePlant * _housePlant) {};
	
	virtual void visit(FoliarHousePlant * _housePlant) {};

	virtual void visit(Room * _room) {};
};

#endif // !VISITOR_H

