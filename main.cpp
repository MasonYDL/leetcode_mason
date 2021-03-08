//
//  main.cpp
//  leetcode
//
//  Created by Mason on 2020/7/21.
//  Copyright © 2020 Mason. All rights reserved.
//
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<math.h>
#include<ext/hash_map>
#include<list>
#include<stdio.h>
#include<map> 
#include<unordered_map>
#include<numeric>
using namespace std;
class solustion
{

    public:


    vector<int> partitionLabels(string S) {
    vector< vector<int > > v;
    vector<int> res;
    int i;
    int j;
    int k;
    int len=S.size();
    vector<int> temp(2,0);
    //v.push_back(temp);
    for(i=0;i<len;i++)
    {
        for(k=0;k<v.size();k++)
            if(S[v[k][0]]==S[i])
                break;
        if(k!=v.size())
            continue;
        for(j=len;j>=0;j--)
        {
            if(S[i]==S[j])
            {
                temp[0]=i;
                temp[1]=j;
                v.push_back(temp);
                break;
            }
        }
    }
    //sort(v.begin(),v.end(),[] (vector<int> a,vector<int> b){return a[0]<b[0];});
    for(i=0;i<v.size();i++)
    cout<<v[i][0]<<','<<v[i][1]<<endl;
    vector<int> temp1(2,0);
    temp1=v[0];
    cout<<temp1[1]<<endl;
    for(i=1;i<v.size();i++)
    {
        if(temp1[1]==temp1[0])
        {
            res.push_back(1);
            temp1=v[i];
        }
        if(v[i][0]>temp1[1])
            {
                res.push_back(v[i][0]-temp1[0]);
                cout<<i<<endl;
                temp1=v[i];
            }
    }
    for(i=0;i<res.size();i++)
        len-=res[i];
    if(len!=0)
        res.push_back(len);
    return res;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> res;
    int l=numbers.size();
    int start=0;
    int end=l-1;
    while(1)
    {
        if(numbers[start]+numbers[end]==target)
        {
            res.push_back(start);
            res.push_back(end);
            break;
        }
        if(numbers[start]+numbers[end]>target)
            --end;
        if(numbers[start]+numbers[end]<target)
            ++start;
    }
    return res;
}


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int l1=m-1;
    int l2=n-1;
    int l3=nums1.size()-1;
    while(1)
    {
        if(l1==-1 && l2==-1)
            break;
        if(nums1[l1]>nums2[l2])
        {
            nums1[l3]=nums1[l1];
            --l1;
            --l3;
        }
        else{
            nums1[l3]=nums2[l2];
            --l2;
            --l3;
        }
    }
}


int maxProfit(vector<int>& prices) {
    int res=0;
    int len=prices.size();
    if(len==0|| len==1)
        return 0;
    for(int i=0;i<len-1;i++)
    {
        if(prices[i+1]>prices[i])
            res+=prices[i+1]-prices[i];
    }
    return res;
}
bool compare(vector<int> a,vector<int> b)
{
    return a[0]>b[0];
}




bool checkPossibility(vector<int>& nums) {
    int len=nums.size();
    int i;
    int mistake=0;
    if(len<2)
        return true;
    for(i=1;i<len;i++)
    {
        if(mistake>1)
            return false;
        if(nums[i-1]>nums[i])
        {
            mistake++;
            nums[i]=nums[i-1];
        }
    }
    return true;
}

/*
ListNode *detectCycle(ListNode *head) {
    ListNode *fast=head;
    ListNode *slow=head;
    fast=fast->next->next;
    slow=slow->next;
    while(fast!=slow)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    fast=head;
    while(fast!=slow)
    {
        fast=fast->next;
        slow=slow->next;
    }
    return fast;
}
*/

bool judgeSquareSum(int c) {
    int p=(int)sqrt(c);
    int i=p,j=0;
    while(i!=j)
    {
        cout<<j<<','<<i<<endl;
        if(i*i+j*j<c)
            j++;
        else if(i*i+j*j>c)
            i--;
        if(i*i+j*j==c)
            return true;
    }
    return false;
}



string findLongestWord(string s, vector<string>& d) {
    vector<int> c(26,0);
    int len1=s.size();
    int i,j;
    int len2=d.size();
    int max=0;
    int temp=-1;
    for(i=0;i<len1;i++)
    ++c[s[i]-97];
    for(i=0;i<len2;i++)
    {
        for(j=0;j<d[i].size();j++)
        {
            if(c[d[i][j]]==0)
                break;
        }
        if(j==max)
            if(j>max)
            {
                max=j;
                temp=i;
            }
    }
    if(temp==-1)
        return "";
    return d[temp];
}

int mySqrt(int x) {
    int n=1;
    int left,right,temp;
    while(n*n<x)
        n*=2;
    left=1;
    right=n;
    while(left+1!=right)
    {
        temp=(left+right)/2;
        if(x>temp*temp)
            left=temp;
        else
            right=temp; 
    }
    return left;
}


int upper(vector<int>& nums, int target)
{
    int l=0,r=nums.size(),mid=0;
    while(l<r)
    {
        mid=(l+r)/2;
        if(nums[mid]>target)
            r=mid;
        else
        {
            l=mid+1;
        }
    }
    return l;
}

int lower(vector<int>& nums, int target)
{
    int l=0,r=nums.size(),mid=0;
    while(l<r)
    {
        mid=(r+l)/2;
        if(nums[mid]>=target)
            r=mid;
        else
        {
            l=mid+1;
        }
    }
    return l;
}

