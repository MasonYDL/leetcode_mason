#include<iostream>

using namespace std;


class test
{
    public:
    bool checkPowersOfThree(int n) {
        //1780 medium
        if(n<=0)
            return false;
        if(n==1)
            return true;
        if(n%3==0)
            checkPowersOfThree(n/3);
        else if(n%3==1)
            checkPowersOfThree((n-1)/3);
        return false;

    }
};

int main()
{
    test t;
    cout<<t.checkPowersOfThree(12)<<endl;
}


