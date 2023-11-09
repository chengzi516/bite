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
		//����ֻ�ṩconst�汾 
		typedef typename RBTree<k, k, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<k, k, SetKeyOfT>::const_iterator const_iterator;

		pair<iterator,bool> Insert(const k& key) {  //�ᱨ����Ϊ�����iterator��const�汾����insert����ͨ�汾��
		    //	return _t.Insert(key);
			pair<RBTree<k, k, SetKeyOfT>::iterator, bool> ret = _t.Insert(key);  //����һ����ͨ��������������
			return pair<iterator, bool>(ret.first, ret.second);  //��first����ͨת��Ϊconst
		}
		iterator begin() {
			return _t.begin();
		}
		iterator end() {
			return _t.end();
		}
		//setֻ�ṩconst����֧���޸�
		const_iterator begin() const{
			return _t.begin();
		}
		const_iterator end() const {
			return _t.end();
		}
	};
}