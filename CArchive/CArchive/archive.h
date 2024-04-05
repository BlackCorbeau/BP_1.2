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
    T max(T val_1, T val_2) {
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
    TArchive& remove_all();
    TArchive& remove_first(T value);
    TArchive& remove_last(T value);

    size_t* find_all(T value, size_t& count) const noexcept;
    size_t find_first(T value);
    size_t find_last(T value);
private:
    //size_t count_value(T value);
};

template <typename T>
TArchive<T>::TArchive() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < STEP_CAPACITY; i++) {
        _states[i] = State::empty;
    }
}

template <typename T>
TArchive<T>::TArchive(const TArchive& archive)
{
    _capacity = archive._capacity;
    _size = archive._size;              
    _deleted = archive._deleted;
    _states = new State[_capacity];
    _data = new T[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = archive._states[i];
    }
    for (int i = 0; i < _size; i++)
    {
        _data[i] = archive._data[i];
    }
}

template <typename T>
TArchive<T>::TArchive(const T* arr, size_t n)
{
    _size = n;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _states = new State[_capacity];
    _data = new T[_capacity];
    _deleted = 0;
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = State::empty;
    }
    for (int i = 0; i < n; i++)
    {
        _data[i] = arr[i];
    }
    for (size_t i = 0; i < n; i++) {
        _states[i] = State::busy;
    }
}

template <typename T>
TArchive<T>::TArchive(size_t n, T value)
{
    _size = n;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _states = new State[_capacity];
    _data = new T[_capacity];
    _deleted = 0;
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = State::empty;
    }
    for (int i = 0; i < n; i++)
    {
        _data[i] = value;
    }
    for (size_t i = 0; i < n; i++) {
        _states[i] = State::busy;
    }
}

template <typename T>
TArchive<T>::TArchive(const TArchive& archive, size_t pos, size_t len)
{
    _size = len;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _deleted = 0;
    _states = new State[_capacity];
    _data = new T[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = State::empty;
    }
    for (size_t i = 0; i < _size; i++) {
        _states[i] = State::busy;
    }
    for (int i = 0; i < _size; i++)
    {
        _data[i] = archive._data[i + pos];
    }
}

template <typename T>
TArchive<T>::~TArchive() 
{
    delete[] _data;
    _data = nullptr;
}

template <typename T>
inline bool TArchive<T>::empty() const noexcept {
    return _size == 0;
}

template <typename T>
inline bool TArchive<T>::full() const noexcept {
    return _size == _capacity;
}

template<typename T>
size_t TArchive<T>::size()
{
    return _size;
}
template<typename T>
size_t TArchive<T>::capacity()
{
    return _capacity;
}

template<typename T>
const T* TArchive<T>::data()
{
    return _data;
}

template<typename T>
void TArchive<T>::swap(TArchive& archive)
{
    for (int i = 0; i < algorithms::max(_size, archive._size); i++)
    {
        algorithms::swap(_data[i], archive._data[i]);
    }
}


template<typename T>
void TArchive<T>::clear() // ѕодумать как доделать (после работы видно мусор)
{
    int j = 0;
    for (int i = 0; i < _capacity; i++) {
        if (_states[i] != State::deleted) {
            _data[j] = _data[i];
            _states[j] = _states[i];
            j++;
        }
    }
}

