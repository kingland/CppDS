class  Buffer : public IoDevice {

constructor:
	explicit Buffer(Object *parent = nullptr);
    Buffer(ByteArray *buf, Object *parent = nullptr);
	
deconstructor:
	~Buffer();
	
public:
	ByteArray &buffer();
    const ByteArray &buffer() const;
    void set_buffer(ByteArray *a);
	void set_data(const ByteArray &data);
    inline void set_data(const char *data, int len);
    const ByteArray &data() const;
	void close() override;
    usize size() const override;
    usize position() const override;
    bool seek(isize off) override;
    bool at_end() const override;
    bool can_read_line() const override;
	
protected:
    void connect_notify(u32 signal) override;
    void disconnect_notify(u32 signal) override;
    isize read_data(char *data, isize maxlen) override;
    isize write_data(const char *data, isize len) override;
    void emit_signals();
}