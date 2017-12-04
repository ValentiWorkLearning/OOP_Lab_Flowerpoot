#ifndef VISITOR_H
#define VISITOR_H


class FoliarHousePlant;

class Visitor 
{
public:

	virtual ~Visitor() = default;
	
	virtual void timeToPlantOut (FoliarHousePlant * _housePlant) = 0;

};

#endif // !VISITOR_H