template<typename T>
void TArchive<T>::reserve(size_t n)
{
    if (_capacity == -1)
    {
        std::cout << "ѕереполнение, добавление большего количества элементов в этот архив невозможно, пожалуйста создайте новый архив или удалите часть элементов." << '\n';
        return;
    }
    else
    {
        _capacity = ((_size + n) / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    }
    T* new_data;
    State* new_states;
    new_data = new T[_capacity];
    new_states = new State[_capacity];
    for (int i = 0; i < _size; i++)
    {
        new_data[i] = _data[i];
        new_states[i] = _states[i];
    }
    for (int i = _size; i < _capacity; i++)
    {
        new_states[i] = State::empty;
    }
    delete[] _data;
    delete[] _states;
    _data = new_data;
    _states = new_states;
}

template<typename T>
void TArchive<T>::resize(size_t n, T value)
{
    n -= 1;
    this->reserve(n);
    for (int i = _size - 1; i < _size + n; i++)
    {
        _data[i] = value;
    }
    for (int i = _size - 1; i < _size + n; i++)
    {
        _states[i] = State::busy;
    }
    _size += n;
}

template<typename T>
TArchive<T>& TArchive<T>::assign(const TArchive& archive) 
{
    this->reserve(archive._size);
    for (int i = 0; i < archive._size; i++)
    {
        _data[i] = archive._data[i];
        _states[i] = State::busy;
    }
    for (int i = archive._size; i < _capacity; i++)
    {
        _states[i] = State::empty;
    }
    _size = archive._size;
    return *this;
}

template<typename T>
void TArchive<T>::push_back(T value)
{
    this->reserve(1);
    _data[_size] = value;
    _size += 1;
}

template<typename T>
void TArchive<T>::pop_back()
{
    _states[_size - 1] = State::deleted;
}

template<typename T>
void TArchive<T>::push_front(T value)
{
    this->reserve(1);
    for (int i = _size; i >= 0; i--)
    {
        _data[i + 1] = _data[i];
    }
    _data[0] = value;
    _size += 1;
}

template<typename T>
void TArchive<T>::pop_front()
{
    _states[0] = State::deleted;
}


template<typename T>
TArchive<T>& TArchive<T>::remove_by_index(size_t pos)
{
    _states[pos] = State::deleted;
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::insert(T value, size_t pos) {
    if (_size < pos) {
        throw std::logic_error("Error in function \
\"TArchive<T>& insert(T value, size_t pos)\": wrong position value.");
    }
    
    // действи€ при переполнении
    this->reserve(1);
    
    for (size_t i = _size; i > pos; i--) {
        _data[i] = _data[i - 1];
    }
    _data[pos] = value;
    _states[pos] = State::busy;
    _size++;
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::insert(const T* arr, size_t n, size_t pos) // не работает при pos = 0
{
    this->reserve(n);
    for (int i = _size - 1; i >= pos; i--)
    {
        _data[i + n] = _data[i];
    }
    for (int i = pos, j = 0; i < n + pos; i++, j++)
    {
        _data[i] = arr[j];
    }
    _size += n;
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::replace(size_t pos, T new_value)
{
    _data[pos] = new_value;
    return *this;
}

template <typename T>
void TArchive<T>::print() const noexcept {
    for (size_t i = 0; i < _size; i++) {
        if (_states[i] != State::deleted) {
            std::cout << _data[i] << ", ";
        }
    }
}

template <typename T>
TArchive<T>& TArchive<T>::erase(size_t pos, size_t n)
{
    for (int i = pos; i < pos + n; i++)
    {
        _states[i] = State::deleted;
    }
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::remove_all() // ƒопилить, работает криво.
{
    for (int i = 0; i < _size; i++)
    {
        _states[i] = State::deleted;
    }
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::remove_first(T value)
{
    for (int i = 0; i < value; i++)
    {
        _states[i] = State::deleted;
    }
    return *this;
}

template <typename T>
TArchive<T>& TArchive<T>::remove_last(T value)
{
    for (int i = _size-1, j = 0; j < value; i--, j++)
    {
        _states[i] = State::deleted;
    }
    return *this;
}

template <typename T>
size_t* TArchive<T>::find_all(T value, size_t& count) const noexcept
{
    size_t* find_values;
    size_t _count = 0;
    for (int i = 0; i < _size; i++)
    {
        if (_data[i] == value)
        {
            _count++;
        }
    }
    find_values = new size_t[_count];
    count = _count;
    _count = 0;
    for (int i = 0; i < _size; i++)
    {
        if (_data[i] == value)
        {
            find_values[_count] = i;
            _count++;
        }
    }
    return find_values;
}

template <typename T>
size_t TArchive<T>::find_first(T value)
{
    for (int i = 0; i < _size; i++)
    {
        if (_data[i] == value)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
size_t TArchive<T>::find_last(T value)
{
    for (int i = _size; i >= 0; i--)
    {
        if (_data[i] == value)
        {
            return i;
        }
    }
    return -1;
}

/*
// пример реализации с возвратом массива найденных позиций
template <typename T>
size_t* TArchive<T>::find_all (T value) const noexcept {
    size_t count = this->count_value(value);
    if (count == 0) { return nullptr; }
    int* found_positions = new int[count + 1];
    found_positions[0] = count;

    // TBD

    return found_positions;
}
*/
