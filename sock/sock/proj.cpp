#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// This class just constructs a student, I haven't figured out how to do complex data types
class student {
public:
	string name;
	int age;
	int grade;
	double GPA;
	//char courses[4];
	string email;
	string phone;
	double balance;
	int SSN;
	//char parents[2];
public:
	student(string tname, int tage, int tgrade, double tGPA, string temail, string tphone, int tSSN, double tbalance)
	{
		name = tname;
		age = tage;
		grade = tgrade;
		GPA = tGPA;
		email = temail;
		phone = tphone;
		SSN = tSSN;
		balance = tbalance;
	};
};

// This function encrypts and decrypts a string with XOR (Key is K)
string encryptDecrypt(string toEncrypt) {
	char key = 'K';
	string output = toEncrypt;

	for (int i = 0; i < toEncrypt.size(); i++)
		output[i] = toEncrypt[i] ^ key;

	return output;
}

int main() {

	// Build txt file with sensitive information 
	student student1("Dolores", 18, 13, 2.75, "dolo1@school.edu", "3031231234", 1234, 45.82);
	student student2("Teddy", 19, 14, 3.42, "tedd5@school.edu", "3031234321", 4321, 14.42);
	ofstream myfile;
	myfile.open("StudentProfile.txt");
	myfile << "Name:    " << student1.name << endl;
	myfile << "Age:     " << student1.age << endl;
	myfile << "Grade:   " << student1.grade << endl;
	myfile << "GPA:     " << student1.GPA << endl;
	myfile << "Email:   " << student1.email << endl;
	myfile << "Phone:   " << student1.phone << endl;
	myfile << "SSN:     " << student1.SSN << endl;
	myfile << "Balance: " << student1.balance << endl;
	myfile << "Courses: " << endl;
	myfile << "Parents: " << endl;
	myfile << endl;
	myfile << "Name:    " << student2.name << endl;
	myfile << "Age:     " << student2.age << endl;
	myfile << "Grade:   " << student2.grade << endl;
	myfile << "GPA:     " << student2.GPA << endl;
	myfile << "Email:   " << student2.email << endl;
	myfile << "Phone:   " << student2.phone << endl;
	myfile << "SSN:     " << student2.SSN << endl;
	myfile << "Balance: " << student2.balance << endl;
	myfile << "Courses: " << endl;
	myfile << "Parents: " << endl;
	myfile.close();

	//_____________________________________________________________________________________________
	// ENCRYPTION

	// This opens the txt file and read all contents into a single string

	ifstream enFile;
	enFile.open("StudentProfile.txt");	// open the file

	stringstream strStream;
	strStream << enFile.rdbuf();		// read the file
	string str = strStream.str();		// str holds the content of the file

	cout << str << "\n";				// FOR DEBUG
	enFile.close();

	// This sends this new string to the encryption function 

	string encrypted = encryptDecrypt(str);
	cout << "Encrypted:" << endl;		// FOR DEBUG
	cout << encrypted << endl;

	// Now write the encrypted string to a new text file

	ofstream myencfile;
	myencfile.open("encryptedStudentProfile.txt");
	myencfile << encrypted << endl;
	myencfile.close();





















	//_____________________________________________________________________________________________
	// DECRYPTION

	// To check if it worked, also added decryption section
	// This is the same exact process as the encryption function also decrypts 

	ifstream deFile;
	deFile.open("encryptedStudentProfile.txt");

	stringstream strStream2;
	strStream2 << deFile.rdbuf();
	string str2 = strStream2.str();

	cout << str2 << "\n";

	string decrypted = encryptDecrypt(str2);
	cout << "Decrypted:" << endl;		// FOR DEBUG
	cout << decrypted << endl;

	ofstream myencfile2;
	myencfile2.open("decryptedStudentProfile.txt");
	myencfile2 << decrypted;
	myencfile2.close();

	//_____________________________________________________________________________________________
	return 0;
}
