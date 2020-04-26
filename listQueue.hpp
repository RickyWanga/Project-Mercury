#include "Ostacolo.hpp"

class Queue
{
	protected:
		struct qNode
		{
			Entity n;
			qNode* next;
			qNode *head, *tail;
			qNode(Entity e)
			{
				n = e;
				next = nullptr;
			}
			qNode(){};
		}typedef Node;

		qNode qN;

	public:
		Queue() = default;

		void enQ(Entity e);
		void deQ();
};