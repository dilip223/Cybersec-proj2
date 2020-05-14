#include <iostream>
#include <stdio.h>
#include <bitset>
using namespace std;

string crc(string ms) {
    string msg_bin,msg, key, encoded, final_msg = "";
    msg.append(ms);
    for (char& _char : msg) {
        msg_bin += bitset<8>(_char).to_string();
    }
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
    final_msg = msg_bin + encoded.substr(encoded.length() - n + 1);
    cout<< "\nThe remainder is:\t"<< encoded.substr(encoded.length() - n + 1) << endl;
    return final_msg;
    }



