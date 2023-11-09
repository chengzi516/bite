#pragma once
#include "rbtree.h"

namespace chengzi {
	template<class k,class v>
	class map {
		struct MapKeyOfT {
			const k& operator()(const pair<k, v>& kv) {
				return kv.first;
			}
		};
	private:     
		RBTree<k, pair< k,v>,MapKeyOfT> _t; //如果只传value，那么无法使用const key_type去接受参数，比如find函数，他需要的是key，而map只有value是无法提取的。
	public:
		//map和set不一样，value是可以修改的，所以不能套用set的方法。 
		typedef typename RBTree<k, pair<k,v>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<k, pair<const k, v>, MapKeyOfT>::const_iterator const_iterator;
		//只给k添加const修饰就可以保证k不可被修改
		
			pair<iterator,bool> Insert(const pair<k, v>& kv) {
				return _t.Insert(kv);
		}
			iterator begin() {  
				return _t.begin();
			}
			iterator end() {
				return _t.end();
			}
			const_iterator begin() const {
				return _t.begin();
			}
			const_iterator end() const {
				return _t.end();
			}
			v& operator[](const k& key)
			{
				pair<iterator, bool> ret = insert(make_pair(key, v()));
				return ret.first->second;
			}
		};
	
}