class ByteArrayMatcher {
constructor:
	ByteArrayMatcher();
    explicit ByteArrayMatcher(const ByteArray &pattern);
    explicit ByteArrayMatcher(const char *pattern, usize length);
    ByteArrayMatcher(const ByteArrayMatcher &other);
	
deconstructor:
	~ByteArrayMatcher();
	 
public:
	void setPattern(const ByteArray &pattern);
	isize index_in(const ByteArray &ba, isize from = 0) const;
    isize index_in(const char *str, isize len, isize from = 0) const;
	inline ByteArray get_pattern() const
	
	
operator:
	ByteArrayMatcher &operator=(const ByteArrayMatcher &other);
	

private:
	ByteArrayMatcherPrivate *m_impl;
    ByteArray m_pattern;
    struct Data
    {
        ubyte m_skiptable[256];
        const ubyte *m_ptr;
        usize m_len;
    };
    union
    {
        uint  m_dummy[256];
        Data m_data;
    };
}


class StaticByteArrayMatcherBase {
constructor:
deconstructor:

protected:
	explicit constexpr StaticByteArrayMatcherBase(const char *pattern, uint n) noexcept
	int index_of_in(const char *needle, uint nlen, const char *haystack, int hlen, int from) const noexcept;
	
private:
static:
	static constexpr Skiptable generate(const char *pattern, uint n) noexcept
	
}


template <uint N>
class StaticByteArrayMatcher : StaticByteArrayMatcherBase {
	
constructor:
	explicit StaticByteArrayMatcher(const char (&patternToMatch)[N]) noexcept //PDK_DECL_RELAXED_CONSTEXPR
	
deconstructor:

public:
	int index_in(const ByteArray &haystack, int from = 0) const noexcept
	int index_in(const char *haystack, int hlen, int from = 0) const noexcept
}

constexpr StaticByteArrayMatcher<N> cm_make_static_byte_array_matcher(const char (&pattern)[N]) noexcept