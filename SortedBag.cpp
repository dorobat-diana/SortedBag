#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <exception>

SortedBag::SortedBag(Relation r) {

    this->relation = r;
    this->capacity = 10;
    this->nrElements= 0;
    this->elements= new TComp[this->capacity];
}//theta(1)

void SortedBag::add(TComp e) {

if(this->nrElements == this->capacity){
        this->capacity *= 2;
        TElem * newElements = new TComp[this->capacity];
        for(int i = 0; i < this->nrElements; i++){
            newElements[i] = this->elements[i];
        }
        delete [] this->elements;
        this->elements = newElements;
    }
    int index = 0;
    while(index < this->nrElements && this->relation(this->elements[index], e)){
        index++;
    }

    for(int i = this->nrElements; i > index; i--){
        this->elements[i] = this->elements[i-1];
    }
    this->elements[index] = e;
    this->nrElements++;
}//best case: theta(nrElements) worst case: theta(nrElements)=>average case theta(nrElements)



void SortedBag::addOccurences(int nr, TComp e){
    if (nr < 0){
        throw std::exception();
    }
    for(int i = 0; i < nr; i++){
        this->add(e);
    }
}//best case: theta(1) worst case: theta(nr)=>average case theta(nr)


bool SortedBag::remove(TComp e) {

    for(int i=0;i<this->nrElements;i++){
        if(this->elements[i]==e){
            for(int j=i;j<this->nrElements-1;j++){
                this->elements[j]=this->elements[j+1];
            }
            this->nrElements--;
            return true;
        }
    }
	return false;
}//best case: theta(nrElements) worst case: theta(nrElements)=>average case theta(nrElements)


bool SortedBag::search(TComp elem) const {

    for(int i = 0; i < this->nrElements; i++){
        if(this->elements[i] == elem){
            return true;
        }
    }
	return false;
}//best case: theta(1) worst case: theta(nrElements)=>average case theta(nrElements)


int SortedBag::nrOccurrences(TComp elem) const {

    int nr=0;
    for(int i=0;i<this->nrElements;i++){
        if(this->elements[i]==elem){
            nr++;
        }
    }
	return nr;
}//best case=worst case=average case: theta(nrElements)



int SortedBag::size() const {

    return this->nrElements;
}//best case=worst case=average case: theta(1)


bool SortedBag::isEmpty() const {

    if(this->nrElements==0){
        return true;
    }
	return false;
}//best case=worst case=average case: theta(1)



SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}//best case=worst case=average case: theta(1)



SortedBag::~SortedBag() {

    delete [] this->elements;
}//theta(1)
