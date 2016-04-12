#include <iostream>
#include <vector>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
	int val;
	int length;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    val = nums[0];
	    length = nums.size();
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		int tmp = val;
	    val = Iterator::next();
	    return tmp;
	}

	bool hasNext() const {
	    return Iterator::hasNext();
	}
};

int main() {
	return 0;
}