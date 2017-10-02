#include <iostream>

using namespace std;

template <typename T>
class stack
{
public:
	stack();
	stack(const stack<T> &copy);
	stack<T>& operator=(const stack<T>& other);
	size_t count() const;
	void print()const;
	void push(T const &);
	T pop();
	void print();
	T printLast();
	~stack();
private:
	T * array_;
	size_t array_size_;
	size_t count_;
};

template <typename T> 
stack<T>::stack() : count_(0), array_size_(0), array_{ nullptr }
{}

template<typename T>
stack<T>::~stack()
{
	count_ = 0;
	array_size_ = 0;
	delete[] array_;
}

template <typename T> 
stack<T>::stack(const stack<T>& copy)
{
	array_size_ = copy.array_size_;
	count_ = copy.count_;
	array_ = new int[array_size_];

	for (int i = 0; i < count_; i++)
		array_[i] = copy.array_[i];
}

template<typename T>
stack<T>& stack<T>::operator=(const stack<T>& copy)
{
	if (&copy != this)
	{
		delete[] array_;
		count_ = copy.count_;
		array_size_ = copy.array_size_;
		array_ = new int[array_size_];
		for (unsigned int i = 0; i < count_; i++)
			array_[i] = copy.array_[i];
	}
	return *this;
}

template<typename T>
void stack<T>::print()
{
	for (int i = 0, i < count_ - 1, i++)
		cout << array_[i] << " ";
}

template<typename T>
T stack<T>::printLast()
{
	return array_[count_ - 1];
}

template<typename T>
size_t stack<T>::count() const
{
	return count_;
}

template <typename T>
void stack<T>::push(T const &value)
{
	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_];
	}
	if (array_size_ == count_)
	{
		array_size_ = array_size_ * 2;
		T *s1 = new T[array_size_];
		for (int i = 0; i < count_; i++)
			s1[i] = array_[i];
		delete[] array_;
		array_ = s1;
	}
	array_[count_] = value;
	count_++;
}

template <typename T>
T stack<T>::pop()
{
	try
	{
		if (count == 0) 
			throw "logic_error" ;
		T x = array_[count - 1];
		count_--;
		return x;
	}
	catch (int i)
	{
		cout << "stack empty";
	}
}

template <typename T>
void stack<T>::print() const
{
	for (int i = 0; i < array_size_; i++)
		cout << array_[i];
}
