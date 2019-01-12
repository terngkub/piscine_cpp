#include "Squad.hpp"
#include <iostream>

Squad::Squad() :
	_size(0),
	_first(NULL),
	_last(NULL)
{
}

Squad::~Squad()
{
	_clearList();
}

Squad::Squad(Squad const & src)
{
	*this = src;
}


Squad & Squad::operator=(Squad const & rhs)
{
	if (this != &rhs)
	{
		if (_size > 0)
			_clearList();
		t_list * cur = rhs._first;
		while (cur)
		{
			push(cur->content);
			cur = cur->next;
		}
	}
	return *this;
}

int Squad::getCount() const
{
	return _size;
}

ISpaceMarine* Squad::getUnit(int place) const
{
	t_list *cur = _first;
	while (place-- > 0 && cur)
		cur = cur->next;
	if (cur)
		return cur->content;
	return NULL;
}

int Squad::push(ISpaceMarine* marine)
{
	if (marine == NULL)
		return _size;

	if (_first == NULL)
	{
		_first = new(t_list);
		_first->content = marine;
		_first->next = NULL;
		_last = _first;
	}
	else
	{
		_last->next = new(t_list);
		_last->next->content = marine;
		_last->next->next = NULL;
		_last = _last->next;
	}
	_size++;
	return _size;
}

void Squad::_clearList()
{
	t_list * cur = _first;
	while (cur)
	{
		_first = cur->next;
		delete cur->content;
		delete cur;
		cur = _first;
	}
	_size = 0;
	_first = NULL;
	_last = NULL;
}