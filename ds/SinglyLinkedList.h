template<typename T>
class SinglyLinkedList {

constructor:
	SinglyLinkedList() 
	
deconstructor:
	~SinglyLinkedList()
	
public:
	bool is_empty() const
	inline usize size_slow()
	void clear()
	T& first()
	const T& first() const
	T& last()
	const T& last() const
	T take_first()
	void append(const T& value)
	void append(T&& value)
	bool contains_slow(const T& value) const
	
	Iterator begin() 
	Iterator end()	
	ConstIterator begin() const 
	ConstIterator end() const
	
	ConstIterator find(Finder finder) const	
	template<typename Finder>
    Iterator find(Finder finder)
	ConstIterator find(const T& value) const
	Iterator find(const T& value)
	
	void remove(Iterator iterator)
	void insert_before(Iterator iterator, const T& value)
	void insert_before(Iterator iterator, T&& value)
	void insert_after(Iterator iterator, const T& value)
	void insert_after(Iterator iterator, T&& value)
	
private:
	Node* head()
	const Node* head()
	Node* tail()
	const Node* tail() const
}