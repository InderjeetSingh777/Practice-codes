//Problem Statement:
//Given a list of contacts which exist in a phone directory and a query string str.
//The task is to implement search query for the phone directory.
//Run a search query for each prefix p of the query string str(i.e from  index 1 to str length) that prints all the distinct recommended contacts which have the same prefix as our query (p) in lexicographical order. Please refer the explanation part for better understanding.
//NOTE: If there is no match between query and contacts , print "0".

//Input:
//The first line of input contains an integer T denoting the number of test cases.
//Then T test cases follow. Each test case contains three lines.
//First line of each test case contains N i.e., number of contacts.
//Second line contains space separated all the contacts in the form of string. And third line contains query string.

//Output:
//For each test case, print each query result in new line. If there is no match between query and contacts, print "0".

//Constraints:
//1<=T<=100
//1<=N<=50
//1<=|contact[i].length|<=50
//1<=|query length|<=6

//C++ Code:
#include<bits/stdc++.h>
using namespace std;
struct trie
{
    trie*child[26];//considering 26 alphabets.lowercase,index 0-25 fro --'a'-'z'
    bool isEnd;
    trie(){//constructor
        for(int i=0;i<26;i++)
        child[i]=NULL;//initially no child is active
        isEnd=false;
    }
};
void insert(trie*root,string&s)//insertion in trie
{
    trie*Pcrawl=root;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        int index=s[i]-'a';//calculete index for a particular alphabet
        if(Pcrawl->child[index]==NULL)//if child is present ,move to it,else create it firstly then move to it
        Pcrawl->child[index]=new trie();
        Pcrawl=Pcrawl->child[index];
    }
    Pcrawl->isEnd=true;///set end of word to true

}
void print_strings(trie*root,string& s)
{
    if(root==NULL)
    return;
    if(root->isEnd)//if end of word is true,print it..but do not put return statement..as we can have more words after it
    {
        cout<<s<<" ";
        //return;
    }
    for(int i=0;i<26;i++)
    {
        if(root->child[i])//scan for active children
        {

           s.push_back(i+'a');//add this child before recursive call
            print_strings(root->child[i],s);//make recursive call
            s.pop_back();//remove child after recursive call returns
        }
    }
    return;
}
void search_strings(trie*root,string&s,string&prefix)
{
     int len=s.length();
     trie*curr=root;
	    for(int i=0;i<len;i++)
	    {

	        int index=s[i]-'a';
	           if(curr->child[index])//if child active,add it to make prefix
	            {
	                prefix.push_back(s[i]);
	                curr=curr->child[index];
	                print_strings(curr,prefix);//print all the strings present in trie,having this prefix
	                cout<<"\n";

	            }
	            else//if child is not active ,then after this no prefix of query string will match to any string in,thus all answers are 0 after this point
	            {
	                while(i++<len)
	                cout<<"0\n";//for rest cases no match

	            }

	    }
}
int main() {
	int test;
	cin>>test;//input test cases
	while(test--)
	{
	    trie *root=new trie();//create root node for trie
	    int n;
	    string s,s1;
	    cin>>n;//input of no. of strings
	    while(n--)
	    {
	        cin>>s;//take input one by one and insert into trie
	        insert(root,s);
	    }
	    cin>>s1;//input of query string
	    string prefix;
	    search_strings(root,s1,prefix);

	}
	return 0;
}