int singleNonDuplicate(vector<int>& nums) {
    int len=nums.size();

    int l=0;
    int r=len-1;
    int x=2;
    if(len==1)
    return nums[0];
    if(nums[0]!=nums[1])
    return nums[0];
    if(nums[len-2]!=nums[len-1])
    return nums[len-1];

    while(r<len)
    {
        r=l+x;
        x*=2;
        if(nums[r]==nums[r+1] && r<len)
        l=r;
        else if(r>len)
        {
            r=l;
            x=2;
        }
        else
        {
            if(r==l+2)
            return nums[r];
            else
            {
                x=2;
                r=l;
            }
            
        }

        cout<<l<<endl;
    }
    return nums[r];
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1=nums1.size(),len2=nums2.size();
    int flag=0;
    int num;
    int l=0;
    int r,mid;
    if(len2>len1)
    {
        vector<int> temp=nums2;
        int temp1=len2;
        len2=len1;
        len1=temp1;
        nums2=nums1;
        nums1=temp;
    }
    if((len1+len2)%2==0)
        num=(len1+len2)/2;
    else
    {
        flag=1;
        num=(len1+len2)/2+1;
    }
    r=num;
    if(len2==0)
    {
        if(flag==1)
        return nums1[num-1];
        else
        return (nums1[num-1]+nums1[num])/2;
    }
    while(l<r)
    {
        mid=(l+r)/2;
        if(nums1[mid-1]>nums2[num-mid])
        {
            r=mid-1;
        }
        else if(nums1[mid-1]<nums2[num-mid-2])
        {
            l=mid;
        }
        cout<<l<<','<<r<<endl;
    }
    return nums1[l];
}


int quickSelection(vector<int> &nums,int l,int r)
{
    int i=l+1,j=r;
    while(1)
    {
        while(i<r && nums[i]<=nums[l])
        ++i;
        while(l<j && nums[j]>=nums[l])
        --j;
        if(i>=j)
        break;
        swap(nums[i],nums[j]);
    }
    swap(nums[l],nums[j]);
    return j;
}



vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> counts;
    int max_count=0;
    for(const int & num : nums)
    {
        max_count=max(max_count,++counts[num]);
    }
    vector<vector<int> > buckets(max_count+1);
    for(const auto & p: counts)
    {
        buckets[p.second].push_back(p.first);
    }
    vector<int> ans;
    for(int i=max_count;i>=0 && ans.size()<k;--i)
    {
        for(const int & num: buckets[i])
        {
            ans.push_back(num);
            if(ans.size()==k)
            {
                break;
            }
        }
    }
    return ans;
}

string frequencySort(string s) {
//451
    string str;
    vector<int>hash(128,0);
    int j;
    priority_queue<int,vector<int>,less<int> >que;
    for(int i=0;i<s.size();i++)
    {
        hash[s[i]]++;
    }
    for(int i=0;i<hash.size();i++)
    {
        if(hash[i])
        {
            que.push(hash[i]);
        }
    }
    while(!que.empty())
    {
        int res=que.top();
        for( j=0;j<hash.size();j++)
        {
            if(hash[j]==res)
            {
                for(int k=0;k<res;k++)
                {
                    str+=(char)j;
                }
                break;
            }
        }
        hash[j]=0;
        que.pop();
    }
    return str;
}

void sortColors(vector<int>& nums) {
//75
int zero=-1;
int two=nums.size();
for(int i=0;i<two;)
{
    if(nums[i]==1)
        i++;
    else if(nums[i]==2)
    {
        swap(nums[i],nums[--two]);
    }
    else
    {
        swap(nums[++zero],nums[i++]);
    }
}
}


int maxAreaOfIsland(vector<vector<int> >& grid) {
    //695
    int len1=grid.size();
    int len2=grid[0].size();
    vector<vector<int> > visited(len1,vector<int>(len2,0));
    stack<pair <int,int> > st;
    int i,j;
    int max=0;
    for(i=0;i<len1;i++)
        for(j=0;j<len2;j++)
        {
            if(grid[i][j]==1 && visited[i][j]==0)
            {
                int temp=0;
                visited[i][j]=1;
                st.push(pair<int,int> (i,j));
                temp++;
                while(!st.empty())
                {
                    int t1=st.top().first;
                    int t2=st.top().second;
                    st.pop();
                    cout<<t1<<','<<t2<<','<<temp;
                    if(t1-1>0)
                        if(grid[t1-1][t2]==1 && visited[t1-1][t2]==0)
                            {
                                visited[t1-1][t2]=1;
                                st.push(pair<int,int> (t1-1,t2));
                                temp++;
                                cout<<"up"<<endl;
                            }
                    if(t1+1<len1)
                        if(grid[t1+1][t2]==1 && visited[t1+1][t2]==0)
                            {
                                visited[t1+1][t2]=1;
                                st.push(pair<int,int> (t1+1,t2));
                                temp++;
                                cout<<"down"<<endl;
                            }
                    if(t2-1>0)
                        if(grid[t1][t2-1]==1 && visited[t1][t2-1]==0)
                        {
                            visited[t1][t2-1]=1;
                            st.push(pair<int,int> (t1,t2-1));
                            temp++;
                            cout<<"left"<<endl;
                        }
                    if(t2+1<len2)
                        if(grid[t1][t2+1]==1 && visited[t1][t2+1]==0)
                        {
                            visited[t1][t2+1]=1;
                            st.push(pair<int,int> (t1,t2+1));
                            temp++;
                            cout<<"right"<<endl;
                        }
                }
                if(temp>max)
                max=temp;
            }

        }
    return max;    
}



