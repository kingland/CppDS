class CharacterRef {

constructor:
	inline operator Character() const
	
	
deconstructor:

public:
	inline bool is_null() const
	inline bool is_print() const
	inline bool is_punct() const
	inline bool is_space() const
	inline bool is_mark() const
	inline bool is_letter() const
	inline bool is_number() const
	inline bool is_letter_or_number() const
	inline bool is_digit() const
	inline bool is_lower() const
	inline bool is_upper() const
	inline bool is_title_case() const
	inline int  digit_value() const
	inline Character to_lower() const
	inline Character to_upper() const
	inline Character to_title_case() const
	inline Character::Category category() const
	inline Character::Direction direction() const
	inline Character::JoiningType join_type() const
	inline bool has_mirrored() const
	inline Character mirrored_character() const
	inline String decomposition() const
	inline Character::Decomposition decomposition_tag() const
	inline uchar combining_class()
	inline Character::Script script() const
	inline Character::UnicodeVersion unicode_version() const
	inline uchar cell() const
	inline uchar row() const
	inline void set_cell(uchar cell);
	inline void set_row(uchar row);
	char to_latin1() const
	uchar16 unicode() const
	uchar16 &unicode()

operator:
	inline CharacterRef &operator=(Character c)
	inline CharacterRef &operator=(const CharacterRef &c)
	inline CharacterRef &operator=(ushort c)
	inline CharacterRef &operator=(short c)
	inline CharacterRef &operator=(uint c)
	inline CharacterRef &operator=(int c)
	
}

class StringRef {
	
constructor:
	inline constexpr StringRef()
	inline StringRef(const String *str, int position, int size);
	inline StringRef(const String *str);
	
deconstructor:

public:
	inline const String *str() const
	inline int position() const
	inline int size() const
	inline int length() const
	
	int index_of(const String &str,
                 int from = 0,
                 cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int index_of(Character c,
                 int from = 0,
                 cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int index_of(Latin1String str,
                 int from = 0,
                 cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int index_of(const StringRef &str,
                 int from = 0,
                 cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
                 
    int last_index_of(const String &str,
                      int from = -1,
                      cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int last_index_of(Character c,
                      int from = -1,
                      cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int last_index_of(Latin1String str,
                      int from = -1,
                      cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int last_index_of(const StringRef &str,
                      int from = -1,
                      cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
					  
    inline bool contains(const String &str,
                         cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    inline bool contains(Character c,
                         cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    inline bool contains(Latin1String str,
                         cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    inline bool contains(const StringRef &str,
                         cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
						 
	bool starts_with(const String &needle,
                     cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    bool starts_with(Latin1String needle,
                     cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    bool starts_with(Character needle,
                     cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    bool starts_with(const StringRef &needle,
                     cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;

    bool ends_with(const String &needle,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    bool ends_with(Latin1String needle,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    bool ends_with(Character needle,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    bool ends_with(const StringRef &needle,
                   cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;					 
						 
    int count(const String &needle,
              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int count(Character needle,
              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
    int count(const StringRef &needle,
              cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
			  
	std::vector<StringRef> split(const String &separator,
                                 String::SplitBehavior behavior = String::SplitBehavior::KeepEmptyParts,
                                 cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
	std::vector<StringRef> split(Character separator,
                                 String::SplitBehavior behavior = String::SplitBehavior::KeepEmptyParts,
                                 pdcmk::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const;
								 
	int compare(const String &rhs,
                cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept;
    int compare(const StringRef &rhs,
                cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept;
    int compare(Latin1String rhs,
                cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) const noexcept;
    							 
								 
	StringRef left(int n) const;
	StringRef right(int n) const;
	StringRef substring(int pos, int n = -1) const;
	void truncate(int pos) noexcept
	void chop(int n) noexcept
	bool is_right_to_left() const;
	
	inline const Character *raw_data() const
	inline const Character *const_raw_data() const
	
	inline const_iterator begin() const
	inline const_iterator cbegin() const
	inline const_iterator end() const
	inline const_iterator cend() const
	inline const_reverse_iterator rbegin() const
	inline const_reverse_iterator rcbegin() const
	inline const_reverse_iterator rend() const
	inline const_reverse_iterator rcend() const
	
	ByteArray to_latin1() const;
	ByteArray to_utf8() const;
	ByteArray to_local_8bit() const;
	std::vector<char32_t> to_ucs4() const;
	inline void clear()
	String to_string() const;
	inline bool is_empty() const
	inline bool is_null() const
	StringRef append_to(String *str) const;
	inline const Character at(int i) const
	
	int locale_aware_compare(const String &other) const;
    int locale_aware_compare(const StringRef &other) const;
    static int locale_aware_compare(const StringRef &lhs, const String &rhs);
    static int locale_aware_compare(const StringRef &lhs, const StringRef &rhs);
	
	inline const Character *unicode() const
	
operator:	
	inline StringRef &operator=(const String *str);	
	Character operator[](int i) const
	
static:
	static int compare(const StringRef &lhs,
                       const String &rhs,
                       cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) noexcept;
    static int compare(const StringRef &lhs,
                       const StringRef &rhs,
                       cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) noexcept;
    static int compare(const StringRef &lhs,
                       Latin1String rhs,
                       cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive) noexcept;
	
}