#include "Coda.hpp"
#include "Ostacolo.hpp"
#include "listQueue.hpp"

using namespace std;

Queue::Queue()
{
	qN.head = qN.tail = nullptr;
}

void Queue::enQ(Entity e)
{
	Node* tmp = new Node(e);

	if (qN.tail == nullptr)
	{
		qN.head = qN.tail = tmp;
		return;
	}

	qN.tail->next = tmp;
	qN.tail = tmp;
}

void Queue::deQ()
{
	if (qN.head == nullptr)
		return;

	Node* tmp = qN.head;
	qN.head = qN.head->next;

	if (qN.head == nullptr)
		qN.tail = nullptr;

	delete(tmp);
}