int findCircleNum(vector<vector<int> >& isConnected) {
    //547
    int len=isConnected.size();
    vector<int> visited(len,0);
    stack<int> st;
    int i,j;
    int num=0;
    for(i=0;i<len;i++)
    {
        if(isConnected[i][i]==1 && visited[i]==0)
            {
                st.push(i);
                visited[i]=1;
            }
        while(!st.empty())
        {
            int temp=st.top();
            cout<<temp<<endl;
            st.pop();
            for(int j=temp;j<len;j++)
            {
                if(isConnected[temp][j]==1 && visited[j]==0)
                    {
                        visited[j]=1;
                        st.push(j);
                    }
            }
            if(st.empty())
                num++;
        }
        cout<<"/////////"<<endl;
    }
        return num;
}


/*
vector<vector<int> > pacificAtlantic(vector<vector<int> >& matrix) 
{
//417
    if(matrix.empty() || matrix[0].empty())
    {
        return {{}};
    }

    vector<vector<int> > ans;
    int m=matrix.size(), n=matrix[0].size();
    vector<vector<bool> > can_reach_p(m,vector<bool>(n,false));
    vector<vector<bool> > can_reach_a(m,vector<bool>(n,false));
    for(int i=0;i<m;++i)
    {
        dfs(matrix,can_reach_p,i,0);
        dfs(matrix,can_reach_a,i,n-1);
    }
    for(int i=0;i<m;++i)
    {
        dfs(matrix,can_reach_p,0,i);
        dfs(matrix,can_reach_a,m-1,i);
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;++j)
            if(can_reach_p[i][j] && can_reach_a[i][j])
            {
                ans.push_back(vector<int>(i,j));
            }
    return ans;
}
void dfs(const vector<vector<int> > & matrix, vector<vector<bool> >& can_reach, int r, int c)
{//417
    if(can_reach[r][c])
    {
        return;
    }
    can_reach[r][c]=true;
    int x,y;
    for(int i=0;i<4;++i)
    {
        x=r+direction[i],y=c+direction[i+1];
        if(x>=0 && x<matrix.size() && y>=0 && y<matrix[0].size() && matrix[r][c]<=matrix[x][y])
        {
            dfs(matrix,can_reach,x,y);
        }
    }
}
*/


vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > ans;
    backtracking(nums,0,ans);
    return ans;
}

void backtracking(vector<int> &nums, int level,vector<vector<int> > &ans)
{
    if(level==nums.size()-1)
    {
        ans.push_back(nums);
        return ;
    }
    for(int i=level;i<nums.size();i++)
    {
        swap(nums[i],nums[level]);
        backtracking(nums,level+1,ans);
        swap(nums[i],nums[level]);
    }
}

vector<vector<int> > combine(int n, int k) {
    //77
    vector<vector<int> > ans;
    vector<int> comb(k,0);
    int count=0;
    backtracking_77(ans,comb,count,1,n,k);
    return ans;
}

void backtracking_77(vector<vector<int> >& ans, vector<int>& comb,int count, int pos,int n,int k)
{
   if(k==count)
    {
        ans.push_back(comb);
        return ;
    }
    for(int i=pos;i<=n;i++)
    {
        comb[count++]=i;
        backtracking_77(ans,comb,count,i+1,n,k);
        count--;
    }
}


bool exist(vector<vector<char> >& board, string word) {
//79
    int len1=board.size(),len2=board[0].size();
    vector<vector<bool> > visited(len1,vector<bool>(len2,false));
    bool find=false;
    
    for(int i=0;i<len1;++i)
        for(int j=0;j<len2;++j)
        {
            backtracking_79(i,j,board,word,find,visited,0);
        }
    return find;
}

void backtracking_79(int i,int j,vector<vector<char> > & board,string & word,bool &find, vector<vector<bool> > & visited, int pos)
{
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size())
        return ;
    if(visited[i][j] || find || word[pos]!=board[i][j])
        return ;
    if(pos==word.size()-1)
        {
            find = true;
            return ;
        }
    visited[i][j]=true;
            backtracking_79(i+1,j,board,word,find,visited,pos+1);
            backtracking_79(i-1,j,board,word,find,visited,pos+1);
            backtracking_79(i,j+1,board,word,find,visited,pos+1);
            backtracking_79(i,j-1,board,word,find,visited,pos+1);



    visited[i][j]=false;
}

vector<vector<string> > solveNQueens(int n) {
    //51
    vector<vector<string> > ans;
    if(n==0)
        return ans;
    vector<string> board(n,string(n,'.'));
    vector<bool> column(n,false); 
    vector<bool> ldiag(2*n-1,false);
    vector<bool> rdiag(2*n-1,false);
    backtracking_51(ans,board,column,ldiag,rdiag,0,n);
    return ans;
}

void backtracking_51(vector<vector<string> >& ans, vector<string>& board, vector<bool> &column,vector<bool> &ldiag, vector<bool> &rdiag,int row,int n)
{
    if(row==n)
    {
        ans.push_back(board);
        return ;
    }
    for(int i=0;i<n;i++)
    {
        if(column[i] || ldiag[n-row+i-1] || rdiag[row+i+1])
            continue;
        board[row][i]='Q';
        column[i]=ldiag[n-row+i-1]=rdiag[row+1+i]=true;
        backtracking_51(ans,board,column,ldiag,rdiag,row+1,n);
        board[row][i]='.';
        column[i]=ldiag[n-row+i-1]=rdiag[row+1+i]=false;
    }
    
}



