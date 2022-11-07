#define MAX_RECORD 100005

#include<iostream>
#include<string>
#include <fstream>
using namespace std;

string DATA_FILE = "data.txt";

int ID_SPACE = 5;
int RECORD_SPACE = 20;

struct RecordModel {
	string id;
	string name;
	string email;
	string phone;
	string bill;
};

RecordModel LoadedData[MAX_RECORD];

class FileUtils {
public:

	// Chen du lieu vao cuoi FILE
	void appendDataToFile(RecordModel billModel) {
		string data = "";
		data += "\n" +
			billModel.id + "$" +
			billModel.name + "$" + 
			billModel.email + "$" + 
			billModel.phone + "$" + 
			billModel.bill + "$";


		ofstream MyFile(DATA_FILE, std::ios_base::app);
		MyFile << data;
		MyFile.close();
	}


	// Tai du lieu tu bo nho vao file
	void loadAllDataToFile() {
		ofstream MyInitFile(DATA_FILE);
		MyInitFile << "";
		MyInitFile.close();

		ofstream MyFile(DATA_FILE, std::ios_base::app);
		for(int i=1;i<=totalRecord;i++) {
			if(i!=1) {
				MyFile << "\n";
			}
			MyFile << LoadedData[i].id << "$" 
				<< LoadedData[i].name << "$"
				<< LoadedData[i].email << "$"
				<< LoadedData[i].phone << "$"
				<< LoadedData[i].bill << "$";

		}

		MyFile.close();
	}

	// Tai du lieu tu file vao bo nho
	void loadDataFromFile() {
		string aRecord;
		totalRecord = 0;

		ifstream MyFile(DATA_FILE);
		while (getline (MyFile, aRecord)) {
			LoadedData[totalRecord + 1] = formatRecordToStruct(aRecord);

			totalRecord ++;

			if (totalRecord == MAX_RECORD - 1) {
				break;
			}
		}
		cout << totalRecord << endl;
		MyFile.close();
	}


	// Hien thi toan bo du lieu
	void displayAllData() {
		cout << "ID   Name                Email               Phone               Bill                " << endl ;

		for (int i=1 ;i<=totalRecord;i++) {
			displayARecord(LoadedData[i]);
		}
	}

	// Hien thi ban ghi có @ID
	void displayDataById(int id) {
		cout << "ID   Name                Email               Phone               Bill                " << endl ;

		displayARecord(LoadedData[id]);
	}

	// Tra ve tong so ban ghi
	int getTotalRecord() {
		return totalRecord;
	}

	// Sua 1 ban ghi theo @ID
	void setRecordModelById(int id, RecordModel record) {
		string saveId = LoadedData[id].id;

		LoadedData[id] = record;
		LoadedData[id].id = saveId;
	}

	// Them ban ghi moi
	void addRecord(RecordModel record) {
		totalRecord++;
		LoadedData[totalRecord] = record;
		LoadedData[totalRecord].id = std::to_string(totalRecord);	
	}

private:
	int totalRecord;

	// Chuyen du lieu ve dung format
	RecordModel formatRecordToStruct(string data) {
		string tmpData[5];
		string recordField = "";
		int field = 0;
		int key = 0;
		while(data[key] != 0) {
			if (data[key] == '$') {

				tmpData[field] = recordField;
				field++;

				// Khoi tao lai bien tam
				recordField = "";
			} else {
				recordField += data[key];
			}

			key++;
		}

		RecordModel rnt;
		rnt.id = tmpData[0];
		rnt.name = tmpData[1];
		rnt.email = tmpData[2];
		rnt.phone = tmpData[3];
		rnt.bill = tmpData[4];
 		return (rnt);
	}

	void displayARecord(RecordModel record) {
		string display = "";
		display += record.id;
		for (int i=0;i<ID_SPACE-record.id.length();i++) {
			display += " ";
		}
		display+=record.name;
		for (int i=0;i<RECORD_SPACE-record.name.length();i++) {
			display += " ";
		}
		display+=record.email;
		for (int i=0;i<RECORD_SPACE-record.email.length();i++) {
			display += " ";
		}
		display+=record.phone;
		for (int i=0;i<RECORD_SPACE-record.phone.length();i++) {
			display += " ";
		}
		display+=record.bill;
		for (int i=0;i<RECORD_SPACE-record.bill.length();i++) {
			display += " ";
		}

		cout << display << endl;
	}
};