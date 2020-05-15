#ifndef CPP17TEST_ERRORS_H
#define CPP17TEST_ERRORS_H

#include <exception>
#include <string>

class baseError : public std::exception
{
public:
    baseError(std::string filename, std::string classname, int line,
              std::string info = "Error")
    {
        errorInfo = "\nFile name: " + filename + "\nClass: " + classname +
                   "\nLine#: " + std::to_string(line);
    }
    virtual const char* what() const noexcept override
    {
        return errorInfo.c_str();
    }
protected:
    std::string errorInfo;
};


class emptyError : public baseError
{
public:
    emptyError(std::string filename, std::string classname, int line,
               std::string info = "Action with empty matrix") :
            baseError(filename, classname, line, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class badIndexError : public baseError
{
public:
    badIndexError(std::string filename, std::string classname, int line,
               std::string info = "Index out of range") :
            baseError(filename, classname, line, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class divisionByZeroError : public baseError
{
public:
    divisionByZeroError(std::string filename, std::string classname, int line,
                  std::string info = "Zero division error") :
            baseError(filename, classname, line, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class badMultiplySizes : public baseError
{
public:
    badMultiplySizes(std::string filename, std::string classname, int line,
                        std::string info = "This matrixs sizes makes unable to perform multiply") :
            baseError(filename, classname, line, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class nonEqualSizesError : public baseError
{
public:
    nonEqualSizesError(std::string filename, std::string classname, int line,
                       std::string info = "You can add only matrix have sizes like first") :
            baseError(filename, classname, line, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class badInitSizes : public baseError
{
public:
    badInitSizes(std::string filename, std::string classname, int line,
                std::string info = "You can not use those sizes") :
            baseError(filename, classname, line, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};


#endif //CPP17TEST_ERRORS_H
