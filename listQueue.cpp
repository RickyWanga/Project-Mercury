#include "Ostacolo.hpp"
#include "listQueue.hpp"

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

void Queue::enQ(Entity e)
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
	tmp = head;

	while (tmp != NULL)
	{
		tmp->n.moveDown();
		tmp = tmp->next;
	}
}

void Queue::print()
{
	tmp = head;

	while (tmp != NULL)
	{
		tmp->n.stampa();
		tmp = tmp->next;
	}
}

void Queue::checkLimit(int limit)
{
	if (head->n.getY() > limit && getDim() > 0)
	{
		setCursorPosition(head->n.getBufferX(), head->n.getBufferY(),247);
		cout << "-";
		deQ();
	}
}

bool Queue::checkCollision(int x, int y)
{
	tmp = head;

	while (tmp != NULL)
	{
		if (tmp->n.getX() == x && tmp->n.getY() == y)
		{
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}