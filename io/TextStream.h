class TextStream {

constructor:
	TextStream();
    explicit TextStream(IoDevice *device);
    explicit TextStream(FILE *fileHandle, IoDevice::OpenModes openMode = IoDevice::OpenMode::ReadWrite);
    explicit TextStream(String *string, IoDevice::OpenModes openMode = IoDevice::OpenMode::ReadWrite);
    explicit TextStream(ByteArray *array, IoDevice::OpenModes openMode = IoDevice::OpenMode::ReadWrite);
    explicit TextStream(const ByteArray &array, IoDevice::OpenModes openMode = IoDevice::OpenMode::ReadOnly);
	
deconstructor:
	virtual ~TextStream();
	
public:
	void set_codec(TextCodec *codec);
    void set_codec(const char *codecName);
    TextCodec *codec() const;
    void set_auto_detect_unicode(bool enabled);
    bool auto_detect_unicode() const;
    void set_generate_byte_order_mark(bool generate);
    bool generate_byte_order_mark() const;
	
	void set_locale(const Locale &locale);
    Locale locale() const;
	void set_device(IoDevice *device);
    IoDevice *device() const;

    void set_string(String *string, IoDevice::OpenMode openMode = IoDevice::OpenMode::ReadOnly);
    String *string() const;

    Status status() const;
    void set_status(Status status);
    void reset_status();

    bool at_end() const;
    void reset();
    void flush();
    bool seek(i64 pos);
    i64 position() const;

    void skip_white_space();
    String read_line(i64 maxLength = 0);
    bool read_line_into(String *line,i64 maxLength = 0);
    String read_all();
    String read(i64 maxLength);

    void set_field_alignment(FieldAlignment alignment);
    FieldAlignment field_alignment() const;

    void set_pad_char(Character ch);
    Character pad_char() const;

    void set_field_width(int width);
    int field_width() const;

    void set_number_flags(NumberFlags flags);
    NumberFlags number_flags() const;

    void set_integer_base(int base);
    int integer_base() const;

    void set_real_number_notation(RealNumberNotation notation);
    RealNumberNotation real_number_notation() const;

    void set_real_number_precision(int precision);
    int real_number_precision() const;
	
operator:	
	TextStream &operator>>(Character &ch);
    TextStream &operator>>(char &ch);
    TextStream &operator>>(signed short &i);
    TextStream &operator>>(unsigned short &i);
    TextStream &operator>>(signed int &i);
    TextStream &operator>>(unsigned int &i);
    TextStream &operator>>(signed long &i);
    TextStream &operator>>(unsigned long &i);
    //TextStream &operator>>(plonglong &i);
    //TextStream &operator>>(pulonglong &i);
    TextStream &operator>>(float &f);
    TextStream &operator>>(double &f);
    TextStream &operator>>(String &s);
    TextStream &operator>>(ByteArray &array);
    TextStream &operator>>(char *c);
	
	TextStream &operator<<(Character ch);
    TextStream &operator<<(char ch);
    TextStream &operator<<(signed short i);
    TextStream &operator<<(unsigned short i);
    TextStream &operator<<(signed int i);
    TextStream &operator<<(unsigned int i);
    TextStream &operator<<(signed long i);
    TextStream &operator<<(unsigned long i);
    //TextStream &operator<<(plonglong i);
    //TextStream &operator<<(pulonglong i);
    TextStream &operator<<(float f);
    TextStream &operator<<(double f);
    TextStream &operator<<(const String &s);
    TextStream &operator<<(Latin1String s);
    TextStream &operator<<(const StringRef &s);
    TextStream &operator<<(const ByteArray &array);
    TextStream &operator<<(const char *c);
    TextStream &operator<<(const void *ptr);
}