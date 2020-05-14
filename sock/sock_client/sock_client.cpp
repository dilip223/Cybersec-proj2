#include "client.h"
#include "crc_rev.h"
#include <io.h>
using namespace std;

string encryptDecrypt(string toEncrypt) {
    char key = 'K';
    string output = toEncrypt;

    for (int i = 0; i < toEncrypt.size(); i++)

        output[i] = toEncrypt[i] ^ key;

    return output;
}

int main()
{
    for (int i = 1; i <= 3; i++) {

        long SUCCESSFUL;
        WSAData WinSockData;
        WORD DLLVERSION;
        DLLVERSION = MAKEWORD(2, 1);
        SUCCESSFUL = WSAStartup(DLLVERSION, &WinSockData);

        string RESPONSE;
        string CONVERTER;
        char MESSAGE[10000];

        SOCKADDR_IN ADDRESS;

        SOCKET sock;
        sock = socket(AF_INET, SOCK_STREAM, NULL);

        ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
        ADDRESS.sin_family = AF_INET;
        ADDRESS.sin_port = htons(444);

        connect(sock, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
        SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);

        cout << "\nMESSAGE from Server is:\n" << MESSAGE << endl;
        string str(MESSAGE);
        string final_dat = "", msg = "";
        msg.append(crc_rev(MESSAGE));
        cout << "\nThe data decoded after crc is:\n" << msg << endl;

        final_dat.append(encryptDecrypt(msg));
        cout << "\nThe data decoded after final decoding is:\n" << final_dat << endl;
        
        system("pause");
    }
    return 0;
}