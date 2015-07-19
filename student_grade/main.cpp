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

int main()
{
	list<student_info> students;
	struct student_info record;
	string::size_type maxlen = 0;

	while(read(cin, record))
	{
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	//students.sort(compare);

	for(list<student_info>::iterator iter = students.begin(); iter != students.end(); ++iter)
	{
		try
		{
			iter->final_grade = grade(*iter);
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
		cout << iter->name << string(maxlen-(iter->name).size()+1, ' ') << setprecision(3) << iter->final_grade << endl;
	}

	//showing results of failing students
	cout << "Grades of failed students" << endl;
	for(list<student_info>::iterator iter = fail.begin(); iter != fail.end(); ++iter)
	{
		cout << iter->name << string(maxlen-(iter->name).size()+1, ' ') << iter->final_grade << endl;
	}
	cout << setprecision(prec);

	return 0;
}



