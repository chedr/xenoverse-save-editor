/**
 * File:        XenoverseException.h
 * Author:      chedr
 * Description: XenoverseException declarations
 */

#ifndef XENOVERSE_XENOVERSEEXCEPTION_H
#define XENOVERSE_XENOVERSEEXCEPTION_H

#include <exception>
#include <string>

class XenoverseException : public std::exception
{

public:

    /**
     * Constructor
     * Params: message
     */
    XenoverseException(std::string msg);


    /**
     * Get exception message
     * Return: cstring message
     */
    virtual const char *what(void) const throw();

private:

    /** Exception message */
    std::string message;

};

#endif //XENOVERSE_XENOVERSEEXCEPTION_H
