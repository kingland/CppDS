template<typename K, typename V, typename KeyTraits>
class HashMap {
	
constructor:
	HashMap()
	
deconstructor:
	
public:
	bool is_empty() const 
	usize size() const
	usize capacity() const
	void clear()
	
	HashSetResult set(const K& key, const V& value)
	HashSetResult set(const K& key, V&& value)
	
	bool remove(const K& key)
	void remove_one_randomly() 
	
	IteratorType begin()
	IteratorType end() 
	IteratorType find(const K& key)	
	template<typename Finder>
    IteratorType find(unsigned hash, Finder finder)
	
	ConstIteratorType begin() const 
	ConstIteratorType end() const 
	ConstIteratorType find(const K& key) const
	template<typename Finder>
    ConstIteratorType find(unsigned hash, Finder finder) const
	
	void ensure_capacity(usize capacity) 
	Optional<typename Traits<V>::PeekType> get(const K& key) const
	bool contains(const K& key) const
	void remove(IteratorType it)	
	V& ensure(const K& key)
	Vector<K> keys() const	
	
}