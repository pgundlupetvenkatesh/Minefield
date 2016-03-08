/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, isSafeOutBoundPlacePasitiveSafeOutOFRange)
{
	bool safe = false;
	Field minefield;
	try {
		minefield.placeMine(9,2);
		minefield.isSafe(11,10);
	}
	catch (...) {
		safe = true;
	}
	ASSERT_TRUE(safe);
}


TEST(FieldTest, isSafeOutBoundPlaceOutOfRangeSafePositive)
{
	bool safe = false;
	Field minefield;
	try {
		minefield.placeMine(10,10);
		minefield.isSafe(2,9);
	}
	catch (...) {
		safe = true;
	}
	ASSERT_TRUE(safe);
}


TEST(FieldTest, isSafeOutBound_X_Y_Negative)
{
	bool safe = false;
	Field minefield;
	try {
		minefield.placeMine(-1,-1);
		minefield.isSafe(-1,-1);
	}
	catch (...) {
		safe = true;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBound_X_Negative)
{
	bool safe = false;
	Field minefield;
	try {
		minefield.placeMine(-1,1);
		minefield.isSafe(-1,1);
	}
	catch (...) {
		safe = true;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBound_Y_Negative)
{
	bool safe = false;
	Field minefield;
	try {
		minefield.placeMine(1,-1);
		minefield.isSafe(1,-1);
	}
	catch (...) {
		safe = true;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBound_X_OutOfRange)
{
	bool safe = false;
	Field minefield;
	try {
		minefield.placeMine(10,9);
		minefield.isSafe(10,9);
	}
	catch (...) {
		safe = true;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBound_Y_OutOfRange)
{
	bool safe = false;
	Field minefield;
	try {
		minefield.placeMine(9,10);
		minefield.isSafe(9,10);
	}
	catch (...) {
		safe = true;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBoundX_YOutOfRange)
{
	bool safe = false;
	Field minefield;
	try {
		minefield.placeMine(10,10);
		minefield.isSafe(10,10);
	}
	catch (...) {
		safe = true;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeInBoundNotSafe)
{
	Field minefield;
	minefield.placeMine(4,5);
	ASSERT_FALSE(minefield.isSafe(4,5) );
}

TEST(FieldTest, isSafeInBoundSafe)
{
	Field minefield;
	minefield.placeMine(4,5);
	ASSERT_TRUE(minefield.isSafe(1,5) );
}

TEST(FieldTest, isSafeInBoundSafe_0_0)
{
	Field minefield;
	minefield.placeMine(0,0);
	ASSERT_FALSE(minefield.isSafe(0,0) );
}

TEST(FieldTest, isSafeInBoundSafePlaceMine_0_isSafePositive)
{
	Field minefield;
	minefield.placeMine(0,0);
	ASSERT_TRUE(minefield.isSafe(0,9) );
}

TEST(FieldTest, isSafeInBoundSafePlaceMinePositiveisSafe_0)
{
	Field minefield;
	minefield.placeMine(0,9);
	ASSERT_TRUE(minefield.isSafe(0,0) );
}



/*TEST(FieldTest, revealAdjacent1)
{
	Field minefield;
	minefield.revealAdjacent(4,5);
	ASSERT_EQ(2, minefield.get(5,5) );
}

TEST(FieldTest, revealAdjacent2)
{
	Field minefield;
//	minefield.placeMine(5,5);
	minefield.revealAdjacent(5,5);
	ASSERT_EQ( 2,minefield.get(5,5) );
}

TEST(FieldTest, revealAdjacent3)
{
	Field minefield;
	minefield.revealAdjacent(5,5);
	ASSERT_EQ( 2,minefield.get(4,5) );
}*/
