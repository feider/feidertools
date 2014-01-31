#include "feidertools.hpp"

namespace fdr
{

	void split_string(const std::string& str, std::string & left, std::string & right, const std::string & delim)
	{
		unsigned int pos = str.find(delim);

		if ( std::string::npos == pos )
		{
			left = str;
			right = "";
			return;
		}

		left = str.substr(0, pos);
		right = str.substr(pos+1);
	}

	void swap_pointers(void * a, void * b)
	{
		void * temp = b;
		b = a;
		a = temp;
	}

	std::vector<std::string> tokenise(const std::string & str, const std::string & delim)
	{
		std::vector< std::string > return_vector;

		std::string token, rest;

		rest = str;

		do
		{
			split_string(rest, token, rest, delim);
			return_vector.push_back(std::string(token));
		}
		while(rest.compare("") != 0);
		
		return return_vector;
	}
}