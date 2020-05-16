# cybersec-proj2
This project simulates the transfer of an encoded file over a network. The file is encoded on the server side and decoded on the client side. The project will perform data transmission for sensitive student information.

## Project components

The project-2 has been presented as a visual studio solution. It has two projects inside the solution, server and client projects. Each project will have its own dependencies present in its header files. There are 3 cpp files present in the server project and 2 in the client project.
Server project:
"first.cpp" - The student data is generated and saved in text files. The first stage XOR encoding is performed in this stage.
"crc.cpp" - The cyclic redundancy is performed in this section with the sppecified key.
"sock_server.cpp" - The main program. The socket programming is performed and data is sent over a port in this section.

Client project:
"sock_client.cpp" - The main function for client side. Socket functions are employed to perform data recieving. The XOR decoding is also performed in this section.
"crc_rev.cpp"- The modulo-2 division is performed and remainder is determined to check for error in transmission.

To install the project, just dowload the zip and extract the solution. Needs Visual Studio.

## Dependencies

Notable Libraries required outside the standard C++ libraries include: 

WinSock2
sdkddkver

## Usages

The project can be used to perform encoded data transmission over a network. The server and clients can be in the same or different computers. Various other encoding strategies can be incorporated in the project.

