/*
The MIT License (MIT)

Copyright (c) 2013 Rajendra Kumar Uppal

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/


#include "MailRecipient.h"


MailRecipient::MailRecipient():
    _address(),
    _name(),
    _type(PRIMARY_RECIPIENT)
{
}


MailRecipient::MailRecipient(const MailRecipient& recipient):
    _address(recipient._address),
    _name(recipient._name),
    _type(recipient._type)
{
}


MailRecipient::MailRecipient(RecipientType type, const std::string& address):
    _address(address),
    _name(),
    _type(type)
{
}


MailRecipient::MailRecipient(RecipientType type, const std::string& address, const std::string& name):
    _address(address),
    _name(name),
    _type(type)
{
}


MailRecipient::~MailRecipient()
{
}


MailRecipient& MailRecipient::operator = (const MailRecipient& recipient)
{
    if ( this != &recipient ) {
        this->_address = recipient._address;
        this->_name = recipient._name;
        this->_type = recipient._type;
    }
    return *this;
}


MailRecipient::RecipientType MailRecipient::getType() const
{
    return _type;
}


void MailRecipient::setType(RecipientType type)
{
    _type = type;
}


const std::string& MailRecipient::getAddress() const
{
    return _address;
}


void MailRecipient::setAddress(const std::string& address)
{
    _address = address;
}


const std::string& MailRecipient::getName() const
{
    return _name;
}


void MailRecipient::setName(const std::string& name)
{
    _name = name;
}


// ~EOF
