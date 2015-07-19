#ifndef GUARD_grade_h
#define GUARD_grade_h

#include"student_info.h"
#include<vector>

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const student_info&);

#endif
