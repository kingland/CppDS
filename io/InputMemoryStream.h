class InputMemoryStream final : public InputStream {

constructor:
	InputMemoryStream(ConstBytes bytes)

deconstructor:

public:	
	bool eof() const override
	usize read(Bytes bytes) override
	bool read_or_error(Bytes bytes) override
	bool discard_or_error(usize count) override
	void seek(usize offset)
	u8 peek_or_error() const
	ConstBytes bytes() const
	usize offset() const
	usize remaining() const
}