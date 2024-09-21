#include <iostream>
using namespace std;
int count[27]; //1~26

int main(){

    //a:97 ~ z:122
    char word[110];

    cin>>word;
    for(char a:word)
    {
        if (a == NULL){
            break;
        }
        {
            /* code */
        }
        
        for(int i=1; i<=26;i++)
        {
            if(a == i+96)
            {
                ::count[i]++;
            }
            
        }
    }

    for(int i=1;i<=26;i++)
    {
        cout<<::count[i]<<" ";
    }


}