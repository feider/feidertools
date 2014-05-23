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

	/**
		* Splits a string in two other strings at the first delimiter found. Does not include the delimiter in one of the new strings.
		* @param str the string that will be split
		* @param left the string to the left of the delimiter
		* @param right the string to the right of the delimiter
		* @param delim the delimiter
		*/
	void split_string(const std::string& str, std::string & left, std::string & right, const std::string & delim);

	/**
		* Swaps two pointers, regardless of the type
		* @param a the first pointer
		* @param b the second pointer
		*/
	void swap_pointers(void * a, void * b);

	/**
		* Splits a string into a vector of tokens at the delimiters
		* @param str the string that will be split
		* @param delim the delimiter
		* @return a vector of strings
		*/
	std::vector<std::string> tokenise(const std::string & str, const std::string & delim);

	/**
		* Checks if two strings are equal and is completely useless. I could have used "=="...
		* @param left the first string
		* @param right the second string
		* @return left==right
		*/
	bool str_equals(const std::string & left, const std::string & right);
	bool str_contains(const std::string & container, const std::string & sequence);


	std::string to_string(const std::vector<std::string> & input_vector);
	std::string to_string(const std::vector<std::string> & input_vector, const std::string & delim);





	/**
	  * Objects that can be stored in the sorted vector
	  * should be derived from this class.
	  * The sort_val must be set for the sorted vector
	  * to sort by
	  */

	class Storeable
	{
	private:
		unsigned int * sort_val;
	public:
		/**
			* Sets the pointer to the unsigned integer variable the vector should be sorted by.
			* @param sort_val the pointer to the unsigned integer variable the vector should be sorted by
			*/
		void sort_by(unsigned int * sort_val);

		/**
			* Returns the sort value
			* @return the sort value
			*/
		unsigned int get_sort_val();
	};

	/**
		* This data structure stores a sorted vector
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

		/**
			* Insert a storeable by pointer from the back
			* @param storeable the pointer to the storeable object
			*/
		void insert_from_back(Storeable * storeable);

		/**
			* Insert a storeable by pointer from the front
			* @param storeable the pointer to the storeable object
			*/
		void insert_from_front(Storeable * storeable);

		/**
			* Insert a storeable by pointer from the muddle
			* @param storeable the pointer to the storeable object
			*/
		void insert_from_middle(Storeable * storeable);

		/**
			* Insert a storeable by pointer at a certain position.
			* Be careful! This might kill your sorting.
			* @param storeable the pointer to the storeable object
			*/
		void insert(Storeable * storeable, std::vector<Storeable*>::iterator position);

	};

}

#endif