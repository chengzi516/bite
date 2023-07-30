#pragma once
#include<assert.h>

namespace bit
{
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;

		list_node(const T& val = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{}
	};

	template<class T>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		typedef __list_iterator<T> self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		T operator*()
		{
			return _node->_val;
		}

		 T* operator->()
		{
			return &_node->_val;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
		{
			self tmp(*this);

			_node = _node->_next;

			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int)
		{
			self tmp(*this);

			_node = _node->_prev;

			return tmp;
		}

		bool operator!=(const self& it) const
		{
			return _node != it._node;
		}

		bool operator==(const self& it) const
		{
			return _node == it._node;
		}
	};

	/*template<class T>
	struct __list_const_iterator
	{
		typedef list_node<T> Node;
		Node* _node;

		__list_const_iterator(Node* node)
			:_node(node)
		{}

		const T& operator*()
		{
			return _node->_val;
		}

		__list_const_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		__list_const_iterator<T> operator++(int)
		{
			__list_const_iterator<T> tmp(*this);

			_node = _node->_next;

			return tmp;
		}

		bool operator!=(const __list_const_iterator<T>& it)
		{
			return _node != it._node;
		}

		bool operator==(const __list_const_iterator<T>& it)
		{
			return _node == it._node;
		}
	};*/

	template<class T>
	class list
	{
		typedef list_node<T> Node;

	public:
		typedef __list_iterator<T> iterator;
		typedef __list_iterator<T> const_iterator;



		iterator begin()
		{
			//return _head->_next;
			return iterator(_head->_next);
		}

		iterator end()
		{
			return _head;
			//return iterator(_head);
		}

		const_iterator begin() const
		{
			//return _head->_next;
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return _head;
			//return const_iterator(_head);
		}

		void empty_init()
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;

			_size = 0;
		}

		list()
		{
			empty_init();
		}

		// lt2(lt1)
		list(const list<T>& lt)
			//list(const list& lt)
		{
			empty_init();

			for (auto& e : lt)
			{
				push_back(e);
			}
		}

		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);
			std::swap(_size, lt._size);
		}

		list<T>& operator=(list<T> lt)
			//list& operator=(list lt)
		{
			swap(lt);

			return *this;
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}

			_size = 0;
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		// posλ��֮ǰ����
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_next = cur;

			cur->_prev = newnode;
			newnode->_prev = prev;

			++_size;

			return newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;

			--_size;

			return next;
		}

		size_t size()
		{
			/*size_t sz = 0;
			iterator it = begin();
			while (it != end())
			{
				++sz;
				++it;
			}

			return sz;*/

			return _size;
		}

	private:
		Node* _head;
		size_t _size;
	};

	

	
}