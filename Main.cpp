#include <iostream>
#include "FileUtils.cpp"
using namespace std;

FileUtils fileUtils;

int main() {
    int key;
    RecordModel tmp;

    fileUtils.loadDataFromFile();

    while (true) {
        cout << "1. Xem tất cả các bản ghi" << endl;
        cout << "2. Tìm kiếm theo ID" << endl;
        cout << "3. Tìm kiếm theo tên" << endl;
        cout << "4. Tìm kiếm theo email" << endl;
        cout << "5. Sửa bản ghi" << endl;
        cout << "6. Thêm bản ghi" << endl;
        cout << "7. Xoá bản ghi" << endl;
        cout << "8. Thoát" << endl;
        cin >> key;

        switch(key) {
            case 1:
                fileUtils.displayAllData();
                break;

            case 2:
                int id;
                cout << "Nhập ID: ";
                cin >> id;
                if (id <= 0 || id > fileUtils.getTotalRecord()) {
                    cout << "ID không hợp lệ \n";
                } else {
                    fileUtils.displayDataById(id);
                }
                break;

            case 5:
                cout << "Nhập ID: ";
                cin >> id;
                if (id <= 0 || id > fileUtils.getTotalRecord()) {
                    cout << "ID không hợp lệ \n";
                } else {
                    cout << "Sửa bản ghi: \n";
                    fileUtils.displayDataById(id);

                    

                    cout << "name: ";
                    cin >> tmp.name;
                    cout << "email: ";
                    cin >> tmp.email;
                    cout << "phone: ";
                    cin >> tmp.phone;
                    cout << "bill: ";
                    cin >> tmp.bill;
                    fileUtils.setRecordModelById(id, tmp);
                }
                break;
                
            case 6:
                cout << "Thêm bản ghi: \n";

                cout << "name: ";
                cin >> tmp.name;
                cout << "email: ";
                cin >> tmp.email;
                cout << "phone: ";
                cin >> tmp.phone;
                cout << "bill: ";
                cin >> tmp.bill;
                fileUtils.addRecord(tmp);
                break;

            case 8:
                fileUtils.loadAllDataToFile();
                return 0;
            default:
                break;
        }
    }
    return 0;
}