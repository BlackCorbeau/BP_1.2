#include "string.h"

/// <summary>
/// ����������� �� ���������.
/// </summary>
CString::CString() {
    _size = 0;
    _capacity = STEP_CAPACITY;
    _data = new char[_capacity];
    _data[0] = '\0';
}

/// <summary>
/// ����������� �����������.
/// </summary>
/// <param name="str"> - ���������� ������</param>
CString::CString(const CString& str) {
    _size = str._size;
    _capacity = str._capacity;
    _data = new char[_capacity];
    for (size_t i = 0; i < _size; i++) {
        _data[i] = str._data[i];
    }
    _data[_size] = '\0';
}

CString::CString(const char* c_str)
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

CString::CString(const char* c_str, size_t n)
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
CString::CString(size_t n, char c)
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

CString::CString(const CString& str, size_t pos, size_t len)
{
    _size = 0;
    while (str._data[_size] != '\0')
    {
        _size++;
    }
    _capacity = (_size / STEP_CAPACITY) * STEP_CAPACITY + STEP_CAPACITY;
    _data = new char[_capacity];
    for (int i = 0; i < len; i++)
    {
        _data[i] = str._data[i + pos];
    }
    _data[len] = '\0';
}

/// <summary>
/// ����������.
/// </summary>
CString::~CString() {
    delete[] _data;
    _data = nullptr;
}

/// <summary>
/// �������� ������ �� �������.
/// </summary>
/// <returns>
/// true - ���� ������ �����,
/// false - �����.
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
/// ������ ��� ������� ������.
/// </summary>
/// <returns>������ (�����) ������</returns>
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
/// <summary>
/// ������� ��������� (�������������������).
/// </summary>
/// <param name="str"> - ������ ��� ���������</param>
/// <returns>
/// 1 - ���� �������� ������ ������,
/// -1 - ���� �������� ������ ������,
/// 0 - ���� ������ ���������.
/// </returns>
int CString::compare(const CString& str) const noexcept {
    for (size_t i = 0; i < algorithms::min(_size, str._size); i++) {
        if (this->_data[i] < str._data[i]) {
            return 1;
        }
        else if (this->_data[i] > str._data[i]) {
            return -1;
        }
    }
    if (this->_size > str._size) return 1;
    else if (this->_size < str._size) return -1;
    else return 0;
}

/*
/// <summary>
/// ������� ������� � ����� ������.
/// </summary>
/// <param name="c"> - ������ ��� �������</param>
void CString::push_back(char c) {
    if (this->full()) {
        this->reserve(_capacity);
    }

    _data[_size] = c;
    _data[++_size] = '\0';
}*/

/// <summary>
/// �������� ������� �� ����� ������.
/// <exception cref="std::logic_error">����������, ���� �������� ������ �����.</exception>
/// </summary>
void CString::pop_back() {
    if (this->empty()) {
        throw std::logic_error("Error in function \
                  \"void pop_back()\": source CString is empty");
    }
    _data[--_size] = '\0';
}

/*
// ���� ������ ����������
/// <summary>
/// ������� ������ ����� �������� ������� � ��������.
/// </summary>
/// <param name="pos"> - ������� ��� ������� � �������� ������.</param>
/// <param name="str"> - ������ ��� �������</param>
/// <returns>���������� �������� ������</returns>
CString& CString::insert(size_t pos, const CString& str) {
    CString begin(*this, 0, pos);
    CString end(*this, pos, _size - pos);
    begin.append(str);
    begin.append(end);
    this->swap(begin);
    return *this;
}*/

/// <summary>
/// ����� ������� ���������� � �������� ������ � ����� �� �������� �������� ������.
/// </summary>
/// <param name="str"> - ����� �������� ��� ������</param>
/// <param name="pos"> - �������, � ������� ������� �������� �����</param>
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
