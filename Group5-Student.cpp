// Group5-Student.cpp: 定义应用程序的入口点。
//

#include "Group5-Student.h"
#include "rapidcsv.h"
using namespace std;

struct student
{
	string name;
	int64_t id;
	int age;
	string birthday;
	// subject ,times, score
	map<string, int, int> score;
};

void printMenu()
{
	cout << "1. Add student" << endl;
	cout << "2. Delete student" << endl;
	cout << "3. Modify student" << endl;
	cout << "4. Search student" << endl;
	cout << "5. Display all students" << endl;
	cout << "6. Exit" << endl;
}
void printSecondMenu()
{
	cout << "1. Modify student ID" << endl;
	cout << "2. Modify student name" << endl;
	cout << "3. Modify student birthday" << endl;
	cout << "4. Add subject" << endl;
	cout << "5. Modify subject Score" << endl;
	cout << "6. Delete subject" << endl;
	cout << "7. Back" << endl;
}
int main()
{
	// 检测是否存在data.csv文件,如果不存在则创建,创建完成后打开,等待输入
	if (!filesystem::exists("data.csv"))
	{
		ofstream file("data.csv");
		file.close();
	}
	
	// 创建一个csv对象,并将data.csv文件作为参数传入
	rapidcsv::Document doc("data.csv");

	while (true)
	{
		printMenu();
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			// 添加学生
			string name;
			int64_t id;
			string birthday;

			cin >> name >> id >> birthday;
			// 检测是否存在该学生
			if (doc.GetRowIdx(to_string(id)) != -1)
			{
				cout << "The student already exists" << endl;
				break;
			}
			// 计算年龄
			auto now = chrono::system_clock::now();
			// 计算年龄
			tm tm_birthday = {};
			istringstream ss(birthday);
			ss >> get_time(&tm_birthday, "%Y-%m-%d");
			time_t birthday_time_t = mktime(&tm_birthday);
			int age = std::chrono::duration_cast<std::chrono::years>(now - std::chrono::system_clock::from_time_t(birthday_time_t)).count();

			time_t now_time_t = std::chrono::system_clock::to_time_t(now);
			// 将学生信息写入csv文件
			doc.SetCell("name", to_string(id), name);
			doc.SetCell("id", to_string(id), to_string(id));
			doc.SetCell("age", to_string(id), to_string(age));
			doc.SetCell("birthday", to_string(id), birthday);
		}
		case 2:
		{
			// 删除学生
			int64_t id;
			cin >> id;
			// 检测是否存在该学生
			if (doc.GetRowIdx(to_string(id)) == -1)
			{
				cout << "The student does not exist" << endl;
				break;
			}
			// 删除学生信息
			doc.RemoveRow(to_string(id));
			break;
		}
		case 3:
		{
			int operation;
			cin >> operation;
			switch (operation)
			{
			case 1:
			{
				// 修改学生ID
				int64_t id, new_id;
				cin >> id >> new_id;
				// 检测是否存在该学生
				if (doc.GetRowIdx(to_string(id)) == -1)
				{
					cout << "The student does not exist" << endl;
					break;
				}
				// 修改学生ID
				doc.SetCell("id", to_string(id), to_string(new_id));
				break;
			}
			case 2:
			{
				// 修改学生姓名
				int64_t id;
				string name;
				cin >> id >> name;
				// 检测是否存在该学生
				if (doc.GetRowIdx(to_string(id)) == -1)
				{
					cout << "The student does not exist" << endl;
					break;
				}
				// 修改学生姓名
				doc.SetCell("name", to_string(id), name);
				break;
			}
			case 3:
			{
				// 修改学生生日
				int64_t id;
				string birthday;
				cin >> id >> birthday;
				// 检测是否存在该学生
				if (doc.GetRowIdx(to_string(id)) == -1)
				{
					cout << "The student does not exist" << endl;
					break;
				}
				// 修改学生生日
				doc.SetCell("birthday", to_string(id), birthday);
				break;
			}
			case 4:
			{
				// to be done
			}
			case 5:
			{
				// 修改学科
			}
			}

		case 6:
		{
			// 退出程序
			return 0;
		}
		default:
		{
			cout << "Invalid input" << endl;
		}
		}
		}
	}
}