#include<bits/stdc++.h>
using namespace std;

hash<string> mystdhash;
string temp;

void permute(string s, int i, int j){
    static int count=0;

    if(i==4){
        count++;
        // cout<<count<<": "<<s<<endl;
        if(to_string(mystdhash(s))==temp){
            ofstream MyFile("password.txt");
            MyFile<<s;
            MyFile.close();
            cout<<"Password saved";
        }
        return;
    }

    for(int x=0;x<=9;x++){
        string temp=s;
        temp += ('0'+x);
        permute(temp, i+1, j);
    }
        

}

int main(){
    cout<<"--Crack MPIN of 4 digit using hashed value only--\n";
    string passwrd;
    cout<<"Enter password :";
    cin>>passwrd;

    //crack the password using hash value only
    temp=to_string(mystdhash(passwrd));
    cout<<"You have entered :"<<temp<<endl;
    permute("", 0, 4);
    return 0;
}