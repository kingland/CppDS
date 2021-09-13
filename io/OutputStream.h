class OutputStream : public virtual internal::Stream {
public:
    virtual usize write(ConstBytes) = 0;
    virtual bool write_or_error(ConstBytes) = 0;	
}

class internal::Stream {
	
deconstructor:
	virtual ~Stream()
	
public:
	bool has_error() const  
    bool handle_error()  
}


inline OutputStream& operator<<(OutputStream& stream, ConstBytes bytes)


template<typename Integral, typename EnableIf<IsIntegral<Integral>::value, int>::Type = 0>
OutputStream& operator<<(OutputStream& stream, Integral value)

template<typename FloatingPoint, typename EnableIf<IsFloatingPoint<FloatingPoint>::value, int>::Type = 0>
OutputStream& operator<<(OutputStream& stream, FloatingPoint value)

inline OutputStream& operator<<(OutputStream& stream, bool value)