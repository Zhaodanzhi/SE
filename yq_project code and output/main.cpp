#include <bits/stdc++.h>       //万能头文件
using namespace std;
int main() {
    freopen("yq_in.txt", "r", stdin);//输入重定向，输入数据从yq_in.txt文件读取
	freopen("out.txt", "w", stdout);//输出重定向，输出数据将保存在out.txt中
    map<string, vector<pair<string,int> > > m;//定义map变量，因为一个省有多个城市，故使用vector数组
    string province, city;
    int num;
	while(cin >> province >> city >> num)
		m[province].push_back(pair<string,int>(city, num));//将对应数据存入m中
	for(auto i : m){//遍历m中每一个元素
		cout << i.first << '\n';//输出城市
		for(auto j : i.second){//遍历i.second中的每一个元素
			if(j.first == "待明确地区") 
				continue;
			cout << j.first << " " << j.second << '\n';//输出城市与对应人数
		}
		cout << '\n';
	}
    return 0;
}
