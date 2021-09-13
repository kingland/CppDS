class InputStream : public virtual internal::Stream {
public:
	virtual usize read(Bytes) = 0;
    virtual bool read_or_error(Bytes) = 0;
    virtual bool eof() const = 0;
    virtual bool discard_or_error(usize count) = 0;
}


class internal::Stream {
	
deconstructor:
	virtual ~Stream()
	
public:
	bool has_error() const  
    bool handle_error()  
}


inline InputStream& operator>>(InputStream& stream, Bytes bytes)

template<typename T>
InputStream& operator>>(InputStream& stream, Optional<T>& value)

template<typename Integral, typename EnableIf<IsIntegral<Integral>::value, int>::Type = 0>
InputStream& operator>>(InputStream& stream, Integral& value)

template<typename FloatingPoint, typename EnableIf<IsFloatingPoint<FloatingPoint>::value, int>::Type = 0>
InputStream& operator>>(InputStream& stream, FloatingPoint& value)

inline InputStream& operator>>(InputStream& stream, bool& value)