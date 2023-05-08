#include <exception>
#include <iostream>

using std::cerr;
using std::endl;
using std::cout;
using std::size_t;

template <typename T>
class Array
{
private:
	T* _start;
	T* _end;
public:
	Array(): _start(new T[0]), _end(_start) {};
	Array(size_t n): _start(new T[n]), _end(_start + n)  {};
	Array(const Array &rhs): _start(new T[rhs.size()]), _end(_start + rhs.size())
	{
		for (size_t i = 0; i < rhs.size(); i++)
			*(_start + i) = *(rhs._start + i);
	};
	~Array()
	{
		delete [] this->_start;
		this->_end = _start;
	};

	Array &operator=(const Array &rhs)
	{
		if (this != &rhs)
		{
			delete [] this->_start;
			this->_start = new T[rhs.size()];
			this->_end = _start + rhs.size();
			for (size_t i = 0; i < rhs.size(); i++)
				*(_start + i) = *(rhs._start + i);
		}
		return *this;
	};
	T &operator[](unsigned int index)
	{
		if (index >= this->size())
		{
			throw OutOfBoundException();
		}
		else
			return _start[index];
	};
	size_t size(void) const
	{
		return _end - _start;
	};
	class OutOfBoundException: public std::exception
	{
		const char *what() const throw()
		{
			return "Exception: Index is out of bounds";
		}
	};
};
