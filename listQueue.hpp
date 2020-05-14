#pragma once
#include "Ostacolo.hpp"
#include "Entity.hpp"
#include "setCursorPosition.hpp"
#include <iostream>

class Queue
{
	protected:
		struct Node
		{
			Entity n;
			//bool notstamp;
			struct Node *next;
		}typedef qN;

		qN* head = NULL;
		qN* tail = NULL;
		qN* tmp = NULL;

		int dim; //dimension of Queue

	public:
		Queue();

		int getDim();
		bool isEmpty();
		void enQ(Entity e);
		void deQ();

		void move();
		void print();
		void checkLimit(int l);
		bool checkCollision(int x, int y);
};