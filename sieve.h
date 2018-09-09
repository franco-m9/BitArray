/*
Name: Franco Marcoccia
Course: COP3330 Section 6
Assignment: Homework7
Purpose: This header file allows the Sieve of Eratosthenes function to work in order to find prime numbers.
*/
#ifndef _sieve_H
#define _sieve_H
#include <cmath>
#include "bitarray.h"
void Sieve(BitArray& x)
{
	for (int i = 0; i < x.Length(); i++) // sets all bits to 1
		x.Set(i);

	x.Unset(0); // sets first bit to 0 as it is never prime
	x.Unset(1); // sets second bit to 0 as it is never prime

	for (int i = 2; i < sqrt(x.Length()); i++)  // for loop which runs with the length function
	{
		if (x.Query(i) == true)  // if bit is a 1
		{
			for (int j = 2; (j*i) < x.Length(); j++) 
			x.Unset(j*i); // unsets all the bits which aren't prime according to the Sieve of Eratoshenes
		}
	}
}
#endif

