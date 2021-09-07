class BitArray {  
constructor:
	inline BitArray() noexcept
	explicit BitArray(int size, bool value = false);
	BitArray(const BitArray &other)
	inline BitArray(BitArray &&other) noexcept	
	
deconstructor:

public:
	inline void swap(BitArray &other) noexcept
	inline usize size() const
	usize count(bool on) const;
	inline bool is_empty() const
	inline bool is_null() const
	void resize(isize size);
	inline void detach()
	inline bool is_detached() const
	inline void clear()
	bool test_bit(isize i) const;
    void set_bit(isize i);
    void set_bit(isize i, bool value);
	inline void clear_bit(isize i);
    bool toggle_bit(isize i);
    bool at(isize i) const;
	inline bool fill(bool value, int size = -1);
    void fill(bool value, int first, int last);
    inline void truncate(int pos)
	inline DataPtr &get_data_ptr()
	
    

operator:
	inline BitArray &operator=(const BitArray &other)	
	inline BitArray &operator=(BitArray &&other) noexcept
	BitRef operator[](isize i);
    bool operator[](isize i) const;
    BitRef operator[](usize i);
    bool operator[](usize i) const;
	BitArray &operator&=(const BitArray &);
    BitArray &operator|=(const BitArray &);
    BitArray &operator^=(const BitArray &);
    BitArray operator~() const;
	inline bool operator==(const BitArray &other) const
	inline bool operator!=(const BitArray &other) const

}

class BitRef {
private:
constructor:
	inline BitRef(BitArray &array, usize idx)
	
public:

operator:
	inline operator bool() const
	inline bool operator!() const
	BitRef &operator=(const BitRef &value)
	BitRef &operator=(bool value)
}

BitArray operator&(const BitArray &, const BitArray &);
BitArray operator|(const BitArray &, const BitArray &);
BitArray operator^(const BitArray &, const BitArray &);


inline void swap(ds::BitArray &lhs, ds::BitArray &rhs) noexcept(noexcept(lhs.swap(rhs)))

