#include"student_info.h"
//#include<iostream>
//#include<vector>

using std::istream;
using std::vector;



bool compare(const student_info& x, const student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, student_info& s)
{
	is >> s.name >> s.final >> s.midterm;
	read_hw(is,s.homework);

	return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if(in)
	{
		hw.clear();

		double x;
		while(in >> x)
			hw.push_back(x);

		in.clear();
	}
	return in;
}
