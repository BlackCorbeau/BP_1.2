#pragma once
#define STEP_CAPACITY 15
#include <iostream>

enum State { empty, busy, deleted };

namespace algorithms {
    template<typename T>
    inline void swap(T& val_1, T& val_2) noexcept {
        T tmp = val_1;
        val_1 = val_2;
        val_2 = tmp;
    }

    template<typename T>
    T Max(T val_1, T val_2) {
        if (val_1 > val_2) return val_1;
        else return val_2;
    }
}

template <typename T>
class TArchive {
    T* _data;                  // динамический массив данных
    State* _states;            // состо€ни€ €чеек
    size_t _capacity;          // реальный размер массива
    size_t _size;              // количество хранимых данных
    size_t _deleted;           // количество "удалЄнных" позиций
public:
    TArchive();
    TArchive(const TArchive& archive);
    TArchive(const T* arr, size_t n);
    TArchive(size_t n, T value);
    TArchive(const TArchive& archive, size_t pos, size_t len);

    ~TArchive();

    void print() const noexcept;

    inline bool empty() const noexcept;
    inline bool full() const noexcept;

    size_t size();
    size_t capacity();
    const T* data();

    void swap(TArchive& archive);

    void clear();
    void reserve(size_t n);
    void resize(size_t n, T value);
    void repack();

    TArchive& assign(const TArchive& archive);


    void push_back(T value);             // вставка элемента (в конец)
    void pop_back();                     // удаление элемента (из конца)
    void push_front(T value);            // вставка элемента (в начало)
    void pop_front();                    // удаление элемента (из начала)

    TArchive& insert(const T* arr, size_t n, size_t pos);
    TArchive& insert(T value, size_t pos);

    TArchive& replace(size_t pos, T new_value);

    TArchive& remove_by_index(size_t pos);
    TArchive& erase(size_t pos, size_t n);
    TArchive& remove_all(T value);
    TArchive& remove_first(T value);
    TArchive& remove_last(T value);

    size_t* find_all(T value, size_t& count) const noexcept;
    size_t find_first(T value);
    size_t find_last(T value);
private:
    //size_t count_value(T value);
};
