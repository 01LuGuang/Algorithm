//小 A 有一段代码，这段代码是一个长为 n 的仅包含大写字母的字符串 S 。
//小 A 会不断对代码执行操作，每次操作中他会将字代码的最后一个字符移动到第一个字符，然后将得到的新字符串并拼接到原字符串的结尾，
//从而得到新的代码。也就是说每次操作后代码的长度都会增加一倍。
//现在小 A 想知道，在这个无限长的字符串中，第 k 个位置是什么字符。


#include <iostream>
#include <string>

using namespace std;

char findChar(string S, long long k, long long length) {
    if(k <= S.size()) return S[k - 1];

    long long pre_len = length / 2;

    if(k > pre_len) {
        k -= pre_len;
        if(k == 1) return findChar(S, pre_len, pre_len);
        else return findChar(S, k - 1, pre_len);
    }

    return findChar(S, k, pre_len);
}


int main() {
    string S;
    long long k;

    cin >> S >> k;
    long long length = S.size();

    while(length < k) {
        length *= 2;
    }
    cout << findChar(S, k, length) << endl;
    return 0;
}