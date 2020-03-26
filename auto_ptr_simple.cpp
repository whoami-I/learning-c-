#include <iostream>
// #include <climits>
#include <limits>
//using namespace std;
#include <vector>
#include <algorithm>
// template <typename T>
// typename T::value_type get(T it)
// {
//     return *it;
// }

// template <typename T>
// class MyIter
// {

//     T *mPtr;

// public:
//     using value_type = T;

//     MyIter(T *p)
//     {
//         mPtr = p;
//     }

//     T &operator*()
//     {
//         return *mPtr;
//     }
// };

// template <typename T>
// class MyIter<T *>
// {

//     T *mPtr;

// public:
//     using value_type = T;

//     MyIter(T *p)
//     {
//         mPtr = p;
//     }

//     T &operator*()
//     {
//         cout << "use spec" << endl;
//         return *mPtr;
//     }
// };

// class Iter
// {
//     T *mPtr;

// public:
//     using value_type = int *;
//     MyIter(T *p)
//     {
//         mPtr = p;
//     }

//     T &operator*()
//     {
//         cout << "use spec" << endl;
//         return *mPtr;
//     }
// };

struct input_iterator_tag
{
};
struct output_iterator_tag
{
};
struct forward_iterator_tag : public input_iterator_tag
{
};
struct bi_iterator : public forward_iterator_tag
{
};
struct random_iterator : public bi_iterator
{
};

template <typename InputIterator>
void __madvance(InputIterator &i, int distance, input_iterator_tag)
{
    std::cout << "InputIterator type" << std::endl;
}

template <typename BiIterator>
void __madvance(BiIterator &i, int distance, bi_iterator)
{
    std::cout << "BiIterator type" << std::endl;
}

template <typename RandomIterator>
void __madvance(RandomIterator &i, int distance, random_iterator)
{
    std::cout << "RandomIterator type" << std::endl;
}

template <typename T>
struct iterator_traits
{
    using iterator_category = typename T::iterator_category;
    //typedef typename T::iterator_category iterator_category;
};

template <typename InputIterator>
void madvance(InputIterator &i, int distance)
{
    __madvance(i, distance, iterator_traits<InputIterator>::iterator_category());
    //__madvance(i, distance, typename InputIterator::iterator_category());
}

//template <typename T>
class MyIter11
{
public:
    using iterator_category = input_iterator_tag;
};

//template <typename T>
class MyIter12
{
public:
    using iterator_category = bi_iterator;
};

//template <typename T>
class MyIter13
{
public:
    using iterator_category = random_iterator;
};

int main()
{
    // MyIter<int> a(new int(5));
    // MyIter<float> b(new float(6.7F));
    // cout << get(a) << endl;
    // cout << get(b) << endl;
    // int ci = 10;
    // int *pci = &ci;
    // MyIter<int *> d(pci);
    // cout << get(d) << endl;

    // vector<int> v1;
    // v1.push_back(10);
    // v1.push_back(20);
    // cout << count(v1.begin(), v1.end(), 10) << endl;

    // MyIter11<int> iter11;
    // MyIter12<int> iter12;
    // MyIter13<int> iter13;

    MyIter11 iter11;
    MyIter12 iter12;
    MyIter13 iter13;
    madvance(iter11, 10);

    madvance(iter13, 10);

    madvance(iter12, 10);
    typedef int haha;
    haha aa = haha(10);
    std::cout << aa << std::endl;
    return 0;
}