#include "Ostacolo.hpp"
#include <iostream>

class Queue
{
	protected:
		struct Node
		{
			Entity n;
			struct Node *next;
		}typedef qN;

		qN* head = NULL;
		qN* tail = NULL;
		qN* tmp;

		int dim; //dimension of Queue

	public:
		Queue();

		void enQ(Entity e);
		void deQ();
		// int getDim();
		// bool isEmpty();
		// Entity getTesta();
};