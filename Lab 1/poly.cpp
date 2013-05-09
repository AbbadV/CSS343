/*
 * poly.cpp
 * Shane Honanie
 * 1/11/2012
 * 1164606
 * Lab 1
 * 
 * poly.cpp contains all the implementations of functions and data members needed 
 * to create, modify, and destroy an array which represents a polynomial.
 */

#include "poly.h"
#include <cstdlib>

//----------------------------------------------------------------------------
// Poly
// default constructor:  No parameters, creates Poly object of size 1 with
// its only value set to 0

Poly::Poly()
   : size(1)
{
   polyPtr = new int[1];
   polyPtr[0] = 0;
}

//----------------------------------------------------------------------------
// Poly
// overloaded constructor:  create an a Poly object with an array of size 1 
// with coeff parameter as its only value

Poly::Poly(int coeff)
   : size(1)
{
   polyPtr = new int[1];
   polyPtr[0] = coeff;
}

//----------------------------------------------------------------------------
// Poly
// overloaded constructor:  Creates a Poly object with its size set to 
// power + 1 and coeff as the array's last indexed value

Poly::Poly(int coeff, int power)
   : size(power+1)
{
   polyPtr = new int[size];

   for(int i = 0;i<size; i++)
   {
      polyPtr[i] = 0;
   }

   polyPtr[power] = coeff;
}

//----------------------------------------------------------------------------
// Poly
// copy constructor:  creates an exact deep copy of the Poly object passed in

Poly::Poly(const Poly &orig)
{
   size = orig.size;
   polyPtr = new int[size]; 

   for (int i = 0; i < size; i++) //Copy array values to new Object
      polyPtr[i] = orig.polyPtr[i];  
}

//----------------------------------------------------------------------------
// ~Poly
// destructor:  delete polyPtr and set to NULL

Poly::~Poly(void)
{
   delete [] polyPtr; 
   polyPtr = NULL;
}

//----------------------------------------------------------------------------
// setCoeff
// power represents array index, that index is set to the coeff value.
// If power is larger than current array, a new one is dynamically allocated
// to fit the new elements.

void Poly::setCoeff(int coeff,int power)
{
	if (power >= 0) //Only perform if value in range
	{
		if ((power+1) > size) //checks to see whether to increase array size
		{
			int *temp = new int[power+1]; //Create new array
			
			for (int i = 0; i < size; i++)
				temp[i] = polyPtr[i]; //Copy old values into temp 

			for (int j = size; j < (power+1); j++)
				temp[j] = 0; //Fill remaining array space with zero's

			temp[power] = coeff; //set coeff value in specified location
			
			delete [] polyPtr; //Delet and NULL to reserve space
			polyPtr = NULL;
			polyPtr = temp; //Copy all values from temp to polyPtr
			temp = NULL; 
			size = power + 1; //set new size
		}
		else //less than or equal
			polyPtr[power] = coeff; //set coeff value in specified location
	}
}

//----------------------------------------------------------------------------
// getCoeff
// Retrieve the value of the specified index, which is represented by power.
// If value out of range then 0 is returned

int Poly::getCoeff(int power)
{
		if ((power >= 0) && (power < size)) //Make sure values in range
			return polyPtr[power];
		else
			return 0;
}

//----------------------------------------------------------------------------
// getSize
// Gets the current size of the array

int Poly::getSize() const
{
   return size;
}

//----------------------------------------------------------------------------
// operator=
// overloaded =: assigns LHS to be RHS

Poly& Poly::operator=(const Poly& rhs)
{
   if (&rhs != this)
   {
      delete [] polyPtr;
      polyPtr= NULL;
      size = rhs.size;
      polyPtr = new int[size];

      for (int i = 0; i < size; i++)
         polyPtr[i] = rhs.polyPtr[i];
   }

   return *this;
}

//----------------------------------------------------------------------------
// operator==
// overloaded ==: true if current object is == parameter, otherwise false

bool Poly::operator==(const Poly& rhs) const 
{
   if (size != rhs.size)
      return false;
   
   for(int i = 0; i < size; i++)
      if(polyPtr[i] != rhs.polyPtr[i])
         return false;
      return true;
}

//----------------------------------------------------------------------------
// operator!=
// overloaded !=: true if current object is != parameter, otherwise false

bool Poly::operator!=(const Poly& rhs) const 
{
   return !(*this == rhs);
}

//----------------------------------------------------------------------------
// operator>>
// overloaded >>: Takes input from console such as "1 3" and sets the first
// value to coeff and second to power. Calls setCoeff to accomplish this.
// input can be on same line or new line and ends with " 0 0".

