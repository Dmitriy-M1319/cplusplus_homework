#ifndef PAGE_H
#define PAGE_H

namespace cache {


    class page_t
    {
    private:
        int d_size;
        char *data;
    public:
        page_t(int size);
        page_t(int size, const char *data);
        ~page_t();
        int size();
        char *get_data();
    };
}
#endif
