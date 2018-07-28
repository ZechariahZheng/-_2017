/*
继MIUI8推出手机分身功能之后，MIUI9计划推出一个电话号码分身的功能：首先将电话号码中的每个数字加上8取个位，
然后使用对应的大写字母代替 （"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"），
 然后随机打乱这些字母，所生成的字符串即为电话号码对应的分身。
 
输入描述:
第一行是一个整数T（1 ≤ T ≤ 100)表示测试样例数；接下来T行，每行给定一个分身后的电话号码的分身（长度在3到10000之间）。
输出描述:
输出T行，分别对应输入中每行字符串对应的分身前的最小电话号码（允许前导0）。
*/

/*思路：
从字符串中根据公式获取数字，将数字排序

字符串
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    int i = 0, j = 0;
    int n;
    while (cin >> n){
        string s;  
        for (i = 0; i < n; i++){
            cin >> s;
            vector<int> iimap(256);
            for (j = 0; j < s.size(); j++){
                iimap[s[j]]++;
            }
            vector<int> res(10);
            int count = iimap['U'];
            res[6] = count;
            iimap['F'] -= count;
            iimap['O'] -= count;
            iimap['U'] -= count;
            iimap['R'] -= count;
 
            count = iimap['X'];
            res[8] = count;
            iimap['S'] -= count;
            iimap['I'] -= count;
            iimap['X'] -= count;
 
            count = iimap['W'];
            res[4] = count;
            iimap['T'] -= count;
            iimap['W'] -= count;
            iimap['O'] -= count;
 
            count = iimap['G'];
            res[0] = count;
            iimap['E'] -= count;
            iimap['I'] -= count;
            iimap['G'] -= count;
            iimap['H'] -= count;
            iimap['T'] -= count;
 
            count = iimap['Z'];
            res[2] = count;
            iimap['Z'] -= count;
            iimap['E'] -= count;
            iimap['R'] -= count;
            iimap['O'] -= count;
 
            count = iimap['F'];
            res[7] = count;
            iimap['F'] -= count;
            iimap['I'] -= count;
            iimap['V'] -= count;
            iimap['E'] -= count;
 
            count = iimap['V'];
            res[9] = count;
            iimap['S'] -= count;
            iimap['E'] -= count;
            iimap['V'] -= count;
            iimap['E'] -= count;
            iimap['N'] -= count;
 
            count = iimap['T'];
            res[5] = count;
            iimap['T'] -= count;
            iimap['H'] -= count;
            iimap['R'] -= count;
            iimap['E'] -= count;
            iimap['E'] -= count;
 
            count = iimap['O'];
            res[3] = count;
            iimap['O'] -= count;
            iimap['N'] -= count;
            iimap['E'] -= count;
 
            count = iimap['I'];
            res[1] = count;
            iimap['N'] -= count;
            iimap['I'] -= count;
            iimap['N'] -= count;
            iimap['E'] -= count;
 
            for (int k = 0; k < res.size(); k++){
                for (int l = 0; l < res[k]; l++)
                    cout << k;
            }
            cout << endl;
        }
    }
    return 0;
}