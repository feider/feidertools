#include "feidertools.hpp"
#include <cstring>
namespace fdr
{
	std::string to_string(const std::vector<std::string> & input_vector)
	{
		return to_string(input_vector, "");
	}

	std::string to_string(const std::vector<std::string> & input_vector, const std::string & delim)
	{
		std::vector<std::string> temp_vector = input_vector;
		std::string return_string = "";
		for(std::vector<std::string>::iterator it = temp_vector.begin(); it != temp_vector.end(); it++)
		{
			return_string += *it;
			return_string += delim;
		}
		return return_string;
	}



	void split_string(const std::string& str, std::string & left, std::string & right, const std::string & delim)
	{
		size_t pos = str.find(delim);

		if ( std::string::npos == pos )
		{
			left = str;
			right = "";
			return;
		}

		size_t pos_r = pos + delim.length();
		left = str.substr(0, pos);
		right = str.substr(pos_r);


		//std::cout<<left<<" - "<<pos<<" - "<<right<<std::endl;
	}

	void swap_pointers(void * a, void * b)
	{
		void * temp = b;
		b = a;
		a = temp;


	}

	bool str_equals(const std::string & left, const std::string & right)
	{
		return (0 == left.compare(right));
	}


	bool str_contains(const std::string & container, const std::string & sequence)
	{
		return (std::string::npos != container.find(sequence));
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


	void Storeable::sort_by(unsigned int * sort_by)
	{
		this->sort_val = sort_by;
	}

	unsigned int Storeable::get_sort_val()
	{
		return *(this->sort_val);
	}


	void Sorted_Vector::insert_from_back(Storeable * storeable)
	{
		if(this->intern_vector.size() == 0)
		{
			this->intern_vector.push_back(storeable);
			this->move = false;
			this->middle_element = this->intern_vector.begin();
		}
		else
		{
			this->insert(storeable, this->intern_vector.end());
		}
	}

	void Sorted_Vector::insert_from_front(Storeable * storeable)
	{
		if(this->intern_vector.size() == 0)
		{
			this->intern_vector.push_back(storeable);
			this->move = false;
			this->middle_element = this->intern_vector.begin();
		}
		else
		{
			this->insert(storeable, this->intern_vector.begin());
		}
	}



	void Sorted_Vector::insert_from_middle(Storeable * storeable)
	{
		if(this->intern_vector.size() == 0)
		{
			this->intern_vector.push_back(storeable);
			this->move = false;
			this->middle_element = this->intern_vector.begin();
		}
		else
		{
			this->insert(storeable, this->intern_vector.begin());
		}
	}

	void Sorted_Vector::insert(Storeable * storeable, std::vector<Storeable*>::iterator position)
	{
		// do nothing
	}



	int replace_char(std::string & input_string, char c, char new_c)
	{
		char to_chars[input_string.length()];
		strcpy(to_chars, input_string.c_str());

		int counter = replace_char(to_chars, c, new_c);

		input_string = to_chars;

		return counter;
	}

	int replace_char(char * input_string, char c, char new_c)
	{
		int counter = 0;
		int i = 0;
		char current = input_string[i];
		while(current != '\0')
		{
			if(current == c)
			{
				counter++;
				input_string[i] = new_c;
			}
			i++;
			current = input_string[i];
		}
		return counter;
	}


}