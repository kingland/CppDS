class IoDevice : public Object {
constructor:
	explicit IoDevice(Object *parent);
protected:
	IoDevice(IoDevicePrivate &dd, Object *parent = nullptr);
	
deconstructor:
	virtual ~IoDevice();
	
public:
	OpenModes open_mode() const;
	void set_text_mode_enabled(bool enabled);
    bool is_text_mode_enabled() const;
	
	bool is_open() const;
    bool is_readable() const;
    bool is_writable() const;
    virtual bool is_sequential() const;
	
	int read_channel_count() const;
    int write_channel_count() const;
    int current_read_channel() const;
    void set_current_read_channel(int channel);
    int current_write_channel() const;
    void set_current_write_channel(int channel);
	
	virtual bool open(OpenModes mode);
    virtual void close();

	virtual isize position() const;
    virtual usize size() const;
    virtual bool seek(isize pos);
    virtual bool at_end() const;
    virtual bool reset();
	
	virtual isize bytes_available() const;
    virtual isize bytes_to_write() const;
	
	isize read(char *data, isize maxLength);
    ByteArray read(isize maxLength);
    ByteArray read_all();
    isize read_line(char *data, isize maxLength);
    ByteArray read_line(isize maxLength = 0);
    virtual bool can_read_line() const;

	void start_transaction();
    void commit_transaction();
    void rollback_transaction();
    bool is_Transaction_started() const;
	
	isize write(const char *data, isize length);
    isize write(const char *data);
    inline isize write(const ByteArray &data)
	
	isize peek(char *data, isize maxLength);
    ByteArray peek(isize maxLength);
    isize skip(isize maxSize);
	
	virtual bool wait_for_ready_read(int msecs);
    virtual bool wait_for_bytes_written(int msecs);
	
	void unget_char(char c);
    bool put-char(char c);
    bool get_char(char *c);

    String get_error_string() const;
	
protected:
    virtual isize read_data(char *data, isize maxLength) = 0;
    virtual isize read_line_data(char *data, isize maxLength);
    virtual isize write_data(const char *data, isize length) = 0;
    void set_open_mode(OpenModes openMode);
    void set_error_string(const String &errorString);
}