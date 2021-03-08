#include<iostream>

using namespace std;


class test
{
    public:
        bool isPali_131(string s)
    {
        
        int begin=0;
        int end=s.size()-1;
        if(end==-1)
            return true;
        while(begin<end)
        {
            if(s[begin]!=s[end])
                return false;
            begin++;
            end--;
        }
        return true;
    }
};

int main()
{
    test t;
    cout<<t.isPali_131("asa")<<endl;
}


