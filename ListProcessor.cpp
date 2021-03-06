// ListProcessor.cpp
// Finley McIlwaine
// COSC2030 Lab2
// 9/26/2018

#include "pch.h"
#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	// Testing size and sum methods.
	List cows;
	cout << "cows list  :  " << cows <<
		"            size  :  " << cows.getSize() <<
		"  sum  :  " << cows.sum() << endl << endl;

	cows.insertAsFirst(1.23);
	cows.insertAsFirst(2.34);
	cout << "cows list  :  " << cows << 
		"  size  :  " << cows.getSize() <<
		"  sum  :  " << cows.sum() << endl << endl;

	cows.removeFirst();
	cout << "cows list  :  " << cows << 
		"        size  :  " << cows.getSize() <<
		"  sum  :  " << cows.sum() << endl << endl;

	List horses(cows);
	cout << "cows list  :  " << cows << 
		"        size  :  " << cows.getSize() <<
		"  sum  :  " << cows.sum() << endl;
	cout << "horses list:  " << horses << 
		"        size  :  " << horses.getSize() <<
		"  sum  :  " << horses.sum() << endl << endl;

	horses.removeFirst();
	horses.insertAsFirst(5.67);
	cows.insertAsFirst(6.78);
	cout << "cows list  :  " << cows << 
		"  size  :  " << cows.getSize() <<
		"  sum  :  " << cows.sum() << endl;
	cout << "horses list:  " << horses << 
		"        size  :  " << horses.getSize() <<
		"  sum  :  " << horses.sum() << endl << endl;

	List pigs;
	cout << "cows list  :  " << cows << 
		"  size  :  " << cows.getSize() <<
		"  sum  :  " << cows.sum() << endl;
	cout << "horses list:  " << horses << 
		"        size  :  " << horses.getSize() <<
		"  sum  :  " << horses.sum() << endl;
	cout << "pigs list  :  " << pigs << 
		"            size  :  " << pigs.getSize() <<
		"  sum  :  " << pigs.sum() << endl << endl;

	pigs = cows;
	cout << "cows list  :  " << cows << 
		"  size  :  " << cows.getSize() <<
		"  sum  :  " << cows.sum() << endl;
	cout << "horses list:  " << horses << 
		"        size  :  " << horses.getSize() <<
		"  sum  :  " << horses.sum() << endl;
	cout << "pigs list  :  " << pigs << 
		"  size  :  " << pigs.getSize() <<
		"  sum  :  " << pigs.sum() << endl << endl;

	pigs = horses;
	cout << "cows list  :  " << cows << 
		"  size  :  " << cows.getSize() <<
		"  sum  :  " << cows.sum() << endl;
	cout << "horses list:  " << horses << 
		"        size  :  " << horses.getSize() <<
		"  sum  :  " << horses.sum() << endl;
	cout << "pigs list  :  " << pigs << 
		"        size  :  " << pigs.getSize() <<
		"  sum  :  " << pigs.sum() << endl << endl;

	// Testing insert as last method.
	cows.insertAsLast(3.14);
	horses.insertAsLast(-4.25);
	pigs.insertAsLast(0.00);
	
	cout << "cows list  :  " << cows <<
		"  size  :  " << cows.getSize() <<
		"  sum  :  " << cows.sum() << endl;
	cout << "horses list:  " << horses <<
		"       size  :  " << horses.getSize() <<
		"  sum  :  " << horses.sum() << endl;
	cout << "pigs list  :  " << pigs <<
		"           size  :  " << pigs.getSize() <<
		"  sum  :  " << pigs.sum() << endl << endl;

	// Test insert as last in empty list.
	List sheep;
	cout << "sheep list  :  " << sheep <<
		"  size  :  " << sheep.getSize() <<
		"  sum  :  " << sheep.sum() << endl << endl;

	sheep.insertAsLast(100.0);
	cout << "Inserting node as last in sheep list:" << endl << endl;

	cout << "sheep list  :  " << sheep <<
		"  size  :  " << sheep.getSize() <<
		"  sum  :  " << sheep.sum() << endl << endl;

	sheep.insertAsLast(-200.0);
	cout << "Inserting node as last in sheep list:" << endl << endl;

	cout << "sheep list  :  " << sheep <<
		"  size  :  " << sheep.getSize() <<
		"  sum  :  " << sheep.sum() << endl << endl;

	cout << "End of code" << endl;

	return 0;
}