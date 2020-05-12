#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class film
{
private:
    string str;
    char a[4];

public:
    void Instructions()
    {
        cout<<"INSTRUCTIONS:-"<<endl<<endl;
        cout<<"Computer will choose a word and you have to guess it."<<endl;
        cout<<"Player has to enter 4 letter word which will be traversed by the computer."<<endl;
        cout<<"*Only 4 letter words are there and there is no repetition of letter.*"<<endl;
        cout<<"If entered word has 1 letter matching to the chosen word on correct position then 1 BULL is printed."<<endl;
        cout<<"If entered word has 1 letter matching to the chosen word on incorrect position then 1 COW is printed."<<endl;
        cout<<"For hint enter ( . ) "<<endl;
        cout<<"Word's letters will not be printed until hint is called or either the player wins or looses."<<endl;
        cout<<"10 chances will be given and it will be deducted after every action taken by the player."<<endl;
        cout<<"There are only 2 hints available for a player i.e. the player can see only 1st and 2nd letter of the word."<<endl;
    }
    film(){

        Instructions();
        read();
    }
    void read()
    {string line[1570];
        int i=0;
        ifstream fp("c&b.txt");

        while(getline(fp,line[i]))
        {

            i++;
        }

        selection(line);
    }
    void selection(string line[])
    {
        srand(time(0));
        int i = (rand() % 1000) + 1;
        str = line[i];
        for(int j=0;j<4;j++)
        {
        a[j]='-';
        }
    }
    void print()
    {
    cout<<"Word is: ";
    for(int i=0;i<4;i++)
        {
        cout<<a[i];
        }
        cout<<endl<<endl<<"____________________________________________"<<endl;
    }
string getword()
{string word;
    cout<<endl<<"Enter a 4 letter Word:-"<<endl;
    cin>>word;
    return word;
}

void chance(int a)
{
    cout<<endl<<"____________________________________________"<<endl;
    cout<<endl<<"Chances Remaining: "<<10-a<<endl;
}

    void hint();

    void insertion(string a)
    {
        for(int j=0;j<4;j++)
        {

            if(str[j]==a[j])
            {
                cout<<"1 BULL"<<endl;
            }
            if(str[j]!=a[j])
            {
                for(int i=0;i<4;i++)
                {
                    if(str[j]==a[i])
                    cout<<"1 COW"<<endl;
                }
            }
        }
    }

    /*bool isCheck(char b)
    {int n=str.length();
        for(int j=0;j<n;j++)
        {

        if(str[j]==b)
            {
                a[j]=b;
                return 1;
            }
        }
        return 0;
    }*/

    bool isEqual(string word)
    {
        for(int i=0;i<4;i++)
        {
            if(word[i]!=str[i])
            {
                return 0;
            }
        }
        return 1;
    }

     bool isEquals()
    {
        for(int i=0;i<4;i++)
        {
            if(a[i]!=str[i])
            {
                return 0;
            }
        }
        return 1;
    }

void gameplay()
{int k=0,l=0;
string word;
    while(k!=10)
    {

        chance(k);
        word = getword();
        if(word==".")
        {
            if(l!=2)
            {
                hint();
                if(isEquals())
                {   cout<<"Word is: "<<str<<endl;
                    cout<<"Congratulations!!! You won the game"<<endl;
                    exit(0);
                }
                l++;
                k++;
            }
            else
                {
                    cout<<"No more hints available"<<endl;
                    k++;
                }

        }
        else
        {
        insertion(word);
        if(isEqual(word))
            {   cout<<"Word is: "<<str<<endl;
                cout<<"Congratulations!!! You won the game"<<endl;
                exit(0);
            }
        k++;
        }

    }
    cout<<endl<<"____________________________________________"<<endl;
    cout<<"You have exhausted your 10 moves"<<endl;
    cout<<"Game over"<<endl;
    cout<<"Word is "<<str<<endl;

}
film(string a)
{
    film start;
    start.gameplay();
}


};

void film::hint()
    {
    for(int j=0;j<4;j++)
        {
        if(a[j]=='-')
            {
                a[j]=str[j];
                print();
                return;
            }
        }
    }

int main()
{
    film w("begin");

}
