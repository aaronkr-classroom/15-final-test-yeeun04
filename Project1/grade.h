#pragma once
// grade.h

#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <list>
#include <vector>

using namespace std;

double grade(double, double, double);
double grade(double, double, const vector<double>&); // no const was the error!

#endif