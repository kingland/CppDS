class Latin1String {

constructor:
	constexpr inline Latin1String() noexcept
	constexpr inline explicit Latin1String(const char *str) noexcept
	constexpr explicit Latin1String(const char *f, const char *l)
	constexpr inline explicit Latin1String(const char *str, int size) noexcept
	inline explicit Latin1String(const ByteArray &str) noexcept
	
deconstructor:

public:
	constexpr const char *latin1() const noexcept
	constexpr int size() const noexcept
	constexpr const char *raw_data() const noexcept
	constexpr bool is_null() const noexcept
	constexpr bool is_empty() const noexcept
	constexpr Latin1Character at(int i) const
	constexpr Latin1Character front() const
	constexpr Latin1Character back() const
	bool starts_with(StringView s,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept
	bool starts_with(Latin1String s,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept
	constexpr bool starts_with(Character c) const noexcept
	inline bool starts_with(Character c, cm::CaseSensitivity cs) const noexcept
	bool ends_with(StringView s,
                  cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept
	bool ends_with(Latin1String s,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept
	constexpr bool ends_with(Character c) const noexcept
	inline bool ends_with(Character c, cm::CaseSensitivity cs) const noexcept
	constexpr const_iterator begin() const noexcept
	constexpr const_iterator cbegin() const noexcept
	constexpr const_iterator end() const noexcept
	constexpr const_iterator cend() const noexcept
	const_reverse_iterator rbegin() const noexcept
	const_reverse_iterator crbegin() const noexcept
	const_reverse_iterator rend() const noexcept
	const_reverse_iterator crend() const noexcept
	constexpr Latin1String substring(int pos) const
	constexpr Latin1String substring(int pos, int n) const
	constexpr Latin1String left(int n) const
	constexpr Latin1String right(int n) const
	constexpr Latin1String chopped(int n) const
	void chop(int n)
	void truncate(int n)
	Latin1String trimmed() const noexcept
	
operator:	
	constexpr Latin1Character operator[](int i) const
	inline bool operator==(const String &str) const noexcept;
    inline bool operator!=(const String &str) const noexcept;
    inline bool operator>(const String &str) const noexcept;
    inline bool operator<(const String &str) const noexcept;
    inline bool operator>=(const String &str) const noexcept;
    inline bool operator<=(const String &str) const noexcept;
	
}


class String {

constructor:
	inline String() noexcept;
    explicit String(const Character *unicode, int size = -1);
    String(Character c);
    String(int size, Character c);
    inline String(Latin1String other);
    template <int N>
    inline String(const char (&str)[N])
	inline String(const String &other) noexcept;   
	String(int size, cm::Initialization);
    constexpr inline String(StringDataPtr dataPtr);
	inline String(String &&other) noexcept
	
	String(const char *str) = delete;
    String(const ByteArray &str) = delete;
	
deconstructor:
	inline ~String();
	
public:
	inline void swap(String &other) noexcept
	inline int size() const
	inline bool is_null() const
	bool is_simple_text() const;
    bool is_right_to_left() const;
	inline int length() const;
    inline bool is_empty() const;
    void resize(int size);
    void resize(int size, Character fillChar);
    String &fill(Character c, int size = -1);
    void truncate(int pos);
    void chop(int n);
    int capacity() const;
    inline void reserve(int size);
    inline void squeeze();
	inline const Character *unicode() const;
    inline Character *raw_data();
    inline const Character *raw_data() const;
    inline const Character *const_raw_data() const;
    inline void detach();
    inline bool is_detached() const;
    inline bool is_shared_with(const String &other) const
	
	String left(int n) const;
	String right(int n) const;
	String substring(int pos, int n = -1) const;
	
	String chopped(int n) const
	StringRef left_ref(int n) const;
	StringRef right_ref(int n) const;
	StringRef substring_ref(int pos, int n = -1) const;
	
	String to_lower() const &
	String to_lower() &&
	String to_upper() const &
	String to_upper() &&
	String to_case_folded() const &
	String to_case_folded() &&
	String trimmed() const &
	String trimmed() &&
	String simplified() const &
	String simplified() &&
	String to_html_escaped() const;
	
	String &insert(int i, Character c);
	String &insert(int i, const Character *str, int length);
	inline String &insert(int i, const String &str)
	inline String &insert(int i, const StringRef &str);
    String &insert(int i, Latin1String str);
	
	String &append(Character ch);
    String &append(const Character *str, int length);
    String &append(const String &str);
    String &append(const StringRef &str);
    String &append(Latin1String str);
	
	inline String &prepend(Character c)
	inline String &prepend(const Character *str, int length)
	inline String &prepend(const String &str)
	inline String &prepend(const StringRef &str)
	inline String &prepend(Latin1String str)
	
	String &replace(const RegularExpression &regex, const String &after);
    inline String &remove(const RegularExpression &regex)
	
	String repeated(int times) const;
    const uchar16 *utf16() const;
	ByteArray to_latin1() const &
	ByteArray to_latin1() &&
	ByteArray to_utf8() const &
	ByteArray to_utf8() &&
	ByteArray to_local_8bit() const &
	ByteArray to_local_8bit() &&
	std::vector<char32_t> to_ucs4() const;
	inline int to_wchar_array(wchar_t *array) const;
	String &set_raw_data(const Character *str, int size);
    String &set_unicode(const Character *str, int size);
    inline String &set_utf16(const uchar16 *utf16, int size);
	
	int locale_aware_compare(const String &str) const;
    int locale_aware_compare(const StringRef &str) const;
	
	short to_short(bool *ok = nullptr, int base = 10) const;
    ushort to_ushort(bool *ok = nullptr, int base = 10) const;
    int to_int(bool *ok = nullptr, int base = 10) const;
    uint to_uint(bool *ok = nullptr, int base = 10) const;
    long to_long(bool *ok = nullptr, int base = 10) const;
    ulong to_ulong(bool *ok = nullptr, int base = 10) const;
    pdk::plonglong to_longlong(bool *ok = nullptr, int base = 10) const;
    pdk::pulonglong to_ulongLong(bool *ok = nullptr, int base = 10) const;
    float to_float(bool *ok = nullptr) const;
    double to_double(bool *ok = nullptr) const;
	
	String &set_num(short value, int base = 10);
    String &set_num(ushort value, int base = 10);
    String &set_num(int value, int base = 10);
    String &set_num(uint value, int base = 10);
    String &set_num(long value, int base = 10);
    String &set_num(ulong value, int base = 10);
    String &set_num(pdk::plonglong value, int base = 10);
    String &set_num(pdk::pulonglong value, int base = 10);
    String &set_num(float value, char f = 'g', int prec = 6);
    String &set_num(double value, char f = 'g', int prec = 6);	
	
	int index_of(Character needle,
                 int from = 0,
                 cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int index_of(const String &needle,
                 int from = 0, 
                 cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int index_of(Latin1String needle,
                 int from = 0, 
                 cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int index_of(const StringRef &needle,
                 int from = 0, 
                 cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int last_index_of(Character needle,
                      int from = -1,
                      cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int last_index_of(const String &needle,
                      int from = -1, 
                      cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int last_index_of(Latin1String needle,
                      int from = -1, 
                      cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int last_index_of(const StringRef &needle,
                      int from = -1, 
                      cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
	inline bool contains(Character needle,
                         cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    inline bool contains(const String &needle,
                         cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    inline bool contains(Latin1String needle,
                         cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    inline bool contains(const StringRef &needle,
                         cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
	int count(Character needle,
              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int count(const String &needle,
              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int count(const StringRef &needle,
              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
			  
	int index_of(const RegularExpression &regex,
                 int from = 0,
                 RegularExpressionMatch *rmatch = nullptr) const;
    int last_index_of(const RegularExpression &regex,
                      int from = -1,
                      RegularExpressionMatch *rmatch = nullptr) const;
    bool contains(const RegularExpression &regex,
                  RegularExpressionMatch *match = nullptr) const;
    int count(const RegularExpression &regex) const;
	
	String section(Character separator,
                   int start,
                   int end = -1,
                   SectionFlags flags = SectionFlag::Default) const;
    String section(const String &separator,
                   int start, 
				   int end = -1,
                   SectionFlags flags = SectionFlag::Default) const;
	String section(const RegularExpression &regex,
                   int start, 
				   int end = -1,
                   SectionFlags flags = SectionFlag::Default) const;	
	bool starts_with(const String &needle,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
	bool starts_with(const StringRef &needle,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
	bool starts_with(StringView s,
                     cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept
	bool starts_with(Latin1String needle,
                     cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
	bool starts_with(Character needle,
                     cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
	bool ends_with(const String &needle,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;		
	bool ends_with(const StringRef &needle,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
	bool ends_with(StringView s,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept
	bool ends_with(Latin1String needle,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
	bool ends_with(Character needle,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
				   
	String left_justified(int width,
                          Character fill = Latin1Character(' '),
                          bool truncate = false) const;
	String right_justified(int width,
                           Character fill = Latin1Character(' '),
                           bool truncate = false) const;
						   
	String &remove(int pos, int length);
    String &remove(Character c,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);
    String &remove(const String &str,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);	

	String &replace(int pos, int length, Character after);
    String &replace(int pos, int length, const Character *after, int alength);
    String &replace(int pos, int length, const String &after);
    String &replace(Character before, 
					Character after,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);
    String &replace(const Character *before, 
					int blength, 
					const Character *after, 
					int alength,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);
    String &replace(Latin1String before, 
					Latin1String after,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);
    String &replace(Latin1String before, 
					const String &after,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);
    String &replace(const String &before, 
					Latin1String after,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);
    String &replace(const String &before, 
					const String &after,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);
    String &replace(Character c, 
					Latin1String after,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);
    String &replace(Character c, 
					const String &after,
                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);
					
	StringList split(const String &separator,
                     SplitBehavior behavior = SplitBehavior::KeepEmptyParts,
                     cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
	std::vector<StringRef> splitRef(const String &separator,
                                    SplitBehavior behavior = SplitBehavior::KeepEmptyParts,
                                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
	StringList split(Character separator,
                     SplitBehavior behavior = SplitBehavior::KeepEmptyParts,
                     cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;	
	std::vector<StringRef> splitRef(Character separator,
                                    SplitBehavior behavior = SplitBehavior::KeepEmptyParts,
                                    cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;	
	StringList split(const RegularExpression &separator,
                     SplitBehavior behavior = SplitBehavior::KeepEmptyParts) const;
	std::vector<StringRef> splitRef(const RegularExpression &separator,
                                    SplitBehavior behavior = SplitBehavior::KeepEmptyParts) const;
									
	String normalized(NormalizationForm mode,
                      Character::UnicodeVersion version = Character::UnicodeVersion::Unicode_Unassigned) const;
					  
	int compare(const String &str,
                cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept;
    int compare(Latin1String str,
                cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept;
    inline int compare(const StringRef &str,
                       cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept;
	
	
	inline Iterator begin();
    inline ConstIterator begin() const;
    inline ConstIterator cbegin() const;
    inline ConstIterator const_begin() const;
	
	inline Iterator end();
    inline ConstIterator end() const;
    inline ConstIterator cend() const;
    inline ConstIterator const_end() const;
	
	ReverseIterator rbegin()
	ReverseIterator rend()
	ConstReverseIterator rbegin() const
	ConstReverseIterator rend() const
	ConstReverseIterator crbegin() const
	ConstReverseIterator crend() const
	
	inline void push_back(Character c)
	inline void push_back(const String &str)
	inline void push_front(Character c)
	inline void push_front(const String &str)
	
	
    inline std::string to_std_string() const;    
    inline std::wstring to_std_wstring() const;
	inline std::u16string to_std_u16_string() const;
	inline std::u32string to_std_u32_string() const;
	
operator:
	String &operator=(const char *str) = delete;
    String &operator=(const ByteArray &str) = delete;

    String &operator=(Character c);
    String &operator=(const String &other) noexcept;
    String &operator=(Latin1String other);
	
	template <int N>
    inline String &operator=(const char (&str)[N])	
	inline String &operator=(String &&other) noexcept
	
	String &operator+=(const char *str) = delete;
    String &operator+=(const ByteArray &str) = delete;
	
	const Character operator[](int i) const;
    CharacterRef operator[](int i);
    const Character operator[](uint i) const;
    CharacterRef operator[](uint i);
	
	inline String &operator+=(Character c)
	inline String &operator+=(Character::SpecialCharacter c)
	inline String &operator+=(const String &str)
	inline String &operator+=(const StringRef &str)
	inline String &operator+=(Latin1String str)
	friend bool operator==(const String &lhs, const String &rhs) noexcept;
	friend bool operator<(const String &lhs, const String &rhs) noexcept;
	friend inline bool operator>(const String &lhs, const String &rhs) noexcept
	friend inline bool operator!=(const String &lhs, const String &rhs) noexcept
	friend inline bool operator<=(const String &lhs, const String &rhs) noexcept
	friend inline bool operator>=(const String &lhs, const String &rhs) noexcept
	bool operator==(Latin1String other) const noexcept;
    bool operator<(Latin1String other) const noexcept;
    bool operator>(Latin1String other) const noexcept;
	inline bool operator!=(Latin1String other) const noexcept
	inline bool operator<=(Latin1String other) const noexcept
	inline bool operator>=(Latin1String other) const noexcept
	
static:	
	static String vasprintf(const char *format, va_list ap)
	static String asprintf(const char *format, ...)
	static inline String from_latin1(const char *str, int size = -1)
	static inline String from_utf8(const char *str, int size = -1)
	static inline String fromLocal8Bit(const char *str, int size = -1)
	static inline String from_latin1(const ByteArray &str)
	static inline String from_utf8(const ByteArray &str)
	static inline String from_local_8bit(const ByteArray &str)
	static String from_utf16(const uchar16 *str, int size = -1);
    static String from_ucs4(const uchar32 *str, int size = -1);
    static String from_raw_data(const Character *str, int size);
	static inline String from_utf16(const ushort *str, int size = -1)
	static inline String from_ucs4(const uint *str, int size = -1)
	static inline String from_wchar_array(const wchar_t *string, int size = -1);
	static inline int compare(const String &lhs,
                              const String &rhs,
                              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) noexcept;
	static inline int compare(const String &lhs,
                              Latin1String rhs,
                              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) noexcept;
	static inline int compare(Latin1String lhs,
                              const String &rhs,
                              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) noexcept;
	static inline int compare(const String &lhs,
                              const StringRef &rhs,
                              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) noexcept;
	static int locale_aware_compare(const String &lhs, const String &rhs);
	static int locale_aware_compare(const String &lhs, const StringRef &rhs);	
	
	static String number(int, int base = 10);
    static String number(uint, int base = 10);
    static String number(long, int base = 10);
    static String number(ulong, int base = 10);
    static String number(pdk::plonglong, int base = 10);
    static String number(pdk::pulonglong, int base = 10);
    static String number(double, char f = 'g', int prec = 6);
	
	static inline String from_std_string(const std::string &str);
	static inline String from_std_wstring(const std::wstring &str);
	static inline String from_std_u16_string(const std::u16string &str);
	static inline String from_std_u32_string(const std::u32string &str);
	
private:
	void realloc_data(uint alloc, bool grow = false);
    String multi_arg(int numArgs, const String **args) const;
	void replace_helper(uint *indices, int nIndices, int blength, const Character *after, int alength);
	template <typename T>
    static T to_integral_helper(const Character *data, int len, bool *ok, int base)
	
operator:
	friend inline bool operator==(Character lhs, const String &rhs) noexcept;
    friend inline bool operator<(Character lhs, const String &rhs) noexcept;
    friend inline bool operator>(Character lhs, const String &rhs) noexcept;
    friend inline bool operator==(Character lhs, const StringRef &rhs) noexcept;
    friend inline bool operator<(Character lhs, const StringRef &rhs) noexcept;
    friend inline bool operator>(Character lhs, const StringRef &rhs) noexcept;
    friend inline bool operator==(Character lhs, Latin1String rhs) noexcept;
    friend inline bool operator<(Character lhs, Latin1String rhs) noexcept;
    friend inline bool operator>(Character lhs, Latin1String rhs) noexcept;
	
static:	
	static int compare_helper(const Character *lhs, int lhsLength,
                              const Character *rhs, int rhsLength,
                              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) noexcept;
	static int compare_helper(const Character *lhs, int lhsLength,
                              const char *rhs, int rhsLength,
                              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) noexcept;
	static int compare_helper(const Character *lhs, int lhsLength, Latin1String rhs,
                              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) noexcept;
	static int locale_aware_compare_helper(const Character *lhs, int lhsLength,
                                           const Character *rhs, int rhsLength);
										   
	static String to_lower_helper(const String &str);
    static String to_lower_helper(String &str);
    static String to_upper_helper(const String &str);
    static String to_upper_helper(String &str);
    static String to_case_folded_helper(const String &str);
    static String to_case_folded_helper(String &str);
    static String trimmed_helper(const String &str);
    static String trimmed_helper(String &str);
    static String simplified_helper(const String &str);
    static String simplified_helper(String &str);
    static Data *from_latin1_helper(const char *str, int size = -1);
    static Data *from_ascii_helper(const char *str, int size = -1);
    static String from_utf8_helper(const char *str, int size = -1);
    static String from_local_8Bit_helper(const char *str, int size = -1);	
	static ByteArray to_latin1_helper(const String &str);
    static ByteArray to_latin1_helper(const Character *str, int size);
    static ByteArray to_latin1_helper_inplace(String &str);
    static ByteArray to_utf8_helper(const String &str);
    static ByteArray to_local_8bit_helper(const Character *str, int size);
    static int to_ucs4_helper(const uchar16 *str, int length, char32_t *out);
    static pdk::plonglong to_integral_helper(const Character *data, int len, bool *ok, int base);
    static pdk::pulonglong to_integral_helper(const Character *data, uint len, bool *ok, int base);
}