int shortestBridge(vector<vector<int> >& grid) {
    //934
    vector<int> direction;
    direction.push_back(-1);
    direction.push_back(0);
    direction.push_back(1);
    direction.push_back(0);
    direction.push_back(-1);
    int m=grid.size(),n=grid[0].size();
    queue<pair<int,int> > points;
    
    bool flipped=false;
    for(int i=0;i<m;++i)
    {
        if(flipped)
            break;
        for(int j=0;j<n;++j)
        {
            if(grid[i][j]==1)
            {
                dfs(points,grid,m,n,i,j);
                flipped=true;
                break;
            }
        }
    }
    int x,y;
    int level=0;
    while(!points.empty())
    {
        ++level;
        int n_points=points.size();
        while(n_points--)
        {
            int r=points.front().first;
            int c=points.front().second;
            points.pop();
            for(int k=0;k<4;++k)
            {
                x=r+direction[k],y=c+direction[k+1];
                if(x>=0 && y>=0 && x<m && y<n)
                {
                    if(grid[x][y]==2)
                    {
                        continue;
                    }
                    if(grid[x][y]==1)
                    {
                        return level;
                    }
                    points.push(pair<int,int>(x,y));
                    grid[x][y]=2;
                }
            }
        }
    }
    return 0;
}

void dfs(queue<pair<int,int> > &points, vector<vector<int> >& grid,int m,int n,int i,int j)
{
    if(i<0 || j<0 || i==m || j==n || grid[i][j]==2)
    {
        return ;
    }
    if(grid[i][j]==0)
    {
        points.push(pair<int,int>(i,j));
        return ;
    }
    grid[i][j]=2;
    dfs(points,grid,m,n,i-1,j);
    dfs(points,grid,m,n,i+1,j);
    dfs(points,grid,m,n,i,j-1);
    dfs(points,grid,m,n,i,j+1);
}

vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
    //126 hard
    queue<string> q;
    vector<vector<string> > ans;
    int len1=beginWord.size();
    int len2=wordList.size();
    vector<int> visited(0,len2);
    int p=0;;
    q.push(beginWord);
    for(int i=0;i<len2;i++)
    {
        if(wordList[i]==beginWord)
            visited[i]=1;
    }
    while(!q.empty())
    {
        string temp=q.front();
        q.pop();
        if(temp==" ")
        {
            p++;
            temp=q.front();
            q.pop();
        }
        if(q.empty())
            q.push(" ");
        for(int i=0;i<len2;++i)
        {
            if(judgedifference(temp,wordList[i]) && !visited[i])
            {
                q.push(wordList[i]);
                visited[i]=1;
                vector<string> temp1;
                temp1.push_back(wordList[i]);
                ans.push_back(temp1);
            }
        }
    }
}
bool judgedifference(string s1, string s2)
{
    //126 hard
    int d=0;
    for(int i=0;i<s1.size();i++)
        if(s1[i]!=s2[i])
            ++d;
    if(d==1)
        return true;
    return false;
}

void solve(vector<vector<char> >& board) {
    //130 Medium
    int len1=board.size();
    if(len1==0)
        return ;
    int len2=board[0].size();
    vector<vector<int> > visited(len1,vector<int>(len2,0));
    stack<pair<int,int> > s;
    vector<pair<int,int> > buffer;
    int flag=0;
    for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++)
        {
            if(board[i][j]=='O' && !visited[i][j] & i>0 && i<len1-1 && j>0 && j<len2-1)
            {
                visited[i][j]=1;
                s.push(pair<int,int>(i,j));
            }
            while(!s.empty())
            {
                pair<int, int> temp=s.top();
                if(temp.first==0 || temp.first== len1-1 || temp.second==0 || temp.second==len2-1)
                {
                    flag=1;
                }
                buffer.push_back(temp);
                s.pop();

                if(temp.first+1<len1)
                {
                    if(board[temp.first+1][temp.second]=='O' && !visited[temp.first+1][temp.second])
                    {
                        visited[temp.first+1][temp.second]=1;
                        s.push(pair<int,int>(temp.first+1,temp.second));
                    }
                }
                if(temp.first-1>=0)
                    if(board[temp.first-1][temp.second]=='O' && !visited[temp.first-1][temp.second])
                {
                    visited[temp.first-1][temp.second]=1;
                    s.push(pair<int,int>(temp.first-1,temp.second));
                }
                if(temp.second+1<len2)
                    if(board[temp.first][temp.second+1]=='O' && !visited[temp.first][temp.second+1])
                {
                    visited[temp.first][temp.second+1]=1;
                    s.push(pair<int,int>(temp.first,temp.second+1));
                }
                if(temp.second-1>=0)
                    if(board[temp.first][temp.second-1]=='O' && !visited[temp.first][temp.second-1])
                    {
                        visited[temp.first][temp.second-1]=1;
                        s.push(pair<int,int>(temp.first,temp.second-1));
                    }
            }
            if(flag==0)
            for(int i=0;i<buffer.size();i++)
                board[buffer[i].first][buffer[i].second]='X';
            buffer.clear();
            flag=0;
        }
}
vector<int> vis;
void backtrack_47(vector<int>& nums, vector<vector<int> >& ans, int idx, vector<int>& perm) {
    //47
    if (idx == nums.size()) {
        ans.push_back(perm);
        return;
    }
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
            continue;
        }
        perm.push_back(nums[i]);
        vis[i] = 1;
        backtrack_47(nums, ans, idx + 1, perm);
        vis[i] = 0;
        perm.pop_back();
    }
}

vector<vector<int> > permuteUnique(vector<int>& nums) {
    //47
    vector<vector<int> > ans;
    vector<int> perm;
    vis.resize(nums.size());
    sort(nums.begin(), nums.end());
    backtrack_47(nums, ans, 0, perm);
    return ans;
}



int rob(vector<int>& nums) {
    //198 medium
    if(nums.empty())
        return 0;
    int n=nums.size();
    vector<int> dp(n+1,0);
    dp[1]=nums[0];
    for(int i=2;i<=n;++i)
        dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
    return dp[n];
}


int numberOfArithmeticSlices(vector<int>& A) {
    // 413 medium
    int n=A.size();
    if(n<3)
    return 0;
    vector<int> dp(n,0);
    for(int i=2;i<n;i++)
    {
        if(A[i]-A[i-1]==A[i-1]-A[i-2])
            dp[i]=dp[i-1]+1;
    }
    return accumulate(dp.begin(),dp.end(),0);
}



