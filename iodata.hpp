#ifndef DATAIODEF
#define DATAIODEF

// template 
class File
{
private:
    std::string mData;
    int 
public:
    File(const std::string& fileName);
    void PrintDebug() const;

    // make a decorator for it to be verbose

    void shape();
    void head(auto i);
};
#endif //DATAIODEF