#include<bits/stdc++.h>
using namespace std;
map<string,vector<pair<string,int>>> mp;//map�����洢
string province,city;
int num;
int main(int argc,char* argv[]){//�����в���
    ifstream input;//�ļ�����
    input.open(argv[1]);//argv[1]:�����ļ���
    if(!input){//�ļ���������Ҳ����ļ�
        cout<<"���ļ�ʧ��\n";
        return 0;
    }
    ofstream output;//�ļ�д��
    output.open(argv[2]);//argv[2]����Ҫд����ļ���
    if(!output){//�ļ���������Ҳ����ļ�
        cout<<"���ļ�ʧ��\n";
        return 0;
    }
    if(argc==3){//����������ʵ�����ͬ
        while(input>>province>>city>>num) {
            mp[province].push_back(pair<string, int>(city, num));
        }
        for (auto i: mp) {
            output << i.first << '\n';
            for (auto j: i.second) {
                if (j.first == "����ȷ����")
                    continue;
                output << j.first << ' ' << j.second << '\n';
            }
            output << '\n';
        }
    }
    else if(argc==4) {//�ĸ�����ֻ��Ҫд��argv[3]��Ӧ��ʡ��
        while (input >> province >> city >> num) {
            if (province == argv[3]) {//ֻ��ʡ����argv[3]һ�²Ŵ���mp��
                mp[province].push_back(pair<string, int>(city, num));
            }
            else
                continue;
        }
        for (auto i: mp) {
            output << i.first << '\n';
            for (auto j: i.second) {
                if (j.first == "����ȷ����")
                    continue;
                output << j.first << ' ' << j.second << '\n';
            }
            output << '\n';
        }
    }
    input.close();//�ر��ļ�
    output.close();//�ر��ļ�
    return 0;
}