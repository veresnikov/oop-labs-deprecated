#include <map>
#include <string>

#ifndef WORDCOUNTER_WORDCOUNTER_H
#define WORDCOUNTER_WORDCOUNTER_H
typedef std::map<std::string, int> Statistic;

Statistic GetWordCountStatistic(std::istream& input, bool isCaseSensitive);
void PrintStatistic(std::ostream& output, const Statistic& statistic);
#endif // WORDCOUNTER_WORDCOUNTER_H
