
class AbstractConcatenable {
protected:
    static void convert_from_ascii(const char *a, int len, Character *&out) noexcept;
    static inline void convert_from_ascii(char a, Character *&out) noexcept;
	static void append_latin1_to(const char *a, int len, Character *out) noexcept;
}

struct StringBuilderCommon {
	
	T to_upper() const
    {
        return resolved().to_upper();
    }
   
    T to_lower() const
    {
        return resolved().to_lower();
    }
	
	T resolved() const
    {
        return *static_cast<const Builder *>(this);
    }
}

template<typename Builder, typename T>
struct StringBuilderBase : public StringBuilderCommon<Builder, T>{}

template<typename Builder>
struct StringBuilderBase<Builder, String> : public StringBuilderCommon<Builder, String> {
	
	ByteArray to_latin1() const
    {
        return this->resolved().to_latin1();
    }

    ByteArray to_utf8() const
    {
        return this->resolved().to_utf8();
    }

    ByteArray to_local_8bit() const
    {
        return this->resolved().to_local_8bit();
    }
}

template <typename A, typename B>
class StringBuilder : public StringBuilderBase<StringBuilder<A, B>, typename internal::ConvertToTypeHelper<typename Concatenable<A>::ConvertTo, typename Concatenable<B>::ConvertTo>::ConvertTo> {

constructor:
	StringBuilder(const A &a, const B &b)
	 
deconstructor:

public:
	usize size() const
	
operator:
	operator ConvertTo() const
	
}

template <>
class StringBuilder <String, String> : public StringBuilderBase<StringBuilder<String, String>, String> {
	
public:
	StringBuilder(const String &a, const String &b)
	StringBuilder(const StringBuilder &other)
	
operator:
	operator String() const

}

template <>
class StringBuilder <ByteArray, ByteArray> : public StringBuilderBase<StringBuilder<ByteArray, ByteArray>, ByteArray> {

public:
	StringBuilder(const ByteArray &a, const ByteArray &b)
	StringBuilder(const StringBuilder &other)
	
operator:	
	operator ByteArray() const
}


template <typename T>
struct Concatenable
{};

template <> 
struct Concatenable<Latin1Character> {
	
public:
static:
	static usize size(const Latin1Character)
	static inline void append_to(const Latin1Character c, Character *&out)	
	static inline void append_to(const Latin1Character c, char *&out)
}

template <> 
struct Concatenable<Character> : private AbstractConcatenable {
	
public:
static:
	static usize size(const Character)
	static inline void append_to(const Character c, Character *&out)
}

template <>
struct Concatenable<Character::SpecialCharacter> : private AbstractConcatenable {

public:
static:
	static usize size(const Character::SpecialCharacter)
	static inline void append_to(const Character::SpecialCharacter c, Character *&out)
}

template <>
struct Concatenable<CharacterRef> : private AbstractConcatenable {

public:
static:
	static usize size(CharacterRef)
	static inline void append_to(CharacterRef c, Character *&out)
}

template <> 
struct Concatenable<Latin1String> : private AbstractConcatenable {

public:
static:
	static usize size(const Latin1String a)
	static inline void append_to(const Latin1String a, Character *&out)
	static inline void append_to(const Latin1String a, char *&out)
}

template <> 
struct Concatenable<String> : private AbstractConcatenable {

public:
static:
	static usize size(const String &a)
	static inline void append_to(const String &a, Character *&out)
	static inline void append_to(const String &a, char *&out)	
}

template <> 
struct Concatenable<StringRef> : private AbstractConcatenable {

public:
static:
	static usize size(const StringRef &a)
	static inline void append_to(const StringRef &a, Character *&out)
	
}

template <int N> 
struct Concatenable<const char[N]> : private AbstractConcatenable {

public:
static:
	static usize size(const char[N])
	static inline void append_to(const char a[N], char *&out)
}

template <int N> 
struct Concatenable<char[N]> : Concatenable<const char[N]> {
	typedef char type[N];
}

template <> 
struct Concatenable<const char *> : private AbstractConcatenable {

public:
static:
	static usize size(const char *a)
	static inline void append_to(const char *a, char *&out)
}

template <> 
struct Concatenable<char *> : Concatenable<const char*>
{
   typedef char *type;
};

template <> 
struct Concatenable<ByteArray> : private AbstractConcatenable {

public:
static:
	static usize size(const ByteArray &ba)
	static inline void append_to(const ByteArray &ba, char *&out)
}

template <typename A, typename B>
struct Concatenable< StringBuilder<A, B> > {

public:
static:
	static usize size(const type &p)
	template <typename T>
    static inline void append_to(const type &p, T *&out)
}


template <typename A, typename B>
StringBuilder<typename Concatenable<A>::type, typename Concatenable<B>::type> operator%(const A &a, const B &b)

template <typename A, typename B>
StringBuilder<typename Concatenable<A>::type, typename Concatenable<B>::type> operator+(const A &a, const B &b)

template <typename A, typename B>
ByteArray &operator+=(ByteArray &a, const StringBuilder<A, B> &b)

template <typename A, typename B>
String &operator+=(String &a, const StringBuilder<A, B> &b)