# include <iostream>
# include <cstring>

using namespace std;

void rev_str(char s[]);
void rev_str(char s[], char t[]);

int main(){
    char s1[100], s2[100], temp[100];

    strcpy(s1, "Hello world");
    strcpy(s2, '\0');

    rev_str(s1);
    rev_str(s1, s2);

    cout << "\nReverse-1: " << s1;
    cout << "\nReverse-2: " << s2 << endl;

    return 0;
}

void rev_str(char s[]){
    char temp;
    int len = strlen(s);

    for(int i = 0 ; i < len / 2 ; i++){
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

void rev_str(char s[], char t[]){
    int len = strlen(s), j = 0;

    for (int i = len - 1; i >= 0 ; i--){
        t[j] = s[i];
        j++;
    }
}