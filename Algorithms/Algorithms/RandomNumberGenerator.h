#pragma once
class RandomNumberGenerator
{
public:
	RandomNumberGenerator();
	RandomNumberGenerator(int lowerLimit, int upperLimit);
	// generate a random number within the classes range variables
	int generate() const;
	// return the upper limit used for number generation
	int getHighNumber() const;
	// return the lower limit used for number generation
	int getLowNumber() const;
	// set the range for number generation
	void setRange(int lowerLimit, int upperLimit);
	// get the range
	int getRange() const;
	~RandomNumberGenerator();

private:
	int upperLimit;
	int lowerLimit;
};

