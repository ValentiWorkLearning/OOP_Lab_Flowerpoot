#ifndef VISITOR_H
#define VISITOR_H

class HousePlant;
class FoliarHousePlant;

class FlowersVisitor 
{
public:

	virtual ~FlowersVisitor() = default;
	
	virtual void visit(HousePlant * _housePlant) {};
	
	virtual void visit(FoliarHousePlant * _housePlant) {};
};

#endif // !VISITOR_H

