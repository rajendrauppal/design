
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
