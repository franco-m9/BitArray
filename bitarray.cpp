/*
Name: Franco Marcoccia
Course: COP3330 Section 6
Assignment: Homework7
Purpose: This cpp file contains all the necessary function definitions of the header file necessary for bit operations to work.
*/
#include <iostream>
#include "bitarray.h"
using namespace std;

ostream & operator<<(ostream & os, const BitArray & a)
{
	os << "(";
	for (int i = 0; i < (a.arraySize*a.size); i++)
	{
		if (a.Query(i) == true)  // if bit is a 1, cout a 1
			os << '1';
		else
			os << '0';
	}
	os << ")";
	
	return os;
}

bool operator==(const BitArray & x, const BitArray & y)
{
	if (x.arraySize == y.arraySize)
	{
		for (int i = 0; i < x.arraySize; i++)
		{
			if (x.barray[i] != y.barray[i]) // checks each bit and compares one by one
				return false;
		}
		return true;
	}
	else
		return false; // if not the same size, already know they aren't equal
}

bool operator!=(const BitArray & x, const BitArray & y)
{
	return !(x == y); // calls opposite of == operator
}

BitArray::BitArray(unsigned int n)
{
	if (n % size == 0) // if user entered n can already be divided by "8" with no remainder
		arraySize = (n / size);
	else
		arraySize = (n-(n%size)+size)/size; // basically adds 1 extra array slot
	
	barray = new unsigned char[arraySize];

	for (int i = 0; i < arraySize; i++)
		barray[i] = 0;
}

BitArray::BitArray(const BitArray & b) // copy constructor
{
	arraySize = b.arraySize;
	barray = new unsigned char[b.arraySize];
	for (int i = 0; i < b.arraySize; i++)
		barray[i] = b.barray[i];
}

BitArray::~BitArray()
{
	delete[] barray;
	barray = 0;
}

BitArray & BitArray::operator=(const BitArray & a)
{
	if (this != &a)
	{
		delete[] barray;
		arraySize = a.arraySize;
		barray = new unsigned char[a.arraySize];
		for (int i = 0; i < a.arraySize; i++)
			barray[i] = a.barray[i];
	}
	return *this;
}

unsigned int BitArray::Length() const
{
	return (arraySize*size); // size of the array * 8
}

void BitArray::Set(unsigned int index) // mostly taken from Bob's examples
{
	int bitloc = (index / size);
	int bitloc2 = (index%size);
	barray[bitloc]=barray[bitloc] | Mask(bitloc2); // inclusive or
}

void BitArray::Unset(unsigned int index)
{
	int bitloc = (index / size);
	int bitloc2 = (index%size); 
	barray[bitloc]=barray[bitloc]&~Mask(bitloc2); // and
}

void BitArray::Flip(unsigned int index)
{
	int bitloc = (index / size);
	int bitloc2 = (index % size);
	barray[bitloc]=barray[bitloc]^Mask(bitloc2); // exclusive or
}

bool BitArray::Query(unsigned int index) const
{
	int bitloc = (index / size);
	int bitloc2 = (index % size);
	if (barray[bitloc] & Mask(bitloc2)) // and , has to be 1
		return true;
	else
		return false;
}

char BitArray::Mask(unsigned int n) const
{
	return (1<<n);
}
