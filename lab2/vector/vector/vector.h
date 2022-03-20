#include <algorithm>
#include <iomanip>
#include <istream>
#include <optional>
#include <stdexcept>
#include <vector>


#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

std::optional<std::vector<double>> ParseVector(std::istream& input);

void PrintVector(std::ostream& output, const std::vector<double> &v);

void MultiplyEverythingByTheMinimumElement(std::vector<double> & item);

void SortVectorInAscendingOrder(std::vector<double> &vector);

#endif // VECTOR_VECTOR_H