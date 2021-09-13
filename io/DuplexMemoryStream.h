
// All data written to this stream can be read from it. Reading and writing is done
// using different offsets, meaning that it is not necessary to seek to the start
// before reading; this behaviour differs from BufferStream.
//
// The stream keeps a history of 64KiB which means that seeking backwards is well
// defined. Data past that point will be discarded.
class DuplexMemoryStream final : public DuplexStream {

constructor:

decontructor:

public:
	bool eof() const override
	bool discard_or_error(usize count) override
	Optional<usize> offset_of(ConstBytes value) const
	usize read(Bytes bytes) override
	usize read(Bytes bytes, usize offset)
	bool read_or_error(Bytes bytes) override
	bool write_or_error(ConstBytes bytes) override
	usize roffset() const
	usize woffset() const 
	void rseek(usize offset)
	void try_discard_chunks()
}