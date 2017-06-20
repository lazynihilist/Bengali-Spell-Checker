#include <bits/stdc++.h>
using namespace std;
string hoshonto, ko, sho;
string convertToDoubleMetaphone (vector <string> word) {
    string ret;

    return ret;
}
string doubleMetaphone (string word) {
    vector <string> chars;
    vector <string> done;
    string tmp;
    for (int i=0; i<word.length(); i+=3) {
        for (int j=i; j<i+3; j++) {
            tmp.push_back(word[j]);
        }
        chars.push_back(tmp);
        tmp.clear();
    }
    for (int i=0; i<chars.size(); i++) {
        // kkhiyo
        if (chars[i] == ko && i < chars.size() - 2 && chars[i+1] == hoshonto && chars[i+2] == sho) {
             done.push_back(ko+hoshonto+sho);
             i++;
             i++;
        }
        // nio
        
        // bo fola
        else if (chars[i] == ba && i < chars.size() - 2 && chars[i+1] == hoshonto && chars[i+2] == ba) {
            done.push_back(ba+hoshonto+ba);
             i++;
             i++;
        }
        else if (chars[i] == ma && i < chars.size() - 2 && chars[i+1] == hoshonto && chars[i+2] == ba) {
            done.push_back(ma+hoshonto+ba);
             i++;
             i++;
        }
        else if (chars[i] == ga && i < chars.size() - 2 && chars[i+1] == hoshonto && chars[i+2] == ba) {
            done.push_back(ga+hoshonto+ba);
             i++;
             i++;
        }
        else if (chars[i] == U && i < chars.size() - 3 && chars[i+1] == D && chars[i+2] == hoshonto && chars[i+3] == ba) {
            done.push_back(U+D+hoshonto+ba);
             i++;
             i++;
             i++;
        }
        else if (chars[i] == hoshonto && i < chars.size() - 1 && chars[i+1] == ba && i > 1 && chars[i-2] != hoshonto) {
            done.push_back(ba+ba);
            i++;
        }
        // mo fola        
        
        else if (chars[i] == hoshonto && i < chars.size() - 1 && chars[i+1] == ma && i > 1 && chars[i-2] != hoshonto) {
            done.push_back(ba+ba);
            i++;
        }
        // ho
        
        // bishorgo
        
        else {
            done.push_back(chars[i]);
        }
    }
    return convertToDoubleMetaphone(done);
}
char str[101];
int main () {
    FILE * id;
    id = fopen("hoshonto.txt", "r");
    fscanf(id, "%s", str);
    for (int i=0; i<3; i++) hoshonto.push_back(str[i]);
    fscanf(id, "%s", str);
    for (int i=0; i<3; i++) ko.push_back(str[i]);
    fscanf(id, "%s", str);
    for (int i=0; i<3; i++) sho.push_back(str[i]);
    fclose(id);
    string word;
    cin >> word;
    cout << "Double Metaphone of " << word << " is " << doubleMetaphone(word) <<endl;
    return 0;
}
