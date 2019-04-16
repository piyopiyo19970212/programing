//
//  cmp_dir.cpp
//
//
//  Created by Koharu Okahana on 2018/11/19.
//

/*
卒論で作成した2つのディレクトリの中身を
比較したtxtファイルがどこまで等しいか検証するプログラム

それぞれの検証方法のパラメタのパターンの進み具合は違うので，
少ない方に多い方が全て一致したい
(今の所パラメタc,cHatの片方固定の場合だと結果は同じだと予測)
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    ifstream ifs("diff_negative.txt");
    if (ifs.fail())
    {
        std::cerr << "失敗" << std::endl;
        return -1;
    }
    int cnt=0, cnt_c=0,cnt_cHat=0;
    while (getline(ifs, str))
    {
        /*"Only ~~": 片方のディレクトリにのみ存在するファイルを探す*/
        if(str[0]=='O'&&
            str.find('7')==std::string::npos && //7を含まない
            str.find("_A.txt")!=std::string::npos){ //行列Aだけカウントする
                cout<<str<<endl;
                if(str.find("cHat")!=std::string::npos){ //cHatだけのファイルの数
                    cnt_cHat++;
                }
                else { cnt_c++; } //cだけのファイルの数

        }
        else if(str[0]=='F'&&
            str.find('7')==std::string::npos && //7を含まない
            str.find("_A.txt")!=std::string::npos)
            { cnt++; } //両方に含まれているファイルの数
        else {}
    }
    cout<<"Shared file: "<<cnt<<endl;
    cout<<"c: "<<cnt_c<<"  "<<"cHat: "<<cnt_cHat<<endl;
    return 0;
}
