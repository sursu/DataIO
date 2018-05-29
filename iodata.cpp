#include <iodata.hpp>

//Constructor
File::File(std::string tagString, std::string probString)
{
    mData = tagString;
    mProblem = probString;
}

void File::PrintDebug() const
{
    std::cerr << "** Error (" << mTag    <<") **\n";
    std::cerr << "Problem: "  << mProblem << "\n\n";
}