int minPathSum(vector<vector<int> >& grid) {
    //64 medium
    int len1=grid.size();
    int len2=grid[0].size();
    vector<vector<int> > distance(len1,vector<int>(len2,0));
    distance[0][0]=grid[0][0];
    for(int i=1;i<len2;++i)
        distance[0][i]=distance[0][i-1]+grid[0][i];
    for(int i=1;i<len1;i++)
        distance[i][0]=distance[i-1][0]+grid[i][0];
    for(int i=1;i<len1;++i)
        for(int j=1;j<len2;++j)
        {
            distance[i][j]=min(distance[i-1][j],distance[i][j-1])+grid[i][j];
        }
    return distance[len1-1][len2-1];
}


vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    //542 medium
    if (matrix.empty()) 
    return matrix;
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int> > dp(n, vector<int>(m, INT_MAX - 1));
    for (int i = 0; i < n; ++i) 
    {
       for (int j = 0; j < m; ++j) 
       {
           if (matrix[i][j] == 0) 
           {
              dp[i][j] = 0;
           } 
           else 
           {
              if (j > 0) 
              {
                  dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
              }
              if (i > 0) 
              {
                  dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            } 
           }
       }
    }
    for (int i = n - 1; i >= 0; --i) 
    {
       for (int j = m - 1; j >= 0; --j) 
       {
           if (matrix[i][j] != 0) 
           {
              if (j < m - 1) 
              {
                  dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
              }
              if (i < n - 1) 
            {
                  dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
            }
           }
        }
    }
return dp; 
}

int maximalSquare(vector<vector<char> >& matrix) {
    //221 medium
    if(matrix.size() || matrix[0].empty())
        return 0;
    int m=matrix.size(),n=matrix[0].size();
    int max_side=0;
    vector<vector<int> > dp(m+1,vector<int>(n+1,0));
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
        {
            if(matrix[i-1][j-1]=='1')
            {
                dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
            }
            max_side=max(max_side,dp[i][j]);
        }
    return max_side*max_side;
}




int numSquares(int n)
{
    //279 medium
    vector<int> result(n+1, 0x7FFFFFFF); // 每个数的最优解都存在result数组里
    result[0] = 0;
    for (int i = 1; i <= n; i++){
        for(int j = 1; i-j*j >= 0 ; j++) {  // 观察比N小的数，且符合N = IxI + N'的数值
            result[i] = min(result[i], result[i-j*j] + 1); // 把最优解（最小值）+ 1 写入result
        }
    }
    return result[n];
}

int numDecodings(string s) {
    //91 medium
    if(s[0]=='0')
        return 0;
    int pre=1,curr=1;
    for(int i=1;i<s.size();++i)
    {   
        int temp=curr;
        if(s[i]=='0')
        {
            if(s[i-1]=='1' || s[i-1]=='2')
                curr=pre;
            else 
                return 0;
        }   
        else if(s[i-1]=='1' || (s[i-1]=='2' && s[i]>='1' && s[i]<='6'))
            curr=curr+pre;
        pre=temp;
    }
    return curr;

}


bool wordBreak(string s, vector<string>& wordDict) {
    //139 medium
    int len=s.size();
    vector<int> dp(len+1,false);
    dp[0]=true;
    for(int i=1;i<len;i++)
        for(const string & word:wordDict)
        {
            int temp=word.size();
            if(i>=temp && s.substr(i-temp,i)==word)
                dp[i]=dp[i]||dp[i-temp];
        }
    return dp[len];
}


int lengthOfLIS(vector<int>& nums) {
    //300 medium
    int n=(int)nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}


