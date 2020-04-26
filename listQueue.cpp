#include "Ostacolo.hpp"
#include "listQueue.hpp"

using namespace std;

Queue::Queue()
{
	dim = 0;
}

void Queue::enQ(Entity e)
{
	if (tail == NULL)
	{
		tail = (qN *) malloc(sizeof(qN));
		tail->next = NULL;
		tail->n = e;
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