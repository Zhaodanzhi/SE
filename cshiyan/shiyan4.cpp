#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;//定义数组常量
map<string,int> mp,sl;//mp存省份在vec中的位置,sl存每个省的病例人数
vector<pair<string,int> > vec[maxn],pt;//vec数组保存市和人数信息，对城市排序；pt用来对省份排序
string province,city;
int num,cnt=0;
ifstream input;
ofstream output;
bool cmp(pair<string,int> p1,pair<string,int> p2){//比较函数，在sort中作为第三个参数
    if(p1.second!=p2.second)//按人数排序
        return p1.second>p2.second;
    else//数量相同字典序
        return p1.first<p2.first;
}
void begin1(){//传入三个参数调用
    while(input>>province>>city>>num){	
        sl[province]+=num;//保存数量
        if(mp[province]==0){
            mp[province]=cnt;//为province定位数组vec中的位置
            cnt++;
        }
        vec[mp[province]].push_back(pair<string,int>(city,num));//存入数组vec
    }
}
void begin2(char* ptr){//传入四个参数调用
	while(input>>province>>city>>num){
			if(ptr==province){//省份与参数相同进行保存
				sl[province]+=num;
				if(mp[province]==0){
					mp[province]=cnt;
					cnt++;
				}
				vec[mp[province]].push_back(pair<string,int>(city,num));
			}
	}
}
void NumSort(){//排序函数
	map<string,int>::iterator it;//构造迭代器
    for(it=mp.begin();it!=mp.end();it++ ){
        pt.push_back(pair<string,int>(it->first,sl[it->first]));//将省份对应人数存入pt数组
    }
    sort(pt.begin(),pt.end(),cmp);//对省份按数量和字典序进行排序
    for(int i=0;i<cnt;i++){//对vec数组中的二维数组排序
        sort(vec[i].begin(),vec[i].end(),cmp);
    }
}
void Write(){//写入函数
	vector<pair<string,int> >::iterator at;//构造迭代器
    for(at=pt.begin();at!=pt.end();at++){
        output<<at->first<<' '<<vec[mp[at->first]].size()<<"个地区"<<" 病例有："<<sl[at->first]<<"人"<<'\n';
        for(int j=0;j<vec[mp[at->first]].size();j++){
            output<<vec[mp[at->first]][j].first<<' '<<vec[mp[at->first]][j].second<<'\n';//写入城市和数量信息
        }
        output<<'\n';
    }
}
int main(int argc,char* argv[]){//传入命令行参数
    input.open(argv[1]);
    output.open(argv[2]);
    if(!input){
        cout<<"文件不存在或文件名错误\n";
        return 0;
    }
    if(!output){
        cout<<"文件不存在或文件名错误\n";
        return 0;
    }
    if(argc<=3){//三个参数调用第一个函数
        begin1();
    }
    else if(argc==4){//四个参数调用第二个函数
		begin2(argv[3]);
    }
	NumSort();//调用排序函数
	Write();//调用写入函数
	input.close();
	output.close();
    return 0;
}
