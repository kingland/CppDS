
template<typename T, typename TraitsForT>
class HashTable {

constructor:
	HashTable()
	HashTable(usize capacity)
	HashTable(const HashTable& other)
	HashTable(HashTable&& other)
	
deconstructor:	
	 ~HashTable()
	 
public:
	bool is_empty() const
	usize size() const
	usize capacity() const
	void ensure_capacity(usize capacity)
	
	HashSetResult set(const T&);
    HashSetResult set(T&&);
	
	template<typename U, usize N>
    void set_from(U (&from_array)[N])
	
	bool contains(const T&) const;	
	void clear();
	
	Iterator begin() 
	Iterator end() 
	
	ConstIterator begin() const
	ConstIterator end() const 
	
	template<typename Finder>
    Iterator find(unsigned hash, Finder finder)
	
	template<typename Finder>
    ConstIterator find(unsigned hash, Finder finder) const
	
	Iterator find(const T& value)
	ConstIterator find(const T& value) const
	
	bool remove(const T& value)
	void remove(Iterator);	
	
operator:
	HashTable& operator=(const HashTable& other)
	HashTable& operator=(HashTable&& other)
	
private:
    Bucket& lookup(const T&, usize* bucket_index = nullptr);
    const Bucket& lookup(const T&, usize* bucket_index = nullptr) const;
	Bucket& lookup_with_hash(unsigned hash, usize* bucket_index)
	const Bucket& lookup_with_hash(unsigned hash, usize* bucket_index) const
	
	void rehash(usize capacity);
    void insert(const T&);
    void insert(T&&);
	
	Bucket& bucket(usize index)
	const Bucket& bucket(usize index) const
}