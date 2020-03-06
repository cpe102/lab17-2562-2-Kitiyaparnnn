//Write your code here
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

string upper(string order){
	for(int i=0;i<order.size();i++){
		order[i] = toupper(order[i]);
	}
	return order;
}


int main()
{
	ifstream ns("name_score.txt");
	string n,comand;
	vector<string> vname,vgrade;
	vector<int> sum;
	char name[100];
	int s1,s2,s3;
	while (getline(ns,n)){
		sscanf(n.c_str(),"%[^:]: %d %d %d",name,&s1,&s2,&s3);
		//cout<<n<<"\n";
		vname.push_back(name);
		sum.push_back(s1+s2+s3);
	}
	for(int i=0;i<sum.size();i++){
		//cout<<sum[i]<<"\n";
		if(sum[i]<50) vgrade.push_back("F");
		else if(sum[i]<60) vgrade.push_back("D");
		else if(sum[i]<70) vgrade.push_back("C");
		else if(sum[i]<80) vgrade.push_back("B");
		else vgrade.push_back("A");
		//cout<<vgrade[i]<<"\n";
	}
	while(1){	
	cout<<"Please input your command :";
	getline(cin,comand);
	int idx = comand.find_first_of(" ");
	string S1 = upper(comand.substr(0,idx)); //order
	string S2 = upper(comand.substr(idx+1,comand.size())); //option
	
	if(S1 == "EXIT") break;
	else if(S1 == "NAME"){
		for(int j=0;j<20;j++) cout<<"-";
	 	cout<<"\n";
		for(int i=0;i<vname.size();i++){
			if(S2 == upper(vname[i])) cout<<vname[i]<<"'s grade = "<<vgrade[i]<<"\n";
			else if (S2 != upper(vname[i])&& i!=vname.size()-1) ;
			else cout<<"Cannot found"<<"\n";
		}
		for(int j=0;j<20;j++) cout<<"-";
		cout<<"\n";	
	}
	
	else if(S1 == "GRADE"){
		for(int j=0;j<20;j++) cout<<"-";
		cout<<"\n";
		for(int i=0;i<vgrade.size();i++){
			if(S2 == vgrade[i]) cout<<vname[i]<<"\n";
			else if (S2 != vgrade[i]&& i!=vname.size()-1) ;
			else cout<<"Cannot found"<<"\n";
		}
		for(int a=0;a<20;a++) cout<<"-";
		cout<<"\n";
	}
	else cout<<"Invalid command"<<"\n";
	}
	
}
