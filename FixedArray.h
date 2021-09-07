template<typename T>
class FixedArray {
constructor:
	FixedArray()
	explicit FixedArray(size_t size)
	FixedArray(const FixedArray& other)
	
	FixedArray(FixedArray&&) = delete;
	FixedArray& operator=(FixedArray&&) = delete;
	
deconstructor:
	~FixedArray()

public:
	void clear()
	usize size() const 
	T* data()
	const T* data() const
	Bytes bytes() -> Span<u8>:
	ConstBytes bytes() const
	void resize(usize new_size)
	bool contains(const T& value) const
	void swap(FixedArray& other)
	
	Iterator begin() 
	Iterator end() 
	ConstIterator begin() const
	ConstIterator end() const
	
	
operator:
	FixedArray& operator=(const FixedArray& other)
	T& operator[](usize index)
	const T& operator[](usize index) const
	operator Bytes()
	operator ConstBytes() const
}