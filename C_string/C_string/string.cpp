#include "string.h"

/// <summary>
///  онструктор по умолчанию.
/// </summary>
CString::CString() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new char[_capacity];
    _data[0] = '\0';
}

/// <summary>
///  онструктор копировани€.
/// </summary>
/// <param name="str"> - копируема€ строка</param>
CString::CString(const CString& str) { //добавить проверку на переполненность!!!
    _size = str._size;
    _capacity = str._capacity;
    _data = new char[_capacity];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = str._data[i];
    }
    _data[_size] = '\0';
}

CString::CString(const char* c_str) //добавить проверку на переполненность!!!
{
    _size = 0;
    while (c_str[_size] != '\0')
    {
        _size++;
    }
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _data[i] = c_str[i];
    }
    _data[_size] = '\0';
}

CString::CString(const char* c_str, size_t n) //добавить проверку на переполненность!!!
{
    _size = 0;
    while (c_str[_size] != '\0')
    {
        _size++;
    }
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = n; i < _size; i++)
    {
        _data[i-n] = c_str[i];
    }
    _data[_size-n] = '\0';
}
CString::CString(size_t n, char c) //добавить проверку на переполненность!!!
{
    _size = n;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _data[i] = c;
    }
    _data[_size] = '\0';
}

CString::CString(const CString& str, size_t pos, size_t len) //добавить проверку на переполненность!!!
{
    _size = len;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = 0; i < len; i++)
    {
        _data[i] = str._data[i + pos];
    }
    _data[len] = '\0';
}

/// <summary>
/// ƒеструктор.
/// </summary>
CString::~CString() {
    delete[] _data;
    _data = nullptr;
}

/// <summary>
/// ѕроверка строки на пустоту.
/// </summary>
/// <returns>
/// true - если строка пуста,
/// false - иначе.
/// </returns>
bool CString::empty() const noexcept {
    return _size == 0;
}

bool CString::full() const noexcept
{
    return _size == -1;
}

void CString::print() const noexcept
{
    size_t i = 0;
    while (_data[i] != '\0')
    {
        std::cout << _data[i];
        i++;
    }
    std::cout << "\n";
}

Status CString::check_overfull() const noexcept
{
    Status stat = EMPTY;
    if (_size > 0)
    {
        stat = NOT_FULL;
        if (_capacity + STEP_CAPACITY == _max_capacity)
        {
            stat = CAPACITY_FULL_IN_ONE_STEP;
        }
        if (_capacity == _max_capacity)
        {
            stat = CAPACITY_FULL;
        }
        else if (_size == _max_capacity)
        {
            stat = SIZE_FULL;
        }
        return stat;
    }
    return stat;
}
/// <summary>
/// √еттер дл€ размера строки.
/// </summary>
/// <returns>размер (длина) строки</returns>
size_t CString::size() const noexcept {
    return _size;
}
size_t CString::capacity() const noexcept
{
    return _capacity;
}
const char* CString::data() const
{
    return _data;
}
void CString::swap(CString& str)
{
    for (int i = 0; i < _size; i ++)
    {
        algorithms::swap(_data[i], str._data[i]);
    }
    _data[_size] = '\0';
    str._data[_size] = '\0';
}

//size_t CString::copy(char* buf, size_t len, size_t pos = 0) const
//{
//    //???
//}

//CString CString::substr(size_t pos, size_t len) const //ƒописать !!!_CrtIsValidHeapPointer(block)
//{
//    size_t new_capacity = (len / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
//    char* new_data;
//    new_data = new char[new_capacity];
//    for (int i = 0; i < len; i++)
//    {
//        new_data[i] = _data[i + pos];
//    }
//    new_data[len] = '\0';
//    CString REP(new_data);
//    delete[] new_data;
//    new_data = nullptr;
//    return REP;
//}

CString& CString::assign(const CString& str)
{
    _size = 0;
    delete _data;
    while (str._data[_size] != '\0')
    {
        _size++;
    }
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _data[i] = str._data[i];
    }
    _data[_size] = '\0';
    return *this;
}

CString& CString::assign(const CString& str, size_t pos, size_t len)
{
    _size = len;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    delete _data;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _data[i] = str._data[i+pos];
    }
    _data[_size] = '\0';
    return *this;
}
CString& CString::assign(const char* s)
{
    _size = 0;
    delete _data;
    while (s[_size] != '\0')
    {
        _size++;
    }
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _data[i] = s[i];
    }
    _data[_size] = '\0';
    return *this;
}

CString& CString::assign(const char* s, size_t n)
{
    _size = 0;
    delete _data;
    while (s[_size] != '\0')
    {
        _size++;
    }
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _data[i] = s[i+n];
    }
    _data[_size] = '\0';
    return *this;
}
CString& CString::assign(size_t n, char c)
{
    _size = n;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    delete _data;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _data[i] = c;
    }
    _data[_size] = '\0';
    return *this;
}
/// <summary>
/// ‘ункци€ сравнени€ (лексикографического).
/// </summary>
/// <param name="str"> - строка дл€ сравнени€</param>
/// <returns>
/// 1 - если исходна€ строка больше,
/// -1 - если исходна€ строка меньше,
/// 0 - если строки совпадают.
/// </returns>
int CString::compare(const CString& str) const noexcept {
    if (this->_size > str._size) return 1;
    else if (this->_size < str._size) return -1;
    else {
        for (size_t i = 0; i < algorithms::min(_size, str._size); i++) {
            if (this->_data[i] < str._data[i]) {
                return -1;
            }
            else if (this->_data[i] > str._data[i]) {
                return 11;
            }
        }
        return 0;
    }
}

