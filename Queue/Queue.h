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
		finish = finish % size;
		pMem[finish] = el;
		count++;
	}

	T pop() {
		if (empty()) throw "The queue is empty";
		T el = pMem[start];
		start++;
		start = start % size;
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

	bool operator==(const TQueue& object)
	{
		if (count != object.count)
		{
			return false;
		}
		else
		{
			TQueue this_tmp = *this;
			TQueue obj_tmp = object;
			while (!this_tmp.empty())
			{
				if (this_tmp.front() != obj_tmp.front())
				{
					return false;
				}
				this_tmp.pop();
				obj_tmp.pop();
			}
		}

		return true;
	}

	bool operator!=(const TQueue& q) {
		return !(*this == q);
	}

	TQueue& operator= (const TQueue& q)
	{
		if (*this == q) return *this;
		delete[] pMem;
		size = q.size;
		count = q.count;
		start = q.start;
		pMem = new T[size];
		std::copy(q.pMem, q.pMem + size, pMem);
		return *this;
	}

	int getMaxSize() { return size; }

	int getSize() { return count; }

	int getHead() { return start; }
};