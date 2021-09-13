template<typename T, usize inline_capacity=10>
class Vector {

constructor:
	Vector()
	Vector(Vector&& other)
	Vector(const Vector& other)
	
	template<usize other_inline_capacity>
    Vector(const Vector<T, other_inline_capacity>& other)
	
	Vector(const T* d, usize size) 
	
deconstructor:
	~Vector()
	
public:	
	Span<T> span()
	Span<const T> span() const
	void clear()
	void clear_with_capacity()	
	bool contains_slow(const T& value) const
	bool is_null() const 
	bool is_empty() const 
	inline usize size() const 
	usize capacity() const
	T* data()
	const T* data() const
	inline const T& at(usize i) const
	inline T& at(usize i)
	const T& first() const
	T& first()
	const T& last() const 
	T& last()
	T take_last()
	T take_first()
	T take(usize index)
	T unstable_take(usize index)
	void remove(usize index)
	void insert(usize index, T&& value)
	void insert(usize index, const T& value)
	
	template<typename C>
    void insert_before_matching(T&& value, C callback, usize first_index = 0, usize* inserted_index = nullptr)

	void append(Vector&& other)
	void append(const Vector& other)
	
	template<typename Callback>
    void remove_first_matching(Callback callback)
	
	template<typename Callback>
    void remove_all_matching(Callback callback)
	
	inline void unchecked_append(T&& value)
	inline void unchecked_append(const T& value)
	
	template<class... Args>
    void empend(Args&&... args)
	
	inline void append(T&& value)
	inline void append(const T& value)
	void prepend(T&& value)
	void prepend(const T& value)
	void prepend(Vector&& other)
	void append(const T* values, usize count)
	void grow_capacity(usize needed_capacity)
	void ensure_capacity(usize needed_capacity)
	void shrink(usize new_size, bool keep_capacity = false)
	void resize(usize new_size, bool keep_capacity = false)
	void resize_and_keep_capacity(usize new_size)
	
	template <typename S>
    static constexpr Vector<T> vcast(Vector<S> input)
	
	Iterator begin()
	Iterator end() 
	
	ConstIterator begin() const
	ConstIterator end() const
	
	template<typename Finder>
    ConstIterator find(Finder finder) const	
	template<typename Finder>
    Iterator find(Finder finder)
	ConstIterator find(const T& value) const
	Iterator find(const T& value)
	Optional<usize> find_first_index(const T& value)
	
operator:	
	Vector& operator=(Vector&& other)
	bool operator==(const Vector& other) const
	bool operator!=(const Vector& other) const
	operator Span<T>()
	operator Span<const T>() const
	inline const T& operator[](usize i) const
	inline T& operator[](usize i)
	Vector& operator=(const Vector& other)
	
	template<usize other_inline_capacity>
    Vector& operator=(const Vector<T, other_inline_capacity>& other)
	
private:
	void reset_capacity()
	static usize padded_capacity(usize capacity)
	T* slot(usize i)
	const T* slot(usize i) const 
	T* inline_buffer()
	const T* inline_buffer() const
	
}