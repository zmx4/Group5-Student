// Group5-Student.cpp: 定义应用程序的入口点。
//

#include "Group5-Student.h"
#include "rapidcsv.h"
#define endl "\n"
using namespace std;
int languages = 0;
// 定义学生结构体
struct student
{
	string name;
	int64_t id;
	int age;
	string birthday;
	// subject ,times, score
	struct StudentScore
	{
		string subject;
		int times;
		int score;
	};
};

class printmenu
{
public:
	void printMenu()
	{
		if (languages == 0)
		{
			cout << "1. Add student" << endl;
			cout << "2. Delete student" << endl;
			cout << "3. Modify student" << endl;
			cout << "4. Query student" << endl;
			cout << "5. Settings" << endl;
			cout << "6. Exit" << endl;
		}
		else if (languages == 1)
		{
			cout << "1. 添加学生" << endl;
			cout << "2. 删除学生" << endl;
			cout << "3. 修改学生" << endl;
			cout << "4. 查询学生" << endl;
			cout << "5. 设置" << endl;
			cout << "6. 退出" << endl;
		}
	}
	void printSecondMenu()
	{
		if (languages == 0)
		{
			cout << "1. Modify student id" << endl;
			cout << "2. Modify student name" << endl;
			cout << "3. Modify student birthday" << endl;
			cout << "4. Modify student subject" << endl;
		}
		else if (languages == 1)
		{
			cout << "1. 修改学生学号" << endl;
			cout << "2. 修改学生姓名" << endl;
			cout << "3. 修改学生生日" << endl;
			cout << "4. 修改学生科目" << endl;
		}
	}
	void printSettingsMenu()
	{
		if (languages == 0)
		{
			cout << "1. Language" << endl;
		}
		else if (languages == 1)
		{
			cout << "1. 语言" << endl;
		}
	}
};
/*
static inline void printMenu()
{
	if (languages == 0)
	{
		cout << "1. Add student" << endl;
		cout << "2. Delete student" << endl;
		cout << "3. Modify student" << endl;
		cout << "4. Query student" << endl;
		cout << "5. Settings" << endl;
		cout << "6. Exit" << endl;
	}
	else if (languages == 1)
	{
		cout << "1. 添加学生" << endl;
		cout << "2. 删除学生" << endl;
		cout << "3. 修改学生" << endl;
		cout << "4. 查询学生" << endl;
		cout << "5. 设置" << endl;
		cout << "6. 退出" << endl;
	}
}
static inline void printSecondMenu()
{
	if (languages == 0)
	{
		cout << "1. Modify student id" << endl;
		cout << "2. Modify student name" << endl;
		cout << "3. Modify student birthday" << endl;
		cout << "4. Modify student subject" << endl;
	}
	else if (languages == 1)
	{
		cout << "1. 修改学生学号" << endl;
		cout << "2. 修改学生姓名" << endl;
		cout << "3. 修改学生生日" << endl;
		cout << "4. 修改学生科目" << endl;
	}
}
static inline void printSettingsMenu()
{
	if (languages == 0)
	{
		cout << "1. Language" << endl;
	}
	else if (languages == 1)
	{
		cout << "1. 语言" << endl;
	}
}
*/

void recoverCSVfromlog(const int &backsteps)
{
	ofstream outFile("log.log", ios::app);
	//to be done
}
// 写入日志
static void writeLog(const string &done,const string &attribute)
{
	ofstream outFile("log.log", ios::app);
	if (outFile.is_open()) {
		string msg = std::format("\n[{}] {} {}",
			chrono::system_clock::now(),
			done,
			attribute,
			"\n");
		outFile.write(msg.c_str(), msg.size());
		outFile.close();
	}
	else {
		if (languages == 0)
		{
			cout << "Unable to open log file" << endl;
		}
		else if (languages == 1)
		{
			cout << "无法打开日志文件" << endl;
		}
	}
	
}
// 创建 printmenu 对象
printmenu menu;

