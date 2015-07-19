#include"student_info.h"
#include"median.h"
#include<vector>
#include<stdexcept>
#include"grade.h"

using std::vector;
using std::domain_error;


double grade(double final, double midterm, double homework)
{
	return 0.4*final + 0.2*midterm + 0.4*homework;
}


double grade(double final, double midterm, const vector<double>& hw)
{
	if(hw.size() == 0)
		throw domain_error("Homework grades can not be empty!");

	return grade(final, midterm, median(hw));
}

double grade(const student_info& s)
{
	return grade(s.final, s.midterm, s.homework);
}
