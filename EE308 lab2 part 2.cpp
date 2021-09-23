	#include<bits/stdc++.h>
	#include<iostream>
    using namespace std;
	string Keyword[105]={"auto","break","case","char","const","continue","default","do",
	"double","else","enum","extern","float","for","goto","if",
	"int","long","register","return","short","signed","sizeof","static",
	"struct","switch","typedef","union","unsigned","void","volatile","while"};
    int elseif_num,else_num;
	int total_num=0;
	int switch_num=0;
    int case_num[1000];
	 
    string Delete(string s)
	{
	    string res="";
	    for(int i=0;i<s.size();i++){
	        if(s[i]=='"'){
	            for(int j=i+1;i<s.size();j++){
	                if(s[j]=='"'){
	                    s.erase(i,j-i+1);
	                    break;
	                }
	            }
	        }
	    }    
	    for(int i=0;i<s.size();i++){
	        if(s[i]=='/'&&s[i+1]=='/'){
	            return res;
        }
	        res+=s[i];
	    }
	} 
	 
	bool Match(string s)
	{
		string res="NULL";
		for(int i=0;i<=32;i++){
			if(s==Keyword[i]){
				res=Keyword[i];
				break;
			}
		}
		if(res=="switch"){
			switch_num++;
		}
		if(res=="case")case_num[switch_num]++;
		if(res=="if" || res=="else");
		if(res!="NULL"){
			total_num++;
			return true;
		}
		return false;
	}
	 
	void check(string s)
	{
		int len=s.size();
		s+="llllllll";
		for(int i=0;i<len;i++){
			for(int j=8;j>=2;j--){
				if(Match(s.substr(i,j))){
					i+=j-1;
					break;
				}
			}		
		}
	}
	 
	int main()
	{	
	 
		int level;
		cin>>level;
		FILE* fp=freopen("data.txt","r",stdin);
		if (fp == NULL)
		{
			cout<<"File not found"<<endl;
			return 0;
		}
	 
		string s;
		while(getline(cin,s)){
			s=Delete(s);
			check(s);
		}
		if(level>=1)cout<<"total num: "<<total_num<<endl;	
		if(level>=2){		
			cout<<"switch num: "<<switch_num<<endl;
			cout<<"case num: ";	
			for(int i=1;i<=switch_num;i++){
				if(i)cout<<" ";
				cout<<case_num[i];	
			}
			cout<<endl;
		}
		if(level>=3)cout<<"if-else num: "<<else_num<<endl;
		if(level>=4)cout<<"if-elseif-else num: "<<elseif_num<<endl;		
		return 0;
	}

