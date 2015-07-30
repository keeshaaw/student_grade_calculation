
#include"student_info.h"
#include"grade.h"

using std::istream;
using std::vector;

//compare function to be used for sorting students in dictionary order
bool compare(const student_info& x, const student_info& y)
{
	return x.name() < y.name();
}

//two overloaded function to read data from the user
istream& student_info::read(istream& is)
{
	is >> n >> final >> midterm;
	read_hw(is, homework);

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

//definition of member function grade()
double student_info::grade() const
{
	return ::grade(final, midterm, homework);
}


//constructor definition

student_info::student_info(): midterm(0), final(0), FinalGrade(0) {}

student_info::student_info(istream& is) {read(is); }
