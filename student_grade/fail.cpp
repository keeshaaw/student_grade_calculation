/*this function takes a vector of student_info type and returns
the failed students (grade < 60) and also modify the input vector
to only contain passed students*/

#include"student_info.h"
#include<list>
#include"fail.h"
#include"grade.h"

using std::list;

list<student_info> extract_fail(list<student_info>& students)
{
	list<student_info> fail;
	list<student_info>::iterator iter = students.begin();

	while(iter != students.end())
	{
		if(is_fail(iter->final_grade()))
		{
			fail.push_back(*iter);
			iter = students.erase(iter);
		}

		else
			++iter;
	}
	return fail;
}

bool is_fail(const double& final_grade)
{
	return final_grade < 60;
}
