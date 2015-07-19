//this function calculates the median of the doubles

#include<vector>
#include<algorithm>
#include<stdexcept>
#include"median.h"

using std::domain_error;
using std::vector;
using std::sort;

double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_s;
	vec_s size = vec.size();

	if(size == 0)
		throw domain_error("median of an empty vector!");

	sort(vec.begin(), vec.end());

	vec_s mid = size/2;

	return size%2 == 0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
}