istream& operator>>(istream &input, Poly &polyObj) 
{
   int coeff;
   int power;

   for(int i = 0; i < polyObj.size; i++) //Erase all old values in array
   {
      polyObj.polyPtr[i] = 0;
   }

   while(input >> coeff >> power) //Take input
   {

      if ((coeff == 0) && (power == 0)) //End input if "0 0"
         break;

      polyObj.setCoeff(coeff,power); //set the new value for each pair of int
   }

   return input;                       
}

//----------------------------------------------------------------------------
// operator<<
// overloaded <<: Outputs the contents of the array which represents a 
// polynomial. If the array is empty then " 0" is output. All output 
// is formatted to look like a regular polynomial expression.

ostream& operator<<(ostream &output, const Poly &polyObj) 
{
   bool allZeroArrayFlag = true; //Flag to indicate empty array

   for(int i = polyObj.size - 1; i >= 0; --i)
   {
      if(polyObj.polyPtr[i] != 0)
      {
         allZeroArrayFlag = false;
         output << " ";

         if (polyObj.polyPtr[i] > 0) //Display "+" if positive coeff
            output << "+";

         if(i == 1) //Chooses correct output for polynomial
            output  << polyObj.polyPtr[i] << "x";
         else if (i == 0)
            output  << polyObj.polyPtr[i];
         else
            output  << polyObj.polyPtr[i] << "x^" << i;
      }
   }

   if (allZeroArrayFlag) //If empty polynomial display " 0"
      output << " 0";
   
   return output;
}

//----------------------------------------------------------------------------
// operator+
// overloaded +: adds the contents of two polynomials together.

Poly Poly::operator+(const Poly& rhs) const 
{
   if (size > rhs.size) //Is size of LHS bigger than RHS?
   {
      Poly polySum(*this); //Make polySum a copy of LHS

      for(int i = 0; i < rhs.size; i++) //Add contents of RHS to LHS
      {
         polySum.polyPtr[i] = (polyPtr[i] + rhs.polyPtr[i]);
      }
      return polySum;
   }
   else //Size of RHS is larger or greater than LHS
   {
      Poly polySum(rhs); //Make polySum a copy of LHS

      for(int i = 0; i < size; i++) //Add contents of RHS to LHS
      {
         polySum.polyPtr[i] = (polyPtr[i] + rhs.polyPtr[i]);
      }
      return polySum;
   }
}

//----------------------------------------------------------------------------
// operator-
// overloaded -: subtract contents of RHS poly from LHS poly

Poly Poly::operator-(const Poly& rhs) const
{
   int maxSize; //Size of largest array
   int smallestSize; //Size of smaller array

   if (size < rhs.size) //Determine the correct size's for calculations
   {
      maxSize = rhs.size;
      smallestSize = size;
   }
   else
   {
      maxSize = size;
      smallestSize = rhs.size;
   }

   Poly polySum(0,maxSize-1); //New Poly object to hold all values 

   for(int i = 0; i < smallestSize; i++) 
   {

      polySum.polyPtr[i] = (polyPtr[i] - rhs.polyPtr[i]);
   }

   while(smallestSize < rhs.size) //Add remaining values left RHS to array
   {
      if (rhs.polyPtr[smallestSize] > 0) //Adjust remaing signs for coeff
         polySum.polyPtr[smallestSize] = 0 - rhs.polyPtr[smallestSize];
      else
         polySum.polyPtr[smallestSize] = rhs.polyPtr[smallestSize];

      smallestSize++;
   }

   while(smallestSize < size) //Add remaining values left LHS to array
   {
      polySum.polyPtr[smallestSize] = polyPtr[smallestSize];
      smallestSize++;
   }

   return polySum;
}

//----------------------------------------------------------------------------
// operator*
// overloaded *: multiplies two Poly objects together

Poly Poly::operator*(const Poly& rhs) const
{
	int arraySize = (getSize() + rhs.getSize() - 2); //Size of new array

	Poly temp(0,arraySize); //New Poly size holds all values

	for(int i = 0;i < size;i++) //Populate temp with calculations
	{
		for(int j = 0; j < rhs.size; j++)
		{
				temp.polyPtr[i+j] += (polyPtr[i] * rhs.polyPtr[j]);
		}
	}
	return temp;
}

//----------------------------------------------------------------------------
// operator+=
// overloaded +=: current object = current object + parameter 

Poly& Poly::operator+=(const Poly& rhs)
{
   *this = *this + rhs;
   return *this;
}

//----------------------------------------------------------------------------
// operator-=
// overloaded -=: current object = current object - parameter 

Poly& Poly::operator-=(const Poly& rhs)
{
   *this = *this - rhs;
   return *this;
}

//----------------------------------------------------------------------------
// operator*=
// overloaded *=: current object = current object * parameter 

Poly& Poly::operator*=(const Poly& rhs)
{
	*this = *this * rhs;
	return *this;
}
