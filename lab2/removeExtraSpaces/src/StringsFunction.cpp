#include <string>

std::string LeftTrim(std::string const& arg)
{
	std::string result = arg;
	result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char ch) { return !std::isspace(ch); }));
	return result;
}

std::string RightTrim(std::string const& arg)
{
	std::string result = arg;
	result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), result.end());
	return result;
}

std::string RemoveSpacesInsideString(std::string const& arg)
{
	std::string result = arg;
	result.erase(std::unique_copy(arg.begin(), arg.end(), result.begin(), [](unsigned char ch1, unsigned char ch2) -> bool {
		return std::isspace(ch1) && std::isspace(ch2);
	}),
		result.end());
	return result;
}

std::string Trim(std::string const& arg)
{
	std::string leftTrimmed = LeftTrim(arg);
	return RightTrim(leftTrimmed);
}

std::string RemoveExtraSpaces(std::string const& arg)
{
	std::string trimmed = Trim(arg);
	return RemoveSpacesInsideString(trimmed);
}
