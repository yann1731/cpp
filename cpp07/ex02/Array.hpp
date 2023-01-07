#include <exception>
#include <iostream>

template <typename T>
class Array
{
private:
	T *_e;
	size_t _size;
public:
	Array(): _e(new T[0]), _size(0) {};
	Array(size_t n): _e(new T[n]), _size(n) {};
	Array(const Array &rhs): _e(new T[rhs._size]), _size(rhs._size)
	{
		for (size_t i = 0; i < rhs._size; i++)
			_e[i] = rhs._e[i];
	};
	~Array()
	{
		delete [] this->_e;
	};
	Array &operator=(const Array &rhs)
	{
		if (this != rhs)
		{
			_size = rhs._size;
			delete [] this->_e;
			this->_e = new T[rhs._size];
			for (size_t i = 0; i < rhs._size; i++)
				_e[i] = rhs._e[i];
		}
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
			return "Exception: Index is out of bounds";
		}
	};
};
