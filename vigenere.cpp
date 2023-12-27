#include <iostream>

using namespace std;

string message;
string mappedKey;

void messageAndKey(){
    string msg;
    cout << "Enter Message: ";
    getline(cin, msg);
    cin.ignore();

    for(int i=0; i<msg.length(); i++){
        msg[i] = toupper(msg[i]);
    }

    string key;
    cout << "Enter Key: ";
    getline(cin, key);
    cin.ignore();
    
    for(int i=0; i<key.length(); i++){
        key[i] = toupper(key[i]);
    }

    string KeyMap = "";

    for(int i=0, j=0; i<msg.length(); i++){
        if(msg[i] == 32){
            KeyMap += 32;
        }
        else{
            if(j < key.length()){
                KeyMap += key[j];
                j++;
            }
            else{
                j = 0;
                KeyMap += key[j];
                j++;
            }
        }
    }
    message = msg;
    mappedKey = KeyMap;
}

int tableArr[26][26];
void createVignereTable(){
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            int temp = i+j + 65;
            if((i+65)+j > 90){
                temp = (i+65)+j - 26;
            }
            tableArr[i][j] = temp;
        }
    }
    // for(int i=0; i<26; i++){
    //     for(int j=0; j<26; j++){
    //         cout << (char)tableArr[i][j];
    //     }
    //     cout << endl;
    // }
} 

void cipherEncryption(string message, string mappedKey){
    createVignereTable();
    string encryptedText = "";

    for(int i=0; i<message.length(); i++){
        if(message[i] == 32 && mappedKey[i] == 32){
            encryptedText += " ";
            }
        else{
                int x = (int)message[i] - 65;
                int y = (int)mappedKey[i] - 65;
                encryptedText += (char)tableArr[x][y];
            }
        }
        cout << "Encrypted Text: " << encryptedText << endl;
    }

int itrcount(int key, int msg){
    int counter = 0;
    string result = "";
    for(int i=0; i<26; i++){
        if(key + i > 90){
            result += (char)(key + (i-26));
        }
        else{
            result += (char)(key + i);
        }
    }

    for(int i=0; i<result.length(); i++){
        if(result[i] == msg){
            break;
        }
        else{
            counter++;
        }
    }
    return counter;
}

void cipherDecryption(string message, string mappedKey){
    string decryptedText = "";
    for(int i=0; i<message.length(); i++){
        if(message[i] == 32 && mappedKey[i] == 32){
            decryptedText += " ";
        }
        else{
            int temp = itrcount((int)mappedKey[i], (int)message[i]);
            decryptedText += (char)(65+temp);
        }
    }

    cout << "Decrypted Text: " << decryptedText << endl;
}

int main(){
    cout << "Message and Key can only be alphabatic" << endl;
    int choice;
    cout << "1. Encryption\n2. Decryption\nChosse(1,2): ";
    cin >> choice;
    cin.ignore();

    if(choice == 1){
        cout << "Encryption" << endl;
        messageAndKey();
        cipherEncryption(message, mappedKey);
    }
    else if(choice == 2){
        cout << "Decryption" << endl;
        messageAndKey();
        cipherDecryption(message, mappedKey);
    }
    else{
        cout << "Wrong Choice" << endl;
    }
    return 0;
}
