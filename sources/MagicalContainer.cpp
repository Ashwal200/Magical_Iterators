
#include "MagicalContainer.hpp"
using namespace ariel;

namespace ariel
{

// This function iterating over each element pointer in the _elements container using a range-based for loop.
// Inside the loop, it calls the free() function to deallocate the memory pointed to by each element pointer. This suggests that the elements stored in _elements were allocated dynamically using malloc() or a similar function.
MagicalContainer::~MagicalContainer()
{
    for (auto* i : _elements)
    {
        free(i);
    }
}

 // This function adds a new element to the MagicalContainer. 
 // It allocates memory for a new Data object, sets its value and prime status, 
 // and finds the appropriate position to insert the element while maintaining the ascending order of the container. 
 // It then iterates over the elements to determine the prime-related attributes of the new element, such as the next prime index. 
 // Finally, it sets the first prime index and updates the prime counter accordingly.
void MagicalContainer::addElement(int val) 
{
    ptrData newData = (ptrData)malloc(sizeof(Data));
    newData->value = val;
    newData->prime = isPrime(val);
    // https://stackoverflow.com/questions/17711652/lower-bound-of-vector-of-pairs-with-lambda
    // The purpose of lower_bound is to find the position where an element would go.
    auto it = lower_bound(_elements.begin(), _elements.end(), newData,
        [](const ptrData a, const ptrData b) 
        {
            return a->value < b->value;
        }
    );
    // Insert the element in the write place
    _elements.insert(it, newData);
    size_t index = 0;
    // Set the element 
    for (auto i : _elements)
    {
        if (i->value == val && newData->prime && _primeCounter != 0)
        {
            newData->next = setPrime(index , val);
            newData->place = index;
            break;
        }
        if (i->value == val && !newData->prime)
        {
       	    newData->place = index;
            break;
        }
        index++;
    }
    // For the first prime
    if (_flage && newData->prime)
    {
        _firstPrime = index;
        _flage = false;
    }    
}

// This function sets the next prime index for a given element in the MagicalContainer.
// It iterates over the elements and finds the appropriate index where the next prime element occurs.
// If there is no next prime element, it returns INT_MAX.
// This function is used during the addition of new elements to establish the connection between prime elements.
size_t MagicalContainer::setPrime(size_t index , int val)
{
    size_t k = 0;
    for (auto i : _elements)
    {
        if (i->prime && i->value != val && index < k)
        {
            return k;
        }
        if (i->prime && i->next == INT_MAX && i->value != val && index > k)
        {
            i->next = index;
        }
        k++;
    }
    return size_t(INT_MAX); 
}

// This function checks whether a given number is prime. 
// It returns true if the number is prime, false otherwise. 
// It uses a simple algorithm to iterate over potential divisors up to the square root of the number.
bool MagicalContainer::isPrime(int number) {
    if (number <= 1)
    {
        return false;
    }

    int sqr = int(sqrt(number));
    for (int i = 2; i <= sqr; i++) {
        if (number % i == 0)
        {
            return false;
        }
    }
    _primeCounter++;
    return true;
}

// This function removes a specified element from the MagicalContainer. 
// It iterates over the elements and erases the element matching the provided value from the container. 
// If the element is not found, it throws a runtime_error.
void MagicalContainer::removeElement(int element) {
    int flage = 1;
    for (auto r : _elements)
    {
        if (r->value == element)
        {
            _elements.erase(_elements.begin() + long(r->place));
            flage = 0;
        }
        
    }
    if(flage == 1)
    {
        throw runtime_error("This element isn't in the container");
    }
}
// This function return the continer size.
int MagicalContainer::size() const {
    return int(_elements.size());
}

// This function return the continer index of the first prime number.
size_t MagicalContainer::getFirstPrime()
{
    return _firstPrime;
}

// This function return the continer size of prime numbers.
int MagicalContainer::getPrimeCounter()
{
    return _primeCounter;
}


}
