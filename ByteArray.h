class ByteArray {

constructor:
	inline ByteArray() noexcept;
	ByteArray(const char *data, isize size = -1);
	ByteArray(isize size, char c);
	ByteArray(isize size, Initialization);
	inline ByteArray(const ByteArray &data) noexcept;
	inline ByteArray(ByteArrayDataPtr dataPtr);
	inline ByteArray(ByteArray &&other) noexcept;
	
deconstructor:
	inline ~ByteArray();

public:
	inline void swap(ByteArray &other) noexcept
	inline usize size() const;
	inline bool is_empty() const;
	void resize(isize size);
	ByteArray &fill(char c, isize size = -1);
	inline usize capacity() const;
	inline void reserve(usize size);
	inline void squeeze();
	char *get_raw_data();
	const char *get_raw_data() const;
	inline const char *get_const_raw_data() const;
	inline void detach();
	inline bool is_detached() const;
	inline bool is_shared_with(const ByteArray &other) const;
	void clear();
	inline char at(usize i) const;
	char front() const
	inline ByteRef front();
	char back() const
	inline ByteRef back();
	isize index_of(char needle, isize from = 0) const;
	isize index_of(const char *needle, isize from = 0) const;
	isize index_of(const ByteArray &needle, isize from = 0) const;
	isize last_index_of(char needle, isize from = -1) const;
	isize last_index_of(const char *needle, isize from = -1) const;
	isize last_index_of(const ByteArray &needle, isize from = -1) const;
	inline bool contains(char c) const;
	inline bool contains(const char *array) const;
	inline bool contains(const ByteArray &array) const;
	usize count(char c) const;
	usize count(const char *array) const;
	usize count(const ByteArray &array) const;
	ByteArray left(isize length) const;
	ByteArray right(isize length) const;
	ByteArray mid(isize index, isize length = -1) const;
	ByteArray chopped(int len) const
	ByteArray chopped(isize len) const
	bool starts_with(const ByteArray &array) const;
	bool starts_with(char c) const;
	bool starts_with(const char *str) const;
	bool ends_with(const ByteArray &array) const;
	bool ends_with(const char c) const;
	bool ends_with(const char *str) const;
	void truncate(isize pos);
	void chop(isize n);

	ByteArray to_lower() const & -> TODO:
	ByteArray to_lower() const && -> TODO:
	ByteArray to_upper() const & -> TODO:
	ByteArray to_upper() const && -> TODO:
	ByteArray trimmed() const & -> TODO:
	ByteArray trimmed() const && -> TODO: 
	ByteArray simplified() const & -> TODO:
	ByteArray simplified() const && -> TODO:

	ByteArray left_justified(isize width, char fill = ' ', bool truncate = false) const;
	ByteArray right_justified(isize width, char fill = ' ', bool truncate = false) const;
	ByteArray &prepend(char c);
	inline ByteArray &prepend(int count, char c);
	ByteArray &prepend(const char *str);
	ByteArray &prepend(const char *str, usize length);
	ByteArray &prepend(const ByteArray &array);
	ByteArray &append(char c);
	inline ByteArray &append(int count, char c);
	ByteArray &append(const char *str);
	ByteArray &append(const char *str, usize length);
	ByteArray &append(const ByteArray &array);
	ByteArray &insert(isize pos, char c);
	ByteArray &insert(isize pos, isize count, char c);
	ByteArray &insert(isize pos, const char *str);
	ByteArray &insert(isize pos, const char *str, isize length);
	ByteArray &insert(isize pos, const ByteArray &array);
	ByteArray &remove(usize index, isize length);
	ByteArray &replace(usize index, isize length, const char *after);
	ByteArray &replace(usize index, isize length, const char *after, isize alength);
	ByteArray &replace(usize index, isize length, const ByteArray &after);
	inline ByteArray &replace(char before, const char *after);
	ByteArray &replace(char before, const ByteArray &after);
	inline ByteArray &replace(const char *before, const char *after);
	ByteArray &replace(const char *before, usize blength, const char *after, usize alength);
	ByteArray &replace(const ByteArray &before, const ByteArray &after);
	inline ByteArray &replace(const ByteArray &before, const char *after);
	ByteArray &replace(const char *before, const ByteArray &after);
	ByteArray &replace(char before, char after);
	inline ByteArray &operator+=(char c);
	inline ByteArray &operator+=(const char *str);
	inline ByteArray &operator+=(const ByteArray &array);
	std::list<ByteArray> split(char sep) const;
	ByteArray repeated(int times) const;

	i16 to_short(bool *ok = nullptr, int base = 10) const; -> TODO:
	u16 to_ushort(bool *ok = nullptr, int base = 10) const; -> TODO:
	i32 to_int(bool *ok = nullptr, int base = 10) const; -> TODO:
	u32 to_uint(bool *ok = nullptr, int base = 10) const; -> TODO:
	i64 to_long(bool *ok = nullptr, int base = 10) const; -> TODO: 
	u64 to_ulong(bool *ok = nullptr, int base = 10) const; -> TODO:
	plonglong toLongLong(bool *ok = nullptr, int base = 10) const; -> TODO:
	pulonglong toULongLong(bool *ok = nullptr, int base = 10) const; -> TODO:
	float to_float(bool *ok = nullptr) const; -> TODO:
	double to_double(bool *ok = nullptr) const; -> TODO:


	ByteArray to_base64(Base64Options options = Base64Encoding) const;
	ByteArray to_hex(char separator = '\0') const;
	ByteArray to_percent_encoding(const ByteArray &exclude = ByteArray(),
								 const ByteArray &include = ByteArray(),
								 char percent = '%') const;
							 
	inline ByteArray &set_num(i16, int base = 10); -> TODO:
	inline ByteArray &set_num(u16, int base = 10); -> TODO:
	inline ByteArray &set_num(i32, int base = 10); -> TODO:
	inline ByteArray &set_num(u32, int base = 10); -> TODO:
	inline ByteArray &set_num(i64, int base = 10); -> TODO:
	inline ByteArray &set_num(u64, int base = 10); -> TODO: 
	ByteArray &setNum(pdk::plonglong, int base = 10); -> TODO: 
	ByteArray &setNum(pdk::pulonglong, int base = 10);  -> TODO:
	inline ByteArray &set_num(float, char f = 'g', int prec = 6); -> TODO:
	ByteArray &set_num(double, char f = 'g', int prec = 6); -> TODO:	

	inline void push_back(char c);
	inline void push_back(const char *c);
	inline void push_back(const ByteArray &array);
	inline void push_front(char c);
	inline void push_front(const char *c);
	inline void push_front(const ByteArray &array);
	void shrink_to_fit()
	inline std::string to_std_string() const;
	inline usize length() const
	bool is_null() const;
	inline DataPtr &get_data_ptr()
	
	CFDataRef to_cf_data() const ; -> TODO:
	CFDataRef to_raw_cf_data() const ; -> TODO:
	NSData *to_ns_data() const ; -> TODO:
	NSData *to_raw_ns_data() const ; -> TODO:

static:	
	static ByteArray number(i32, int base = 10); -> TODO:
	static ByteArray number(u32, int base = 10); -> TODO:
	static ByteArray number(pdk::plonglong, int base = 10); -> TODO:	 
	static ByteArray number(pdk::pulonglong, int base = 10); -> TODO:
	static ByteArray number(double, char f = 'g', int prec = 6); -> TODO:
	static ByteArray from_raw_data(const char *, isize size);	
	static ByteArray from_base64(const ByteArray &base64, Base64Options options = Base64Encoding);
	static ByteArray from_hex(const ByteArray &hexEncoded);
	static ByteArray from_percent_encoding(const ByteArray &pctEncoded, char percent = '%');
	static inline ByteArray from_std_string(const std::string &str);	

	static ByteArray from_cf_data(CFDataRef data); -> TODO:
	static ByteArray from_raw_cf_data(CFDataRef data); -> TODO:
	static ByteArray from_ns_data(const NSData *data); -> TODO:
	static ByteArray from_raw_ns_data(const NSData *data); -> TODO:

operator:
	ByteArray &operator=(const ByteArray &other) noexcept;
	ByteArray &operator=(const char *str);
	inline ByteArray &operator=(ByteArray &&other) noexcept
	inline operator const char *() const;
	inline operator const void *() const;
	inline char operator[](isize i) const;
	inline char operator[](usize i) const;   
	inline ByteRef operator[](isize i);
	inline ByteRef operator[](usize i);
	
	
private:
	void realloc_data(usize alloc, Data::AllocationOptions options);
	void expand(isize i);
	ByteArray get_null_terminated() const;

static:
	static ByteArray to_lower_helper(const ByteArray &a); -> TODO:
	static ByteArray to_lower_helper(ByteArray &a); -> TODO:
	static ByteArray to_upper_helper(const ByteArray &a); -> TODO:
	static ByteArray to_upper_helper(ByteArray &a);-> TODO: 
	static ByteArray trimmed_helper(const ByteArray &a);-> TODO: 
	static ByteArray trimmed_helper(ByteArray &a); -> TODO:
	static ByteArray simplified_helper(const ByteArray &a); -> TODO:
	static ByteArray simplified_helper(ByteArray &a);-> TODO: 
	
friend:
	friend class ByteRef;
	friend class String;

}

