#include <iostream>
using namespace std;

int numberCard[11]; //0~9
int set=0;
int main(){

    char number[10];

    cin>>number;

    for(char digit:number)
    {
        if(digit == NULL)
        {
            break;
        }
        if(digit == 54 || digit == 57) //6() or 9
            {
                if(numberCard[6]>0)
                {
                    numberCard[6]--;
                }
                else if(numberCard[9]>0)
                {
                    numberCard[9]--;
                }
                else
                {
                    set++;
                    for(int i=0;i<10;i++)
                    {
                        numberCard[i]++;
                    }
                    numberCard[6]--;
                }
            }
        else{
            for(int i = 48; i<58 ;i++) //0~9
                {
                        if(digit == i)
                        {
                            if(numberCard[i-48] >0)
                            {
                                numberCard[i-48]--;
                            }
                            else{
                                set++;
                                for(int j=0;j<10;j++)
                                {
                                    numberCard[j]++;
                                }
                                numberCard[i-48]--;
                        
                            }
                        }
                }
        
        
        }
    // for(int k=0;k<10;k++)
    //     {
    //         cout<<endl<<"현황:  "<<endl;
    //         cout<<k<<"번째 카드 남은 개수: "<<numberCard[k];
    //     }
        
        
}


    cout<<set;
}