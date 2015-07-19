
#include"student_info.h"

using std::istream;
using std::vector;

//compare function to be used for sorting students in dictionary order
bool compare(const student_info& x, const student_info& y)
{
	return x.name < y.name;
}

//two overloaded function to read data from the user
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
