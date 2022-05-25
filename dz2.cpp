#include<iostream>
#include<stdexcept>

template <unsigned N = 10>
class Vector {
private:
    int* t;
    unsigned size;
    unsigned capacity;
public:
    Vector() : t(nullptr),
               size(0),
               capacity(N) {
        t = new int[N];
    }
    void add(int value) {
        if (capacity == size) {
            capacity *= 2;
            int* p = new int[capacity];
            for(unsigned i = 0; i < size; ++i) {
                p[i]=t[i];
            }
            delete[] t;
            t = p;
        }
        t[size] = value;
        size++;
    }
    void pop() {
        --size;
        if (capacity> 2 * size) {
            capacity = size;
            int* p = new int[capacity];
            for(unsigned i = 0;i < size; ++i) {
                p[i] = t[i];
            }
            delete[] t;
            t = p;
        }
    }

    Vector(const Vector& other) : t(new int[other.size]),
                                  size(other.size),
                                  capacity(other.size){}

    Vector& operator= (const Vector& other) {
        if (this == &other) {
            return *this;
        }
        delete[] t;
        size = other.size;
        capacity = other.size;
        t = new int[size];
        for(unsigned i = 0;i < size; ++i) {
            t[i] = other.t[i];
        }
        return *this;
    }

    unsigned get_size() const {
        return size;
    }

    int& operator[] (unsigned i) {
        if(i >= size){
            throw std::runtime_error("error");
        }
        return t[i];
    }

    int *begin () {
        return t;
    }

    int* end () {
        return t + size;
    }

    Vector(int* begin, int* end): t(nullptr), size(0), capacity(N) {
        t = new int[N];
        for(auto i = begin; i != end; i++) {
            add(*i);
        }
    }

    ~Vector() {
        delete[] t;
    }
};

int main() {
    Vector<5> v;
    for (int i = 0; i < 50; ++i) {
        v.add(i);
    }
    std::cout << 5 << " = " << v[5]<< std::endl;
    while (v.get_size() > 0) {
        v.pop();
    }

    return 0;
}