int longestCommonSubsequence(string text1, string text2) {
    //1143 medium
    int len1=text1.size();
    int len2=text2.size();
    vector<vector<int> > dp(len1+1,vector<int>(len2+1,0));
    for(int i=1;i<=len1;++i)
        for(int j=1;j<=len2;++j)
        {
            if(text1[i-1]==text2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else   
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    return dp[len1][len2];
}


bool canPartition(vector<int>& nums) {
    //416 medium //not finished
    int sum=accumulate(nums.begin(),nums.end(),0);
    int len=nums.size();
    if(sum & 1)
        return false;
    int target=sum/2;

    vector<vector<bool> > dp(len+1,vector<bool>(target+1,false));
    for(int i=0;i<len;++i)
        dp[i][0]=true;
    for(int i=0;i<=len;++i)
        for(int j=nums[i-1];j<=target;++j)
        {
            dp[i][j]=dp[i-1][0] || dp[i][j-nums[i-1];
        }
    return dp[n][target];
}


int findMaxForm(vector<string>& strs, int m, int n) {
    //474 medium
    int len=strs.size();
    vector<vector<int> > dp(m+1,vector<int>(n+1,0));
    for(const string & str:strs)
    {
        auto [count1,count2]=count_474(str);
        for(int i=m;i>=count1;--i)
        {
            for(int j=n;j>=count2;--j)
                dp[i][j]=max(dp[i][j],1+dp[i-count1][j-count2]);
        }
    }
    return dp[m][n];
}

pair<int,int> count_474(string str)
{
    int count0=0,count1=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='0')
            count0++;
        else
            count1++;
    }
    return make_pair(count0,count1);
}


int coinChange(vector<int>& coins, int amount) {
    // 322 medium
    vector<int> dp(amount+1,amount+2);
    dp[0]=0;
    for(int i=1;i<=amount;++i)
        for(const int & coin :coins)
            if(i>=coin)
                dp[i]=min(dp[i],dp[i-coin]+1);
    return dp[amount]==amount+2 ? -1:dp[amount];
}


int maxTurbulenceSize(vector<int>& arr) {
    //978 medium
    int len=arr.size();
    vector<int> dp1(len+1,1);
    vector<int> dp2(len+1,1);
    for(int i=1;i<len;++i)
    {
        if(i&1)
        {
            if(arr[i]>arr[i-1])
                dp1[i]=max(dp1[i],dp1[i-1]+1);
        }
        else
        {
            if(arr[i]<arr[i-1])
                dp1[i]=max(dp1[i],dp1[i-1]+1);
        }
    }

    for(int i=1;i<len;++i)
    {
        if(i&1)
        {
            if(arr[i]<arr[i-1])
                dp2[i]=max(dp2[i],dp2[i-1]+1);
        }
        else
        {
            if(arr[i]>arr[i-1])
                dp2[i]=max(dp2[i],dp2[i-1]+1);
        }
    }
    int max1=0,max2=0;
    for(int i=0;i<len+1;++i)
        {
            if(dp1[i]>max1)
                max1=dp1[i];
        }
    for(int i=0;i<len+1;++i)
        {
            if(dp2[i]>max2)
                max2=dp2[i];
        }
    cout<<"max1:"<<max1<<endl;
    cout<<"max2:"<<max2<<endl;
    if(max1>max2)  
    {
        cout<<'1'<<endl;
        return max1;
    }    

    return max2;
}



int minDistance(string word1, string word2) {
    //72 medium
    int len1=word1.size();
    int len2=word2.size();
    vector<vector<int> >dp(len1+1,vector<int>(len2+1,0));
    for(int i=0;i<=len1;++i)
        for(int j=0;j<=len2;++j)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else
            {
                dp[i][j]=min(dp[i-1][j-1]+((word1[i-1]==word2[j-1]) ? 0:1),min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
        }
    return dp[len1][len2];
}

int minSteps(int n) {
    vector<int> dp(n+1);
    for(int i=2;i<=n;++i)
    {
        dp[i]=i;
        for(int j=2;j<=n;++j)
        {
            if(i%j==0)
            {
            dp[i]=dp[i]+dp[i/j];
            break;
            }
        }
    }
    return dp[n];
}




int maxProfit_121(vector<int>& prices) {
    //121 easy
    int maximum=0;
    int len=prices.size();
    vector<int> dp(len,0);
    dp[0]=prices[0];
    for(int i=1;i<len;++i)
    {
        dp[i]=min(dp[i-1],prices[i]);
        maximum=max(maximum,prices[i]-dp[i]);
    }
    return maximum;

}


int maxProfit_188(int k, vector<int>& prices) {
    //188 hard
    int len=prices.size();
    if(len<2)
        return 0;
    if(k>=len)
        return helper_188(prices);
    vector<int> sell(len+1,0), buy(len+1,INT_MIN);
    for(int i=0;i<=len;++i)
        for(int j=1;j<=k;++j)
        {
            buy[j]=max(buy[j],sell[j-1]-prices[i]);
            sell[j]=max(sell[j],buy[j]+prices[i]);
        }
    return sell[k];
}

int helper_188(vector<int>& prices)
{
    int sum=0;
    for(int i=1;i<prices.size();++i)
        sum+= prices[i]-prices[i-1]>0 ? (prices[i]-prices[i-1]):0;
    return sum;
}

int maxProfit_309(vector<int>& prices) {
    //309 medium
    int len=prices.size();
    vector<int> buy(len),sell(len),s1(len),s2(len);
    buy[0]=s1[0]=-prices[0];
    sell[0]=s2[0]=0;
    for(int i=1;i<len;++i)
    {
        buy[i]=s2[i-1]-prices[i];
        s1[i]=max(s1[i-1],buy[i-1]);
        sell[i]=max(buy[i-1],s1[i-1])+prices[i];
        s2[i]=max(s2[i-1],sell[i-1]);
    }
    return max(sell[len-1],s2[len-1]);
}

int rob_213(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    int result1 = helper_213(nums, 0, nums.size() - 2); // 情况二
    int result2 = helper_213(nums, 1, nums.size() - 1); // 情况三
    return max(result1, result2);
}

int helper_213(vector<int>& nums, int start, int end) {
    if (end == start) return nums[start];
    vector<int> dp(nums.size());
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);
    for (int i = start + 2; i <= end; i++) {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    return dp[end];
}


   int maxSubArray(vector<int>& nums) {
       //53 easy
        int pre = 0, maxAns = nums[0];
        int len=nums.size();
        for (int i=0;i<len;++i) {
            pre = max(pre + nums[i], nums[i]);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }


    int minDistance_583(string word1, string word2) {
        //583 medium
        int len1=word1.size();
        int len2=word2.size();
        vector<vector<int> > dp(len1+1,vector<int>(len2+1,0));
        for(int i=1;i<=len1;++i)
            dp[i][0]=i;
        for(int i=1;i<=len2;++i)
            dp[0][i]=i;
        for(int i=1;i<=len1;++i)
            for(int j=1;j<=len2;++j)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j-1]+2,min(dp[i-1][j],dp[i][j-1])+1);
            }
        return dp[len1][len2];

    }
int countPrimes(int n) {
    if(n<2)
        return 0;
    int count=n-2;
    vector<bool> prime(n,true);
    for(int i=2;i<=n;++i)
    if(prime[i])
        for(int j=i*2;j<n;j+=i)
        {
            if(prime[j])
            {
                prime[j]=false;
                count--;
            }
        }
    return count;
}

