#pragma once

// #include <iostream>
#include "Entity.hpp"
#include "Hittable.hpp"
#include "Auto.hpp"
#include "setCursorPosition.hpp"


class Queue
{
	protected:
		struct Node
		{
			Hittable n;

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
		void enQ(Hittable e);
		void deQ();
		Hittable getTesta();

		void move();
		void print();
		void checkLimit(int l);
		bool checkCollision(int x, int y);
		//bool checkCollision2(int x, int y);
};