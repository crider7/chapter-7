// Pseudocode PLD Chapter 7 #6a pg. 301
// Start
// Declarations
// InputFile masterFile;
// InputFile transactionFile;
// OutputFile newMasterFile;
// num mClientNumber, mtotalClientCost, tClientNumber,
//titemClientCost
// string mClientfName, mClientlName
// output "Master File Updating Starting"
// open masterFile "Master.rtf"
// open transactionFile "Transaction.rtf"
// open newMasterFile "newMaster.rtf"
// read mClientNumber, mClientfName, mClientlName, mtotalClientCost
//from masterFile
// read tClientNumber, titemClientCost from transactionFile
// while ( transactionFile not EOF )
// while (( masterFile not EOF) and (mClientNumber <
//tClientNumber))
// output mClientNumber, mClientfName, mClientlName,
//mtotalClientCost to newMasterFile
// read mClientNumber, mClientfName, mClientlName,
//mtotalClientCost from masterFile
// endwhile
// if (masterFile is EOF)
// output "Error Client ID: ", tClientNumber, " not in Master
//File."
// else if (mClientNumber == tClientNumber) then
// mtotalClientCost = mtotalClientCost + titemClientCost
// output mClientNumber, mClientfName, mClientlName,
//mtotalClientCost to newMasterFile
// read mClientNumber, mClientfName, mClientlName,
//mtotalClientCost from masterFile
// else if (mClientNumber > tClientNumber) then
// output "Error Client ID: ", tClientNumber, " not in Master
//File."
// endif
// read tClientNumber, titemClientCost from transactionFile
// endwhile
// while (masterFile not EOF)
// output mClientNumber, mClientfName, mClientlName,
//mtotalClientCost to newMasterFile
// read mClientNumber, mClientfName, mClientlName,
//mtotalClientCost from masterFile
// endwhile
// output "Master File Updating Complete"
// close masterFile
// close transactionFile
// close newMasterFile
// Stop
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream masterFile("Master.rtf");
    ifstream transactionFile("Transaction.rtf");
    ofstream newMasterFile("newMaster.rtf");

    double mClientNumber, mtotalClientCost, tClientNumber, titemClientCost;
    string mClientfName, mClientlName;

    cout << "Master File Updating Starting" << endl;

    masterFile.open("Master.rtf");
    transactionFile.open("Transaction.rtf");
    newMasterFile.open("newMaster.rtf");

    masterFile >> mClientNumber >> mClientfName >> mClientlName >> mtotalClientCost;
    transactionFile >> tClientNumber >> titemClientCost;

    while (!transactionFile.eof()) {
        while (!masterFile.eof() && mClientNumber < tClientNumber) {
            newMasterFile << mClientNumber << " " << mClientfName << " " << mClientlName << " " << mtotalClientCost << endl;
            masterFile >> mClientNumber >> mClientfName >> mClientlName >> mtotalClientCost;
        }

        if (masterFile.eof()) {
            cout << "Error Client ID: " << tClientNumber << " not in Master File." << endl;
        } else if (mClientNumber == tClientNumber) {
            mtotalClientCost += titemClientCost;
            newMasterFile << mClientNumber << " " << mClientfName << " " << mClientlName << " " << mtotalClientCost << endl;
            masterFile >> mClientNumber >> mClientfName >> mClientlName >> mtotalClientCost;
        } else if (mClientNumber > tClientNumber) {
            cout << "Error Client ID: " << tClientNumber << " not in Master File." << endl;
        }

        transactionFile >> tClientNumber >> titemClientCost;
    }

    while (!masterFile.eof()) {
        newMasterFile << mClientNumber << " " << mClientfName << " " << mClientlName << " " << mtotalClientCost << endl;
        masterFile >> mClientNumber >> mClientfName >> mClientlName >> mtotalClientCost;
    }

    cout << "Master File Updating Complete" << endl;

    masterFile.close();
    transactionFile.close();
    newMasterFile.close();

    return 0;
}
