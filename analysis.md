Write up for COSC 5010 Project 2
Dilip Pndit
Zachary Tovar

Data Tampering: 

To illustrate data tampering, we will consider a scenario where the third 
student’s data is lost/tampered intentionally during data transmission. In the 
client side, after receiving the message we will edit some binary bits such that 
the remainder of CRC key division will not be zero. The client program should be 
able to detect the tampering and send a message to resend the data.Figure 5 in the pdf is the 
data for student “Bernard” which is successfully sent from the server. However, 
before the message is received in the “sock_client.cpp”, a FOR loop is implemented 
to change some bits in the MESSAGE buffer. The resulting message does not yield a 0 
remainder and error message is sent indicating data needs to be re sent which is 
seen in Figure 6 in the pdf.

IDA pro analysis of the software:

In this section, the disassembly is done on the executable of the server file. We 
will attempt to reverse engineer the keys for XOR encoding and Cyclic Redundancy Check. 
We will assume to have some information about the program. 

First in the IDA disassembly, we check for the imports of the data. We can see two 
interesting imports related to file handling and socket. There are multiple imports 
such as fread, fwrite, fclose related to file handling. We know that running the 
executable we obtain encrypted and decrypted student information on the code directory.
Another import is related to network. There are imports of WSAstartup, WSAcleanup, listen, 
bind, socket, etc which indicate the program will listen for upcoming connection.From the 
imports, we went to the subroutines where they were called. It was difficult to decode 
anything from file imports. However, it was seen that the all the network functions were 
called from a single subroutine sub_4236C0. From Figure 7 in the pdf, we can see the calls the 
subroutine makes to WSAstartup, creates a socket, and uses INETaddress. Furthermore, to 
prove that it was main function, at the start of the function the stack content is compared 
with 3 which represents number of student data for which the server code is iterated. It can 
be seen in Figure 8 in the pdf.Inside the main function, strings were found that represented the message 
displayed on screen. First, we checked the section for CRC. Before displaying the binary 
string, a call was made to sub_411636. Using the X-ref, the subroutine sub_41A230 called the 
function where an offset value of 1001 is pushed as seen in Figure 9 in the pdf. Location loc_41A501 of 
the subroutine has a long arithmetic operation which hints at modulo-2 division and remainder 
calculation. Thus, we can conclude that sub_41A230 represents the “crc.cpp” where CRC was 
performed.Next, we need to find the key for the XOR encoding. A search is made for all 
possible XOR opcodes and the initializing operations are discarded. Still, there are numerous 
XOR operations between registers, registers and memory locations. So, it is hard to find the 
key using this approach.Again, we will reverse our way from the main function. Since we have 
the subroutine for CRC, we know that the XOR encoding is done prior to the CRC. So, we will 
monitor calls made before the CRC call. One of the calls to the subroutines, sub_411726 made 
a jump to a location in the subroutine sub_417F90. The subroutine was a hub for many subroutines 
but interestingly, it was a hub for subroutines which used the file imports. Searching for XOR 
operations in subroutines that called sub_417F90 from sub_411726, the subroutine sub_41ECD0 was 
most susceptible. It XORed the content obtained from sub_417F90 with a variable var_15 as seen 
in Figure 10 in the pdf. Moving up to see what was loaded in var_15, Figure 11 in the pdf should a value of 4Bh was 
loaded. It is the ASCII of ‘K’ which is the key for XOR encoding in our case.