vector<vector<int> > matrixReshape(vector<vector<int> >& nums, int r, int c) {
    //566 easy
    int len1=nums.size();
    int len2=nums[0].size();
    int num=len1*len2;
    if(num!=r*c)
        return nums;
    vector<int> temp(r*c,0);
    for(int i=0;i<len1;++i)
        for(int j=0;j<len2;++j)
        {
            temp[i*len1+j]=nums[i][j];
        }
    vector<vector<int> > res(r,vector<int>(c,0));
    for(int i=0;i<num;++i)
    {
        res[i/r][i%c]=temp[i];
    }
    return res;
}


int longestOnes(vector<int>& A, int K) {
    //1005 medium
    int res = 0, zeros = 0, left = 0;
    for (int right = 0; right < A.size(); ++right) {
        if (A[right] == 0) ++zeros;
        while (zeros > K) {
            if (A[left++] == 0) --zeros;
        }
        res = max(res, right - left + 1);
    }
    return res;
}
    string convertToBase7(int num) {
        //504 easy
        if (num < 0) return "-" + convertToBase7(-1 * num);
        if (num < 7) return to_string(num);
        return convertToBase7(num / 7) + to_string(num % 7);
    }

int trailingZeroes(int n) {
    //172 easy
    return n==0? 0: n/5+trailingZeroes(n/5);
}


string addStrings(string num1, string num2) 
{
    //415 easy
    string res("");
    int len1=num1.size();
    int len2=num2.size();
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    if(len1>len2)
    {
        swap(len1,len2);
        swap(num1,num2);
    }
    int addbit=0;
    for(int i=0;i<len1;++i)
    {
        int cur_sum=(num1[i]-'0')+(num2[i]-'0')+addbit;
        res+=to_string(cur_sum%10);
        addbit= cur_sum<10 ? 0:1;
    }
    for(int i=len1;i<len2;++i)
    {
        int cur_sum=(num2[i]-'0')+addbit;
        res+=to_string(cur_sum%10);
        addbit=cur_sum<10 ? 0:1;
    }
    if(addbit)
        res+="1";
    reverse(res.begin(),res.end());
    return res;
}


    bool isPowerOfThree(int n) {
        //326 easy
        return fmod(log10(n)/log10(3),1)==0;
    }

    int hammingDistance(int x, int y) {
        //416 easy
        int temp=x^y;
        int res=0;
        while(temp)
        {
            res+=temp&1;
            temp>>=1;
        }
        return res;
    }
    uint32_t reverseBits(uint32_t n) {
        //190 easy
        uint32_t res=0;
        for(int i=0;i<32;i++)
        {
            res<<=1;
            res+=n&1;
            n>>=1;
        }
        return res;
    }

    int singleNumber(vector<int>& nums) {
            //136 easy
            int temp=0;
            for(int i=0;i<nums.size();++i)
                temp^=nums[i];
            return temp;
    }



    bool isPowerOfFour(int n) {
        //342 easy
        int count=0;
        while(n)
        {
            if(!n&1)
                {
                    count++;
                    n>>=1;
                }
            else
            {
                n>>=1;
                break;
            }
        }
        if(!n)
            return false;
        if(n&1)
            return false;
        return true;
    }

    int maxProduct(vector<string>& words) {
        //318 medium
        unordered_map<int,int> hash;
        int ans=0;
        for(const string & word: words)
        {
            int mask=0; 
            int size=word.size();
            for(const char & c:word)
            {
                mask|=1<<(c-'a');
            }
            hash[mask]=max(hash[mask],size);
        }
        for(const auto &[h_mask,h_len]:hash)
        {
            if(!(mask&h_mask))
            {
                ans=max(ans,size*h_len);
            }
        }
        return ans;
    }
    vector<int> countBits(int num) {
        //338 medium
        vector<int> res(num+1);
        int temp;
        for(int i=0;i<=num;++i)
        {
            temp=i;
            while(temp)
            {
                res[i]+=(temp&1);
                temp>>=1;
            }
        }
        return res; 
    }

    int missingNumber(vector<int>& nums) {
        //268 medium
        int temp=0;
        for(int i=0;i<nums.size();++i)
        {
            temp=nums[i]^i;
        }
        return temp;
    }


    bool hasAlternatingBits(int n) {
        //693 easy
        int temp=0;
        temp=n&1;
        while(n)
        {
            n>>=1;
            if(!((n&1)^temp))
            {
                return false;
            }
            temp=n&1;
        }
        return true;
    }

    int findComplement(int num) {
        //476 easy
        int temp=num;
        int count=0;
        while(temp)
        {
            temp>>=1;
            ++count;
        }
        while(--count>=0) 
        {
            temp=1<<count;
        }
        return temp^num;
    }

    vector<int> singleNumber_260(vector<int>& nums) {
        //260 medium
        vector<int> res(2);
        int temp=0;
        int temp1=0,temp2=0;
        int count=0;
        int len=nums.size();
        for(int i=0;i<len;++i)
        {
            temp^=nums[i];
        }
        while(!(temp&1))
        {
            temp>>=1;
            ++count;
        }
        temp1=0;
        for(int i=0;i<len;++i)
        {
            if((nums[i]>>count)&1)
                temp1^=nums[i];
            else   
                temp2^=nums[i];
        }
        res[0]=temp1;
        res[1]=temp2;
        return res;
    }
    void rotate(vector<vector<int> >& matrix) {
        //48 medium
        int n=matrix.size();
        int temp;
        for(int i=0;i<n/2;++i)
            for(int j=0;j<n-1;++j)
            {
            temp = matrix[j][n-i];
           matrix[j][n-i] = matrix[i][j];
           matrix[i][j] = matrix[n-j][i];
           matrix[n-j][i] = matrix[n-i][n-j];
           matrix[n-i][n-j] = temp;
            }
    }


