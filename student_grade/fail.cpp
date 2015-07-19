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
		if(grade(*iter) < 60)
		{
			fail.push_back(*iter);
			iter = students.erase(iter);
		}

		else
			++iter;
	}
	return fail;
}
