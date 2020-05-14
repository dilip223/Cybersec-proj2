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

// Function to read text file into a single string variable
string readFile(string fileName)
{
	ifstream enFile;
	enFile.open(fileName);	// open the file

	stringstream strStream;
	strStream << enFile.rdbuf();		// read the file
	string str = strStream.str();		// str holds the content of the file

	//cout << str << "\n";				// FOR DEBUG
	enFile.close();
	return str;
}


string first(int n) {

	// Build txt file with sensitive information 
	student student1("Dolores", 18, 13, 2.75, "dolo1@school.edu", "3031231234", 1234, 45.82);
	student student2("Teddy", 19, 14, 3.42, "tedd5@school.edu", "3031234321", 4321, 14.42);
	student student3("Bernard", 20, 14, 3.90, "bern6@school.edu", "3037654321", 6543, 0.00);

	ofstream myfile;
	myfile.open("StudentProfile1.txt");
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
	myfile.close();


	ofstream myfile2;
	myfile2.open("StudentProfile2.txt");
	myfile2 << "Name:    " << student2.name << endl;
	myfile2 << "Age:     " << student2.age << endl;
	myfile2 << "Grade:   " << student2.grade << endl;
	myfile2 << "GPA:     " << student2.GPA << endl;
	myfile2 << "Email:   " << student2.email << endl;
	myfile2 << "Phone:   " << student2.phone << endl;
	myfile2 << "SSN:     " << student2.SSN << endl;
	myfile2 << "Balance: " << student2.balance << endl;
	myfile2 << "Courses: " << endl;
	myfile2 << "Parents: " << endl;
	myfile2.close();

	ofstream myfile3;
	myfile3.open("StudentProfile3.txt");
	myfile3 << "Name:    " << student3.name << endl;
	myfile3 << "Age:     " << student3.age << endl;
	myfile3 << "Grade:   " << student3.grade << endl;
	myfile3 << "GPA:     " << student3.GPA << endl;
	myfile3 << "Email:   " << student3.email << endl;
	myfile3 << "Phone:   " << student3.phone << endl;
	myfile3 << "SSN:     " << student3.SSN << endl;
	myfile3 << "Balance: " << student3.balance << endl;
	myfile3 << "Courses: " << endl;
	myfile3 << "Parents: " << endl;
	myfile3.close();

	//_____________________________________________________________________________________________
	// ENCRYPTION

	// Student 1
	string str1 = readFile("StudentProfile1.txt");		// Read text file into single string
	string encrypted1 = encryptDecrypt(str1);			// Encrypt this string

	ofstream myencfile1;
	myencfile1.open("encryptedStudentProfile1.txt");	// Write this encrypted string to new txt file
	myencfile1 << encrypted1 << endl;
	myencfile1.close();

	// Student 2
	string str2 = readFile("StudentProfile2.txt");
	string encrypted2 = encryptDecrypt(str2);

	ofstream myencfile2;
	myencfile2.open("encryptedStudentProfile2.txt");
	myencfile2 << encrypted2 << endl;
	myencfile2.close();

	// Student 3
	string str3 = readFile("StudentProfile3.txt");
	string encrypted3 = encryptDecrypt(str3);

	ofstream myencfile3;
	myencfile3.open("encryptedStudentProfile3.txt");
	myencfile3 << encrypted3 << endl;
	myencfile3.close();

	//_____________________________________________________________________________________________
	switch (n){
	case 1: 
		return str1;
		break;
	case 2: return str2;
			break;
	case 3: return str3;
			break;
	}
}