class Latin1Character{
constructor:
	constexpr inline explicit Latin1Character(char character) noexcept
	constexpr inline char to_latin1() const noexcept
	constexpr inline uchar16 unicode() noexcept
	
deconstructor:

public:

}

class Character {

constructor:
	constexpr Character() noexcept
	constexpr Character(uchar16 ch) noexcept
	constexpr Character(short ch) noexcept
	constexpr Character(uchar c, uchar r) noexcept
	constexpr Character(uchar32 rc) noexcept
	constexpr Character(int rc) noexcept
	constexpr Character(uint rc) noexcept
	constexpr Character(SpecialCharacter ch) noexcept
	constexpr Character(Latin1Character ch) noexcept
	constexpr explicit Character(char c) noexcept
	constexpr explicit Character(uchar c) noexcept
	constexpr Character(uchar ch) noexcept
	
deconstructor:

public:
	inline Category category() const noexcept
	inline Direction direction() const noexcept
	inline JoiningType joining_type() const noexcept
	inline unsigned char combining_class() const noexcept
	inline Character mirrored_character() const noexcept
	inline bool has_mirrored() const noexcept
	String decomposition() const;
	inline Decomposition decomposition_tag() const noexcept
	inline int digit_value() const noexcept
	inline Character to_lower() const noexcept
	inline Character to_upper() const noexcept
	inline Character to_title_case() const noexcept
	inline Character to_case_folded() const noexcept
	inline Script script() const noexcept
	inline UnicodeVersion unicode_version() const noexcept
	constexpr inline char to_latin1() const noexcept
	constexpr inline char16_t unicode() const noexcept
	inline uchar16 &unicode() noexcept
	inline bool is_printable() const noexcept
	inline bool is_mark() const noexcept
	inline bool is_punct() const noexcept
	inline bool is_symbol() const noexcept
	constexpr inline bool is_null() const noexcept
	constexpr inline bool is_space() const noexcept
	constexpr inline bool is_letter() const noexcept
	constexpr inline bool is_number() const noexcept
	constexpr inline bool is_letter_or_number() const noexcept
	constexpr inline bool is_digit() const noexcept
	constexpr inline bool is_lower() const noexcept
	constexpr inline bool is_upper() const noexcept
	constexpr inline bool is_title_case() const noexcept
	constexpr inline bool is_non_character() const noexcept
	constexpr inline bool is_high_surrogate() const noexcept
	constexpr inline bool is_low_surrogate() const noexcept
	constexpr inline bool is_surrogate() const noexcept
	constexpr inline uchar cell() const noexcept
	constexpr inline uchar row() const noexcept
	inline void set_cell(uchar acell) noexcept
	inline void set_row(uchar arow) noexcept
	
	
static:
	static constexpr inline Character from_latin1(char c) noexcept
	static constexpr inline bool is_non_character(uchar32 ucs4) noexcept
	static constexpr inline bool is_high_surrogate(uchar32 ucs4) noexcept
	static constexpr inline bool is_low_surrogate(uchar32 ucs4) noexcept
	static constexpr inline bool is_surrogate(uchar32 ucs4) noexcept
	static constexpr inline bool requires_surrogates(uchar32 ucs4) noexcept
	static constexpr inline uchar32 surrogate_to_ucs4(uchar16 high, uchar16 low) noexcept
	static constexpr inline uchar32 surrogate_to_ucs4(Character high, Character low) noexcept
	static constexpr inline uchar16 high_surrogate(uchar32 ucs4) noexcept
	static constexpr inline uchar16 low_surrogate(uchar32 ucs4) noexcept
	
	static Category category(uchar32 ucs4) noexcept;
	static Direction direction(uchar32 ucs4) noexcept;
	static JoiningType joining_type(uchar32 ucs4) noexcept;
	static unsigned char combining_class(uchar32 ucs4) noexcept;
	static uchar32  mirrored_character(uchar32 ucs4) noexcept;
	static bool has_mirrored(uchar32 ucs4) noexcept;
	static String decomposition(uchar32 ucs4);
	static Decomposition decomposition_tag(uchar32 ucs4) noexcept;
	static int digit_value(uchar32 ucs4) noexcept;
	static uchar32 to_lower(uchar32 ucs4) noexcept;
	static uchar32 to_upper(uchar32 ucs4) noexcept;
	static uchar32 to_title_case(uchar32 ucs4) noexcept;
	static uchar32 to_case_folded(uchar32 ucs4) noexcept;
	static Script script(uchar32 ucs4) noexcept; 
	static UnicodeVersion unicode_version(uchar32 ucs4) noexcept;
	static UnicodeVersion current_unicode_version() noexcept;
	static bool is_printable(uchar32 ucs4) noexcept;
	
	static constexpr inline bool is_space(uchar32 ucs4) noexcept;
	static bool is_mark(uchar32 ucs4) noexcept;
	static bool is_punct(uchar32 ucs4) noexcept;
	static bool is_symbol(uchar32 ucs4) noexcept;
	static constexpr inline bool is_letter(uchar32 ucs4) noexcept
	static constexpr inline bool is_number(uchar32 ucs4) noexcept
	static constexpr inline bool is_letter_or_number(uchar32 ucs4) noexcept
	static constexpr inline bool is_digit(uchar32 ucs4) noexcept
	static constexpr inline bool is_lower(uchar32 ucs4) noexcept
	static constexpr inline bool is_upper(uchar32 ucs4) noexcept
	static constexpr inline bool is_title_case(uchar32 ucs4) noexcept 
	
private:
	static bool is_space_helper(uchar32 ucs4) noexcept;
	static bool is_letter_helper(uchar32 ucs4) noexcept ;
	static bool is_number_helper(uchar32 ucs4) noexcept ;
	static bool is_letter_or_number_helper(uchar32 ucs4) noexcept;
	
	friend constexpr bool operator==(Character, Character) noexcept;
    friend constexpr bool operator<(Character, Character) noexcept;
}


constexpr inline bool operator ==(Character lhs, Character rhs) noexcept
constexpr inline bool operator <(Character lhs, Character rhs) noexcept
constexpr inline bool operator !=(Character lhs, Character rhs) noexcept
constexpr inline bool operator >=(Character lhs, Character rhs) noexcept
constexpr inline bool operator >(Character lhs, Character rhs) noexcept
constexpr inline bool operator <=(Character lhs, Character rhs) noexcept
constexpr inline bool operator==(Character lhs, std::nullptr_t) noexcept
constexpr inline bool operator< (Character,     std::nullptr_t) noexcept
constexpr inline bool operator==(std::nullptr_t, Character rhs) noexcept
constexpr inline bool operator< (std::nullptr_t, Character rhs) noexcept
constexpr inline bool operator!=(Character lhs, std::nullptr_t) noexcept
constexpr inline bool operator>=(Character lhs, std::nullptr_t) noexcept
constexpr inline bool operator> (Character lhs, std::nullptr_t) noexcept
constexpr inline bool operator<=(Character lhs, std::nullptr_t) noexcept
constexpr inline bool operator!=(std::nullptr_t, Character rhs) noexcept
constexpr inline bool operator>=(std::nullptr_t, Character rhs) noexcept
constexpr inline bool operator> (std::nullptr_t, Character rhs) noexcept
constexpr inline bool operator<=(std::nullptr_t, Character rhs) noexcept