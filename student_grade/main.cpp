/* A console program that calculates grades of multiple students in a class based on
 * marks in threes components namely
 * 1. Markes in multiple homeworks per student and has a weightage 40% to the total grade
 * 		(median of the homework grades is taken into account
 * 2. Markes in midterm and has a weightage of 20%
 * 3. Markes in final and has a weightahe of 40%
 */

#include<iostream>
#include"student_info.h"
#include"grade.h"
#include"fail.h"
#include<string>
#include<list>
#include<algorithm>
#include<stdexcept>
#include<iomanip>
#include<ios>

using std::cin;
using std::cout;
using std::list;
using std::string;
using std::max;
using std::sort;
using std::endl;
using std::setprecision;
using std::streamsize;
using std::domain_error;
using std::istream;

int main()
{
	list<student_info> students;
	student_info record;
	string::size_type maxlen = 0;

	while(record.read(cin))
	{
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	//students.sort(compare);

	for(list<student_info>::iterator iter = students.begin(); iter != students.end(); ++iter)
	{
		try
		{
			iter->grade();
		}
		catch(domain_error e)
		{
			cout << e.what();
		}
		cout << endl;
	}
	list<student_info> fail = extract_fail(students);
	streamsize prec = cout.precision();

	cout << "Grades of passed students" << endl;
	//showing grades of passed students
	for(list<student_info>::iterator iter = students.begin(); iter != students.end(); ++iter)
	{
		cout << iter->name() << string(maxlen-(iter->name()).size()+1, ' ') << setprecision(3) << iter->final_grade() << endl;
	}

	//showing results of failing students
	cout << "Grades of failed students" << endl;
	for(list<student_info>::iterator iter = fail.begin(); iter != fail.end(); ++iter)
	{
		cout << iter->name() << string(maxlen-(iter->name()).size()+1, ' ') << iter->final_grade() << endl;
	}
	cout << setprecision(prec);

	return 0;
}



