/*
Name:Franco Marcoccia
Course: COP3330 Section 6
Assignment: Homework7
Purpose: this header file contains the class BitArray, which holds the functions necessary to perform bit alterations and storage.
*/
#ifndef _BITARRAY_H
#define _BITARRAY_H

#include <iostream>
using namespace std;

class BitArray // mostly given by Bob's starter files
{
	friend ostream& operator<< (ostream& os, const BitArray& a);
	friend bool operator== (const BitArray&, const BitArray&);
	friend bool operator!= (const BitArray&, const BitArray&);

public:
	BitArray(unsigned int n);    // Construct an array that can handle n bits
	BitArray(const BitArray&);   // copy constructor
	~BitArray();                 // destructor

	BitArray& operator= (const BitArray& a);  // assignment operator

	unsigned int Length() const;            // return number of bits in bitarray

	void Set(unsigned int index);        // set bit with given index to 1
	void Unset(unsigned int index);        // set bit with given index to 0
	void Flip(unsigned int index);        // change bit (with given index)
	bool Query(unsigned int index) const;  // return true if the given bit
						//  is set to 1, false otherwise
private:
	unsigned char* barray;		   // pointer to the bit array
	int arraySize;
	static const int size = (sizeof(unsigned char))*8;
	char Mask(unsigned int n) const;
};

#endif
