

class StringMatcher {
	
constructor:
	StringMatcher();
	explicit StringMatcher(const String &pattern,
        cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);
	StringMatcher(const Character *uc, int len,
        cm::CaseSensitivity cs = cm::CaseSensitivity::Sensitive);
	StringMatcher(const StringMatcher &other);
	
deconstructor:
	~StringMatcher();
	
public:
	void set_pattern(const String &pattern);
    void set_case_sensitivity(cm::CaseSensitivity cs);
	int index_in(const String &str, int from = 0) const;
    int index_in(const Character *str, int length, int from = 0) const;
    String pattern() const;
	inline cm::CaseSensitivity case_sensitivity() const	

operator:
	StringMatcher &operator=(const StringMatcher &other);

}