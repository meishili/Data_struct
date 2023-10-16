#include "double_queue.hpp"
#include <cstring>

bool is_palindrom(const char str[]){
    Double_queue<char> queue(512);
    int size = std::strlen(str);
    for(int i = 0; i != size; ++i){
        if(!queue.isfull()){
            queue.tail_push(str[i]);
        }
    }
    char c1, c2;
    while(!queue.isempty()){
        c1 = queue.head_dequeue();
        if(!queue.isempty()){
            c2 = queue.tail_dequeue();
        }else{
            break;
        }
        if(c1 != c2){
            return false;
        }else{
            continue;
        }
    }
    return true;
}

int main(int argc, char *argv[]){
    std::cout<<"Please enter a string:";
    char str[512];
    std::cin.getline(str, 512);
    if(is_palindrom(str)){
        std::cout<<str<<" is a palindrom."<<std::endl;
    }else{
        std::cout<<str<<" is not a palindrom."<<std::endl;
    }
    return 0;
}