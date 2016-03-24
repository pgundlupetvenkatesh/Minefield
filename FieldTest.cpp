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
	bool safe = true;
	Field minefield;
	try {
		minefield.placeMine(9,2);
		minefield.isSafe(11,10);
	}
	catch (...) {
		safe = false;
	}
	ASSERT_TRUE(safe);
}


TEST(FieldTest, isSafeOutBoundPlaceOutOfRangeSafePositive)
{
	bool safe = true;
	Field minefield;
	try {
		minefield.placeMine(10,10);
		minefield.isSafe(2,9);
	}
	catch (...) {
		safe = false;
	}
	ASSERT_TRUE(safe);
}


TEST(FieldTest, isSafeOutBound_X_Y_Negative)
{
	bool safe = true;
	Field minefield;
	try {
		minefield.placeMine(-1,-1);
		minefield.isSafe(-1,-1);
	}
	catch (...) {
		safe = false;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBound_X_Negative)
{
	bool safe = true;
	Field minefield;
	try {
		minefield.placeMine(-1,1);
		minefield.isSafe(-1,1);
	}
	catch (...) {
		safe = false;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBound_Y_Negative)
{
	bool safe = true;
	Field minefield;
	try {
		minefield.placeMine(1,-1);
		minefield.isSafe(1,-1);
	}
	catch (...) {
		safe = false;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBound_X_OutOfRange)
{
	bool safe = true;
	Field minefield;
	try {
		minefield.placeMine(10,9);
		minefield.isSafe(10,9);
	}
	catch (...) {
		safe = false;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBound_Y_OutOfRange)
{
	bool safe = true;
	Field minefield;
	try {
		minefield.placeMine(9,10);
		minefield.isSafe(9,10);
	}
	catch (...) {
		safe = false;
	}
	ASSERT_TRUE(safe);
}

TEST(FieldTest, isSafeOutBoundX_YOutOfRange)
{
	bool safe = true;
	Field minefield;
	try {
		minefield.placeMine(10,10);
		minefield.isSafe(10,10);
	}
	catch (...) {
		safe = false;
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

TEST(FieldTest, revealAdjacent_MineHiddenInRangeSame)
{
	Field minefield;
	minefield.placeMine(2,4);
	minefield.revealAdjacent(2,4);
	ASSERT_EQ(MINE_HIDDEN, minefield.get(2,4) );
}

TEST(FieldTest, revealAdjacent_MineHiddenInRange)
{
	Field minefield;
	minefield.placeMine(3,5);
	minefield.revealAdjacent(3,6);
	ASSERT_EQ(MINE_HIDDEN, minefield.get(3,5) );
}

TEST(FieldTest, revealAdjacent_MineShownInRange_same)
{
	Field minefield;
	minefield.placeMineShowMine(5,6);
	minefield.revealAdjacent(5,6);
	ASSERT_EQ(MINE_SHOWN, minefield.get(5,6) );
}

TEST(FieldTest, revealAdjacent_InRange_Positive)
{
	Field minefield;
	minefield.revealAdjacent(4,5);
	ASSERT_EQ(EMPTY_SHOWN, minefield.get(4,6) );
}

TEST(FieldTest, revealAdjacent_InRange_Positive_same)
{
	Field minefield;
	minefield.revealAdjacent(5,5);
	ASSERT_EQ(EMPTY_SHOWN,minefield.get(5,5) );
}

TEST(FieldTest, revealAdjacent_InRange_Same_Positive)
{
	Field minefield;
	minefield.revealAdjacent(5,5);
	ASSERT_EQ(EMPTY_SHOWN,minefield.get(4,5) );
}

TEST(FieldTest, revealAdjacent_OutOfRange)
{
	Field minefield;
	bool reveal = false;
	try {
		minefield.revealAdjacent(10,10);
		minefield.get(10,10);
	}
	catch(...) {
		reveal = true;
	}
	ASSERT_TRUE(reveal);
}

TEST(FieldTest, revealAdjacent_MineShownInRange)
{
	Field minefield;
	bool reveal = false;
	try {
		minefield.placeMineShowMine(3,4);
		minefield.revealAdjacent(3,4);
		minefield.get(3,5);
	}
	catch(...) {
		reveal = true;
	}
	ASSERT_FALSE(reveal);
}

TEST(FieldTest, revealAdjacent_MineHiddenOutOfRange)
{
	Field minefield;
	bool reveal = false;
	try {
		minefield.placeMine(-1,5);
		minefield.revealAdjacent(3,6);
		minefield.get(-3,5);
	}
	catch(...) {
		reveal = true;
	}
		ASSERT_TRUE(reveal);
}

TEST(FieldTest, revealAdjacent_X_OutOfRange)
{
	Field minefield;
	bool reveal = false;
	try {
		minefield.revealAdjacent(10,1);
		minefield.get(10,1);
	}
	catch(...) {
		reveal = true;
	}
	ASSERT_TRUE(reveal);
}

TEST(FieldTest, revealAdjacent_Y_OutOfRange)
{
	Field minefield;
	bool reveal = false;
	try {
		minefield.revealAdjacent(1,11);
		minefield.get(1,11);
	}
	catch(...) {
		reveal = true;
	}
	ASSERT_TRUE(reveal);
}

TEST(FieldTest, revealAdjacent_Negative)
{
	Field minefield;
	bool reveal = false;
	try {
		minefield.revealAdjacent(-1,-2);
		minefield.get(-1,-2);
	}
	catch(...) {
		reveal = true;
	}
	ASSERT_TRUE(reveal);
}

TEST(FieldTest, revealAdjacent_X_Negative)
{
	Field minefield;
	bool reveal = false;
	try {
		minefield.revealAdjacent(-1,1);
		minefield.get(-1,2);
	}
	catch(...) {
		reveal = true;
	}
	ASSERT_TRUE(reveal);
}

TEST(FieldTest, revealAdjacent_Y_Negative)
{
	Field minefield;
	bool reveal = false;
	try {
		minefield.revealAdjacent(1,-2);
		minefield.get(1,-2);
	}
	catch(...) {
		reveal = true;
	}
	ASSERT_TRUE(reveal);
}

TEST(FieldTest, revealAdjacent_X0_Y0)
{
	Field minefield;
	bool reveal = true;
	try {
		minefield.revealAdjacent(0,0);
		minefield.get(0,0);
	}
	catch(...) {
		reveal = false;
	}
	ASSERT_TRUE(reveal);
}

TEST(FieldTest, revealAdjacent_X0_Y0_getInRangePositive)
{
	Field minefield;
	bool reveal = true;
	try {
		minefield.revealAdjacent(0,0);
		minefield.get(1,2);
	}
	catch(...) {
		reveal = false;
	}
	ASSERT_TRUE(reveal);
}
