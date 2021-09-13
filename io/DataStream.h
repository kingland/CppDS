class DataStream {
constructor:
	DataStream();
    explicit DataStream(IoDevice *);
    DataStream(ByteArray *, IoDevice::OpenMode flags);
    DataStream(const ByteArray &);
	
deconstructor:
	~DataStream();
	
public:
	IoDevice *device() const;
    void set_device(IoDevice *);
    void unset_device();
	bool at_end() const;
	Status status() const;
    void set_status(Status status);
    void reset_status();
	FloatingPointPrecision get_floating_point_precision() const;
    void set_floating_point_precision(FloatingPointPrecision precision);
	ByteOrder byte_order() const;
    void set_byte_order(ByteOrder);
	Version version() const;
    void set_version(Version);
	DataStream &read_bytes(char *&, usize &len);
    isize read_raw_data(char *, isize len);

    DataStream &write_bytes(const char *, usize len);
    isize write_raw_data(const char *, isize len);

    isize skip_raw_data(isize len);

    void start_transaction();
    bool commit_transaction();
    void rollback_transaction();
    void abort_transaction();

operator:	
	DataStream &operator>>(i8 &i);
    DataStream &operator>>(u8 &i);
    DataStream &operator>>(i16 &i);
    DataStream &operator>>(u16 &i);
    DataStream &operator>>(i32 &i);
    DataStream &operator>>(u32 &i);
    DataStream &operator>>(i64 &i);
    DataStream &operator>>(u64 &i);
    DataStream &operator>>(std::nullptr_t &ptr);
	DataStream &operator>>(bool &i);
    DataStream &operator>>(float &f);
    DataStream &operator>>(double &f);
    DataStream &operator>>(char *&str);
	
	DataStream &operator<<(i8 i);
    DataStream &operator<<(u8 i);
    DataStream &operator<<(i16 i);
    DataStream &operator<<(u16 i);
    DataStream &operator<<(i32 i);
    DataStream &operator<<(u32 i);
    DataStream &operator<<(i64 i);
    DataStream &operator<<(u64 i);
    DataStream &operator<<(std::nullptr_t);
    DataStream &operator<<(bool i);
    DataStream &operator<<(float f);
    DataStream &operator<<(double f);
    DataStream &operator<<(const char *str);
}