class InputBitStream final : public InputStream {

constructor:
	explicit InputBitStream(InputStream& stream)
	
decontructor:

public:	
	bool read_or_error(Bytes bytes) override
	bool eof() const override
	bool discard_or_error(usize count) override
	u32 read_bits(usize count)
	bool read_bit()
	void align_to_byte_boundary()
}