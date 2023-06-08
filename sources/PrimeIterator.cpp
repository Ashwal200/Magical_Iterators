
#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;
namespace ariel
{

// This is the constructor of the PrimeIterator class.
// It initializes the iterator by setting its type to 2 (indicating PrimeIterator),
// storing a reference to the MagicalContainer object, and setting the initial position of the iterator to the index of the first prime element.
// It also handles special cases when the container is empty or has no prime elements by adjusting the iterator position accordingly.
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont) : myIterator(cont) 
{

    _type = 2;
    _container = cont;
    _it = cont.getFirstPrime();
     if (cont.size() == 0)
    {
    	_it = 0;
    }
    if(cont.getPrimeCounter() == 0)
    {
    	_it = size_t(cont.size());
    }
} 

// This is the dereference operator of the PrimeIterator class.
// It allows accessing the value of the current element pointed by the iterator.
// It first checks if the container is empty and throws a runtime_error if it is.
// If the container is not empty, it returns the value of the current element.
int MagicalContainer::PrimeIterator::operator*() 
    {
        if (_container.size() == 0)
        {
            throw new runtime_error("there is no elements in the container");
        }
        else
        {
            return _container._elements.at(_it)->value;
        }
    }


// This is the increment operator of the PrimeIterator class.
// It advances the iterator to the next prime element.
// It checks if the iterator has reached the end or if there are no prime numbers in the container and throws a runtime_error in those cases.
// If it's the first iteration, it sets the iterator to the index of the first prime element.
// If it's not the first iteration, it advances the iterator to the next prime element using the next pointer stored in the current element.
// It also handles the case when the next prime index is at the end of the container.
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {

    if (_it >= _container.size() )
    {
        throw runtime_error("There is no prime numbers or we get to the limit");
    }
    if (_start)
    {
        _it = _container.getFirstPrime();
        _start = false;
    }
    if(_container._elements.at(_it)->next == INT_MAX)
    {
    	_it = size_t(_container.size());
    }
    else if(!_start)
    {
        _it = _container._elements.at(_it)->next;
    }
    
    return *this;
}

// This function returns an iterator pointing to the beginning of the prime elements in the container.
// It creates a new PrimeIterator object with the same 
// MagicalContainer reference and sets its iterator position to the index of the first prime element.
// It returns the newly created iterator.
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const
{
    PrimeIterator temp (_container);
    temp._it = _container.getFirstPrime();
    return temp;
}

// This function returns an iterator pointing to the end of the prime elements in the container.
// It creates a new PrimeIterator object with the same MagicalContainer reference and sets its iterator position to the end (one past the last element).
// It returns the newly created iterator.
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const
{

    PrimeIterator temp(_container);
    temp._it = size_t(_container.size());
    return temp;
    
}
}
