#pragma once
#include "rbtree.h"

namespace chengzi {
	template<class k>
	class set {
		struct SetKeyOfT {
			const k& operator()(const k& key) {
				return key;
			}
		};
	private:
		RBTree<k, k, SetKeyOfT> _t;
	public:
		//可以只提供const版本 
		typedef typename RBTree<k, k, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<k, k, SetKeyOfT>::const_iterator const_iterator;

		pair<iterator,bool> Insert(const k& key) {  //会报错，因为这里的iterator是const版本，而insert是普通版本。
		    //	return _t.Insert(key);
			pair<RBTree<k, k, SetKeyOfT>::iterator, bool> ret = _t.Insert(key);  //先用一个普通迭代器接受数据
			return pair<iterator, bool>(ret.first, ret.second);  //将first从普通转变为const
		}
		iterator begin() {
			return _t.begin();
		}
		iterator end() {
			return _t.end();
		}
		//set只提供const，不支持修改
		const_iterator begin() const{
			return _t.begin();
		}
		const_iterator end() const {
			return _t.end();
		}
	};
}