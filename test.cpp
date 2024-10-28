// Symmetric key Stream Ciphers
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

using namespace std;

string generate_Ks(int k){
    string s = "";
    srand((unsigned int)time(NULL));
    for (int i = 0; i < k; i++) s += rand()%2 + '0';
    return s;
}

string en_decrypt(string txt, string ks){
    string ans_txt = "";
    for (int i = 0; i < txt.size(); i++){
        ans_txt += (((int)txt[i]-48)^((int)ks[i]-48))+'0';
    }
    return ans_txt;
}

int main(){
    int a = 1;
    char b = '0';
    string message;
    string keyS;
    string decryption_txt;
    string encryption_txt;

    cout << "input binary code : ";
    cin >> message;

    keyS = generate_Ks(message.size());
    encryption_txt = en_decrypt(message, keyS); // 암호화
    decryption_txt = en_decrypt(encryption_txt, keyS); // 복호화

    cout << "------------" << endl;
    printf("plain text: %s\nsymmetric key: %s\ncipher text: %s\ndecryption text: %s\
    \n",message.c_str(), keyS.c_str(), encryption_txt.c_str(), decryption_txt.c_str()); 
}   