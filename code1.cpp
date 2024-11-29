#include<iostream>
#include<windows.h>
using namespace std;

class Latitude//纬度
{
	char direction;//北纬/南纬，用N/S表示
	float degree;
	float minute;
	float second;//度、分、秒表示纬度
public:
	Latitude() { direction = {}; degree = -1; minute = -1; second = -1; }
	void set(char c, float x, float y, float z) { direction = c; degree = x; minute = y; second = z; }
}; 
class Longitude//经度
{
	char direction;//西经/东经，用W/E表示
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
	//纬度
	Place() { province = {}; city = {}; town = {}; street = {}; latitude = new Latitude(); longitude = new Longitude(); }
	void find_place_1(Latitude* latitude, Longitude* longitude, string& province, string& city, string& town, string& street)
	//根据定位用户或根据用户在地图上选定的位置，找到对应的城市（县、乡）
	{
		//查找对应城市，将province、city、town（、street）对应为该地的省、市、县
	}
	void Place_1(string province, string city, string town, string street, Latitude* latitude, Longitude* longitude)
	{
		//获取latitude和longitude
		find_place_1(latitude, longitude, province, city, town, street);
	}
	void find_place_2(string& province, string& city, string& town, string& street, Latitude* latitude, Longitude* longitude)
	//根据用户输入的城市，定位其经纬度，在地图上找到对应的位置
	{
		//查找对应地点，将latitude对应到该地的省、市、县
	}
	void Place_2(string province, string city, string town, string street, Latitude* latitude, Longitude* longitude)
	{
		//获取城市信息
		find_place_2( province, city, town, street, latitude, longitude);
	}
};

class User
{
	long long int phone_number;
	string password;
	int age;
	int sex;
	//等个人信息，以下不一一列举
	Place* place;
public:
	friend class Weather;
	User() { phone_number = -1; password = {}; age = -1; sex = -1; place = new Place(); }
	void set_information(int phone_number_) { phone_number = phone_number_; }
	void set_information(string password_) { password = password_; }
	void set_information(int age_, int sex_) { age = age_; sex = sex_; }//设置个人信息
};

class Weather
{
	User* user;
	string weather;
	int temperature[2];
	int humidity;//湿度
	//等天气信息，以下不一一列举
public:
	Weather() { user = new User(); weather = {}; temperature[0] = 0, temperature[1] = -1; humidity = -1; }
	void set_user(User* user_) { user = user_; }
	void set_weather()
	{
		//根据用户信息（place），连接到该地天气
		//输出天气信息
	}
	void accurate_weather()
	{
		//精确预测两小时内天气
		//输出天气信息
	}
	void advice()
	{
		//根据accurate_weather()提供对应的建议
		//输出建议
	}
	void alarm()
	{
		//根据accurate_weather()或set_weather()给出相应预警
		//输出预警
	}
};

string find_password()//查找用户对应密码，这里设置为123
{
	return "123";
}


int main()
{
	//用户点击进入天气APP
	//注册/登录
	User* user = new User();
	cout << "注册/登录？注册：0、登录：1";
	int c = -1;
	cin >> c;

	while (c != 0 && c != 1)//在正式应用中该部分将不存在，为了在控制台上顺利运行而添加
	{
		cout << "输入错误\n";
		cin >> c;
	}

	if (c)
	{
		int number = 0;
		string password;
		string correct_password = find_password();
		do
		{
			cout << "输入手机号码：";
			cin >> number;
			cout << "输入密码：";
			cin >> password;
			if (password == correct_password)
				;//进入应用
			else
			{
				cout << "密码错误\n";
			}
		} while (password != correct_password);
		//根据实际情况可能出现手机号码需要/不需要重新输入两种情况，这里用需要重新输入代替
	}
	else
	{
		long long int number = 0;
		string password;
		string password_;
		do
		{
			cout << "输入手机号码：";
			cin >> number;
			while (password == "")
			{
				cout << "输入密码：";
				cin >> password;
			}
			while (password_ == "")
			{
				cout << "确认密码：";
				cin >> password_;
			}
			if (password == password_)
			{
				user->set_information(number);
				user->set_information(password);
				//设置个人信息，传入set_information();
			}//注册成功
			else
			{
				cout << "两次输入密码不一致，请重新输入\n";
			}
		} while (password != password_);
		//根据实际情况可能出现手机号码需要/不需要重新输入两种情况，这里用需要重新输入代替
	}
	
	//进入应用
	Weather* weather = new Weather();
	weather->set_user(user);
	weather->set_weather();
	weather->alarm();//在显示天气后立刻显示气候预警
	while (true)
	{
		//选择需要进行的功能
		cout << "选择需要进行的功能（查看详细天气：1、查看精确天气：2、查看出行建议：3、选择城市：4、返回主界面：5、退出：6）";
		//该功能用于模拟正式的UI界面,输入对应数字视为点击屏幕的操作
		int operate = -1;
		cin >> operate;
		while (operate != 0 && operate != 1 && operate != 2 && operate != 3 && operate != 4)//在正式应用中该部分将不存在，为了在控制台上顺利运行而添加
		{
			cout << "输入错误\n";
			cin >> operate;
		}
		switch (operate)
		{
		case 1://显示详细天气信息
			break;
		case 2:weather->accurate_weather(); break;
		case 3:weather->advice(); break;
		case 4://根据用户选择在地图上选择城市或者是自选城市调用find_place_1()或者find_place_2()定位城市
			weather->set_weather();
			break;
		case 5:break;
		case 0:return 0;
		}
		operate = -1;
		Sleep(10000);
		//等待，重复执行
	}
}