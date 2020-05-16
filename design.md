## Write up for COSC 5010 Project 2
Dilip Pndit
Zachary Tovar


For this project we designed a scenario of client server communication 
sending sensitive information between eachother. The information sent 
was a student profile list containing info about each student. We 
wanted to use XOR encoding of this data before it was sent across the 
network in order to protect the sensitive information. To do this, we
wrote the student profile to a text file. This text file was then read
back into one string which was then XOR encoded and wrote back to a 
seperate text file. Then, the network was designed with a client and 
server side. 

## Server Side: 
The student data is read from a class. It is then XOR encoded with 
encryption key of ‘K’.  All of this is accomplished in the server-side 
function “first.cpp”. The key for Cyclic Redundancy check is X^3+1 which 
in binary is 1001. A modulo-2 division is performed on the binary string 
of the XOR encoded string. This is accomplished in server-side function 
“crc.cpp”. After obtaining the remainder, the remainder is appended to 
the end of the binary string (for the first student data, it was 010).
In the main function “sock_server.cpp”, socket programming is done. Port 
number 444 has been reserved for the communication. The server will 
indefinitely wait for a client connection. Once a client is found, it will 
transfer the first student data using send() function.The whole server-side 
program is done in iterations of 3 (number of students). After every 
iteration WSAcleanup is performed to send the next data over.Figure 3 in the pdf shows 
the server side for the first student data. As we can see, at the very end 
of CRC encoded binary string, the remainder 010 is appended. 

## Client Side: 

After running the executable for client-side program, a connection is 
established with the host. The recv() function will take the data and store 
it in a character buffer message. The received message is first sent to 
“crc_rev.cpp” function to perform a CRC decoding of the data with the key 
“1001”. If the remainder is zero, the data is not tampered and is successfully 
received as seen in the message in Figure 4 in the pdf. Otherwise, an error message will 
pop up saying there was a transmission error.The decoded binary string is 
recovered by eliminating its remainder. Then, the binary string is converted to 
character string using ASCII values. The resulting encoded string is finally 
XORed with the key “K” to retrieve the original student data. Figure 4 in the pdf shows the 
message received on the client side.
