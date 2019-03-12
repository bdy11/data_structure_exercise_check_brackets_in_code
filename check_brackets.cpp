#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    
    std::stack <Bracket> opening_brackets_stack;
    bool unmatch_found=false;
     for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket brkt(next,position);
            opening_brackets_stack.push(brkt);  //push the bracekt in the stack
        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.empty()){
                std::cout<<position+1<<std::endl;   //no match for the inputted right bracket
                unmatch_found=true;
                break;
            } 
            else{
                Bracket Top=opening_brackets_stack.top();  //pop the bracket from the stack

                if (Top.Matchc(next)){                  // matched bracket, pop out
                    opening_brackets_stack.pop();
                }
                else if(!Top.Matchc(next)){             //no match for the inputted right bracket
                    std::cout<<position+1<<std::endl;
                    unmatch_found=true;
                    break;
                }
            }
        }

    }
    if(!opening_brackets_stack.empty() && unmatch_found==false){
        if(opening_brackets_stack.size()==1){
            Bracket Top=opening_brackets_stack.top();
            std::cout<<Top.position+1<<std::endl;
        }
        else{
            while(opening_brackets_stack.size()>1){
                opening_brackets_stack.pop();
            }
            Bracket Top=opening_brackets_stack.top();
            std::cout<<Top.position+1<<std::endl;
        }
    }

    else if(opening_brackets_stack.empty() && unmatch_found==false){
        std::cout<<"Success"<<std::endl;
    }

    return 0;
}
