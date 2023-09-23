#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	this->current = 0;
}//best case=theta(1), worst case=theta(1), average case=theta(1)

TComp SortedBagIterator::getCurrent() {
	if(this->current>=this->bag.nrElements)
        throw exception();
    else{
        return this->bag.elements[this->current];
    }
	return NULL_TCOMP;
}//best case=theta(1), worst case=theta(1), average case=theta(1)

bool SortedBagIterator::valid() {
	    if (this->current < this->bag.nrElements)
        return true;
	return false;
}//best case=theta(1), worst case=theta(1), average case=theta(1)

void SortedBagIterator::next() {
	if(this->current>=this->bag.nrElements)
        throw exception();
    else{
        this->current++;
    }
}//best case=theta(1), worst case=theta(1), average case=theta(1)


void SortedBagIterator::first() {
    this->current = 0;
}//best case=theta(1), worst case=theta(1), average case=theta(1)

