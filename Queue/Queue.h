#pragma once

template <class T>
struct TNode {
	T val;
	TNode* pNext = nullptr;
};

template <class T>
class TQueue
{
	TNode<T>* pFirst, * pLast;
public:
	TQueue(const TQueue& q) {
		TNode<T>* tmp = q.pFirst, * i;
		pFirst = pLast = nullptr;
		while (tmp != nullptr) {
			i = new TNode<T>;
			i->val = tmp->val;
			if (pFirst == nullptr) pFirst = pLast = i;
			else {
				pLast->pNext = i;
				pLast = i;
			}
			tmp = tmp->pNext;
		}
	}

	~TQueue() {
		//пройтись по очереди и освободить все €чейки
		TNode<T>* i;
		while (pFirst != pLast) {
			pFirst = pFirst->pNext;
		}
		pFirst = pLast = nullptr;
	}

	void push(const T& el) {
		if (full()) throw "The queue is full";
		TNode<T>* tmp = new TNode<T>;
		tmp->val = el;
		if (empty()) pFirst = pLast = tmp;
		else {
			pLast->pNext = tmp;
			pLast = tmp;
		}
	}

	T pop() {
		if (empty()) throw "The queue is empty";
		TNode<T>* tmp = pFirst;
		T el = pFirst->val;
		pFirst = pFirst->pNext;
		//когда 1 элемент?
	}

	bool empty() { return count == 0; }

	bool full() {
		TNode<T>* p = new TNode<T>;
		bool res = (p == nullptr);
		delete p;
		return res;
	}

	T front() { return pFirst->val }

	T back() { return pLast->val }

	/*bool operator==(const TQueue q) {
		if (size != q.size) return false;
		else if (count != q.count) return false;
		else if (start != q.start) return false;
		else {
			for (int i = 0; i++; i < count) {
				if (pMem[i] != q.pMem) return false;
			}
		}
		return true;
	}*/
};