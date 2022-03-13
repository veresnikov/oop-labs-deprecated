#include <algorithm>
#include <iomanip>
#include <istream>
#include <optional>
#include <stdexcept>
#include <vector>
#include <iterator>

std::optional<std::vector<double>> ParseVector(std::istream& input)
{
	std::vector<double> result;
	double num;
	while (!input.fail() && !input.eof())
	{
		input >> num;
		result.push_back(num);
	}
	if (result.empty() || input.fail())
	{
		return std::nullopt;
	}
	return result;
}

void PrintVector(std::ostream& output, const std::vector<double> &v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		output << std::fixed << std::setprecision(3) << v[i];
		if (i != v.size() - 1)
		{
			output << " ";
		}
	}
	output << std::endl;
}

void MultiplyEverythingByTheMinimumElement(std::vector<double> &vector) {
	double min = *std::min_element(vector.begin(), vector.end());
	std::transform(vector.begin(), vector.end(), vector.begin(), [min](double i) -> double { return i * min; });
}

void SortVectorInAscendingOrder(std::vector<double> &vector) {
	std::sort(vector.begin(), vector.end());
}