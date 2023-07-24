#pragma once
#include<assert.h>

namespace newstring {
	class string {
	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}
		//��д���������
		string(const char* str = "") {
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];
			strcpy(_str, str);

		}
		string(const string& s) {
			string tmp(s._str);
			std::swap(_str, tmp._str);
			std::swap(_size, tmp._size);
			std::swap(_capacity, tmp._capacity);
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		// ��ȡ�ַ�������
		size_t size() const {
			return _size;
		}

		// ��ȡ�ַ�������
		size_t capacity() const {
			return _capacity;
		}

		// ��ȡ�ַ�������
		const char* c_str() const {
			return _str;
		}
		//��ȡָ��λ�õ�Ԫ��
		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}
        //��������
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		//�ڴ����һ��Ԫ��
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				// 2������
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}

			_str[_size] = ch;

			++_size;
			_str[_size] = '\0';
		}
		//�ڴ����һ��Ԫ��
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				// �������ݵ�_size + len
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		}
		//��д+=������
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}
		//��д����
		void insert(size_t pos, size_t n, char ch)
		{
			assert(pos <= _size);

			if (_size + n > _capacity)
			{
				// �������ݵ�_size + len
				reserve(_size + n);
			}
			size_t end = _size;
			while (end >= pos && end<_size)//��Ҫ�ĵط�
			{
				_str[end + n] = _str[end];
				--end;
			}

			for (size_t i = 0; i < n; i++)
			{
				_str[pos + i] = ch;
			}

			_size += n;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				// �������ݵ�_size + len
				reserve(_size + len);
			}
			size_t end = _size;
			while (end >= pos && end != -1)
			{
				_str[end + len] = _str[end];
				--end;
			}

			for (size_t i = 0; i < len; i++)
			{
				_str[pos + i] = str[i];
			}

			_size += len;
		}

		void erase(size_t pos, size_t len = -1)
		{
			assert(pos <= _size);

			if (len == -1 || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;

				_str[_size] = '\0';
			}
			else
			{
				size_t end = pos + len;
				while (end <= _size)
				{
					_str[pos++] = _str[end++];
				}
				_size -= len;
			}
		}

		size_t find(char ch, size_t pos = 0)
		{
			assert(pos < _size);

			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return -1;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);

			const char* ptr = strstr(_str + pos, str);
			if (ptr)
			{
				return ptr - _str;
			}
			else
			{
				return -1;
			}
		}

		string& operator=(string tmp)
		{
			std::swap(_str, tmp._str);
			std::swap(_size, tmp._size);
			std::swap(_capacity, tmp._capacity);

			return *this;
		}

		string substr(size_t pos = 0, size_t len = -1)
		{
			assert(pos < _size);

			size_t n = len;
			if (len == -1 || pos + len > _size)
			{
				n = _size - pos;
			}

			string tmp;
			tmp.reserve(n);
			for (size_t i = pos; i < pos + n; i++)
			{
				tmp += _str[i];
			}
			return tmp;
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		
	};
	std::ostream& operator<<(std::ostream& out, const string& s)
	{


		for (auto ch : s)
		{
			out << ch;
		}

		return out;
	}


	std::istream& operator>>(std::istream& in, string& s)
	{
		s.clear();

		char ch = in.get();
		// ����ǰ������ǰ��Ŀո���߻���
		while (ch == ' ' || ch == '\n')
		{
			ch = in.get();
		}

		//in >> ch;
		char buff[128];
		int i = 0;

		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == 127)
			{
				buff[i] = '\0';
				s += buff;
				i = 0;
			}

			ch = in.get();
		}

		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}

		return in;
	}
}
