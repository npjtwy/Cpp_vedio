#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <deque>
#include <numeric>
using  namespace std;

class Speaker
{
public:
	string		m_name;
	int			m_score[3];
private:
};

int GenSpeaker(map<int, Speaker> &mapSpeaker, vector<int> &v)
{
	string str = "ASDFGHJKLQWERTYUIOPZXCVBNM";
	random_shuffle(str.begin(), str.end());

	//����ѡ��
	for (int i = 0; i < 24; i++)
	{
		Speaker tmp;
		tmp.m_name = "ѡ��";
		tmp.m_name += str[i];
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));

		v.push_back(100 + i);
	}


	return 0;
}

//ѡ�ֳ�ǩ
int speech_contest_draw(vector<int> &v1)
{
	random_shuffle(v1.begin(), v1.end());
	return 0;
}

//�Զ���Ƚϲ���

struct greater {
	bool operator() (const int& lhs, const int& rhs) const
	{
		return lhs > rhs;
	}
};


//����
int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2)
{
	multimap<int, int, greater> multimapGroup;
	
	int tmpCount = 0;

	printf("\n\t��%d�ֱ�����ʼ:\n", index + 1);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		tmpCount++;

		//���
		deque<int> dscore;
		for (int j = 0; j < 10; ++j)
		{
			int score = rand() % 50 + 50;
			dscore.push_back(score);
		}
		sort(dscore.begin(), dscore.end());

		//ȥ����� ��� ��
		dscore.pop_back();
		dscore.pop_front();

		//��ƽ���ּ� ���շ�
		int scoresum = accumulate(dscore.begin(), dscore.end(), 0);
		int scoreavg = scoresum / dscore.size();
		mapSpeaker[*it].m_score[index] = scoreavg;

		//ѡ�����յ÷ִ浽 multimap ��
		multimapGroup.insert(make_pair(scoreavg, *it));

		if (tmpCount % 6 == 0)
		{
			cout << "\nС������ɼ�\n" << endl;
			cout << "���\t����\t�ɼ�\n" << endl;
			for (auto mit = multimapGroup.begin(); mit != multimapGroup.end(); mit++)
			{
				cout << mit->second << "\t" << mapSpeaker[mit->second].m_name <<
					"\t" << mapSpeaker[mit->second].m_score[index] << endl;
			}

			//ÿ��ǰ��������
			while (multimapGroup.size() > 3)
			{
				auto it1 = multimapGroup.begin();
				v2.push_back(it1->second);
				multimapGroup.erase(it1);
			}

			//��ձ�С��ɼ�
			multimapGroup.clear();
		}
	}

	
	return 0;
}

//�鿴�������
int speech_contest_rsult(int index, vector<int> &v2, map<int, Speaker> &mapSpeaker)
{
	//�Խ�����������
	sort(v2.begin(), v2.end());

	printf("\n��%d�ֽ�������\n", index+1);
	cout << "\n���\t����\t�ɼ�" << endl;
	for (auto it = v2.begin(); it != v2.end(); ++it)
	{
		cout << *it << "\t" << mapSpeaker[*it].m_name << "\t" << mapSpeaker[*it].m_score[index] << endl;
	}

	return 0;
}


int main()
{
	//ѡ������ map
	map<int, Speaker>	mapSpeaker;
	vector<int>			v1;		//�� n �ֱ�������
	vector<int>			v2;
	vector<int>			v3;
	vector<int>			v4;		//���ǰ����

	//����ѡ�� ���µ�һ�ֲ�������
	GenSpeaker(mapSpeaker, v1);

	//�� 1 ��ѡ�ճ�ǩ   ����  �鿴���
	speech_contest_draw(v1);
	speech_contest(0/*��ʾ�ڼ��ֱ���*/, v1, mapSpeaker, v2);
	speech_contest_rsult(0, v2, mapSpeaker);

	//�� 2 ��ѡ�ճ�ǩ   ����  �鿴���
	speech_contest_draw(v2);
	speech_contest(1, v2, mapSpeaker, v3);
	speech_contest_rsult(1, v3, mapSpeaker);

	//�� 3 ��ѡ�ճ�ǩ   ����  �鿴���
	speech_contest_draw(v3);
	speech_contest(2, v3, mapSpeaker, v4);
	speech_contest_rsult(2, v4, mapSpeaker);


	system("pause");
	return 0;
}