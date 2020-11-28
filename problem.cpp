#include <iostream>
#include <assert.h>
#include <memory.h>

class array {
    int capacity = 0;
    int size = 0;
    int count = 0;
    int* data = NULL;
public:
    array(int capacity) {
        this->capacity = capacity;
        size = capacity;
        data = new int[size];
    }
    ~array() {
        delete data;
    }
    void add(int n) {        
        if (count == size) {            
            int* p = new int[size + capacity];
            for (int i = 0; i < size; ++i) {
                p[i] = data[i];
            }
            delete data;
            size += capacity;
            data = p;            
        }        
        data[count++] = n;
    }
    int* getPointer(int n) {
        if (n < size) {
            return data + n * sizeof(int);
        }
        else {
            return NULL;
        }
    }
    int sum () {
        int s = 0;
        for (int i = 0; i < size; ++i) {
            s += data[i];
        }
        return s;
    }
    bool operator > (array& a) {
        return this->sum() > a.sum();
    }
    bool operator < (array& a) {
        return this->sum() < a.sum();
    }
    bool operator == (array& a) {
        return this->sum() == a.sum();
    }
    bool operator != (array& a) {
        return this->sum() != a.sum();
    }
};

int main (int argc, char** argv) {    
    array& a = *(new array(2));
    a.add(1.0);
    a.add(2.0);
    a.add(3.0);    
    array& b = *(new array(3));
    b.add(3.0);
    b.add(4.0);
    b.add(5.0);

    assert(a < b);

    return 0;
}