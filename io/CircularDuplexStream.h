template<usize Capacity>
class CircularDuplexStream : public DuplexStream {

constructor:

deconstructor:

public:
	usize write(ConstBytes bytes) override
	bool write_or_error(ConstBytes bytes) override
	usize read(Bytes bytes) override
	usize read(Bytes bytes, usize seekback)
	bool read_or_error(Bytes bytes) override
	bool discard_or_error(usize count) override
	bool eof() const override
	usize remaining_contigous_space() const
	Bytes reserve_contigous_space(usize count)	
}