int main()
{
	
	// 检测是否存在data.csv文件,如果不存在则创建,创建完成后打开,等待输入
	if (!filesystem::exists("data.csv"))
	{
		ofstream file("data.csv");
		file.close();
	}
	//读取设置文件
	if (!filesystem::exists("Settings.txt"))
	{
		ofstream file("Settings.txt");
		file << "Language: English" << endl;
		file.close();
	}
	else
	{
		ifstream file("Settings.txt");
		string line;
		while (getline(file, line))
		{
			if (line.find("Language") != string::npos)
			{
				if (line.find("English") != string::npos)
				{
					languages = 0;
				}
				else if (line.find("Chinese") != string::npos)
				{
					languages = 1;
				}
			}
		}
		file.close();
	}
	//检测日志文件是否存在,如果不存在则创建
	if(!filesystem::exists("log.log"))
	{
		ofstream file("log.log");
		file.close();
		ofstream outFile("log.log");
		outFile << "["<< chrono::system_clock::now()<<"]"<<"Log file created" << endl;
		outFile.close();
	}
	else
	{
		ofstream outFile("log.log", ios::app);
		outFile << "[" << chrono::system_clock::now() << "]" << "Data.CSV opened" << endl;
		outFile.close();
	}
	// 创建一个csv对象,并将data.csv文件作为参数传入
	rapidcsv::Document doc("data.csv");

	while (true)
	{
		menu.printMenu();
		// 选择操作
		int choice;
		cin >> choice;
		// 根据选择的操作进行相应的操作
		switch (choice)
		{
		case 1:
		{
			student stu;
			if (languages == 0)
			{
				cout << "Please input student name: ";
				cin >> stu.name;
				cout << "Please input student id: ";
				cin >> stu.id;
			}
			else if (languages == 1)
			{
				cout << "请输入学生姓名: ";
				cin >> stu.name;
				cout << "请输入学生学号: ";
				cin >> stu.id;
			}
			//cout << "Please input student age: ";
			//cin >> stu.age;
			if (languages == 0)
			{
				cout << "Please input student birthday: ";
			}
			else if (languages == 1)
			{
				cout << "请输入学生出生日期: ";
			}
			cin >> stu.birthday;
			//计算年龄
			stu.age = 2024 - stoi(stu.birthday.substr(0, 3));
			int64_t row = doc.GetRowCount();
			// 将学生信息写入csv文件
			doc.SetCell(1, row, stu.name);
			doc.SetCell(2, row, stu.id);
			doc.SetCell(3, row, stu.age);
			doc.SetCell(4, row, stu.birthday);
			doc.Save();
			string thingDone = "Student added";
			//writeLog(thingDone, stu.name);
			
			ofstream outFile("log.log", ios::app);
			outFile << "[" << chrono::system_clock::now() << "]" << "Student " << stu.name << " added"<<"age:"<<stu.age<<"birthday:"<<stu.birthday<<"ID:"<<stu.id << endl;
			outFile.close();
			
			break;
		}
		case 2:
		{
			int64_t id;
			if (languages == 0)
			{
				cout << "Please input student id: ";
			}
			else if (languages == 1)
			{
				cout << "请输入学生学号: ";
			}
			cin >> id;
			int64_t row = doc.GetRowCount();
			string RemovedStudentAttribute = "";
			for (int i = 0; i < row; i++)
			{
				if (doc.GetCell<int64_t>(2, i) == id)
				{
					RemovedStudentAttribute += "Name";
					RemovedStudentAttribute = doc.GetCell<string>(1, i);
					RemovedStudentAttribute += "Age";
					RemovedStudentAttribute += to_string(doc.GetCell<int>(3, i));
					RemovedStudentAttribute += "Birthday";
					RemovedStudentAttribute += doc.GetCell<string>(4, i);
					doc.RemoveRow(i);
					doc.Save();
					break;
				}
			}
			RemovedStudentAttribute = "ID:" + to_string(id) + RemovedStudentAttribute;
			string thingDone = "Student deleted";
			//writeLog(thingDone, RemovedStudentAttribute);
				/*
				cout << "Name: " << doc.GetCell<string>(1, i) << endl;
				cout << "ID: " << doc.GetCell<int64_t>(2, i) << endl;
				cout << "Age: " << doc.GetCell<int>(3, i) << endl;
				cout << "Birthday: " << doc.GetCell<string>(4, i) << endl;
				*/
			
			ofstream outFile("log.log", ios::app);
			outFile << "[" << chrono::system_clock::now() << "]" << "Student " << id << " deleted" << endl;
			outFile.close();
			
			break;
		}
		case 3:
		{
			menu.printSecondMenu();
			int opearation; cin >> opearation;
			switch (opearation)
			{
			case 1:
			{
				int64_t id;
				if (languages == 0)
				{
					cout << "Please input student id: ";
				}
				else if (languages == 1)
				{
					cout << "请输入学生学号: ";
				}
				cin >> id;
				int64_t row = doc.GetRowCount();
				for (int i = 0; i < row; i++)
				{
					if (doc.GetCell<int64_t>(2, i) == id)
					{
						if (languages == 0)
						{
							cout << "Please input new student id: ";
						}
						else if (languages == 1)
						{
							cout << "请输入新的学生学号: ";
						}
						cin >> id;
						doc.SetCell(2, i, id);
						doc.Save();
						ofstream outFile("log.log", ios::app);
						outFile << "[" << chrono::system_clock::now() << "]" << "Student " << id << " modified" << endl;
						outFile.close();
						break;
					}
				}
				break;
			}
			case 2:
			{
				int64_t id;
				if (languages == 0)
				{
					cout << "Please input student id: ";
				}
				else if (languages == 1)
				{
					cout << "请输入学生学号: ";
				}
				cin >> id;
				int64_t row = doc.GetRowCount();
				for (int i = 0; i < row; i++)
				{
					if (doc.GetCell<int64_t>(2, i) == id)
					{
						string name;
						if (languages == 0)
						{
							cout << "Please input new student name: ";
						}
						else if (languages == 1)
						{
							cout << "请输入新的学生姓名: ";
						}
						cin >> name;
						doc.SetCell(1, i, name);
						doc.Save();
						ofstream outFile("log.log", ios::app);
						outFile << "[" << chrono::system_clock::now() << "]" << "Student " << id << " modified" << endl;
						outFile.close();
						break;
					}
				}
				break;
			}
			case 3:
			{
				int64_t id;
				if (languages == 0)
				{
					cout << "Please input student id: ";
				}
				else if (languages == 1)
				{
					cout << "请输入学生学号: ";
				}
				cin >> id;
				int64_t row = doc.GetRowCount();
				for (int i = 0; i < row; i++)
				{
					if (doc.GetCell<int64_t>(2, i) == id)
					{
						string birthday;
						if (languages == 0)
						{
							cout << "Please input new student birthday: ";
						}
						else if (languages == 1)
						{
							cout << "请输入新的学生出生日期: ";
						}
						cin >> birthday;
						doc.SetCell(4, i, birthday);
						doc.Save();
						ofstream outFile("log.log", ios::app);
						outFile << "[" << chrono::system_clock::now() << "]" << "Student " << id << " modified" << endl;
						outFile.close();
						break;
					}
				}
				break;
			}
			case 4:
			{
				int64_t id;
				cout << "Please input student id: ";
				cin >> id;
				int64_t row = doc.GetRowCount();
				for (int i = 0; i < row; i++)
				{
					if (doc.GetCell<int64_t>(2, i) == id)
					{
						string subject;
						int times, score;
						if (languages == 0)
						{
							cout << "Please input subject: ";
							cin >> subject;
							cout << "Please input times: ";
							cin >> times;
							cout << "Please input score: ";
							cin >> score;
						}
						else if (languages == 1)
						{
							cout << "请输入科目: ";
							cin >> subject;
							cout << "请输入次数: ";
							cin >> times;
							cout << "请输入分数: ";
							cin >> score;
						}
						doc.SetCell(5, i, subject);
						doc.SetCell(6, i, times);
						doc.SetCell(7, i, score);
						doc.Save();
						ofstream outFile("log.log", ios::app);
						outFile << "[" << chrono::system_clock::now() << "]" << "Student " << id << " modified" << endl;
						outFile.close();
						break;
					}
				}
				break;
			}
			}
		}
		case 4:
		{
			int64_t id;
			cout << "Please input student id: ";
			cin >> id;
			int64_t row = doc.GetRowCount();
			for (int i = 0; i < row; i++)
			{
				if (doc.GetCell<int64_t>(2, i) == id)
				{
					cout << "Name: " << doc.GetCell<string>(1, i) << endl;
					cout << "ID: " << doc.GetCell<int64_t>(2, i) << endl;
					cout << "Age: " << doc.GetCell<int>(3, i) << endl;
					cout << "Birthday: " << doc.GetCell<string>(4, i) << endl;
					//cout << "Subject: " << doc.GetCell<string>(5, i) << endl;
					//cout << "Times: " << doc.GetCell<int>(6, i) << endl;
					//cout << "Score: " << doc.GetCell<int>(7, i) << endl;
					ofstream outFile("log.log", ios::app);
					outFile << "[" << chrono::system_clock::now() << "]" << "Student " << id << " queried" << endl;
					outFile.close();
					break;
				}
			}
			break;
		}
		case 5:
		{
			menu.printSettingsMenu();
			int settingsChoice;
			cin >> settingsChoice;
			switch (settingsChoice)
			{
			case 1:
			{
				cout << "1. English" << endl;
				cout << "2. Chinese" << endl;
				int languageChoice;
				cin >> languageChoice;
				switch (languageChoice)
				{
				case 1:
				{
                    cout << "Language has been set to English" << endl;
                    ifstream file("Settings.txt");
                    string line;
                    vector<string> lines;
                    while (getline(file, line))
                    {
                    if (line.find("Language") != string::npos)
                    {
                    line = "Language: English";
                    }
                    lines.push_back(line);
                    }
                    file.close();
                    ofstream outFile("Settings.txt");
                    for (const auto& l : lines)
                    {
                    outFile << l << endl;
                    }
                    outFile.close();
					ofstream outLog("log.log", ios::app);
					outLog << "[" << chrono::system_clock::now() << "]" << "Language had been switched to English" << endl;
					outLog.close();
                    break;
				}
				case 2:
				{
					cout << "语言已设置为中文" << endl;
					ifstream file("Settings.txt");
					string line;
					vector<string> lines;
					while (getline(file, line))
					{
						if (line.find("Language") != string::npos)
						{
							line = "Language: Chinese";
						}
						lines.push_back(line);
					}
					file.close();
					ofstream outFile("Settings.txt");
					for (const auto& l : lines)
					{
						outFile << l << endl;
					}
					outFile.close();
					ofstream outLog("log.log", ios::app);
					outLog << "[" << chrono::system_clock::now() << "]" << "Language had been switched to Chinese" << endl;
					outLog.close();
					//重启程序
					
					break;
				}
				default:
				{
					cout << "Invalid input" << endl;
					break;
				}
				}
				break;
			}
			}
		default:
		{
			ofstream outFile("log.log", ios::app);
			outFile << "[" << chrono::system_clock::now() << "]" << "Program exited" << endl;
			outFile.close();
			return 0;
		}
		}
		}
	}
}