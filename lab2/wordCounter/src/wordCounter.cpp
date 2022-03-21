#include "wordCounter.h"
#include "istream"
#include "ostream"

Statistic GetWordCountStatistic(std::istream& input, bool isCaseSensitive)
{
	Statistic statistic;
	std::string word;
	while (input >> word)
	{
		if (!isCaseSensitive)
		{
			std::transform(word.begin(), word.end(), word.begin(),
				[](unsigned char ch) -> unsigned char { return std::tolower(ch); });
		}
		if (statistic.find(word) != statistic.end())
		{
			statistic[word]++;
			continue;
		}
		statistic.insert(std::pair<std::string, int>(word, 1));
	}
	return statistic;
}

void PrintStatistic(std::ostream& output, const Statistic& statistic)
{
	std::for_each(statistic.begin(), statistic.end(), [&output](const std::pair<std::string, int>& item) {
		output << item.first << " -> " << item.second << std::endl;
	});
}