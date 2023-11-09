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
		RBTree<k, pair< k,v>,MapKeyOfT> _t; //���ֻ��value����ô�޷�ʹ��const key_typeȥ���ܲ���������find����������Ҫ����key����mapֻ��value���޷���ȡ�ġ�
	public:
		//map��set��һ����value�ǿ����޸ĵģ����Բ�������set�ķ����� 
		typedef typename RBTree<k, pair<k,v>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<k, pair<const k, v>, MapKeyOfT>::const_iterator const_iterator;
		//ֻ��k���const���ξͿ��Ա�֤k���ɱ��޸�
		
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