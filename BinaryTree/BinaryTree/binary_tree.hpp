#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

namespace algoritms	
{

namespace details
{

enum NodeColor {Black = 0, Red = 1};


//template
//<
//   class T,
//   template <class> class CheckingPolicy,
//   template <class> class ThreadingModel,
//   template <class> class Storage = DefaultSmartPtrStorage
//>
//class SmartPtr;





template <typename T>
struct node 
{
public:
	typedef node<T>* pointer;

	node()
		: left_(0), right_(0), parent_(0), nodeColor_(details::Red)
	{
	}


	node(const T& data)
		: data_(data), left_(0), right_(0), parent_(0), nodeColor_(details::Red)
	{
	}

	node(const T& data, NodeColor nodeColor)
		: data_(data), left_(0), right_(0), parent_(0), nodeColor_(nodeColor)
	{
	}

	virtual ~node()
	{
		//std::cout << "virtual ~node()" << std::endl;
	}

	pointer getGrandParent() const //node<T>*
	{
		if ( this->parent_ == 0)
		{
			return 0;
		}
		else
		{
			return this->parent_->parent_;
		}
	}
 
	pointer getUncle() const //node<T>*
	{
		//node<T> *granParent = this->getGrandParent();
		pointer granParent = this->getGrandParent();

		if (granParent == 0)
		{
			return 0;
		}

		if (this->parent_ == granParent->left_)
		{
			return granParent->right_;
		}
		else
		{
			return granParent->left_;
		}
	}

//protected:
	T data_;
	pointer left_;				
	pointer right_;				
	pointer parent_;			
	NodeColor nodeColor_;		

	//node<T> *left_;			
	//node<T> *right_;			
	//node<T> *parent_;			

};

}


//TODO: //typename Allocator = allocator<T>
template 
<
	typename T, 
	typename NodeType = details::node<T>, 
	typename Compare = std::less<T>, 
	typename Allocator = std::allocator<T> 
> 
class binaryTree
{
public:
	
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef size_t size_type;				//<cstddef>
	typedef ptrdiff_t difference_type;		//<cstddef>
	//typedef NodeType* nodePointer;

	binaryTree()
	{
		initialize();
	}

	
	binaryTree(const binaryTree<T>& other)
	{
		
	}

	binaryTree<T>& operator=(const binaryTree<T>& other)
	{
		if (this == &other) 
		{
			return (*this);
		} 
		
		//...  
		
		return (*this);
	}

	virtual ~binaryTree()
	{
		//std::cout << "virtual ~binaryTree()" << std::endl;
		NodeType *iterator = this->getRoot();
		NodeType *parent = 0;

		while ( iterator != 0 && !isNil(iterator) )
		{
			if ( isNil(iterator->left_) && isNil(iterator->right_) )
			{
				parent = iterator->parent_;

				if (parent != 0)
				{
					if (parent->left_ == iterator)
					{
						parent->left_ = head_;
					}
					else
					{
						parent->right_ = head_;
					}
				}

				delete iterator;
				iterator = 0;
			
				if (parent != 0)
				{
					iterator = parent;
				}
			}
			else
			{
				if ( isNil(iterator->left_) )
				{
					iterator = iterator->right_;
				}
				else
				{
					iterator = iterator->left_;
				}
			}
			
		}
		
		delete head_;
		head_ = 0;
	}

	//void erase(const key_type& x);
	//value_type* find(const key_type& x);
	void insert(const T& data)
	{
		//NodeType *whereNode = getWhereToInsert(data);
		NodeType::pointer whereNode = getWhereToInsert(data);

		if ( isNil(whereNode) )	//root node
		{
			NodeType *newNode = new NodeType(data, details::Black);
			newNode->left_ = head_;
			newNode->right_ = head_;
			newNode->parent_ = head_;

			setRoot(newNode);
			getLMost() = newNode;	
			getRMost() = newNode;
		}
		else
		{
			NodeType *newNode = new NodeType(data);
			newNode->parent_ = whereNode;
			newNode->left_ = head_;
			newNode->right_ = head_;


			//if (whereNode->data_ < data)
			if ( comparator_(whereNode->data_, data) )
			{
				whereNode->right_ = newNode;
				if (whereNode == getRMost())
				{
					getRMost() = newNode;
				}
			}
			else //if (whereNode->data_ > data)
			{
				whereNode->left_ = newNode;
				if (whereNode == getLMost())
				{
					getLMost() = newNode;
				}
			}
			insertCase1(newNode);
		}
	}

