#ifndef VISITOR_H
#define VISITOR_H

class FruitingHousePlant;
class FoliarHousePlant;
class FloweringHouseplant;

class FlowersVisitor 
{
public:

	virtual ~FlowersVisitor() = default;
	
	virtual void visit(FruitingHousePlant & _fruit) {};

	virtual void visit(FoliarHousePlant & _foliar) {};
	
	virtual void visit(FloweringHouseplant &  _flowering) {};

};

#endif // !VISITOR_H

