#define MAKE_SINGLETON(classname)                        \
private:                                                 \
    classname() { }                                      \
                                                         \
public:                                                  \
    classname(const classname& rhs) = delete;            \
    classname& operator=(const classname& rhs) = delete; \
    static classname& GetInstance()                      \
    {                                                    \
        static classname instance;                       \
        return instance;                                 \
    }                                                    \
                                                         \
private: