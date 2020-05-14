#include <iostream>
#include <stdio.h>
#include <sstream>
#include <bitset>
using namespace std;

string crc_rev(string ms) {
    string msg_bin, key, encoded, final_msg1 = "";
    msg_bin.append(ms);
    key = "1001";
    int m = msg_bin.length(), n = key.length();
    encoded += msg_bin;
    for (int i = 1; i <= n - 1; i++)
        encoded += '0';
    for (int i = 0; i <= encoded.length() - n;) {
        for (int j = 0; j < n; j++)
            encoded[i + j] = encoded[i + j] == key[j] ? '0' : '1';
        for (; i < encoded.length() && encoded[i] != '1'; i++);
    }
    for(char i: encoded.substr(encoded.length()-key.length()))
    {
        if (i != '0') {
            cout << "Error in data transmission for this data.."<<endl;
            return 0;
    }
    }
    cout << "Data successfully recieved\n\n" << endl;

    final_msg1 = msg_bin.erase(m-n+1);
    stringstream sstream(final_msg1);
    string final_msg="";
    while (sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        final_msg += c;
    }
    return final_msg;
}

