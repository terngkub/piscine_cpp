#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
public:
	Array() :
		_size(0),
		_arr (new T[0])
	{}

	Array(unsigned int n) :
		_size(n),
		_arr(new T[n])
	{
		for (unsigned int i = 0; i < n; i++)
			_arr[i] = T();
	}

	Array(Array const & src) :
		_size(src._size),
		_arr(new T[_size])
	{
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = src._arr[i];
	}

	Array & operator=(Array const & rhs)
	{
			Array<T> tmp(rhs);
			swap(tmp, *this);
		return (*this);
	}

	void swap(Array & lhs, Array & rhs)
	{
		unsigned int tmp_size = lhs._size;
		lhs._size = rhs._size;
		rhs._size = tmp_size;

		T * tmp = lhs._arr;
		lhs._arr = rhs._arr;
		rhs._arr = tmp;
	}

	~Array()
	{
		delete [] _arr;
	}

	T & operator[](int i)
	{
		if (i < 0 || i > static_cast<int>(_size))
			throw(std::out_of_range("trying to access out of range elements"));
		return _arr[i];
	}


	unsigned int size() const
	{
		return _size;
	}

private:
	unsigned int _size;
	T * _arr;
};

#endif