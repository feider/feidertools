#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#ifndef FEIDERTOOLS_H
#define FEIDERTOOLS_H


/** @file
	*@brief This is the feidertools header file
	*/

/// The feidertools namspace
namespace fdr
{

	/**
		* Replaces every matching character in the input string with the new one
		* @param input_string The input string
		* @param c The old character
		* @param new_c The new character
		*/
	int replace_char(std::string & input_string, char c, char new_c);



	/**
		* Replaces every matching character in the input character array with the new one
		* @param input_string The input character array
		* @param c The old character
		* @param new_c The new character
		*/
	int replace_char(char * input_string, char c, char new_c);


	void split_string(const std::string& str, std::string & left, std::string & right, const std::string & delim);

	void swap_pointers(void * a, void * b);

	std::vector<std::string> tokenise(const std::string & str, const std::string & delim);

	bool str_equals(const std::string & left, const std::string & right);
	bool str_contains(const std::string & container, const std::string & sequence);


	std::string to_string(const std::vector<std::string> & input_vector);
	std::string to_string(const std::vector<std::string> & input_vector, const std::string & delim);





	/*
	 * Objects that can be stored in the sorted vector
	 * should be derived from this class
	 * the sort_val must be set for the sorted vector
	 * to sort by
	 */

	class Storeable
	{
	private:
		unsigned int * sort_val;
	public:
		void sort_by(unsigned int * sort_by);
		unsigned int get_sort_val();
	};

	/* This data structure stores a sorted vector
	 * new elements are automatically inserted
	 * sorted by storeable->get_sort_val()
	 * The user can determine from where the new element is inserted
	 * depending on the application it could be useful
	 * to search from the beginning, the end or the middle
	 */

	class Sorted_Vector
	{
	protected:
		std::vector<Storeable*> intern_vector;
		std::vector<Storeable*>::iterator middle_element; //this points to the middle element of the vector. It must be moved by the insert functions according to the bool move
		bool move; // if true, middle_element is about to be moved right. If false, middle_element is about to be moved left
	public:
		std::vector<Storeable*> & vector();

		void insert_from_back(Storeable * storeable);
		void insert_from_front(Storeable * storeable);
		void insert_from_middle(Storeable * storeable);
		void insert(Storeable * storeable, std::vector<Storeable*>::iterator position);

	};

}

#endif