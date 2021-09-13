

class StringView {

constructor:
	constexpr StringView() noexcept
	explicit constexpr StringView(std::nullptr_t) noexcept
	
	template <typename Char, if_compatible_char<Char> = true>
    explicit constexpr StringView(const Char *str, usize len)
	
	template <typename Char, if_compatible_char<Char> = true>
    explicit constexpr StringView(const Char *f, const Char *l)
	
	template <typename Array, if_compatible_array<Array> = true>
    explicit constexpr StringView(const Array &str) noexcept
	
	template <typename Pointer, if_compatible_pointer<Pointer> = true>
    explicit constexpr StringView(const Pointer &str) noexcept
	
	template <typename String, if_compatible_qstring_like<String> = true>
    StringView(const String &str) noexcept
	
	template <typename StdBasicString, if_compatible_string<StdBasicString> = true>
    explicit StringView(const StdBasicString &str) noexcept
	
deconstructor:

public:
	inline String to_string() const;
	constexpr usize size() const noexcept
	const_pointer data() const noexcept
	constexpr const storage_type *utf16() const noexcept
	ByteArray to_latin1() const
	ByteArray to_utf8() const
	ByteArray to_local_8bit() const
	inline std::vector<uint> to_ucs4() const;
	Character at(usize n) const
	StringView substring(usize pos) const
	StringView substring(usize pos, usize n) const
	StringView left(usize n) const
	StringView right(usize n) const
	StringView chopped(usize n) const
	void truncate(usize n)
	void chop(usize n)
	StringView trimmed() const noexcept
	bool starts_with(StringView s,
                     cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept
	inline bool starts_with(Latin1String s,
                            cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept;	
	bool starts_with(Character c) const noexcept
	bool starts_with(Character c, 
					cm::CaseSensitivity cs) const noexcept
	bool ends_with(StringView s,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept
	inline bool ends_with(Latin1String s,
                          cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept;
	bool ends_with(Character c) const noexcept
	bool ends_with(Character c, pdk::CaseSensitivity cs) const noexcept
	const_iterator begin() const noexcept
	const_iterator end() const noexcept
	const_iterator cbegin() const noexcept
	const_iterator cend() const noexcept
	const_reverse_iterator rbegin() const noexcept
	const_reverse_iterator rend() const noexcept
	const_reverse_iterator crbegin() const noexcept
	const_reverse_iterator crend() const noexcept
	bool empty() const noexcept
	Character front() const
	Character back() const
	bool is_null() const noexcept
	bool is_empty() const noexcept
	int length() const
	Character first() const
	Character last() const
	
operator:
	constexpr Character operator[](pdk::sizetype n) const
	
}

template <typename StringLike, typename std::enable_if<std::is_same<StringLike, String>::value || std::is_same<StringLike, StringRef>::value, bool>::type = true>
inline StringView to_string_view_ignoring_null(const StringLike &s) noexcept