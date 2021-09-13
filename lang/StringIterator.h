
class StringIterator {

constructor:
	explicit StringIterator(StringView string, usize idx = 0)
	inline explicit StringIterator(const Character *begin, const Character *end)
	inline explicit StringIterator(const Character *begin, int idx, const Character *end)
	
deconstructor:
	
	
public:
	inline String::ConstIterator position() const
	inline int index() const	
	inline void set_position(String::ConstIterator position)
	inline bool has_next() const
	inline void advance()
	inline uint peek_next_unchecked() const
	inline uint peek_next(uint invalidAs = Character::ReplacementCharacter) const
	inline uint next_unchecked()
	inline uint next(uint invalidAs = Character::ReplacementCharacter)
	inline bool has_previous() const
	inline void recede()
	inline void recede_unchecked()
	inline uint peek_previous_unchecked() const
	inline uint peek_previous(uint invalidAs = Character::ReplacementCharacter) const
	inline uint previous_unchecked()
	inline uint previous(uint invalidAs = Character::ReplacementCharacter)	
}