/**
 * File:        XenoverseException.cpp
 * Author:      chedr
 * Description: XenoverseException definitions
 */

#include "XenoverseException.h"


XenoverseException::XenoverseException(std::string msg) : message(msg)
{

}


const char *XenoverseException::what() const throw()
{
    return this->message.c_str();
}
