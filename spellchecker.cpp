#include<bits/stdc++.h>
using namespace std;

#define ll long 

vector<string> str;

class trie{
public:
    trie *neighbour[26];
    bool terminal_node;

    trie(){
        for(ll i=0;i<=26;i++){
            neighbour[i]=NULL;
        }

        terminal_node=false;
    }
};

trie *root=new trie();

void insert(string s){

    trie *temp=root;

    for(ll i=0;i<s.length();i++){

        if(temp->neighbour[s[i]-'a']==NULL){

            temp->neighbour[s[i]-'a']=new trie();
        }

        temp=temp->neighbour[s[i]-'a'];
    }

    temp->terminal_node=true;
}

bool check(string s){

    trie *temp=root;

    for(ll i=0;i<s.length();i++){

        if(temp->neighbour[s[i]-'a']==NULL){
            return false;
        }

        temp=temp->neighbour[s[i]-'a'];
    }

    return temp->terminal_node;
}

void get_Str(trie *temp,string s){

    if(temp->terminal_node){

        str.push_back(s);
    }

    for(ll i=0;i<26;i++){
        if(temp->neighbour[i]!=NULL){

            s.push_back((char)(i+'a'));

            get_Str(temp->neighbour[i],s);

            s.pop_back();
        }
    }
}

void Suggest_Str(string s){

    trie *temp=root;

    for(ll i=0;i<s.length();i++){

        if(temp->neighbour[s[i]-'a']==NULL){

            get_Str(temp,s.substr(0,i));
            return ;
        }

        temp=temp->neighbour[s[i]-'a'];
    }

    get_Str(temp,s);

    return ;
}

void solve(){

    ll q=1;
    cin>>q;
    while(q--){

        string s; 
        cin>>s;

        insert(s);
    }

    string s;
    cin>>s;

    if(check(s)){
        cout<<"String "<<s<<" is present";   
    }

    else{

        Suggest_Str(s);

        cout<<"Suggested Strings are:"<<endl;
        for(ll i=0;i<str.size();i++){
            cout<<str[i]<<endl;
        }
    }
}

int main(){

    solve();    

    return 0;
}

/*
i/p->
7
panda
pancreas
pancakes
panpipes
paris
grills
statue
pan
*/
