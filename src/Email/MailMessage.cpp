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


#include "MailMessage.h"


MailMessage::MailMessage():
    _subject(),
    _sender(),
    _content(),
    _date()
{
}


MailMessage::~MailMessage()
{
}


void MailMessage::addRecipient(const MailRecipient& recipient)
{
    _recipients.push_back( recipient );
}


const MailMessage::Recipients& MailMessage::getRecipients() const
{
    return _recipients;
}


void MailMessage::setSubject(const std::string& subject)
{
    _subject = subject;
}


const std::string& MailMessage::getSubject() const
{
    return _subject;
}
    

void MailMessage::setSender(const std::string& sender)
{
    _sender = sender;
}


const std::string& MailMessage::getSender() const
{
    return _sender;
}
    

void MailMessage::setContent(const std::string& content)
{
    _content = content;
}


const std::string& MailMessage::getContent() const
{
    return _content;
}


void MailMessage::setDate(const std::string& date)
{
    _date = date;
}

const std::string& MailMessage::getDate() const
{
    return _date;
}


void MailMessage::addAttachment(const std::string& filepath)
{
    _attachments.push_back( filepath );
}


// ~EOF
