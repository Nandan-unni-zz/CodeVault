#include<iostream>
#include<cstdlib>
#include<string.h>
#include<ctime>
using namespace std;
int main()
{
    
    START:
    system("cls");
    int a,l,i,h=5,f=0,g=0;
    char x,y,z,t[2],temp[20],user[20],ans[20],words[10][20] = { "monument", "trivandrum", "orange", "yellow" ,"citizen", "hydrophobia" ,"engineer", "computer", "economics", "argentina"};
    srand((unsigned) time(0));
    a = (rand() % 10);
    strcpy(ans,words[a]);
    l=strlen(ans);
    cout<<"\n\t";
    for(i=1;i<=l;i++)
    {
        if((i%3)==0)
            user[i-1]=ans[i-1];
        else
            user[i-1]='_';
    }
    user[l]='\0';
    while(h>0)
    {
        WORD:
        system("cls");
        cout<<"\n\t";
        for(i=0;i<l;i++)
            cout<<user[i]<<" ";
        cout<<"\n\n\tLife : "<<h;
        cout<<"\n\n\tDid you get the word ? (y/n) : ";
        cin>>x;
        if((x=='y'||x=='Y')&&(h>0))
        {
            cout<<"\tYour answer : ";
            gets(t);
            gets(temp);
            if(strcmpi(temp,ans)==0)
            {
                cout<<"\n\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*";
                cout<<"\n\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*";
                cout<<"\n\t*.*.*.*  V I C T O R Y  *.*.*.*";
                cout<<"\n\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*";
                cout<<"\n\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*";
                cout<<"\n\n\t Play again ? (y/n) : ";
                cin>>x;
                if(x=='y'||x=='Y')
                    goto START;
                else
                    return 0;   
            }
            else
            {
                cout<<"\n\t WRONG..!";
                h--;
                if(h>0)
                    goto WORD;
                else
                {
                    cout<<"\n\t Life = "<<h;
                    cout<<"\n\n\t -------  FAILED  -------";
                    cout<<"\n\n\t Play again ? (y/n) : ";
                    cin>>x;
                    if(x=='y'||x=='Y')
                        goto START;
                    else
                        return 0;
                }
                
            }
        }
        else if(h==0)
        {
            cout<<"\n\t Life = "<<h;
            cout<<"\n\n\t -------  FAILED  -------";
            cout<<"\n\n\t Play again ? (y/n) : ";
            cin>>x;
            if(x=='y'||x=='Y')
                goto START;
            else
                return 0;
        }
        else
        {
            LETTER:
            cout<<"\n\n\tGuess a letter : ";
            cin>>y;
            f=0;
            for(i=0;i<l;i++)
            {
                if(y==ans[i])
                {
                    user[i]=ans[i];
                    f++;
                }
            }
            
            if(f>0)
            {
                g=0;
                for(i=0;i<l;i++)
                {
                    if(user[i]!=ans[i])
                        g++;
                }
                if(g==0)
                {
                    cout<<"\n\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*";
                    cout<<"\n\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*";
                    cout<<"\n\t*.*.*.*  V I C T O R Y  *.*.*.*";
                    cout<<"\n\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*";
                    cout<<"\n\t*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*";
                    cout<<"\n\n\t Play again ? (y/n) : ";
                    cin>>x;
                    if(x=='y'||x=='Y')
                        goto START;
                    else
                        return 0; 
                }
                goto WORD;
            }
            else
            {
                h--;
                cout<<"\tWrong Guess..!"<<"\n\tLife : "<<h;
                if(h==0)
                {
                    cout<<"\n\t -------  FAILED  -------";
                    cout<<"\n\n\t Play again ? (y/n) : ";
                    cin>>x;
                    if(x=='y'||x=='Y')
                        goto START;
                    else
                        return 0;
                }
                else
                    goto LETTER;
            }  
        }
    }   
return 0;
}