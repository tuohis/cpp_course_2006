#include "averages.hh"
#include <numeric>
#include <stdexcept>

namespace averages {
	class countAverage
	{
	public:
		countAverage(std::vector<double> &av) : av_(av), a_(0) {}
		
		void operator()(list const &l) {
			if (l.size() <= 0)
				throw std::logic_error("");
			
			
			a_ = std::accumulate(l.begin(), l.end(), a_);
			
			a_ = a_ / l.size();
			
			av_.push_back(a_);
			
			a_ = 0;
			return;
		}
		
	private:
		std::vector<double> &av_;
		double a_;
	};
	
	std::vector<double> getAllAverages(averages::vector const &v);
}


// Palauttaa vektorin, jossa on vastaavien parametrivektorin listojen keskiarvot
std::vector<double> averages::getAllAverages(averages::vector const &v)
{
	std::vector<double> averagev;
	averages::countAverage f(averagev);
	
	if (v.size() <= 0)
		throw std::logic_error("");
	
	
	try {
		for_each(v.begin(), v.end(), f);
	}
	catch(std::logic_error e) {
		throw e;
	}
	
	return averagev;
}

double averages::highestAverage(averages::vector const &v)
{
	std::vector<double> averagev = getAllAverages(v);
	
	return *max_element(averagev.begin(), averagev.end());
}


double averages::lowestAverage(averages::vector const &v)
{
	std::vector<double> averagev = getAllAverages(v);
	
	return *min_element(averagev.begin(), averagev.end());
}

double averages::averageOfAverages(averages::vector const &v)
{
	double a = 0;
	std::vector<double> averagev = getAllAverages(v);
	
	return std::accumulate(averagev.begin(), averagev.end(), a) / averagev.size();
}
