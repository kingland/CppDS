template<typename T, usize Capacity>
class CircularQueue {

constructor:
	CircularQueue()
	
deconstructor:
	~CircularQueue()
	
public:
	void clear()
	bool is_empty() const 
	usize size() const 
	usize capacity() const
	void enqueue(T&& value)
	void enqueue(const T& value)
	T dequeue()
	const T& at(usize index) const
	const T& first() const 
	const T& last() const	
	ConstIterator begin() const
	ConstIterator end() const	
	usize head_index()
	
protected:
	T* elements()
	const T* elements() const 

friend:	
	friend class ConstIterator;
	
}


template<typename T, usize Capacity>
class CircularDeque : CircularQueue<T, Capacity> {

public:
	void enqueue_begin(T&& value)
	void enqueue_begin(const T& value)
	T dequeue_end()
}