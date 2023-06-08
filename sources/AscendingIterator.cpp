#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;
namespace ariel
{
// This is the constructor for the AscendingIterator class. 
// It initializes the iterator for a given MagicalContainer. 
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont) : myIterator(cont) 
{
_type = 0;
    _container = cont;
    _it = 0;
} 
// It returns the value of the current element pointed to by the iterator. 
int MagicalContainer::AscendingIterator::operator*() {
    return _container._elements.at(_it)->value;
}
 
// If there are no more elements to iterate over 
// (the current index _it is greater than or equal to the size of the container), it throws a runtime_error. 
// Otherwise, it increments the index _it and returns a reference to the updated iterator.
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++() {
    if (_it >= _container.size())
    {
        throw runtime_error("No more elements");
    }
    ++_it;
    return *this;
}

// This function returns an iterator pointing to the first element of the MagicalContainer
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const
{
    return AscendingIterator(_container);
}

// : This function returns an iterator pointing to the past-the-end element of the MagicalContainer
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const
{
    AscendingIterator temp(_container);
    temp._it = size_t(_container.size());
    return temp;
}
}
