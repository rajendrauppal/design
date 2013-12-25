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


#ifndef MailMessage_INCLUDED
#define MailMessage_INCLUDED


#include "MailRecipient.h"
#include <vector>


class MailMessage
{
public:
    typedef std::vector<MailRecipient> Recipients;
    typedef std::vector<std::string> Paths;

    MailMessage();
    ~MailMessage();

    void addRecipient(const MailRecipient& recipient);
    const Recipients& getRecipients() const;

    void setSubject(const std::string& subject);
    const std::string& getSubject() const;
    
    void setSender(const std::string& sender);
    const std::string& getSender() const;
    
    void setContent(const std::string& content);
    const std::string& getContent() const;

    void setDate(const std::string& date);
    const std::string& getDate() const;

    void addAttachment(const std::string& filepath);

private:
    MailMessage(const MailMessage&);
    MailMessage& operator = (const MailMessage&);

    Recipients _recipients;
    Paths _attachments;
    std::string _subject;
    std::string _sender;
    std::string _content;
    std::string _date;
};


#endif // MailMessage_INCLUDED
