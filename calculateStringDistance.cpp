/*
 * 计算编辑距离
 */

#include <iostream>
#include <string>
using namespace std;
int min(int a, int b, int c) {
    if(a < b)
        return (a>c)? c : a;
    else
        return (b>c) ? c : b;
}
int calculateStringDistance(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    int** c = new int*[len1];
    for(int i = 0; i < len1+1; ++i)
        c[i] = new int[len2+1];
    for(int i = 0; i < len1; i++)
        c[i][len2] = len1 - i;
    for(int j = 0; j < len2; j++)
        c[len1][j] = len2 - j;
    c[len1][len2] = 0;
    for(int i = len1-1; i >=0;i--)
        for(int j = len2-1; j >= 0; j--){
            if(s2[j]==s1[i])
                c[i][j] = c[i+1][j+1];
            else
                c[i][j] = min(c[i][j+1], c[i+1][j], c[i+1][j+1])+1;
        }
    int dis = c[0][0];
    for(int i = 0; i < len1+1; i++)
        delete [] c[i];
    delete [] c;
    return dis;
}
int main()
{
    string s1 = "abcdbsdfed";
    string s2 = "abcef";
    cout << calculateStringDistance(s1, s2) << endl;
    return 0;
}