using ArrayDataOfChar = ArrayDataOf<char>;
using DataPtr = ArrayDataOfChar *;


class ByteRef {

constructor:
	ByteRef(ByteArray &array, usize index)
	
operator:
	inline operator char() const
	inline ByteRef &operator=(char c)
	inline ByteRef &operator=(const ByteRef &c)
	inline bool operator==(char c) const
	inline bool operator!=(char c) const
	inline bool operator>(char c) const
	inline bool operator>=(char c) const
	inline bool operator<=(char c) const
	inline bool operator<(char c) const

private:
friend:
		friend class ByteArray;
}


struct ArrayData
{
	RefCount m_ref;
    usize m_size;
    usize m_alloc : 31;
    usize m_capacityReserved : 1;
    ptrdiff m_offset;   
	
	enum AllocationOption{
	}
	
	void *get_data()
	const void *get_data() const
	bool is_mutable() const
	usize detach_capacity(usize newSize) const
	AllocationOptions detach_flags() const
	AllocationOptions clone_flags() const
	
static:
	static const ArrayData sm_sharedNull[2];
	
	static ArrayData *allocate(usize objectSize,
                               usize alignment,
                               usize capacity,
                               AllocationOptions options = Default) noexcept;
							   
	static ArrayData *reallocate_unaligned(ArrayData *data,
                                           usize objectSize,
                                           usize capacity,
                                           AllocationOptions options = Default) noexcept;
										   
										   
	static void deallocate(ArrayData *data,
                           usize objectSize,
                           usize alignment) noexcept;
						   
