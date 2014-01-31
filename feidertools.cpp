#include "feidertools.hpp"

namespace fdr
{

	void split_string(const std::string& str, std::string & left, std::string & right, const std::string & delim)
	{
		size_t pos = str.find(delim);

		if ( std::string::npos == pos )
		{
			left = str;
			right = "";
			return;
		}


		left = str.substr(0, pos);
		right = str.substr(pos+1);


		//std::cout<<left<<" - "<<pos<<" - "<<right<<std::endl;
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


}