	bool empty() const
	{
		//return (rootNode_ == 0);
		return ( head_->parent_ == head_);
		//return (getRoot() == 0);
	}

	//typename binaryTree<T>::size_type hashmap<Key, T, Compare, Hash>::size() const
	size_type size() const
	{
		// contar los items.
		//return (mSize);

		return 0;
	}

	size_type max_size() const
	{
		//return ((*mElems)[0].max_size());

		return 0;
	}

	void swap( binaryTree<T>& other )
	{
		
		std::swap(*this, other);
	}

	//NodeType::pointer& getRoot() const
	NodeType*& getRoot() const
	{
		return head_->parent_;
	}
	void setRoot(NodeType *newRootNode)
	{
		head_->parent_ = newRootNode;
	}

	//NodeType::pointer& getLMost() const
	NodeType*& getLMost() const
	{
		return head_->left_;
	}

	//NodeType::pointer& getRMost() const
	NodeType*& getRMost() const
	{
		return head_->right_;
	}


protected: 

	NodeType *head_;				
	Compare comparator_;

	bool isNil(NodeType *node) const			
	{
		return (node == head_);
	}

	void initialize()
	{
		this->head_ = new NodeType();
		this->head_->left_ = this->head_;
		this->head_->right_ = this->head_;
		this->head_->parent_ = this->head_;
		this->head_->nodeColor_ = details::Black;
	}

	//NodeType findMostLeft(const NodeType& start) const
	NodeType getMostLeft(const NodeType& start) const
	{
		//NodeType node = start;
	
		//while (true)
		//{
		//	if (node.left_ != 0)
		//	{
		//		node = node.left_;
		//		continue;
		//	}
		//	break;
		//}
		//return node;

		return getLMost();
	}

	void insertCase1(NodeType *node)
	{
		
		//if ( node->parent_ == 0 )
		if ( isNil(node->parent_) )
		{
			node->nodeColor_ = details::Black;
		}
		else
		{
			insertCase2(node);
		}
	}

	void insertCase2(NodeType *node)
	{
		if (node->parent_->nodeColor_ == details::Black)
		{
			return; /* Tree is still valid */
		}
		else
		{
			insertCase3(node);
		}

	}

	void insertCase3(NodeType *node)
	{
		NodeType *uncle = node->getUncle();

		if ( (!isNil(uncle)) && (uncle->nodeColor_ == details::Red) )
		{
			node->parent_->nodeColor_ = details::Black;
			uncle->nodeColor_ = details::Black;
			
			NodeType *grandParent = node->getGrandParent();
			grandParent->nodeColor_ = details::Red;
			insertCase1(grandParent);
		} 
		else 
		{
			insertCase4(node);
		}
	}

	void insertCase4(NodeType *node)
	{

		NodeType *grandParent = node->getGrandParent();
	 
		if ((node == node->parent_->right_) && (node->parent_ == grandParent->left_)) 
		{
			rotateLeft(node->parent_);
			node = node->left_;
		} 
		else if ((node == node->parent_->left_) && (node->parent_ == grandParent->right_)) 
		{
			rotateRight(node->parent_);
			node = node->right_;
		}
		insertCase5(node);

	}

	void insertCase5(NodeType *node)
	{
		NodeType *grandParent = node->getGrandParent();
	 
		node->parent_->nodeColor_ = details::Black;

		//if (grandParent != 0)
		if ( !isNil(grandParent) )
		{
			grandParent->nodeColor_ = details::Red;
		}

		//if ((node == node->parent_->left_) && (grandParent != 0) && (node->parent_ == grandParent->left_)) 
		if ((node == node->parent_->left_) && ( !isNil(grandParent) ) && (node->parent_ == grandParent->left_)) 
		{
			rotateRight(grandParent);
		} 
		else //Here, (node == node->parent->right) && (node->parent == grandParent->right).
		{
			rotateLeft(grandParent);
		}

	}

