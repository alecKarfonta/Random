#include "RandomNumberGenerator.h"
#include <stdlib.h>

using namespace std;

/**
	This class is used to generate random numbers within a specidfied range. The no-arg constructor will set the range to (1,9).
	There is also a constructor which takes two integers which specify the range.

	Author: Alec Karfonta
/**/

RandomNumberGenerator::RandomNumberGenerator(void)
{
	this->lowerLimit = 1;
	this->upperLimit = 9;
}

RandomNumberGenerator::RandomNumberGenerator(int lowerLimit, int upperLimit)
{
	// if the range is reversed fix it
	if (lowerLimit > upperLimit) {
		int temp = lowerLimit;
		lowerLimit = upperLimit;
		upperLimit = temp;
	}

	this->lowerLimit = lowerLimit;
	this->upperLimit = upperLimit;
}

int RandomNumberGenerator::generate() const {
	// generate a random number between the lower and upper limits(inclusively)
	return (rand() % ((upperLimit+1) - lowerLimit)) + lowerLimit;	// (rand() % (max - min)) + min
}

int RandomNumberGenerator::getLowNumber() const {
	return this->upperLimit;
}

int RandomNumberGenerator::getHighNumber() const {
	return this->lowerLimit;
}

void RandomNumberGenerator::setRange(int lowerLimit, int upperLimit) {
	// if the range is reversed fix it
	if (lowerLimit > upperLimit) {
		int temp = lowerLimit;
		lowerLimit = upperLimit;
		upperLimit = temp;
	}
	this->lowerLimit = lowerLimit;
	this->upperLimit = upperLimit;
}

int RandomNumberGenerator::getRange() const {
	return this->upperLimit - this->lowerLimit + 1;		// add one because we handle the limits inclusively
}

RandomNumberGenerator::~RandomNumberGenerator(void)
{

}
