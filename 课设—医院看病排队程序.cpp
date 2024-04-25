#include <iostream>
using namespace std;
#include<queue>
#define MAX 100

int Count = 0;   //���ڶ������������д洢

struct LinkQueue
{
	int num;
	LinkQueue* next;
};

struct Room
{
	queue<int> Q1;   //�������
	queue<int> Q2;   //�������
	int Compare[MAX] = { 0 };   //�����������
};

//��ʼ��,������������
void RoomCount(Room* R)
{
	cout << "���������迪������������";
	cin >> Count;
	//��̬����Count���ṹ��ռ�
	R = (struct Room*)malloc(Count * sizeof(struct Room));
	cout << "��ǰ�ѳɹ�����" << Count << "������" << endl;
}

//����
void Consult(int c, int n, Room* R)   //cΪ���Һţ�nΪ������
{
	cout << "��ǰ������" << Count << "������" << endl;
	cout << "��ѡ�����Һţ�";
	cin >> c;
	cout << "�����벡���ţ�";
	cin >> n;
	int flag = 0;
	for (int i = 0; i < MAX; i++)
	{
		//ͨ����������Ӻ�Ĳ����Ž��бȽ��ж��Ƿ����ڸ���
		if (n == R[c].Compare[i])
		{
			R[c].Q2.push(n);   //�����ڸ�������븴�����
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		R[c].Q1.push(n);   //��������������
	}
	cout << "���ѳɹ��Ŷӣ�" << endl;
}

//�ﲡ
int j = 0;
void Diagnosis(int c, Room* R)
{
	cout << "���������Һţ�";
	cin >> c;
	if (c > Count)
	{
		cout << "����������Һ����󣡵�ǰ����" << Count << "�����ҿ���" << endl;
	}
	else
	{
		cout << "�����밴1�������밴2" << endl;
		cout << "��ѡ��������";
		int temp;
		cin >> temp;
		if (temp == 1)
		{
			if (R[c].Q1.size() == 0)
			{
				cout << "��ǰ�޲����Ŷӣ�" << endl;
			}
			else
			{
				cout << "��ǰ�����һλ���˲�����Ϊ��" << R[c].Q1.front() << endl;
				//������ɺ�������鲢���ӣ��������Ҷ���
				R[c].Compare[j] = R[c].Q1.front();
				j++;
				R[c].Q1.pop();
			}
		}
		else if (temp == 2)
		{
			if (R[c].Q2.size() == 0)
			{
				cout << "��ǰ�޲����Ŷӣ�" << endl;
			}
			else
			{
				cout << "��ǰ�����һλ���˲�����Ϊ��" << R[c].Q2.front() << endl;
				R[c].Q2.pop();
			}
		}
		else
		{
			cout << "����ȷ����ѡ�" << endl;
		}
	}
}

//��ѯ
void Inquire(int c, Room* R)
{
	cout << "�����������ѯ�����Һţ�";
	cin >> c;
	if (c > Count)
	{
		cout << "����������Һ����󣡵�ǰ����" << Count << "�����ҿ���" << endl;
	}
	else
	{
		cout << "������ѯ�����ҵ�ǰ����" << R[c].Q1.size() + R[c].Q2.size() << "���Ŷ�" << endl;
		cout << "��������" << R[c].Q1.size() << "�ˣ�" << "����" << R[c].Q2.size() << "��" << endl;
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
			cout << "     **      ��ӭʹ�ñ�ҽԺ�����Ŷ�ϵͳ       **" << endl;
			cout << "     **      0.����                           **" << endl;
			cout << "     **      1.��ʼ����������������           **" << endl;
			cout << "     **      2.����                           **" << endl;
			cout << "     **      3.�ﲡ                           **" << endl;
			cout << "     **      4.��ѯ                           **" << endl;
			cout << "     **    !ע�������1��3Ϊ����Աר��Ȩ��  **" << endl;
			cout << "     **                 ���˽���ѡ��2��4      **" << endl;
			cout << "     **               ���״�ʹ��ǰ����ִ��1   **" << endl;
			cout << "     **               ��ҽ���ﲡǰ���Ȳ�ѯ!   **" << endl;
			cout << "     **                 ���������޲����Ŷ�    **" << endl;
			cout << "     **                 ���޷���������        **" << endl;
			cout << "     *******************************************" << endl;
			cout << "��ѡ��������Ҫ�ķ���";
		}
		else
		{
			cout << "     *******************************************" << endl;
			cout << "     **      ��ӭʹ�ñ�ҽԺ�����Ŷ�ϵͳ       **" << endl;
			cout << "     **      0.����                           **" << endl;
			cout << "     **      1.��ʼ����������������           **" << endl;
			cout << "     **      2.����                           **" << endl;
			cout << "     **      3.�ﲡ                           **" << endl;
			cout << "     **      4.��ѯ                           **" << endl;
			cout << "     **    !ע�������1��3Ϊ����Աר��Ȩ��  **" << endl;
			cout << "     **                 ���˽���ѡ��2��4      **" << endl;
			cout << "     **               ���״�ʹ��ǰ����ִ��1   **" << endl;
			cout << "     **               ��ҽ���ﲡǰ���Ȳ�ѯ!   **" << endl;
			cout << "     **                 ���������޲����Ŷ�    **" << endl;
			cout << "     **                 ���޷���������        **" << endl;
			cout << "     *******************************************" << endl;
			cout << "��ѡ��������Ҫ�ķ���";
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
			cout << "����ע�����������ѡ��!" << endl;
			break;
		case 3:
			if (flag1 == 1 && flag2 == 1)
			{
				Diagnosis(c, Array);
				cout << endl;
				break;
			}
			cout << endl;
			cout << "����ע�����������ѡ��!" << endl;
			break;
		case 4:
			if (flag1 == 1)
			{
				Inquire(c, Array);
				cout << endl;
				break;
			}
			cout << endl;
			cout << "����ע�����������ѡ��!" << endl;
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