	void rotateLeft(NodeType *x)
	{
		NodeType *y = x->right_;

		x->right_ = y->left_;
		y->left_ = x;

		//if ( x->parent_ == 0 )
		if ( isNil(x->parent_) )
		{
			setRoot(y); //rootNode_ = y;
		}
		else
		{
			if ( x->parent_->left_ == x)
			{
				x->parent_->left_ = y;
			}
			else
			{
				x->parent_->right_ = y;
			}
		}
		y->parent_ = x->parent_;
		x->parent_ = y;

	}

	void rotateRight(NodeType *x)
	{
		NodeType *y = x->left_;

		x->left_ = y->right_;
		y->right_ = x;
		
		//if ( x->parent_ == 0 )
		if ( isNil(x->parent_) )
		{
			setRoot(y); //rootNode_ = y;
		}
		else
		{
			if ( x->parent_->right_ == x)
			{
				x->parent_->right_ = y;
			}
			else
			{
				x->parent_->left_ = y;
			}
		}
		y->parent_ = x->parent_;
		x->parent_ = y;

	}


	//NodeType::pointer getWhereToInsert(const T& data) //const
	NodeType* getWhereToInsert(const T& data) const
	{
		//NodeType *iterator = getRoot();
		NodeType::pointer iterator = getRoot();

		if ( isNil(iterator) )
		{
			return iterator;
		}

		while (true)
		{
			//if (iterator->data_ < data)
			if ( comparator_(iterator->data_, data) )
			{
				if ( isNil(iterator->right_) )
				{
					return iterator;
				}
				else
				{
					iterator = iterator->right_;
					continue;
				}
			}

			//if (iterator->data_ > data)
			if ( ! comparator_(iterator->data_, data) )
			{
				if ( isNil(iterator->left_) )
				{
					return iterator;
					break;	
				}
				else
				{
					iterator = iterator->left_;
					continue;
				}
			}
		}

		return 0;
	}
};

}

#endif //BINARY_TREE_HPP





/*template <typename T> //typename Allocator = allocator<T>
class binaryTree;



template<typename T>
class binaryTree_iterator : public std::iterator<std::bidirectional_iterator_tag, T >
{
public:

	binaryTree_iterator()
	{
		it_ = 0;			//list<pair<const Key, T> >::iterator();
		binaryTree_ = 0;	//mHashmap = NULL;
	}

	//binaryTree_iterator(int bucket, typename list<pair<const Key, T> >::iterator listIt, const binaryTree<T>* inbinaryTree);
	//template<typename Key, typename T, typename Compare, typename Hash>
	//HashIterator<Key, T, Compare, Hash>::HashIterator(
	//int bucket, typename list<pair<const Key, T> >::iterator listIt,
	//const hashmap<Key, T, Compare, Hash>* inHashmap) :
	//mBucket(bucket), mIt(listIt), mHashmap(inHashmap)
	//{
	//}

	T& operator*() const
	{
		return (*it_);
	}

	// Return type must be something to which -> can be applied.
	// Return a pointer to a T, to which the compiler will
	// apply -> again.
	T* operator->() const
	{
		return (&(*it_));
	}

	binaryTree_iterator<T>& operator++()
	{
		increment();
		return (*this);
	}

	const binaryTree_iterator<T> operator++(int)
	{
		binaryTree_iterator<T> oldIt = *this;
		increment();
		return (oldIt);
	}

	//binaryTree_iterator<T>& operator--()
	//{
	//	decrement();
	//	return (*this);
	//}


	//const binaryTree_iterator<T> operator--(int)
	//{
	//	binaryTree_iterator<T> newIt = *this;
	//	decrement();
	//	return (newIt);
	//}

	bool operator==(const binaryTree_iterator& rhs) const;
	bool operator!=(const binaryTree_iterator& rhs) const;
protected:
	//typename list<pair<const Key, T> >::iterator it_;
	T* it_;
	const binaryTree<T>* binaryTree_;

	// Helper methods for operator++ and operator--
	void increment()
	{
		
	}

	void decrement();
};*\
