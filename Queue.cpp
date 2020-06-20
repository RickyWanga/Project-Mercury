#include "Queue.hpp"

using namespace std;

Queue::Queue()
{
	dim = 0;
}

int Queue::getDim()
{
	return dim;
}

bool Queue::isEmpty()
{
	return (dim == 0);
}

void Queue::enQ(Hittable e)
{

	if (tail == NULL)
	{
		tail = (qN *) malloc(sizeof(qN));
		tail->n = e;
		tail->next = NULL;
		head = tail;
	}
	else
	{
		tmp = (qN *) malloc(sizeof(qN));
		tail->next = tmp;
		tmp->n = e;
		tmp->next = NULL;
		tail = tmp;
	}

	dim += 1;
}

void Queue::deQ()
{
	tmp = head;
	if (head == NULL)
	{
		dim = 0;
		return;
	}
	else if (tmp->next != NULL)
	{
		tmp = tmp->next;
		free(head); //we use free because its complementary to malloc
		head = tmp;
	}
	else
	{
		free(head);
		head = NULL;
		tail = NULL;
	}

	dim -= 1;
}

void Queue::move()
{
	if (isEmpty())
		return;

	tmp = head;

	while (tmp != NULL)
	{
		tmp->n.moveDown();
		tmp = tmp->next;
	}
}

Hittable Queue::getTesta()
{
	return head->n;
}

void Queue::print()
{
	if (isEmpty())
		return;

	tmp = head;

	while (tmp != NULL)
	{
		// if (!(tmp->notstamp))
		// {
		// }
		//setCursorPosition(tmp->n.getBufferX(), tmp->n.getBufferY(), 6);
		//cout << " ";
		tmp->n.stampa();
		tmp = tmp->next;
	}
}

void Queue::checkLimit(int limit)
{
	if (isEmpty())
		return;

	if (head->n.getY() >= limit && getDim() > 0)
	{
		setCursorPosition(head->n.getBufferX(), head->n.getBufferY(), 6);
		cout << " ";
		deQ();
	}
}

// bool Queue::checkCollision2(int x, int y)
// {
// 	if (isEmpty())
// 		return NULL;

// 	tmp = head;

// 	if (a.checkBounds(tmp->n.getX(), tmp->n.getY()))
// 	{
// 		return true;
// 	}
// 	return false;
// }

bool Queue::checkCollision(int x, int y)
{
	if(!isEmpty())
	{
		if (getTesta().getX() == x && getTesta().getY() == y)
		{
			return true;
		}
	}
	return false;
}