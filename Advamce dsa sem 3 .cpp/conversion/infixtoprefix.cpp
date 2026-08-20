#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Stack{
    vector<int> item;
    int Top;

    public:

    Stack(int s){
        item.resize(s);
        Top=-1;
    }

    void Push(int x){
        if(Top==item.size()-1){
            cout<<"Stack Overflows"<<endl;
            return;
        }
        else{
        Top++;
        item[Top]=x;
        }
    }

    int Pop(){
        if(Top==-1){
            cout<<"Stack Underflows"<<endl;
            return -1;
        }
        else{
        int x;
        x = item[Top];
        Top--;
        return x;
        }
    }


    int StackTop(){
        int x;
        x = item[Top];
        return x;
    }

    bool IsEmpty(){
        if(Top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

bool prcd(char a ,char b){

    if(a == '(' || b == '('){
        return false;
    }
    if (b == ')') {
        return true;
    }

    if(a=='^'||a=='*'||a=='/'||a=='%'){
        if(b=='^'){
            return false;
        }
        else{
            return true;
        }
    }
    if(a=='+'||a=='-'){
        if(b=='+'||b=='-'){
            return true;
        }
        else{
            return false;
        }
    }

}

void  InfixToPrefix(string Infix){

    Stack s(20);
    int i = Infix.size()-1;
    string Prefix;
    while(i>=0){
        char symbol = Infix[i];
        i--;

        if(symbol>='a' && symbol<='z' || symbol>='A' && symbol<='Z' || symbol>='0' && symbol<='9'){
            Prefix = Prefix + symbol;
        }
        else{
            while(!s.IsEmpty() && !prcd(symbol,s.StackTop()))
            {
                char x = s.Pop();
                Prefix = Prefix + x;
            }
            if(symbol==')'){
                s.Pop();
            }
            else{
                s.Push(symbol);
            } 
        }
    }
while(!s.IsEmpty()){
        char x = s.Pop();
        Prefix = Prefix + x;
    }
    reverse(Prefix.begin(),Prefix.end());
    cout<<Prefix;
}

int main(){
        string Infix;
        cin>>Infix;

        InfixToPrefix(Infix);
        
return 0;

}