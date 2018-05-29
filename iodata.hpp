#ifndef DATAIODEF
#define DATAIODEF

#include <string>

// template 
class File
{
private:
    std::string mData;
    int nRows;
public:
    File(const std::string& fileName);
    void PrintDebug() const;

    // make a decorator for it to be verbose

    void dim();
    void len();

    void head(size_t i);
    void tail(size_t i);

    void nth(size_t i);
    void last(size_t i);

    // overload selection operator
    // select column
    // specify categories (enum)

    

};
#endif //DATAIODEF