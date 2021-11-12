#pragma once

#include<iostream>
#include<string>
#include<vector>

namespace IteratorNamespace
{
	template<typename T, typename U>
	class Iterator
	{
		public: 
			typedef typename std::vector<T>::iterator iter_type;

		private:
			U* _pData;
			iter_type _it;

		public:
			Iterator(U* pData, bool reverse = false) :
				_pData(pData)
			{
				_it = _pData->_mData.begin();
			}

			void First()
			{
				_it = _pData->_mData.begin();
			}

			void Next()
			{
				_it++;
			}

			bool IsDone()
			{
				return (_it == _pData->_mData.end());
			}

			iter_type Current()
			{
				return _it;
			}
	};

	template<typename T>
	class Container
	{
		friend class Iterator<T, Container>;

		private:
			std::vector<T> _mData;

		public:
			void Add(T a)
			{
				_mData.push_back(a);
			}

			Iterator<T, Container>* CreateIterator()
			{
				return new Iterator<T, Container>(this);
			}
	};

	class Data
	{
		private:
			int _mData;

		public:
			Data(int a = 0) : _mData(a) {}

			void setData(int a);

			int data();
	};
}