	static ArrayData *get_shared_null() noexcept
}

template <typename T>
struct ArrayDataOf : ArrayData {
	inline T *get_data()
	inline const T *get_data() const
	Iterator begin(Iterator = Iterator())
	Iterator end(Iterator = Iterator())
	ConstIterator begin(ConstIterator = ConstIterator()) const
	ConstIterator end(ConstIterator = ConstIterator()) const
	ConstIterator cbegin() const
	ConstIterator cend() const
}

template <typename T, usize N>
struct StaticArrayData {
	ArrayData m_header;
    T m_data[N];
}

struct ContainerImplHelper {
	enum class CutResult 
    {
        Null, Empty, Full, Subset 
    };
   
    static CutResult mid(usize originalLength, isize *position, isize *length);
}

inline constexpr Flags<ByteArray::Base64Options> operator|(ByteArray::Base64Options flag1, ByteArray::Base64Options flag2) noexcept
inline constexpr Flags<ByteArray::Base64Options> operator|(ByteArray::Base64Options flag1, Flags<ByteArray::Base64Options> flag2) noexcept
inline constexpr IncompatibleFlag operator|(ByteArray::Base64Options flag1, i32 flag2) noexcept
inline bool operator==(const ByteArray &lhs, const ByteArray &rhs) noexcept
inline bool operator==(const ByteArray &lhs, const char *rhs) noexcept
inline bool operator==(const char *lhs, const ByteArray &rhs) noexcept
inline bool operator!=(const ByteArray &lhs, const ByteArray &rhs) noexcept
inline bool operator!=(const ByteArray &lhs, const char *rhs) noexcept
inline bool operator!=(const char *lhs, const ByteArray &rhs) noexcept
inline bool operator<(const ByteArray &lhs, const ByteArray &rhs) noexcept
inline bool operator<(const ByteArray &lhs, const char *rhs) noexcept
inline bool operator<(const char *lhs, const ByteArray &rhs) noexcept
inline bool operator<=(const ByteArray &lhs, const ByteArray &rhs) noexcept
inline bool operator<=(const ByteArray &lhs, const char *rhs) noexcept
inline bool operator<=(const char *lhs, const ByteArray &rhs) noexcept
inline bool operator>(const ByteArray &lhs, const ByteArray &rhs) noexcept
inline bool operator>(const ByteArray &lhs, const char *rhs) noexcept
inline bool operator>(const char *lhs, const ByteArray &rhs) noexcept
inline bool operator>=(const ByteArray &lhs, const ByteArray &rhs) noexcept
inline bool operator>=(const ByteArray &lhs, const char *rhs) noexcept
inline bool operator>=(const char *lhs, const ByteArray &rhs) noexcept
inline const ByteArray operator+(const ByteArray &lhs, const ByteArray &rhs)
inline const ByteArray operator+(const ByteArray &lhs, const char *rhs)
inline const ByteArray operator+(const ByteArray &lhs, char rhs)
inline const ByteArray operator+(const char *lhs, const ByteArray &rhs)
inline const ByteArray operator+(char lhs, const ByteArray &rhs)

inline void swap(ds::ByteArray &lhs, ds::ByteArray &rhs) noexcept(noexcept(lhs.swap(rhs)))

inline int strcmp(const ds::ByteArray &lhs, const ds::ByteArray &rhs);
inline int strcmp(const ds::ByteArray &lhs, const char *rhs);
inline int strcmp(const char *lhs, const ds::ByteArray &rhs);