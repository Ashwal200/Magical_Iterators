#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <limits.h>
using namespace std;

namespace ariel {

class MagicalContainer {
    // Data structure to represent elements in the container
    typedef struct Data {
        int value = 0;
        size_t next = size_t(INT_MAX);
        size_t place = size_t(-1);
        bool prime = false;
    } Data, *ptrData;

private:
    vector<ptrData> _elements; // Vector to store the elements of the container
    size_t _firstPrime = size_t(-1); // Index of the first prime element
    int _primeCounter = 0; // Counter for the prime elements
    bool _flage = true; // Flag to determine if the first prime index has been set

public:
    size_t getFirstPrime(); 
    int getPrimeCounter(); 
    size_t setPrime(size_t, int); 
    vector<ptrData> &getElements(); 
    void addElement(int element); 
    void removeElement(int element); 
    int size() const; 
    bool isPrime(int);

    ~MagicalContainer();

    // Iterator class for traversing the container
    class myIterator {
    public:
        MagicalContainer& _container; // Reference to the MagicalContainer object
        size_t _it = 0; // Iterator position
        int _type = -1; // Iterator type

        myIterator(MagicalContainer& container); // Constructor

        virtual ~myIterator() = default; // Destructor

        myIterator(const myIterator& other) = default; // Copy constructor

        myIterator(myIterator&& other) noexcept = default; // Move constructor

        myIterator& operator=(const myIterator& other); // Copy assignment operator

        myIterator& operator=(myIterator&& other) noexcept; // Move assignment operator

        bool operator==(const myIterator& other) const; 

        bool operator!=(const myIterator& other) const; 

        bool operator<(const myIterator& other) const; 

        bool operator>(const myIterator& other) const; 

        virtual int operator*() = 0; // Dereference operator

        virtual myIterator& operator++() = 0; // Pre-increment operator
    };

    class AscendingIterator : public myIterator {
    public:
        AscendingIterator(MagicalContainer& cont); // Constructor

        int operator*() override; 

        AscendingIterator& operator++() override; 

        AscendingIterator begin() const; 

        AscendingIterator end() const; 
    };

    class SideCrossIterator : public myIterator {
    private:
        size_t _left = 0; // Iterator position for the left side
        size_t _right = _container._elements.size() - 1; // Iterator position for the right side
    public:
        SideCrossIterator(MagicalContainer& cont); // Constructor

        int operator*() override; 

        SideCrossIterator& operator++() override; 

        SideCrossIterator begin() const;

        SideCrossIterator end() const; 
    };

    class PrimeIterator : public myIterator {
    private:
        bool _start = true; // Flag to determine if the iterator is at the start
    public:
        PrimeIterator(MagicalContainer& cont); // Constructor

        int operator*() override; 

        PrimeIterator& operator++() override; 

        PrimeIterator begin() const; 

        PrimeIterator end() const; 
    };
};

} 
