#include <exception>
// Develop a class template Array that contains elements of type T and that implements
// the following behavior and functions:
// •Construction with no parameter: Creates an empty array.
// •Construction with an unsigned int n as a parameter: Creates an array of n elements
// initialized by default.
// Tip: Try to compile int * a = new int(); then display *a.
// •Construction by copy and assignment operator. In both cases, modifying either the
// original array or its copy after copying musn’t affect the other array.
// •You MUST use the operator new[] to allocate memory. Preventive allocation (al-
// locating memory in advance) is forbidden. Your program must never access non-
// allocated memory.
// •Elements can be accessed through the subscript operator: [ ].
// •When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// •A member function size() that returns the number of elements in the array. This
// member function takes no parameter and musn’t modify the current instance.
// As usual, ensure everything works as expected and turn in a main.cpp file that con-
// tains your tests.

template <typename T>
class Array
{
private:
	T *_e
	size_t _size;
public:
	Array(): _size(0), _e(new T[0]) {};
	Array(size_t n): _size(n), _e(new T[n]) {};
	Array(const Array &rhs): _size(rhs._size), _e(new T[rhs._size])
	{
		for (size_t i = 0; i < rhs.size; i++)
			_e[i] = rhs._e[i];
	};
	Array &operator=(const Array &rhs)
	{
		for (size_t i = 0; i < rhs.size; i++)
			_e[i] = rhs._e[i];
		return *this;
	};
	T &operator[](unsigned int index)
	{
		if (index >= _size)
		{
			throw OutOfBoundException();
		}
		else
			return _e[index];
	};
	size_t size(void) const
	{
		return _size;
	};
	class OutOfBoundException: public std::exception
	{
		const char *what() const throw()
		{
			return "Index used is out of bounds";
		}
	};
};
