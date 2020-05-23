#ifndef CPP17TEST_ERRORS_H
#define CPP17TEST_ERRORS_H

#include <exception>
#include <string>
#include <ctime>


class baseError : public std::exception
{
public:
    baseError(std::string filename, std::string classname, int line, std::string time,
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


class EmptyError : public baseError
{
public:
    EmptyError(std::string filename, std::string classname, int line, std::string time,
               std::string info = "Action with empty matrix") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class badIndexError : public baseError
{
public:
    badIndexError(std::string filename, std::string classname, int line, std::string time,
               std::string info = "Index out of range") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class divisionByZeroError : public baseError
{
public:
    divisionByZeroError(std::string filename, std::string classname, int line, std::string time,
                  std::string info = "Zero division error") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class badMultiplySizes : public baseError
{
public:
    badMultiplySizes(std::string filename, std::string classname, int line, std::string time,
                        std::string info = "This matrixs sizes makes unable to perform multiply") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class nonEqualSizesError : public baseError
{
public:
    nonEqualSizesError(std::string filename, std::string classname, int line, std::string time,
                       std::string info = "You can add only matrix have sizes like first") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class badInitSizes : public baseError
{
public:
    badInitSizes(std::string filename, std::string classname, int line, std::string time,
                std::string info = "You can not use those sizes") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class UnableToExclude: public baseError
{
public:
    UnableToExclude(std::string filename, std::string classname, int line, std::string time,
                            std::string info = "Wrong sizes to exclude") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class UnableToFindDeterminant: public baseError
{
public:
    UnableToFindDeterminant(std::string filename, std::string classname, int line, std::string time,
                  std::string info = "Unable to find determinant of this matrix") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class UnableToInverse: public baseError
{
public:
    UnableToInverse(std::string filename, std::string classname, int line, std::string time,
                            std::string info = "Unable to inverse this matrix") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class badMemoryAlloc : public baseError
{
public:
    badMemoryAlloc(std::string filename, std::string classname, int line, std::string time,
                 std::string info = "Memory could not be allocated") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class badIteratorIndex : public baseError
{
public:
    badIteratorIndex(std::string filename, std::string classname, int line, std::string time,
                   std::string info = "BadIteratorIndex") :
            baseError(filename, classname, line, time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};

class EmptyIterator: public baseError
{
public:
    EmptyIterator(std::string filename, std::string classname, int line, std::string time,
                     std::string info = "Iterator is Empty") :
            baseError(filename, classname, line,  time, info) {};
    virtual const char* what() const noexcept
    {
        return errorInfo.c_str();
    }
};
#endif //CPP17TEST_ERRORS_H
