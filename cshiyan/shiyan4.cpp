#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;//�������鳣��
map<string,int> mp,sl;//mp��ʡ����vec�е�λ��,sl��ÿ��ʡ�Ĳ�������
vector<pair<string,int> > vec[maxn],pt;//vec���鱣���к�������Ϣ���Գ�������pt������ʡ������
string province,city;
int num,cnt=0;
ifstream input;
ofstream output;
bool cmp(pair<string,int> p1,pair<string,int> p2){//�ȽϺ�������sort����Ϊ����������
    if(p1.second!=p2.second)//����������
        return p1.second>p2.second;
    else//������ͬ�ֵ���
        return p1.first<p2.first;
}
void begin1(){//����������������
    while(input>>province>>city>>num){	
        sl[province]+=num;//��������
        if(mp[province]==0){
            mp[province]=cnt;//Ϊprovince��λ����vec�е�λ��
            cnt++;
        }
        vec[mp[province]].push_back(pair<string,int>(city,num));//��������vec
    }
}
void begin2(char* ptr){//�����ĸ���������
	while(input>>province>>city>>num){
			if(ptr==province){//ʡ���������ͬ���б���
				sl[province]+=num;
				if(mp[province]==0){
					mp[province]=cnt;
					cnt++;
				}
				vec[mp[province]].push_back(pair<string,int>(city,num));
			}
	}
}
void NumSort(){//������
	map<string,int>::iterator it;//���������
    for(it=mp.begin();it!=mp.end();it++ ){
        pt.push_back(pair<string,int>(it->first,sl[it->first]));//��ʡ�ݶ�Ӧ��������pt����
    }
    sort(pt.begin(),pt.end(),cmp);//��ʡ�ݰ��������ֵ����������
    for(int i=0;i<cnt;i++){//��vec�����еĶ�ά��������
        sort(vec[i].begin(),vec[i].end(),cmp);
    }
}
void Write(){//д�뺯��
	vector<pair<string,int> >::iterator at;//���������
    for(at=pt.begin();at!=pt.end();at++){
        output<<at->first<<' '<<vec[mp[at->first]].size()<<"������"<<" �����У�"<<sl[at->first]<<"��"<<'\n';
        for(int j=0;j<vec[mp[at->first]].size();j++){
            output<<vec[mp[at->first]][j].first<<' '<<vec[mp[at->first]][j].second<<'\n';//д����к�������Ϣ
        }
        output<<'\n';
    }
}
int main(int argc,char* argv[]){//���������в���
    input.open(argv[1]);
    output.open(argv[2]);
    if(!input){
        cout<<"�ļ������ڻ��ļ�������\n";
        return 0;
    }
    if(!output){
        cout<<"�ļ������ڻ��ļ�������\n";
        return 0;
    }
    if(argc<=3){//�����������õ�һ������
        begin1();
    }
    else if(argc==4){//�ĸ��������õڶ�������
		begin2(argv[3]);
    }
	NumSort();//����������
	Write();//����д�뺯��
	input.close();
	output.close();
    return 0;
}
