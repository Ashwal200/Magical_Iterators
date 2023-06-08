#include "MagicalContainer.hpp"

using namespace ariel;
#include <iterator>
using namespace std;

namespace ariel
{

// It initializes the iterator by setting its type to 1 (indicating SideCrossIterator),
// storing a reference to the MagicalContainer object, and setting the initial position of the iterator to 0.
// It prepares the iterator to traverse the container from both sides, maintaining two indices _left and _right.
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont) : myIterator(cont) 
{
_type = 1;
    _container = cont;
    _it = 0;
} 

// This is the increment operator of the SideCrossIterator class.
// It advances the iterator to the next element in the side-cross pattern.
// It checks if the iterator has reached the end (size of the container) and throws a runtime_error in that case.
// If the current index _it is even, it means the iterator is currently on the left side, so it increments the _left index.
// If the current index _it is odd, it means the iterator is currently on the right side, so it decrements the _right index.
// Finally, it increments the _it index to move to the next position.
// It returns a reference to the updated iterator.
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++() 
{
    if (_it >= _container.size())
    {
        throw runtime_error("No more elements");
    }
    if (_it%2 == 0)
    {
        _left++;
    }
    else 
    {
        _right--; 
    }
    ++_it;
    return *this;
}

// This function returns an iterator pointing to the beginning of the side-cross pattern in the container.
// It creates a new SideCrossIterator object with the same MagicalContainer reference and sets its iterator position to 0.
// It returns the newly created iterator.
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const
{
    return SideCrossIterator(_container);
}

// This function returns an iterator pointing to the end of the side-cross pattern in the container.
// It creates a new SideCrossIterator object with the same MagicalContainer reference and sets its iterator position to the end (one past the last element).
// It returns the newly created iterator.
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const
{
     SideCrossIterator temp(_container);
    temp._it = size_t(_container.size());
    return temp;
}

// This is the dereference operator of the SideCrossIterator class.
// It allows accessing the value of the current element pointed by the iterator.
int MagicalContainer::SideCrossIterator::operator*() 
{
	if (_it%2 == 0)
	{
	    return _container._elements.at(_left)->value;
	}
	else 
	{
	    return _container._elements.at(_right)->value;
	}
}
}
