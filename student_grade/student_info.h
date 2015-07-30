#ifndef GUARD_student_info_h
#define GUARD_student_info_h

#include<istream>
#include<vector>
#include<string>

//a data structure to hold all the information of a student
class student_info {
	private:
		std::string n;
		double midterm, final;
		std::vector<double> homework;
		double FinalGrade = final_grade();

	public:
		//constructors
		student_info();
		student_info(std::istream&);
		//other member functions
		std::string name() const {return n;}
		bool valid() const {return !homework.empty();}
		std::istream& read(std::istream&);
		double grade() const;
		double final_grade() const { return FinalGrade;}
};

bool compare(const student_info&, const student_info&);

std::istream& read_hw(std::istream&, std::vector<double>&);

#endif
