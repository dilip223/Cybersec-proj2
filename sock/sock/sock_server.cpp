#include "server.h"
#include "crc.h"
using namespace std;


int main()
{
    for(int i=1; i<=3; i++){
        string stu, enc_stu, msg="";
        enc_stu.append(first(i));
        //enc_stu.append("xy zsdsdasdasds");
        cout << "The unencoded message without CRC is\n" << enc_stu << endl;
        stu.append(encryptDecrypt(enc_stu));
        cout << "\nThe encoded message without CRC is\n" << stu << endl;
        msg.append(crc(stu));
        cout << "\nThe encoded message with CRC is\n" << msg << endl;

        string temp = msg;
        char* msg_ch = new char[temp.length() + 1];
        strcpy(msg_ch, temp.c_str());
        //cout << "The encoded message with character is" << msg_ch << endl;
        //main locals
        long SUCCESSFUL;
        WSAData WinSockData;
        WORD DLLVERSION;

        //WORDS = objects of a data size that a processor naturally handles (such as 16 or 32-bit)
        DLLVERSION = MAKEWORD(2, 1); //macro to create WORD value by concatenating its arguments

        //Start Winsock DLL
        SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

        //Create Socket Structure
        SOCKADDR_IN ADDRESS;
        int AddressSize = sizeof(ADDRESS);

        //Create Sockets
        SOCKET sock_LISTEN; //listen for incoming connection
        SOCKET sock_CONNECTION; //active if connection found

        //socket Arguments: AF_INET = internet domain,
        //SOCK_STREAM = connection oriented with TCP 
        sock_CONNECTION = socket(AF_INET, SOCK_STREAM, NULL);
        ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1"); //Set IP
        ADDRESS.sin_family = AF_INET;
        ADDRESS.sin_port = htons(444); //port

        sock_LISTEN = socket(AF_INET, SOCK_STREAM, NULL);
        bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
        listen(sock_LISTEN, SOMAXCONN); //listen without limits

        //If connection found:
        //for (;;)
        //{
        cout << "\n\tSERVER: WAITING for incoming connection...";
        if (sock_CONNECTION = accept(sock_LISTEN, (SOCKADDR*)&ADDRESS, &AddressSize))
        {
            cout << "\n\tA connection found!" << endl;
            SUCCESSFUL = send(sock_CONNECTION, msg_ch, 10000, NULL);

        }
        SUCCESSFUL= WSACleanup();
        system("pause");
    }
    return 0;
}
