#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#ifndef FEIDERTOOLS_H
#define FEIDERTOOLS_H

namespace fdr
{

	void split_string(const std::string& str, std::string & left, std::string & right, const std::string & delim);

	void swap_pointers(void * a, void * b);

	std::vector<std::string> tokenise(const std::string & str, const std::string & delim);

	bool str_equals(const std::string & left, const std::string & right);
	bool str_contains(const std::string & container, const std::string & sequence);


	std::string to_string(const std::vector<std::string> & input_vector);
	std::string to_string(const std::vector<std::string> & input_vector, const std::string & delim);





	/*!
	 * \brief Elements of a Sorted_Vector
	 *
	 * Objects that can be stored in the sorted vector
	 * should be derived from this class
	 * the sort_val must be set for the sorted vector
	 * to sort by
	 */
	class Storeable
	{
	private:
		unsigned int * sort_val;	// A pointer to the Value the object is sorted by
	public:

		/*!
		 * Determine the value the object is sorted by
		 * @param[in] sort_by A pointer to the value the object is sorted by
		 */
		void sort_by(unsigned int * sort_by);

		/*!
		 * Determine the value the object is sorted by
		 * @return The value the Object is sorted by as an unsigned integer
		 */
		unsigned int get_sort_val();
	};

	/*!
	 * \brief Stores Storeables
	 *
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

		void insert_from_back(Storeable * storeable);
		void insert_from_front(Storeable * storeable);
		void insert_from_middle(Storeable * storeable);
		void insert(Storeable * storeable, std::vector<Storeable*>::iterator position);

	};


	/*!
	 * \brief Stores command line parameters
	 *
	 * This class can store command line parameters,
	 * check if certain parameters are there
	 * and return the value of a parameter if given
	 */
	class Parameters
	{
	private:
		std::vector<std::string> parameters;
	public:


		
		Parameters(int argc, char ** argv);
		bool has(const std::string & parameter);
		std::string value(const std::string & parameter);
	};


}

#endif