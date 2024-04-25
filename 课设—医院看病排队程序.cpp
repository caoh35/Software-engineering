#include <iostream>
using namespace std;
#include<queue>
#define MAX 100

int Count = 0;   //用于对诊室数量进行存储

struct LinkQueue
{
	int num;
	LinkQueue* next;
};

struct Room
{
	queue<int> Q1;   //首诊队列
	queue<int> Q2;   //复诊队列
	int Compare[MAX] = { 0 };   //首诊出队数组
};

//初始化,设置诊室数量
void RoomCount(Room* R)
{
	cout << "请输入所需开设诊室数量：";
	cin >> Count;
	//动态分配Count个结构体空间
	R = (struct Room*)malloc(Count * sizeof(struct Room));
	cout << "当前已成功创建" << Count << "个诊室" << endl;
}

//看病
void Consult(int c, int n, Room* R)   //c为诊室号，n为病历号
{
	cout << "当前共开设" << Count << "个诊室" << endl;
	cout << "请选择诊室号：";
	cin >> c;
	cout << "请输入病历号：";
	cin >> n;
	int flag = 0;
	for (int i = 0; i < MAX; i++)
	{
		//通过与首诊出队后的病历号进行比较判断是否属于复诊
		if (n == R[c].Compare[i])
		{
			R[c].Q2.push(n);   //若属于复诊则存入复诊队列
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		R[c].Q1.push(n);   //否则存入首诊队列
	}
	cout << "您已成功排队！" << endl;
}

//诊病
int j = 0;
void Diagnosis(int c, Room* R)
{
	cout << "请输入诊室号：";
	cin >> c;
	if (c > Count)
	{
		cout << "您输入的诊室号有误！当前仅有" << Count << "个诊室开设" << endl;
	}
	else
	{
		cout << "首诊请按1，复诊请按2" << endl;
		cout << "请选择首诊或复诊：";
		int temp;
		cin >> temp;
		if (temp == 1)
		{
			if (R[c].Q1.size() == 0)
			{
				cout << "当前无病人排队！" << endl;
			}
			else
			{
				cout << "当前首诊第一位病人病历号为：" << R[c].Q1.front() << endl;
				//首诊完成后存入数组并出队，更新诊室队列
				R[c].Compare[j] = R[c].Q1.front();
				j++;
				R[c].Q1.pop();
			}
		}
		else if (temp == 2)
		{
			if (R[c].Q2.size() == 0)
			{
				cout << "当前无病人排队！" << endl;
			}
			else
			{
				cout << "当前复诊第一位病人病历号为：" << R[c].Q2.front() << endl;
				R[c].Q2.pop();
			}
		}
		else
		{
			cout << "请正确输入选项！" << endl;
		}
	}
}

//查询
void Inquire(int c, Room* R)
{
	cout << "请输入您想查询的诊室号：";
	cin >> c;
	if (c > Count)
	{
		cout << "您输入的诊室号有误！当前仅有" << Count << "个诊室开设" << endl;
	}
	else
	{
		cout << "您所查询的诊室当前共有" << R[c].Q1.size() + R[c].Q2.size() << "人排队" << endl;
		cout << "其中首诊" << R[c].Q1.size() << "人，" << "复诊" << R[c].Q2.size() << "人" << endl;
	}
}

int main()
{
	Room Array[50];
	int c = 0, n = 0;
	int flag = 0;
	int flag1 = 0;
	int flag2 = 0;
	while (1)
	{
		if (flag1 == 0)
		{
			cout << "     *******************************************" << endl;
			cout << "     **      欢迎使用本医院看病排队系统       **" << endl;
			cout << "     **      0.结束                           **" << endl;
			cout << "     **      1.初始化，设置诊室数量           **" << endl;
			cout << "     **      2.看病                           **" << endl;
			cout << "     **      3.诊病                           **" << endl;
			cout << "     **      4.查询                           **" << endl;
			cout << "     **    !注意事项：①1和3为管理员专有权限  **" << endl;
			cout << "     **                 病人仅限选择2和4      **" << endl;
			cout << "     **               ②首次使用前请先执行1   **" << endl;
			cout << "     **               ③医生诊病前请先查询!   **" << endl;
			cout << "     **                 若该诊室无病人排队    **" << endl;
			cout << "     **                 将无法继续进行        **" << endl;
			cout << "     *******************************************" << endl;
			cout << "请选择你所需要的服务：";
		}
		else
		{
			cout << "     *******************************************" << endl;
			cout << "     **      欢迎使用本医院看病排队系统       **" << endl;
			cout << "     **      0.结束                           **" << endl;
			cout << "     **      1.初始化，设置诊室数量           **" << endl;
			cout << "     **      2.看病                           **" << endl;
			cout << "     **      3.诊病                           **" << endl;
			cout << "     **      4.查询                           **" << endl;
			cout << "     **    !注意事项：①1和3为管理员专有权限  **" << endl;
			cout << "     **                 病人仅限选择2和4      **" << endl;
			cout << "     **               ②首次使用前请先执行1   **" << endl;
			cout << "     **               ③医生诊病前请先查询!   **" << endl;
			cout << "     **                 若该诊室无病人排队    **" << endl;
			cout << "     **                 将无法继续进行        **" << endl;
			cout << "     *******************************************" << endl;
			cout << "请选择你所需要的服务：";
		}
		int o = 0;
		cin >> o;
		switch (o)
		{
		case 1:
			RoomCount(Array);
			flag1 = 1;
			cout << endl;
			break;
		case 2:
			if (flag1 == 1)
			{
				Consult(c, n, Array);
				flag2 = 1;
				cout << endl;
				break;
			}
			cout << endl;
			cout << "根据注意事项，请重新选择!" << endl;
			break;
		case 3:
			if (flag1 == 1 && flag2 == 1)
			{
				Diagnosis(c, Array);
				cout << endl;
				break;
			}
			cout << endl;
			cout << "根据注意事项，请重新选择!" << endl;
			break;
		case 4:
			if (flag1 == 1)
			{
				Inquire(c, Array);
				cout << endl;
				break;
			}
			cout << endl;
			cout << "根据注意事项，请重新选择!" << endl;
			break;
		case 0:
			flag = 1;
			break;
		}
		if (flag == 1)
		{
			break;
		}
	}
	return 0;
}
