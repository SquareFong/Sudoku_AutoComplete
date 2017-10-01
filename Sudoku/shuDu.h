//
// Created by squarefong on 17-10-1.
//

#ifndef SHUDU_SHUDU_H
#define SHUDU_SHUDU_H

#include <iostream>
using namespace std;
class shuDu{
    //mat[x][y]表示矩阵上的数字, 值为零表示没有填
    int mat[9][9] = {0};
    //used表示当前x, y上已经被用的数字, true表示已经使用
    int used[9][9][10] = {0};
public:
    shuDu(){

    }
    int getNumber(int i,int j){
        if(i>=0&&i<9&&j>=0&&j<9)
            return mat[i][j];
        else
            return -'0';
    }

    //设置数字, 当数字为零表示取消设置数字；
    bool setNumber(const int x, const int y, const int number){
        //标志是否已经使用
        int u=(1);
        //设置需要更改的数字
        int n=(number);
        if(number == 0) {
            u = -1;
            n = mat[x][y];
        }
        //设置x, y上的数字
        mat[x][y] = number;
        //设置一个九宫格内已经使用的数字
        int temp[9][9]={0};
        int roomX((x/3)*3),roomY((y/3)*3);
        for(int i(0); i<3; ++i){
            for(int j(0); j<3; ++j){
                temp[roomX+i][roomY+j]+=u;
            }
        }
        //设置x,y以及对角线方向上, 已经使用的数字
        int leftXTop(x-y);
        int leftXFeet(x+y);
        for(int i(0); i<9; ++i, ++leftXTop, --leftXFeet){
            temp[x][i]+=u;
            temp[i][y]+=u;
//            if(leftXTop>=0 && leftXTop<9)
//                temp[leftXTop][i]+=u;
//            if(leftXFeet>=0 && leftXFeet<9)
//                temp[leftXFeet][i]+=u;
        }
        for(int i(0); i<9;++i){
            for(int j(0);j<9;++j){
                if(temp[i][j] > 0)
                    used[i][j][n] += 1;
                else if(temp[i][j] < 0)
                    used[i][j][n] -= 1;
            }
        }

    }
    bool Recursion(int x=0, int y=0, int Number=0){
        if(x==8 && y==8){
            if(!used[8][8][Number]) {
                mat[8][8] = Number;
                return true;
            } else
                return false;
        }
        setNumber(x,y,Number);
        int thisX(x),thisY(y);
        //如果有数字了,跳过
        while(mat[x][y] && x<9) {
            ++y;
            if (y > 8) {
                ++x;
                y = 0;
//                cout << x <<endl;
//                display();
//                cout << endl;
            }
        }
        if(x==9)
            return true;
        for(int i(1); i<=9; ++i){
            if(!used[x][y][i]){
                if(Recursion(x,y,i))
                    return true;
            }
        }

        setNumber(thisX,thisY,0);
        return false;
    }
    bool Start(){
        int x(0),y(0);
        for(int i(0); i<9;++i){
            int j(0);
            for(; j<9; ++j){
                if(mat[i][j])
                    continue;
                else
                    break;
            }
            if(j!=9){
                x=i,y=j;
                break;
            }
        }

        for(int i(1); i<=9; ++i){
            if(!used[x][y][i]){
                if(Recursion(x,y,i))
                    return true;
            }
        }
        return false;
    }
    void display() {
        for (int i(0); i < 9; ++i) {
            for (int j(0); j < 9; ++j) {
                cout << mat[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

#endif //SHUDU_SHUDU_H
