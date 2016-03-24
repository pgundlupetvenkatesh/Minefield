#ifndef FIELD_H
#define FIELD_H

#include <vector>

/**
 * For keeping track of whether a location has a mine
 * or empty space as well as whether it is shown or hidden
**/
enum FieldType
{
	MINE_SHOWN,	//0
	MINE_HIDDEN,	//1
	EMPTY_SHOWN,	//2
	EMPTY_HIDDEN	//3
};

class Field
{
	public:
		Field();
		bool isSafe(int, int);
		FieldType get(int,int);
		void revealAdjacent(int, int);
		void placeMine(int, int);
		void placeMineShowMine(int, int);
		

	private:
		bool inBounds(int, int);
		static const int FIELD_DIMENSION = 10;
		std::vector< std::vector<FieldType> > _map;	
};

#endif //FIELD_H
