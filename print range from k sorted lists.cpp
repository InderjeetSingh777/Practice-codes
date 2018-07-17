//Problem statement:A functional problem
//Given K sorted lists of integers of size N each, find the smallest range that includes at least one element from each of the K lists.
// If more than one such range's are found, print the first such range found.
//Input:
//The first line of the input contains a single integer T denoting the number of test cases.
// For each test, inputs will be given to the findSmallestRange function. The input's to the function are:

//1.) A 2D-array(arr) of size K*N, where each row represents an individual list.

//2.) An integer N denoting the size of the list.

//3.) An integer K denoting the number of lists.

//Output:
//For each test case output in a single line with two space-separated integers denoting the required range.

//Constraints:
//1<=T<=50
//1<=K,N<=500

// you are required to complete this function
// function should print the required range
//logic involves the contribution from geeks for geeks editorial
#include<queue>

#define p  pair<int,pair<int,int> >
void findSmallestRange(int arr[][N], int n, int k)
{
      priority_queue< p,vector<p>,greater<p> >pq;//we store element and (list no..index in list)
      //create a min heap iof size k..taking first element of all the lists
      //maintain two variables,min-max
      int mini=INT_MAX,maxi=INT_MIN,list_no=-1,index_in_list=-1;
       pair<int,pair<int,int>> p1;
       pair<int,int> range;
       range=make_pair(-1,-1);
      for(int i=0;i<k;i++)
        {
            pq.push(make_pair(arr[i][0],make_pair(i,0)));//make pair in proper way
            maxi=max(maxi,arr[i][0]);
        }
        while(1)
        {
             p1=pq.top();//get front of min heap
             pq.pop();
             list_no=p1.second.first;
             mini=p1.first;
             index_in_list=p1.second.second;
             //cout<<" min is "<<mini;
             if(range.first==-1)// means we have not got even first range yet
             {
                 range=make_pair(mini,maxi);
             }
             else if((maxi-mini)<(range.second-range.first))//update range if possible
                range=make_pair(mini,maxi);
        //select the next element from the list in which this minimum element is present ,if list is over ,tthen break loop
            if(index_in_list==n-1)
            break;
            int element =arr[list_no][index_in_list+1];
            pq.push(make_pair(element,make_pair(list_no,index_in_list+1)));
            maxi=max(maxi,element);//if element is greater than current max,update current max
        }
        cout<<range.first<<" "<<range.second<<"\n";
        return;


}
