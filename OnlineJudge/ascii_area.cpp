#include <bits/stdc++.h>

using namespace std;


typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define _MAX_ 107

int h, w;
int moves[4][2] =  {  { 0, 1},  { 1, 0},  { 0,-1},  {-1, 0}  };


// int dfs(int x0, int y0, char mtx[_MAX_][_MAX_] ){
//     stack<pii> squares;
//     int puntos = 1;
//     squares.push({x0, y0});
//     mtx[x0][y0] = '1';
//     while (!squares.empty()){
//         int x = squares.top().first;
//         int y = squares.top().second;
//         
//         squares.pop();
//         for (int i = 0; i < 4; i++){
//             int x1 = x + moves[i][0]; 
//             int y1 = y + moves[i][1];
// 
//             if(x1 < 0 || x1 >= h || y1 < 0 || y1 >= w ){//es un punto afuera de la figura,
// 
//                 return -1;
//             }
// 
//             if( mtx[x1][y1] == '.' ){
//                 squares.push({x1, y1});
//                 mtx[x1][y1] = '1';
//                 puntos++;
//             }
//         }
//         
//     }
//     cout<<"\n"<<puntos<<"\n";
//     return puntos;
// }

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    while (cin>>h>>w){
        int numDiagonales = 0;
        int numPuntos = 0;
        char mtx[_MAX_][_MAX_]; 

        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                cin>>mtx[i][j];
                if(mtx[i][j] == '/' || mtx[i][j] == '\\'){
                    numDiagonales++;
                }
            }
        }
        int dentro =  0;
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                if(mtx[i][j] == '/' || mtx[i][j] == '\\'){
                    dentro = (dentro + 1) % 2;
                }else if(dentro){
                    numPuntos++;
                }
            }
        }    
        
        cout<< numPuntos + numDiagonales / 2<<"\n";
    }



    return 0;

}