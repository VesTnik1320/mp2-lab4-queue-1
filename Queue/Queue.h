#pragma once

template <class T>
class TQueue
{
	T* pMem;
	int size, start, finish, count;
public:
	TQueue(int _size) {
		size = _size;
		pMem = new T[size];
		count = 0;
		start = 0;
		finish = -1;
	}

	void push(const T& el) {
		if (full()) throw "The queue is full";
		finish++;
		finish %= size; //if (finish == size) finish = 0;
		pMem[finish] = el;
		count++;
	}

	T pop() {
		if (empty()) throw "The queue is empty";
		T el = pMem[start];
		start++;
		start %= size; // if (start == size) start = 0;
		count--;
		return el;
	}

	bool empty() { return count == 0; }

	bool full() { return count == size; }

	T front() {
		if (empty()) throw "The queue is empty";
		return pMem[start];
	}

	T back() {
		if (empty()) throw "The queue is empty";
		return pMem[finish];
	}

	bool operator==(const TQueue& q) {
		if (size != q.size) return false;
		else if (count != q.count) return false;
		else if (start != q.start) return false;
		else {
			for (int i = 0; i++; i < count) {
				if (pMem[i] != q.pMem[i]) return false;
			}
		}
		return true;
	}

	bool operator!=(const TQueue& q) {
		return !(*this == q);
	}

	int getCount() { return count; }
};