bool searchMatrix(vector<vector<int> >& matrix, int target) {
    //240 medium;
    int m = matrix.size();
    if (m == 0) {
       return false;
    }
    int n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
       if (matrix[i][j] == target) {
           return true;
       } else if (matrix[i][j] > target) {
           --j;
    } else { ++i;
    } }
    return false;
}


int maxChunksToSorted(vector<int>& arr) {
    //769 medium
    int chunks = 0, cur_max = 0;
    for (int i = 0; i < arr.size(); ++i) {
       cur_max = max(cur_max, arr[i]);
       if (cur_max == i) {
        ++chunks; }
}
    return chunks;
}


vector<int> dailyTemperatures(vector<int>& T) {
    //739 medium
    int len=T.size();
    vector<int> ans(len);
    stack<int> s;
    for(int i=0;i<len;++i)
    {
        while(!s.empty())
        {
            int pre_max=s.top();
            if(T[pre_max]>=T[i])
                break;
            s.pop();
            ans[pre_max]=i-pre_max;
        }
        s.push(i);
    }
    return ans;
}


    vector<vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
        //823 easy
        int n = A.size();
        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left < right) {
                if (A[i][left] == A[i][right]) {
                    A[i][left] ^= 1;
                    A[i][right] ^= 1;
                }
                left++;
                right--;
            }
            if (left == right) {
                A[i][left] ^= 1;
            }
        }
        return A;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();++i)
        {
            if(!dq.empty() && dq.front() == i-k)
            {
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }


    vector<int> sortArray(vector<int>& nums) {
            //912 medium
            sort(nums.begin(),nums.end());
        return nums;
    }


    vector<int> twoSum_1(vector<int>& nums, int target) {
        //1 easy
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();++i)
        {
            int num=nums[i];
            auto pos=m.find(target-num);
            if(pos==m.end())
            {
                m[num]=i;
            }
            else
            {
                ans.push_back(pos->second);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }

    bool isIsomorphic(string s, string t) {
        //205 easy
        vector<int> s_first(256,0), t_first(256,0);
        for(int i=0;i<s.size();++i)
        {
            if(s_first[s[i]]!=t_first[t[i]])
                return false;
            s_first[s[i]]=t_first[t[i]]=i+1;
        }
        return true;
    }

    int countBinarySubstrings(string s) {
        //696 easy
        int pre=0,cur=1,count=0;
        for(int i=1;i< s.size();++i)
        {
            if(s[i]==s[i-1])
            {
                ++cur;
            }
            else
            {
                pre=cur;
                cur=1;
            }
            if(pre>=cur)
            {
                ++count;
            }
        }
        return count;
    }


    int longestPalindrome(string s) {
        //409 easy
        vector<int> v(52,0);
        for(int i=0;i<s.size();++i)
        {
            if(s[i]>='a' && s[i]<='z')
                ++v[s[i]-'a'];
            else
                ++v[s[i]-'A'+26];
        }
        int res=0;
        for(int i=0;i<52;++i)
        {
            if((res&1) && (v[i]&1))
                res+=v[i]-1;
            else
                res+=v[i];
        }
        return res;
    }

    vector<string> ambiguousCoordinates(string S) {
        //816 medium
        vector<string> ans;
        S=S.substr(1,S.size()-2);
        for(int i=1;i<S.size();++i)
        {
            string temp1=S.substr(0,i);
            string temp2=S.substr(i);
            vector<string> temp3=par(temp);
            vector<string> temp4=par(temp);
            for(auto it: temp3)
                for(auto it1:temp4)
                {
                    res.push('('+it+','+it1+')');
                }
        }
        return res;
    }
    
    vector<string> par(string now)
    {
        vector<string> temp;
        if(now[0]=='0')
        {
            long long now1=stoll(now);
            if(now1!=0 && now[now.size()-1]!='0')
                temp.push_back("0."+now.substr(1));
            else
            {
                if(now.size()==1)
                    temp.push_back("0)");
            }
        }
        else
        {
            if(now[now.size()-1]=='0')
                temp.push_back(now);
            else
            {
                temp.push_back(now);
                for(int i=0;i<now.size();++1)
                {
                    temp.push_back(now.substr(0,i+1)+'.'+now.substr(i+1));
                }
            }
            return temp;
        }
    }

    const string letterMap[10]={
        "",
        ""
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    vector<string> res_17;
    string s_17;
    vector<string> letterCombinations(string digits) {
        //17 medium
        s_17.clear();
        res_17.clear();
        if(digits.size()==0)
            return res_17;
        traversal_17(digits,0);
        return res_17;
    }

    void traversal_17(const string &digits,int index)
    {
        if(index=digits.size())
        {
            res_17.push_back(s_17);
            return ;
        }
        int digit=digits[index]-'0';
        string letter=letterMap[digit];
        for(int i=0;i<letter.size();++i)
        {
            s_17.push_back(letter[i]);
            traversal_17(digits,i+1);
            s_17.pop_back();
        }
    }


    vector<vector<string> > partition(string s) {
        //131 medium
        vector<vector<string> > res;
        backtrack_131(s,res,{});
        return res;
    }

    void backtrack_131(string s, vector<vector<string> > &res, vector<string> path)
    {
        if(s.size()==0)
        {
            res.push_back(path);
            return ;
        }
        for(int i=1;i<s.size();++i)
        {
            string pre=s.substr(0,i);
            if(isPali_131(pre))
            {
                path.push_back(pre);
                backtrack_131(s.substr(i),res,path);
                path.pop_back();
            }
        }
    }
    
    bool isPali_131(string s)
    {
        
        int begin=0;
        int end=s.size()-1;
        if(end==-1)
            return true;
        while(begin<=end)
        {
            if(s[begin]!=s[end])
                return false;
            begin++;
            end--;
        }
        return true;
    }

};


