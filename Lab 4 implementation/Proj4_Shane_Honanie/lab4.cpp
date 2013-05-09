/*-----------------------------------------------------------------------------
 * lab4
 * CSS 343
 * Zander
 *
 * (sample) main
 * Creates a bankmanager object with all of the initial movies in stock
-----------------------------------------------------------------------------*/

#include "businessmanager.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//-----------------------------------------------------------------------------
int main()
{
	ifstream infile1("data4movies.txt");
	ifstream infile2("data4customers.txt");
	ifstream infile3("data4commands.txt");

	if (!infile1 || !infile2 || !infile3)
	{
		cout << "File could not be opened." << endl;
		return 1;
	}

	BusinessManager biz("Many Overzealous Videos Ignite & Entertain");
	biz.stockShelves(infile1);
	biz.createAccounts(infile2);
	biz.readCommands(infile3);
	return 0;
}
