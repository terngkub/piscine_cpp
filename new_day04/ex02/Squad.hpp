#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"
# include "ISpaceMarine.hpp"


typedef struct		s_list
{
	ISpaceMarine	*content;
	s_list 			*next;
} 					t_list;

class Squad : public ISquad
{
	public:
		Squad();
		~Squad();
		Squad(Squad const & src);
		Squad & operator=(Squad const & rhs);

		int getCount() const;
		ISpaceMarine* getUnit(int place) const;
		int push(ISpaceMarine*);
	
	private:
		int _size;
		t_list *_first;
		t_list *_last;

		void _clearList();
};

#endif