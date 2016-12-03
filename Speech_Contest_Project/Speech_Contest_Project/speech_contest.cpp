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

	//产生选手
	for (int i = 0; i < 24; i++)
	{
		Speaker tmp;
		tmp.m_name = "选手";
		tmp.m_name += str[i];
		mapSpeaker.insert(pair<int, Speaker>(100 + i, tmp));

		v.push_back(100 + i);
	}


	return 0;
}

//选手抽签
int speech_contest_draw(vector<int> &v1)
{
	random_shuffle(v1.begin(), v1.end());
	return 0;
}

//自定义比较操作

struct greater {
	bool operator() (const int& lhs, const int& rhs) const
	{
		return lhs > rhs;
	}
};


//比赛
int speech_contest(int index, vector<int> &v1, map<int, Speaker> &mapSpeaker, vector<int> &v2)
{
	multimap<int, int, greater> multimapGroup;
	
	int tmpCount = 0;

	printf("\n\t第%d轮比赛开始:\n", index + 1);
	for (vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		tmpCount++;

		//打分
		deque<int> dscore;
		for (int j = 0; j < 10; ++j)
		{
			int score = rand() % 50 + 50;
			dscore.push_back(score);
		}
		sort(dscore.begin(), dscore.end());

		//去除最高 最低 分
		dscore.pop_back();
		dscore.pop_front();

		//求平均分即 最终分
		int scoresum = accumulate(dscore.begin(), dscore.end(), 0);
		int scoreavg = scoresum / dscore.size();
		mapSpeaker[*it].m_score[index] = scoreavg;

		//选手最终得分存到 multimap 里
		multimapGroup.insert(make_pair(scoreavg, *it));

		if (tmpCount % 6 == 0)
		{
			cout << "\n小组比赛成绩\n" << endl;
			cout << "编号\t姓名\t成绩\n" << endl;
			for (auto mit = multimapGroup.begin(); mit != multimapGroup.end(); mit++)
			{
				cout << mit->second << "\t" << mapSpeaker[mit->second].m_name <<
					"\t" << mapSpeaker[mit->second].m_score[index] << endl;
			}

			//每组前三名晋级
			while (multimapGroup.size() > 3)
			{
				auto it1 = multimapGroup.begin();
				v2.push_back(it1->second);
				multimapGroup.erase(it1);
			}

			//清空本小组成绩
			multimapGroup.clear();
		}
	}

	
	return 0;
}

//查看比赛结果
int speech_contest_rsult(int index, vector<int> &v2, map<int, Speaker> &mapSpeaker)
{
	//对晋级名单排序
	sort(v2.begin(), v2.end());

	printf("\n第%d轮晋级名单\n", index+1);
	cout << "\n编号\t姓名\t成绩" << endl;
	for (auto it = v2.begin(); it != v2.end(); ++it)
	{
		cout << *it << "\t" << mapSpeaker[*it].m_name << "\t" << mapSpeaker[*it].m_score[index] << endl;
	}

	return 0;
}


int main()
{
	//选择容器 map
	map<int, Speaker>	mapSpeaker;
	vector<int>			v1;		//第 n 轮比赛名单
	vector<int>			v2;
	vector<int>			v3;
	vector<int>			v4;		//最后前三名

	//产生选手 道德第一轮参赛名单
	GenSpeaker(mapSpeaker, v1);

	//第 1 轮选收抽签   比赛  查看结果
	speech_contest_draw(v1);
	speech_contest(0/*表示第几轮比赛*/, v1, mapSpeaker, v2);
	speech_contest_rsult(0, v2, mapSpeaker);

	//第 2 轮选收抽签   比赛  查看结果
	speech_contest_draw(v2);
	speech_contest(1, v2, mapSpeaker, v3);
	speech_contest_rsult(1, v3, mapSpeaker);

	//第 3 轮选收抽签   比赛  查看结果
	speech_contest_draw(v3);
	speech_contest(2, v3, mapSpeaker, v4);
	speech_contest_rsult(2, v4, mapSpeaker);


	system("pause");
	return 0;
}