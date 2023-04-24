#include <iostream>
using namespace std;

class Counter
{
public:
	Counter()
		: m_counter(0) {};

	Counter(const Counter&) = delete;
	Counter& operator = (const Counter&) = delete;

	~Counter() {};
	void reset()
	{
		m_counter = 0;
	}
	unsigned int get()
	{
		return m_counter;
	}

	// Overload post/pre increment
	void operator++()
	{
		m_counter++;
	}

	void operator++(int)
	{
		m_counter++;
	}

	// Overload post/pre decrement
	void operator--()
	{
		m_counter--;
	}
	void operator--(int)
	{
		m_counter--;
	}

	// Overloading << operator
	friend ostream& operator<<(ostream& os,
		const Counter& counter)
	{
		os << "Counter Value : " << counter.m_counter<< endl;
		return os;
	}

private:
	unsigned int m_counter{};
};

template <typename T>
class Shared
{
public:
	explicit Shared(T* ptr)
	{
		m_ptr = ptr;
		m_counter = new Counter();
		(*m_counter)++;
	}

	Shared(Shared<T>& sp)
	{
		m_ptr = sp.m_ptr;
		m_counter = sp.m_counter;
		(*m_counter)++;
	}

	~Shared()
	{
		(*m_counter)--;
		if (m_counter->get() ==0)
		{
			delete m_counter;
			delete m_ptr;
		}
	}

	// Reference count
	unsigned int use_count()
	{
		return m_counter->get();
	}

	// Get the pointer
	T* get()
	{
		return m_ptr;
	}

	T* operator->()
	{
		return m_ptr;
	}

	T& operator *()
	{
		return *m_ptr;
	}



	friend ostream& operator<<(ostream& os,
		Shared<T>& sp)
	{
		os << "Address pointed : " << sp.get() << endl;
		os << *(sp.m_counter) << endl;
		return os;
	}

private:
	T* m_ptr;
	Counter* m_counter;
};




int main()
{
	// ptr1 pointing to an integer.
	Shared<int> ptr1(new int(151));
	cout << "--- Shared pointers ptr1 ---\n";
	*ptr1 = 100;
	cout << " ptr1's value now: " << *ptr1 << endl;
	cout << ptr1;

	{
		// ptr2 pointing to same integer
		// which ptr1 is pointing to
		// Shared pointer reference counter
		// should have increased now to 2.
		Shared<int> ptr2 = ptr1;
		cout << "--- Shared pointers ptr1, ptr2 ---\n";
		cout << ptr1;
		cout << ptr2;

		{
			// ptr3 pointing to same integer
			// which ptr1 and ptr2 are pointing to.
			// Shared pointer reference counter
			// should have increased now to 3.
			Shared<int> ptr3(ptr2);
			cout << "--- Shared pointers ptr1, ptr2, ptr3 "
				"---\n";
			cout << ptr1;
			cout << ptr2;
			cout << ptr3;
		}
		// ptr3 is out of scope.
		// It would have been destructed.
		// So shared pointer reference counter
		// should have decreased now to 2.
		cout << "--- Shared pointers ptr1, ptr2 ---\n";
		cout << ptr1;
		cout << ptr2;
	}

	// ptr2 is out of scope.
	// It would have been destructed.
	// So shared pointer reference counter
	// should have decreased now to 1.
	cout << "--- Shared pointers ptr1 ---\n";
	cout << ptr1;

	return 0;
}