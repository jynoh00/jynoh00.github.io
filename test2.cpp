#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main(){
    //map<int, string> m1;
    std::map<int, std::string> m2;
    std::map<std::string, int> m3{
        {"Kim", 23},
        {"Lee", 24},
        {"Noh", 25}
    };

    std::cout << m3["Lee"] << std::endl; // 24
    std::cout << m3["Noh"] << std::endl; // 25
    m3["Noh"] = 20;
    std::cout << m3["Noh"] << std::endl; // 20

    m3["Park"] = 99; // insert, 없는 key 추가
    std::cout << m3["Park"] << std::endl;

    m3.insert(std::make_pair("Choi", 29)); // insert, using make_pair

    m3.insert({"hel",52});

    std::pair<std::string, int> p1{"Ho", 66};
    m3.insert(p1);

    if (m3.find("Ho") != m3.end()){
        std::cout << "find" << std::endl;
    }
    else{
        std::cout << "not find"<< std::endl;
    }

    std::cout << "-------" << std::endl;
    for (std::map<std::string, int>::iterator iter = m3.begin(); iter != m3.end(); iter++){
        std::cout << iter->first << " " << iter->second << std::endl;
    }
    std::cout << "-------" << std::endl;

    std::cout << "-------" << std::endl;
    for (auto iter : m3){ // auto 정리
        std::cout << iter.first << " " << iter.second << std::endl;
    }
    std::cout << "-------" << std::endl;

    // m3.erase(m3.begin()+2); // why err

    m3.erase("Noh");

    // clear all
    m3.erase(m3.begin(), m3.end());
    m3.clear();

    unordered_map<int,int> m4;
    m4.insert({2, 3});
    cout << m4[2] << endl;
}

/*

Associative container - map

key -> data search can
(python - ditionary와 유사)

balanced binary tree, hashset
연산 빠름

map => #include <map> // 요소 정렬, 중복 허용 x
unordered_map => #include <unordered_map> // 요소 정렬 x
multimap => #include <map> // 중복된 요소 허용
unordered_multimap => #include <unordered_map> // 요소 정렬 x, 중복된 요소 허용

key - value 쌍으로 저장
key 값에 따라 정렬
key 중복 불가
key로 직접 접근 가능
반복자가 유효하지 않을 수 있다.


  key   value
--------------
| Kim  | 20  |
--------------



*/