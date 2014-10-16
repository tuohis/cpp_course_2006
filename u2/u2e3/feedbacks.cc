#include "feedbacks.hh"
#include "student.hh"
#include <algorithm>
#include <stdexcept>

namespace student {
	class addPoints
	{
	public:
		addPoints(std::vector<int> const &fbList) : fbList_(fbList), i(-1) {}
		
		Student operator()(const student::Student &s) {
			Student s_out;
			
			i++;
			
			if (!isValid(s))
				throw std::logic_error("Lisäysvirhe");
			else {
				s_out.id = s.id;
				s_out.points = s.points + fbList_[i];
				s_out.grade = (int)(s_out.points / 6);
				if (!isValid(s_out))
					throw std::runtime_error("Lisäysvirhe");
			}
			
			return s_out;
		}
		
	private:
		
	const std::vector<int> &fbList_;
	int i;
	};
}



student::StudentList student::addFeedbackPoints(student::StudentList const &list,
                                std::vector<int> const &feedbackList)
{
	student::StudentList retlist;
	student::addPoints f(feedbackList);
	
	try {
		
		std::transform(list.begin(), list.end(), std::back_inserter(retlist), f);
	}
	catch(const std::logic_error &e) {
		throw e;
	}
	catch(const std::runtime_error &e) {
		throw e;
	}
	
	return retlist;
	
}
