#include<iostream>
#include<windows.h>
using namespace std;

class Latitude//γ��
{
	char direction;//��γ/��γ����N/S��ʾ
	float degree;
	float minute;
	float second;//�ȡ��֡����ʾγ��
public:
	Latitude() { direction = {}; degree = -1; minute = -1; second = -1; }
	void set(char c, float x, float y, float z) { direction = c; degree = x; minute = y; second = z; }
}; 
class Longitude//����
{
	char direction;//����/��������W/E��ʾ
	float degree;
	float minute;
	float second;
public:
	Longitude() { direction = {}; degree = -1; minute = -1; second = -1; }
	void set(char c, float x, float y, float z) { direction = c; degree = x; minute = y; second = z; }
};
class Place
{
	friend class User;
private:
	string province;
	string city;
	string town;
	string street;
	Latitude *latitude;
	Longitude *longitude;
	//γ��
	Place() { province = {}; city = {}; town = {}; street = {}; latitude = new Latitude(); longitude = new Longitude(); }
	void find_place_1(Latitude* latitude, Longitude* longitude, string& province, string& city, string& town, string& street)
	//���ݶ�λ�û�������û��ڵ�ͼ��ѡ����λ�ã��ҵ���Ӧ�ĳ��У��ء��磩
	{
		//���Ҷ�Ӧ���У���province��city��town����street����ӦΪ�õص�ʡ���С���
	}
	void Place_1(string province, string city, string town, string street, Latitude* latitude, Longitude* longitude)
	{
		//��ȡlatitude��longitude
		find_place_1(latitude, longitude, province, city, town, street);
	}
	void find_place_2(string& province, string& city, string& town, string& street, Latitude* latitude, Longitude* longitude)
	//�����û�����ĳ��У���λ�侭γ�ȣ��ڵ�ͼ���ҵ���Ӧ��λ��
	{
		//���Ҷ�Ӧ�ص㣬��latitude��Ӧ���õص�ʡ���С���
	}
	void Place_2(string province, string city, string town, string street, Latitude* latitude, Longitude* longitude)
	{
		//��ȡ������Ϣ
		find_place_2( province, city, town, street, latitude, longitude);
	}
};

class User
{
	long long int phone_number;
	string password;
	int age;
	int sex;
	//�ȸ�����Ϣ�����²�һһ�о�
	Place* place;
public:
	friend class Weather;
	User() { phone_number = -1; password = {}; age = -1; sex = -1; place = new Place(); }
	void set_information(int phone_number_) { phone_number = phone_number_; }
	void set_information(string password_) { password = password_; }
	void set_information(int age_, int sex_) { age = age_; sex = sex_; }//���ø�����Ϣ
};

class Weather
{
	User* user;
	string weather;
	int temperature[2];
	int humidity;//ʪ��
	//��������Ϣ�����²�һһ�о�
public:
	Weather() { user = new User(); weather = {}; temperature[0] = 0, temperature[1] = -1; humidity = -1; }
	void set_user(User* user_) { user = user_; }
	void set_weather()
	{
		//�����û���Ϣ��place�������ӵ��õ�����
		//���������Ϣ
	}
	void accurate_weather()
	{
		//��ȷԤ����Сʱ������
		//���������Ϣ
	}
	void advice()
	{
		//����accurate_weather()�ṩ��Ӧ�Ľ���
		//�������
	}
	void alarm()
	{
		//����accurate_weather()��set_weather()������ӦԤ��
		//���Ԥ��
	}
};

string find_password()//�����û���Ӧ���룬��������Ϊ123
{
	return "123";
}


int main()
{
	//�û������������APP
	//ע��/��¼
	User* user = new User();
	cout << "ע��/��¼��ע�᣺0����¼��1";
	int c = -1;
	cin >> c;

	while (c != 0 && c != 1)//����ʽӦ���иò��ֽ������ڣ�Ϊ���ڿ���̨��˳�����ж����
	{
		cout << "�������\n";
		cin >> c;
	}

	if (c)
	{
		int number = 0;
		string password;
		string correct_password = find_password();
		do
		{
			cout << "�����ֻ����룺";
			cin >> number;
			cout << "�������룺";
			cin >> password;
			if (password == correct_password)
				;//����Ӧ��
			else
			{
				cout << "�������\n";
			}
		} while (password != correct_password);
		//����ʵ��������ܳ����ֻ�������Ҫ/����Ҫ�������������������������Ҫ�����������
	}
	else
	{
		long long int number = 0;
		string password;
		string password_;
		do
		{
			cout << "�����ֻ����룺";
			cin >> number;
			while (password == "")
			{
				cout << "�������룺";
				cin >> password;
			}
			while (password_ == "")
			{
				cout << "ȷ�����룺";
				cin >> password_;
			}
			if (password == password_)
			{
				user->set_information(number);
				user->set_information(password);
				//���ø�����Ϣ������set_information();
			}//ע��ɹ�
			else
			{
				cout << "�����������벻һ�£�����������\n";
			}
		} while (password != password_);
		//����ʵ��������ܳ����ֻ�������Ҫ/����Ҫ�������������������������Ҫ�����������
	}
	
	//����Ӧ��
	Weather* weather = new Weather();
	weather->set_user(user);
	weather->set_weather();
	weather->alarm();//����ʾ������������ʾ����Ԥ��
	while (true)
	{
		//ѡ����Ҫ���еĹ���
		cout << "ѡ����Ҫ���еĹ��ܣ��鿴��ϸ������1���鿴��ȷ������2���鿴���н��飺3��ѡ����У�4�����������棺5���˳���6��";
		//�ù�������ģ����ʽ��UI����,�����Ӧ������Ϊ�����Ļ�Ĳ���
		int operate = -1;
		cin >> operate;
		while (operate != 0 && operate != 1 && operate != 2 && operate != 3 && operate != 4)//����ʽӦ���иò��ֽ������ڣ�Ϊ���ڿ���̨��˳�����ж����
		{
			cout << "�������\n";
			cin >> operate;
		}
		switch (operate)
		{
		case 1://��ʾ��ϸ������Ϣ
			break;
		case 2:weather->accurate_weather(); break;
		case 3:weather->advice(); break;
		case 4://�����û�ѡ���ڵ�ͼ��ѡ����л�������ѡ���е���find_place_1()����find_place_2()��λ����
			weather->set_weather();
			break;
		case 5:break;
		case 0:return 0;
		}
		operate = -1;
		Sleep(10000);
		//�ȴ����ظ�ִ��
	}
}