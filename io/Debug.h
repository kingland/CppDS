class Debug {

constructor:
	inline Debug(IoDevice *device)
	inline Debug(String *string)
	inline Debug(cm::MsgType t)
	inline Debug(const Debug &other)
	
deconstructor:
	~Debug();
	
public:	
	inline void swap(Debug &other) noexcept
	Debug &reset_format();
	inline Debug &space()
	inline Debug &nospace()
	inline Debug &maybe_space()
	int verbosity() const
	void set_verbosity(int verbosityLevel)
	bool auto_insert_spaces() const
	void set_auto_insert_spaces(bool b)
	inline Debug &quote()
	inline Debug &noquote()
	inline Debug &maybe_quote(char c = '"')

operator:	
	inline Debug &operator=(const Debug &other);
	inline Debug &operator<<(Character t)
	inline Debug &operator<<(bool t)
	inline Debug &operator<<(char t)
	inline Debug &operator<<(signed short t)
	inline Debug &operator<<(unsigned short t)
	inline Debug &operator<<(i16 t)
	inline Debug &operator<<(u16 t)
	inline Debug &operator<<(char16_t t) -> TODO:
	inline Debug &operator<<(char32_t t) -> TODO:
	inline Debug &operator<<(signed int t)
	inline Debug &operator<<(unsigned int t)
	inline Debug &operator<<(signed long t)
	inline Debug &operator<<(unsigned long t)
	inline Debug &operator<<(i32 t)
	inline Debug &operator<<(u32 t)
	inline Debug &operator<<(i64 t)
	inline Debug &operator<<(u64 t)
	inline Debug &operator<<(float t)
	inline Debug &operator<<(double t)
	inline Debug &operator<<(const char *t)
	
	inline Debug &operator<<(const String &t)
	inline Debug &operator<<(const StringRef &t)
	
	inline Debug &operator<<(Latin1String t)
	inline Debug &operator<<(const ByteArray &t)
	inline Debug &operator<<(const void *t)
	inline Debug &operator<<(std::nullptr_t)
	inline Debug &operator<<(TextStreamFunc f)
	inline Debug &operator<<(TextStreamManipulator m)
	inline Debug &operator<<(StringView s)
}


class NoDebug {
	
constructor:
	
	
deconstructor:

public:
	inline NoDebug &space()
	inline NoDebug &nospace()
	inline NoDebug &maybe_space()
	inline NoDebug &quote()
	inline NoDebug &noquote()
	inline NoDebug &maybe_quote(const char = '"')
	
operator:
	inline NoDebug &operator<<(TextStreamFunc)
	inline NoDebug &operator<<(TextStreamManipulator)	
	template <typename T>
    inline NoDebug &operator<<(const T &)
}