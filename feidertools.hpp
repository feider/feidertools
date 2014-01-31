#include <iostream>
#include <string>
#include <cstring>
#include <vector>

namespace fdr
{

	void split_string(const std::string& str, std::string & left, std::string & right, const std::string & delim);

	void swap_pointers(void * a, void * b);

	std::vector<std::string> tokenise(const std::string & str, const std::string & delim);

}