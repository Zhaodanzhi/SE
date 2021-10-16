#include<bits/stdc++.h>
using namespace std;
map<string,vector<pair<string,int>>> mp;//map用来存储
string province,city;
int num;
int main(int argc,char* argv[]){//命令行参数
    ifstream input;//文件读入
    input.open(argv[1]);//argv[1]:读入文件名
    if(!input){//文件名错误或找不到文件
        cout<<"打开文件失败\n";
        return 0;
    }
    ofstream output;//文件写入
    output.open(argv[2]);//argv[2]：需要写入的文件名
    if(!output){//文件名错误或找不到文件
        cout<<"打开文件失败\n";
        return 0;
    }
    if(argc==3){//三个参数与实验二相同
        while(input>>province>>city>>num) {
            mp[province].push_back(pair<string, int>(city, num));
        }
        for (auto i: mp) {
            output << i.first << '\n';
            for (auto j: i.second) {
                if (j.first == "待明确地区")
                    continue;
                output << j.first << ' ' << j.second << '\n';
            }
            output << '\n';
        }
    }
    else if(argc==4) {//四个参数只需要写入argv[3]对应的省份
        while (input >> province >> city >> num) {
            if (province == argv[3]) {//只有省份与argv[3]一致才存入mp中
                mp[province].push_back(pair<string, int>(city, num));
            }
            else
                continue;
        }
        for (auto i: mp) {
            output << i.first << '\n';
            for (auto j: i.second) {
                if (j.first == "待明确地区")
                    continue;
                output << j.first << ' ' << j.second << '\n';
            }
            output << '\n';
        }
    }
    input.close();//关闭文件
    output.close();//关闭文件
    return 0;
}