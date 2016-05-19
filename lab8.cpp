//
//CMPS 335
//Exam framework.
//Name this program lab8.cpp.
//Write code to perform a unit-test on a function.
//Function name: bodyShapeIndex().
//
//SBSI is can be a measure of health for some people.
//
//Range of data is from the following source...
//http://journals.plos.org/plosone/article?id=10.1371/journal.pone.0144639
//
//The SBSI formula has four input values.
//
//	                                      Average     SD
//	                                      ---------   --------
//	. body surface area (cm^2)            18074.000   2168.000
//	. vertical trunk circumference (cm)     174.924     11.908
//	. height (cm)                           167.726     10.102
//	. waist circumference (cm)               92.190     13.229
//
//The formula is:
//
//   (height^(7/4)) * (waistCircumference^(5/6))
//   --------------------------------------------
//   bodySurfaceArea * verticalTrunkCircumference
//
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cmath>
using namespace std;

//Define floating-point standard
typedef double Flt;

//Structure to hold components of the SBSI furmula.
//h    height;
//wc   waist circumference;
//bsa  body surface area;
//vtc  vertical trunk circumference;
struct SBSI {
	Flt h;
	Flt wc;
	Flt bsa;
	Flt vtc;
};

Flt bodyShapeIndex(SBSI *sbsi);

int main(int argc, char *argv[])
{
	SBSI sbsi;
	//
	cout << "cs335 Surface-based body shape index calculator.\n";
	cout << endl;
	cout << "Input your 4 values now.\n";
	cout << " . height\n";
	cout << " . waist circumference\n";
	cout << " . body surface area\n";
	cout << " . vertical trunk circumference\n";
	cin >> sbsi.h >> sbsi.wc >> sbsi.bsa >> sbsi.vtc;
	//
	Flt val = bodyShapeIndex(&sbsi);
	cout << "Thanks.\n";
	cout << "Your SBSI index is: " << val << endl;
	cout << endl;
	return 0;
}

//------------------------------------------
//Do not modify this function on the exam.
//------------------------------------------
Flt bodyShapeIndex(SBSI *sbsi)
{
	// Calculate SBSI --- Surface-based Body Shape Index
	//    (height^(7/4)) * (waistCircumference^(5/6))
	//    --------------------------------------------
	//    bodySurfaceArea * verticalTrunkCircumference
	//
	Flt ret = 0.0;
	Flt p1 = 7.0 / 4.0;
	Flt p2 = 5.0 / 6.0;
	Flt n1 = pow(sbsi->h, p1);
	Flt n2 = pow(sbsi->wc, p2);
	Flt d1 = sbsi->bsa;
	Flt d2 = sbsi->vtc;
	Flt r1 = (n1 * n2);
	Flt r2 = (d1 * d2);
	if (r2 != 0.0)
		ret = (r1 / r2);
	return ret;
}

