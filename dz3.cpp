#include <iostream>
#include <stdexcept>
template <typename T, unsigned N> class Vector
{
  private:
    T *t;
    unsigned size;
    unsigned capacity;

  public:
    Vector() : t(nullptr), size(0), capacity(N) { t = new T[N]; }
    void add(T &value)
    {
        if (capacity == size) {
            capacity *= 2;
            T *p = new T[capacity];
            for (unsigned i = 0; i < size; ++i) {
                p[i] = t[i];
            }
            delete[] t;
            t = p;
        }
        t[size] = value;
        size++;
    }
    void pop()
    {
        --size;
        if (capacity > 2 * size) {
            capacity = size;
            T *p = new T[capacity];
            for (unsigned i = 0; i < size; ++i) {
                p[i] = t[i];
            }
            delete[] t;
            t = p;
        }
    }

    Vector(const Vector &other)
        : t(new T[other.size]), size(other.size), capacity(other.size)
    {
    }

    Vector &operator=(const Vector &other)
    {
        if (this == &other) {
            return *this;
        }
        delete[] t;
        size = other.size;
        capacity = other.size;
        t = new T[size];
        for (unsigned i = 0; i < size; ++i) {
            t[i] = other.t[i];
        }
        return *this;
    }

    unsigned get_size() const { return size; }

    int &operator[](unsigned i)
    {
        if (i >= size) {
            throw std::runtime_error("error");
        }
        return t[i];
    }

    T *begin() { return t; }

    T *end() { return t + size; }

    Vector(T *begin, T const *end) : t(nullptr), size(0), capacity(N)
    {
        t = new T[N];
        for (auto *i = begin; i != end; ++i) {
            add(*i);
        }
    }

    ~Vector() { delete[] t; }
};

int main()
{
    return 0;
}