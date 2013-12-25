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


#include <iostream>
#include "MailMessage.h"


using std::cout;
using std::cin;
using std::endl;


#define print(s) cout<<endl<<(s)<<endl;


void send(const MailMessage& msg)
{
    /// Just a skeleton.
    /// Assuming that there is a third party send
    /// API which is responsible for sending email.
    print( "Sender: " + msg.getSender() );

    print("Recipients:");
    MailMessage::Recipients recipients = msg.getRecipients();
    for ( auto start = recipients.begin(); start != recipients.end(); ++start )
        print( (*start).getAddress() );

    print("Subject: " + msg.getSubject() );
    print("Content: " + msg.getContent() );
}


void Test_MailMessage()
{
    std::string sender("rajen.iitd@gmail.com");
    std::string recipient("uppal@adobe.com");
    std::string subject("Generated email");
    std::string content = "Hi ";
    content += recipient;
    content += ",\n\n";
    content += "Have a good day!\n\n";
    content += "Regards,\n";
    content += "A-Team";
    std::string attachment("C:\\DSC.jpg");

    MailMessage message;
    message.setSender( sender );
    message.addRecipient( MailRecipient(MailRecipient::PRIMARY_RECIPIENT, recipient) );
    message.setSubject( subject );
    message.setContent( content );
    message.addAttachment( attachment );

    send(message);
}


int main(int argc, char ** argv)
{
    Test_MailMessage();

    print("Press any key to continue...");
    cin.get();
    return 0;
}

// ~EOF
