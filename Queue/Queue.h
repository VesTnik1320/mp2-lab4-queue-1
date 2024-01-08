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
	TQueue() {
		pFirst = nullptr;
		pLast = nullptr;
	}

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

		//if (is_full()) {
		//	throw "full queue";
		//}
		//TNode<T>* newElem = new TNode<T>;
		//if (is_empty()) {
		//	pFirst = newElem;
		//	pLast = newElem;
		//}
		//else {
		//	pLast->pNext = newElem;
		//	pLast = newElem;
		//}
		//newElem->val = el;
		//newElem->pNext = nullptr;
	}

	T pop() {
		if (empty()) throw "The queue is empty";
		TNode<T>* tmp = pFirst;
		T el = pFirst->val;
		pFirst = pFirst->pNext;
		if (pFirst == nullptr) {
			pLast = nullptr;
		}
		delete tmp;
		return el;
		//когда 1 элемент?

		//if (is_empty()) {
		//	throw "empty queue";
		//}
		//TNode<T>* p = pFirst;
		//T el = pFirst->val;
		//pFirst = pFirst->pNext;
		//if (pFirst == nullptr) {
		//	pLast = nullptr;
		//}
		//delete p;
		//return el;
	}

	bool empty() { return pFirst == nullptr; }

	bool full() {
		TNode<T>* p = new TNode<T>;
		bool res = (p == nullptr);
		delete p;
		return res;
	}

	T front() {
		if (empty()) throw "The queue is empty";
		return pFirst->val;
	}

	T back() {
		if (empty()) throw "The queue is empty";
		return pLast->val;
	}

	bool operator==(const TQueue& q) {
		TNode<T>* pRight = q.pFirst, * pLeft = pFirst;
		while (pRight != nullptr || pLeft != nullptr) {
			if (pRight->val != pLeft->val) {
				return false;
			}
			pRight = pRight->pNext;
			pLeft = pLeft->pNext;
		}
		if ((pRight == nullptr && pLeft != nullptr) || (pLeft == nullptr && pRight != nullptr)) {
			return false;
		}
		return true;
	}

	bool operator!=(const TQueue& q) {
		return !(*this == q);
	}
};