/*
 * poly.h
 * Shane Honanie
 * 1/11/2012
 * 1164606
 * Lab 1
 * 
 * poly.h contains all the declarations of functions and data members needed 
 * to create, modify, and destroy an array which represents a polynomial.
 */

#include <iostream>
using namespace std;

class Poly
{
   //Overloaded << operator
   //Displays polynomial in standard format
   friend ostream& operator<<(ostream &, const Poly&);

   //Overloaded >> operator
   //Takes in two int values to set coeff ad power respectively
   //end input by enetering "0 0"
   friend istream& operator>>(istream&, Poly&);

public:
   //Constructors and Destructor
   Poly();
   Poly(int);
   Poly(int, int);
   Poly(const Poly&);
   ~Poly();

   void setCoeff(int,int); 
   int getCoeff(int); 
   int getSize() const; 
   
   //boolean comparison operators
   bool operator==(const Poly&) const;
   bool operator!=(const Poly&) const;

   //assignment operators
   Poly operator+(const Poly&) const;
   Poly operator-(const Poly&) const;
   Poly operator*(const Poly&) const;

   //assignment operators
   Poly& operator=(const Poly&);
   Poly& operator+=(const Poly&);
   Poly& operator-=(const Poly&);
   Poly& operator*=(const Poly&);

private:
   int* polyPtr; //pointer to array
   int size; //size of array
};
