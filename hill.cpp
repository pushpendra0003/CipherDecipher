#include <bits/stdc++.h>

using namespace std;

int modulo(int a, int b){
    int k;
    if(a%b > 0){
        k = a%b;
        return k;
    }
    else{
        k = a%b + b;
        return k;
    }
    return k;
}
void cipherEncryption(){
    string msg;
    cout << "Enter Message: ";
    getline(cin, msg);
    // cin.ignore();

    for(int i=0; i<msg.length(); i++){
        msg[i] = toupper(msg[i]);
    }

    msg = regex_replace(msg, regex("\\s+"), "");

    // cout << msg;
    int lenchk = 0;
    if(msg.length()%2 != 0){
        msg += "0";
        lenchk = 1;
    }

    int msg2D[2][msg.length()/2];
    int itr1 = 0;
    int itr2 = 0;

    for(int i=0; i<msg.length(); i++){
        if(i%2 == 0){
            msg2D[0][itr1] = msg[i] - 65;
            itr1++;
        }
        else{
            msg2D[1][itr2] = msg[i] - 65;
            itr2++; 
        }
    }
    // for(int i=0; i<2; i++){
    //     for(int j=0; j<msg.length()/2; j++){
    //         cout << (char)(msg2D[i][j]+65) << " ";
    //     }
    //     cout << endl;
    // }

    string key;
    cout << "Enter 4 letter Key string: ";
    getline(cin, key);
    // cin.ignore();

    for(int i=0; i<key.length(); i++){
        key[i] = toupper(key[i]);
    }

    key = regex_replace(key, regex("\\s+"), "");

    int key2D[2][2];

    int itr3 = 0;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            key2D[i][j] = key[itr3] - 65;
            itr3++; 
        }
    }

    int deter = key2D[0][0]*key2D[1][1] - key2D[0][1]*key2D[1][0];
    deter = modulo(deter,26);

    int mulinv = -1;

    for(int i=0; i<26; i++){
        int tempinv = deter*i;
        if(modulo(tempinv,26) == 1){
            mulinv = i;
            break;
        }
        else{
            continue;
        }
    }

    if(mulinv == -1){
        cout << "Invalid Key" << endl;
        exit(EXIT_FAILURE);
    }

    string encryptText = "";
    int itrcount = msg.length()/2;
    if(lenchk == 0){
        for(int i=0; i<itrcount; i++){
            int temp1 = msg2D[0][i]*key2D[0][0] + msg2D[1][i]*key2D[0][1];
            encryptText += (char)(temp1%26) + 65;
            int temp2 = msg2D[0][i]*key2D[1][0] + msg2D[1][i]*key2D[1][1];
            encryptText += (char)(temp2%26) + 65;
        }
    }
    else{
        for(int i=0; i<itrcount-1; i++){
            int temp1 = msg2D[0][i]*key2D[0][0] + msg2D[1][i]*key2D[0][1];
            encryptText += (char)(temp1%26) + 65;
            int temp2 = msg2D[0][i]*key2D[1][0] + msg2D[1][i]*key2D[1][1];
            encryptText += (char)(temp2%26) + 65;
        }
    }

    cout << endl << "Encrypted Text: " << encryptText << endl;
    return;
}

void cipherDecryption(){
    string msg;
    cout << "Enter Message: ";
    getline(cin, msg);
    // cin.ignore();

    for(int i=0; i<msg.length(); i++){
        msg[i] = toupper(msg[i]);
    }

    msg = regex_replace(msg, regex("\\s+"), "");

    // cout << msg;
    int lenchk = 0;
    if(msg.length()%2 != 0){
        msg += "0";
        lenchk = 1;
    }

    int msg2D[2][msg.length()/2];
    int itr1 = 0;
    int itr2 = 0;

    for(int i=0; i<msg.length(); i++){
        if(i%2 == 0){
            msg2D[0][itr1] = msg[i] - 65;
            itr1++;
        }
        else{
            msg2D[1][itr2] = msg[i] - 65;
            itr2++; 
        }
    }
    // for(int i=0; i<2; i++){
    //     for(int j=0; j<msg.length()/2; j++){
    //         cout << (char)(msg2D[i][j]+65) << " ";
    //     }
    //     cout << endl;
    // }

    string key;
    cout << "Enter 4 letter Key string: ";
    getline(cin, key);
    // cin.ignore();

    for(int i=0; i<key.length(); i++){
        key[i] = toupper(key[i]);
    }

    key = regex_replace(key, regex("\\s+"), "");

    int key2D[2][2];

    int itr3 = 0;
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            key2D[i][j] = key[itr3] - 65;
            itr3++; 
        }
    }

    int deter = key2D[0][0]*key2D[1][1] - key2D[0][1]*key2D[1][0];
    deter = modulo(deter,26);

    int mulinv = -1;

    for(int i=0; i<26; i++){
        int tempinv = deter*i;
        if(modulo(tempinv,26) == 1){
            mulinv = i;
            break;
        }
        else{
            continue;
        }
    }

    if(mulinv == -1){
        cout << "Invalid Key" << endl;
        exit(EXIT_FAILURE);
    }

    swap(key2D[0][0], key2D[1][1]);

    // for(int i=0; i<2; i++){
    //     for(int j=0; j<2; j++){
    //         cout << (char)(key2D[i][j]+65) << " ";
    //     }
    //     cout << endl;
    // }

    key2D[0][1] *= -1;
    key2D[1][0] *= -1;

    key2D[0][1] = modulo(key2D[0][1], 26);
    key2D[1][0] = modulo(key2D[1][0], 26);

    // for(int i=0; i<2; i++){
    //     for(int j=0; j<2; j++){
    //         cout << (char)(key2D[i][j]+65) << " ";
    //     }
    //     cout << endl;
    // }

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            key2D[i][j] *= mulinv;
        }
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            key2D[i][j] = modulo(key2D[i][j], 26);
        }
    }

    string decryptText = "";
    int itrcount = msg.length()/2;
    if(lenchk == 0){
        for(int i=0; i<itrcount; i++){
            int temp1 = msg2D[0][i]*key2D[0][0] + msg2D[1][i]*key2D[0][1];
            decryptText += (char)(temp1%26) + 65;
            int temp2 = msg2D[0][i]*key2D[1][0] + msg2D[1][i]*key2D[1][1];
            decryptText += (char)(temp2%26) + 65;
        }
    }
    else{
        for(int i=0; i<itrcount-1; i++){
            int temp1 = msg2D[0][i]*key2D[0][0] + msg2D[1][i]*key2D[0][1];
            decryptText += (char)(temp1%26) + 65;
            int temp2 = msg2D[0][i]*key2D[1][0] + msg2D[1][i]*key2D[1][1];
            decryptText += (char)(temp2%26) + 65;
        }
    }

    cout << endl << "Decrypted Text: " << decryptText << endl;
    return;

}

int main(){
    cout << "Message and Key can only be alphabatic" << endl;
    int choice;
    cout << "1. Encryption\n2. Decryption\nChosse(1,2): ";
    cin >> choice;
    cin.ignore();

    if(choice == 1){
        cout << "Encryption" << endl;
        cipherEncryption();
    }
     else if(choice == 2){
        cout << "Decryption" << endl;
        cipherDecryption();
    }
    else{
        cout << "Wrong Choice" << endl;
    }
    return 0;
}