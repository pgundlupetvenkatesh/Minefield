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

TEST(FieldTest, isSafeOutBound1)
{
	bool safe = false;
	Field minefield;
	try {
		minefield.isSafe(-1,5);
	}
	catch (int err) {
		safe = true;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBound2)
{
	bool safe = false;
	Field minefield;
	try {
		minefield.isSafe(1,-5);
	}
	catch (int err) {
		safe = true;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBound3)
{
	bool safe = false;
	Field minefield;
	try {
		minefield.isSafe(11,10);
	}
	catch (int err) {
		safe = true;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeInBound)
{
	Field minefield;
	ASSERT_TRUE(minefield.isSafe(4,5) );
}