int CString::compare(size_t pos, size_t len, const CString& str) const
{
    if(len > str._size) return 1;
    else if (len < str._size) return -1;
    else {
        for (size_t i = 0; i < algorithms::min(len, str._size); i++)
        {
            if (this->_data[i + pos] < str._data[i]) return -1;
            else if (this->_data[i + pos] > str._data[i]) return 1;
        }
        return 0;
    }
}
int CString::compare(size_t pos, size_t len, const CString& str, size_t subpos, size_t sublen) const
{
    if (len > sublen) return 1;
    else if (len < sublen) return -1;
    else 
    {
        for (size_t i = 0; i < algorithms::min(len, sublen); i++)
        {
            if (this->_data[i + pos] < str._data[i + subpos]) return -1;
            else if (this->_data[i + pos] > str._data[i + subpos]) return 1;
        }
        return 0;
    }
}

int CString::compare(const char* s) const
{
    size_t len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    if (_size > len) return 1;
    else if (_size < len) return -1;
    else
    {
        for (size_t i = 0; i < algorithms::min(_size, len); i++)
        {
            if (this->_data[i] < s[i]) return -1;
            else if (this->_data[i] > s[i]) return 1;
        }
        return 0;
    }
}

int CString::compare(size_t pos, size_t len, const char* s) const
{
    size_t _len = 0;
    while (s[_len] != '\0')
    {
        _len++;
    }
    if (len > _len) return 1;
    else if (len < _len) return -1;
    else {
        for (size_t i = 0; i < algorithms::min(len, _len); i++)
        {
            if (this->_data[i + pos] < s[i]) return -1;
            else if (this->_data[i + pos] > s[i]) return 1;
        }
        return 0;
    }
}

int CString::compare(size_t pos, size_t len, const char* s, size_t n) const
{
    size_t _len = 0;
    while (s[_len] != '\0')
    {
        _len++;
    }
    if (len > _len) return 1;
    else if (len < _len) return -1;
    else
    {
        for (size_t i = 0; i < algorithms::min(len, _len); i++)
        {
            if (this->_data[i + pos] < s[i + n]) return -1;
            else if (this->_data[i + pos] > s[i + n]) return 1;
        }
        return 0;
    }
}

void CString::clear() noexcept
{
    delete _data;
    _size = 0;
    _capacity = 0 + STEP_CAPACITY;
    _data = new char[_capacity];
    _data[0] = '\0';
}

void CString::reserve(size_t n)
{
    _capacity = ((_size + n) / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    char* new_data;
    new_data = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        new_data[i] = _data[i];
    }
    delete _data;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _data[i] = new_data[i];
    }
    _data[_size] = '\0';
}
void CString::resize(size_t n)
{
    this->reserve(n);
    for (int i = 0; i < n; i++)
    {
        _data[i + _size] = '\0';
    }
    _data[n + _size] = '\0';
}

void CString::push_back(char c)
{
    this->resize(1);
    _data[_size] = c;
    _size += 1;
}

void CString::update(const size_t __size)
{
    _size = __size;
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    char* new_data;
    new_data = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        new_data[i] = _data[i];
    }
    delete _data;
    _data = new char[_capacity];
    for (int i = 0; i < _size; i++)
    {
        _data[i] = new_data[i];
    }
    _data[_size] = '\0';
}

/*
/// <summary>
/// ¬ставка символа в конец строки.
/// </summary>
/// <param name="c"> - символ дл€ вставки</param>
void CString::push_back(char c) {
    if (this->full()) {
        this->reserve(_capacity);
    }

    _data[_size] = c;
    _data[++_size] = '\0';
}*/

/// <summary>
/// ”даление символа из конца строки.
/// <exception cref="std::logic_error">»сключение, если исходна€ строка пуста.</exception>
/// </summary>
void CString::pop_back() {
    if (this->empty()) {
        throw std::logic_error("Error in function \
                  \"void pop_back()\": source CString is empty");
    }
    _data[--_size] = '\0';
}

CString& CString::erase(size_t pos, size_t len)
{
    return *this;
}

/*
// лишь пример реализации
/// <summary>
/// ¬ставка строки после заданной позиции в исходной.
/// </summary>
/// <param name="pos"> - позици€ дл€ вставки в исходной строке.</param>
/// <param name="str"> - строка дл€ вставки</param>
/// <returns>изменЄнна€ исходна€ строка</returns>
CString& CString::insert(size_t pos, const CString& str) {
    CString begin(*this, 0, pos);
    CString end(*this, pos, _size - pos);
    begin.append(str);
    begin.append(end);
    this->swap(begin);
    return *this;
}*/

/// <summary>
/// ѕоиск первого совпадени€ в исходной строке с одним из символов заданной строки.
/// </summary>
/// <param name="str"> - набор символов дл€ поиска</param>
/// <param name="pos"> - позици€, с которой следует начинать поиск</param>
/// <returns></returns>
size_t CString::find_first_of(const CString& str, size_t pos) const {
    for (size_t i = pos; i < _size; i++) {
        for (size_t j = 0; j < str._size; j++) {
            if (_data[i] == str._data[j]) {
                return i;
            }
        }
    }
    return -1;
}
