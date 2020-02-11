///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Josh Cupp
// Email:            cupp26@bellsouth.net
// Label:            A02
// Title:            Linked List Class
// Course:           CMPS 2143
// Semester:         Spring 2020
//
// Description:
//      This program overloads operaters in a linked list class so that the 
//      class can be traversed similar to an array. 
//
// Usage:
//       N/A
//
// Files:             main.cpp
///////////////////////////////////////////////////////////////////////////////




#include <iostream>
#include <string>

using namespace std;

int A[100];

struct Node
{
	int x;
	Node *next;
	Node()
	{
		x = -1;
		next = NULL;
	}
	Node(int n)
	{
		x = n;
		next = NULL;
	}
};
/**
 * List
 *
 * Description:
 *      This class uses linked list methods and overloads operators to 
 *      perform operations similar to an array. 
 *
 * Public Methods:
 *							List()
 *		void				Push(int val)
 *		void                Insert(int val)
 *		void                PrintTail()
 *		int					Pop()
 *		int					operator[](int index)
 *
 * Private Methods:
 *      
 *		N/A
 *
 * Usage:
 *
 *      List L1;            // Create Instance of List
 *      L1.Push(i);         // adds an integer value to the list
 *      L1.PrintTail();     // prints the last element in the list
 *
 */

class List
{
private:
	Node *Head;
	Node *Tail;
	int Size;

public:

  /**
  *	 Public: Default Constructor
  */
	List()
	{
		Head = Tail = NULL;
		Size = 0;
	}

	/**
	 * Public: Push
	 *
	 * Description:
	 *     Adds an integer to the list
	 *
	 * Params:
	 *     int val  : integer value to be added
	 *
	 * Returns:
	 *     void
	 */
	void Push(int val)
	{
		// allocate new memory and init node
		Node *Temp = new Node(val);

		if (!Head && !Tail)
		{
			Head = Tail = Temp;
		}
		else
		{
			Tail->next = Temp;
			Tail = Temp;
		}
		Size++;
	}

	/**
	* Public: Insert
	*
	* Description:
	*       Inserts an integer to the list
	*
	* Params:
	*       int val : integer value to be added
	*
	* Returns:
	*     void
	*/

	void Insert(int val)
	{
		// allocate new memory and init node
		Node *Temp = new Node(val);

		// figure out where it goes in the list

		Temp->next = Head;
		Head = Temp;
		if (!Tail)
		{
			Tail = Head;
		}
		Size++;
	}

	/**
	 * Public: PrintTail
	 *
	 * Description:
	 *      Prints the value of the tail from the list
	 *
	 * Params:
	 *
	 *     Void
	 *
	 * Returns:
	 *
	 *     void
	 */
	void PrintTail()
	{
		cout << Tail->x << endl;
	}

	/**
	 * Public: Print
	 *
	 * Description:
	 *      Prints the linked list
	 *
	 * Params:
	 *
	 *     Void
	 *
	 * Returns:
	 *
	 *     string :  a linked list as a string
	 */
	string Print()
	{
		Node *Temp = Head;
		string list;

		while (Temp != NULL)
		{
			list += to_string(Temp->x) + "->";
			Temp = Temp->next;
		}

		return list;
	}

	// not implemented 
	int Pop()
	{
		Size--;
		return 0; //
	}

	List operator+(const List &Rhs)
	{
		// Create a new list that will contain both when done
		List NewList;

		// Get a reference to beginning of local list
		Node *Temp = Head;

		// Loop through local list and Push values onto new list
		while (Temp != NULL)
		{
			NewList.Push(Temp->x);
			Temp = Temp->next;
		}

		// Get a reference to head of Rhs
		Temp = Rhs.Head;

		// Same as above, loop and push
		while (Temp != NULL)
		{
			NewList.Push(Temp->x);
			Temp = Temp->next;
		}

		// Return new concatenated version of lists
		return NewList;
	}

	// Implementation of [] operator.  This function returns an
	// int value as if the list were an array.
	int operator[](int index)
	{
		Node *Temp = Head;

		if (index >= Size)
		{
			cout << "Index out of bounds, exiting";
			exit(0);
		}
		else
		{

			for (int i = 0; i < index; i++)
			{
				Temp = Temp->next;
			}
			return Temp->x;
		}
	}

	friend ostream &operator<<(ostream &os, List L)
	{
		os << L.Print();
		return os;
	}
};

int main(int argc, char **argv)
{
	List L1;
	List L2;

	// loading items to list
	for (int i = 0; i < 25; i++)
	{
		L1.Push(i);
	}

	for (int i = 50; i < 100; i++)
	{
		L2.Push(i);
	}

	//cout << L1 << endl;
	L1.PrintTail();
	L2.PrintTail();

	List L3 = L1 + L2;
	cout << L3 << endl;

	cout << L3[5] << endl;
	return 0;
}
