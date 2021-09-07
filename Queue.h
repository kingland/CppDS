
template<typename T, usize segment_size = 1000>
class Queue {

constructor:
	Queue()

deconstructor:
	~Queue()

public:
	usize size() const
	bool is_empty() const
	void enqueue(T&& value)
	void enqueue(const T& value)
	T dequeue()
	const T& head() const
	void clear()
}