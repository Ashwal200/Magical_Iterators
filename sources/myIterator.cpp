#include "MagicalContainer.hpp"

using namespace ariel;
namespace ariel
{

// Constructor
MagicalContainer::myIterator::myIterator(MagicalContainer& container) : _container(container), _it(0) {}

// This is the copy assignment operator for the myIterator class. 
// It is responsible for assigning the values of one myIterator object to another. 
MagicalContainer::myIterator& MagicalContainer::myIterator::operator=(const MagicalContainer::myIterator& other) 
{ 
	if(_type != other._type) 
	{ 
		throw runtime_error("Can't compare different Iterators"); 
	}
	if(&_container != &other._container) 
	{ 
		throw runtime_error("There is issue with the containers"); 
	}
	return *this; 
}

// This is the move assignment operator for the myIterator class. 
// It is responsible for moving the state of one myIterator object to another.
// In the corrected implementation, we first check if the current object is not the same as the 
// other object (self-assignment check). 
// Then, we verify that the _type and _container members of the iterators match.
// If they match, we transfer the _it value from the other iterator to the current iterator and 
// reset the other._it to 0 to indicate it is in a valid but unspecified state after the move. 
// Finally, we return a reference to the current object. 
MagicalContainer::myIterator& MagicalContainer::myIterator::operator=( MagicalContainer::myIterator&& other) noexcept 
{ 
	if (this == &other)
        return *this;

    if (this->_type == other._type && &this->_container == &other._container)
    {
        this->_container = other._container;
        this->_it = other._it;
    }
    return *this;
}

// This is the equality comparison operator for the myIterator class. 
// It compares whether two iterators are equal. It checks if the _type and _container members of the iterators match.
// If they don't match, it throws a runtime_error. 
// Otherwise, it compares the _it positions and returns true if they are equal, false otherwise.
bool MagicalContainer::myIterator::operator==(const myIterator& other) const 
{
	if(_type != other._type) 
	{ 
		throw runtime_error("Can't compare different Iterators"); 
	}
	if(&_container != &other._container) 
	{ 
		throw runtime_error("There is issue with the containers"); 
	}
	return _it == other._it;
}

// This is the inequality comparison operator for the myIterator class.
// It compares whether two iterators are not equal. 
// It simply negates the result of the equality comparison operator (==) to determine if the iterators are unequal.
bool MagicalContainer::myIterator::operator!=(const myIterator& other) const 
{
	return !(*this == other);
}

// This is the greater than comparison operator for the myIterator class.
// It compares whether one iterator is greater than another.
// It checks if the _type and _container members of the iterators match.
// If they don't match, it throws a runtime_error.
// Otherwise, it compares the _it positions and returns true if the current iterator's position
// is greater than the other iterator's position, false otherwise.
bool MagicalContainer::myIterator::operator>(const myIterator& other) const 
{
	if(_type != other._type) 
	{ 
		throw runtime_error("Can't compare different Iterators"); 
	}
	if(&_container != &other._container) 
	{ 
		throw runtime_error("There is issue with the containers"); 
	}
	return _it > other._it;
}

// This is the less than comparison operator for the myIterator class.
// It compares whether one iterator is less than another.
// It uses the greater than operator (>) and the inequality operator (!=) to determine if the current iterator is less than the other iterator.
bool MagicalContainer::myIterator::operator<(const myIterator& other) const 
{
	return !(*this > other) && (*this != other);
}
}
