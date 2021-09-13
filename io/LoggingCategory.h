class LoggingCategory {

constructor:
	explicit LoggingCategory(const char *category);
    LoggingCategory(const char *category, cm::MsgType severityLevel);
	
deconstructor:
	~LoggingCategory();
	
public:
	bool is_enabled(cm::MsgType type) const;
    void set_enabled(cm::MsgType type, bool enable);
	bool is_debug_enabled() const
	bool is_info_enabled() const
	bool is_warning_enabled() const
	bool is_critical_enabled() const
	const char *get_category_name() const
	
operator:
	LoggingCategory &operator()()
	const LoggingCategory &operator()() const

static:	
	static LoggingCategory *default_category();
	static CategoryFilter install_filter(CategoryFilter);
	static void set_filter_rules(const String &rules);
	
private:
    void init(const char *category, cm::MsgType severityLevel);
}