#define _CRT_SECURE_NO_WARNINGS
#pragma once
using namespace std;
#include "apft.h"
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include<time.h>

class apft
{

public:

	double* apfcss(double S0, double S1, double S2, double V0, double V1, double V2,int i);
	double* calculateEoARBD(double leader, double follower, const double* z);
	double* apfmain(double S1,double S2);
	

};

