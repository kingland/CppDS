template<typename T>
class DoublyLinkedList {
	
constructor:
	DoublyLinkedList()

deconstructor:
	~DoublyLinkedList()
	
public:
	bool is_empty() const 
	void clear()
	T& first()
	const T& first()
	T& last()
	const T& last() const
	void append(T&& value)
	void append(const T& value)
	void prepend(T&& value)
	void prepend(const T& value)
	bool contains_slow(const T& value) const
	
	Iterator begin() 
	Iterator end() 
	
	ConstIterator begin() const
	ConstIterator end() const
	
	ConstIterator find(const T& value) const
	Iterator find(const T& value)
 
	void remove(Iterator it)
	
private:
	void append_node(Node* node)
	void prepend_node(Node* node)
	Node* head()
	const Node* head() 
	Node* tail()
	const Node* tail()
}



template<typename T, typename ET>
class DoublyLinkedListIterator {
	
public :
	bool is_end() const 
	
operator:
	DoublyLinkedListIterator& operator++()
	bool operator!=(const DoublyLinkedListIterator& other) const
	bool operator==(const DoublyLinkedListIterator& other) const
	ET& operator*()
	ET* operator->() 

static:
	static DoublyLinkedListIterator universal_end()
	
}