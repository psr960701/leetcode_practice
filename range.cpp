#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	string s;
	freopen("range.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取 
	freopen("output.txt","w",stdout); //输出重定向，输出数据将保存out.txt文件中 
	while(cin>>s){
        int i;
        bool flag;
        i=0;
        flag=true;
        while(i!=s.size()){
        if(s[0]!='-') flag=false;
		if(s[i]=='-'&&flag) { cout<<s[i];flag=false;}
        else if (s[i]=='-') { cout<<' ';flag=true;}
        else if (s[i]=='('||s[i]==')') {i++;continue;}
        else cout<<s[i];
        i++;
        }
        cout<<endl;
	}
	fclose(stdin);//关闭重定向输入
	fclose(stdout);//关闭重定向输出 
	return 0;
}