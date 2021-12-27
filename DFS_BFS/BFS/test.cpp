/*
 * @Description: 
 * @code: 
 * @Author: Li Jiaxin
 * @Date: 2021-12-27 16:18:20
 */

#include<iostream>
#include<string>
#include<queue>
#include<utility>
#include<set>
using namespace std;

// string Plus(string s,int index){
//     if(s[index]=='9')
//         s[index] = '0';
//     else 
//         s[index] += 1;
//     return s;
// }

// string Minus(string s,int index){
//     if(s[index]=='0')
//         s[index] ='9';
//     else
//         s[index] -= 1;
//     return s;
// }


// bool NotDead(vector<string> deadends,string s){
//     for(auto i:deadends){
//         if(i==s)return false;
//     }
//     return true;
// }

// int BFS(string target,vector<string> deadends){
//     int times;
//     string start = "0000";
//     queue<pair<string,int>> q;
//     set<string> SET;

//     q.push({start,0});
//     SET.insert(start);
//     while(!q.empty()){
//         string cur = q.front().first;
//         times = q.front().second;
//         q.pop();
//         // cout<<cur<<endl;
//         if(target==cur)
//             break;
//         else if(target != cur){
//             for(int i = 0; i < start.size(); i++){
//                 string plus = Plus(cur,i);
//                 string minus = Minus(cur,i);
//                 if(NotDead(deadends,plus)&&!SET.count(plus)){
//                     q.push({plus,times+1});
//                     SET.insert(plus);
//                 }
//                 if(NotDead(deadends,minus)&&!SET.count(minus)){
//                     SET.insert(minus);
//                     q.push({minus,times+1});
//                 }
//             }
//         }
//     }
//     if(!q.empty())
//         return times;
//     return -1;
// }

// int main(){
//     string target = "0000";
//     vector<string> deadends{"6753","6001","3156","3464","3946","0958","0179","8178","2155","6694","5440","6507","0593","0762","9024","4451","3505","0210","5738","5921","7866","8392","7115","4735","9284","8189","7549","9801","9127","0308","4071","1243","4236","7034","6449","8451","2902","2924","8062","7080","3741","7580","2255","2834","4674","4584","2580","4108","9584","7248","2791","8380","0072","2800","4470","5691","2377","1067","8447","9468","3411","1324","9894","8662","3099","2393","8137","9405","6881","3156","0816","8833","4716","2512","8806","6414","6454","3736","1856","2659","9587","7680","3713","0991","5778","5270","8033","5982","5423","3063","6093","7615","8898","1527","6894","9938","9362","3649","0517","3855","1399","1060","9994","0945","6907","4122","2404","6031","4558","9062","3092","7005","3175","4072","2913","3181","2103","8350","4812","0990","2751","6393","0536","9516","9620","7609","2415","2285","7138","8651","0157","2192","5336","1853","4651","6734","4753","6114","4499","5821","9838","3470","5912","2153","2770","4349","3801","9828","9293","2459","1318","9331","7521","8579","7228","9683","4349","8665","1059","3747","5775","8819","2064","9452","5148","8124","5344","3718","3351","2214","6458","5797","1780","4428","8249","0724","4819","3371","1064","2249","3271","7644","6889","8525","8648","9501","5405","6152","8969","1541","7651","2382","4194","3677","0498","6445","7017","8921","5774","2555","1749","7457","6700","3442","7963","0200","0011","5913","6894","6306","7120","7891","5519","1188","9710","0653","5592","9695","9496","5972","8488","3794","6491","0506","5803","8312","5829","3176","2543","0221","5743","2413","7429","7350","5094","2009","2556","2809","9255","8946","1926","6407","8791","6004","4348","2689","0749","6779","0191","4430","5679","4641","5444","5224","2622","7594","2579","9909","7112","5912","2369","0381","6931","2681","8302","3528","5985","5045","7718","0348","3408","4708","2830","8801","2225","9443","9957","3973","0258","5579","5631","6531","2576","8798","1331","4866","2088","7615","9971","9611","9981","5259","8592","9379","3639","1063","4899","4930","2388","2078","1452","1121","7216","6968","8037","1927","3681","2710","6793","5634","6511","4646","3487","5608","1312","3791","8312","7384","9905","7556","3454","3192","1611","5544","3189","6936","2541","0447","2839","3409","4519","4527","3584","3210","7688","8799","1815","2078","9518","4743","8960","6088","1679","5313","8199","4339","6812","0790","7127","2104","4441","8265","9273","6305","4958","9853","0492","1319","8882","3449","6095","6996","1667","4136","3968","0411","2766","4305","2857","2240","2460","4230","6711","0689","4520","0154","2444","9346","1616","3701","8071","4876","2827","3944","4563","8903","5540","7223","0588","7365","8994","9226","0770","4199","3525","4187","2145","2117","9147","1797","5196","8206","3094","5877","2088","2903","8448","9155","7809","2571","7698","0623","3425","7635","0261","4903","6257","9154","3921","5525","6187","8374","6586","1337","1205","0375","1902","3048","1091","2085","5699","2241","5548","9599","6466","8341","7110","2023","3756","5629","4179","1870","0167","5327","3351","0966","6304","5993","9163","4644","7279","2211","4455","6925","5946","0317","3327","5370","5940","8617","2879","0236","7689","7861","1300","6415","7906","7197","5492","8980","1754","4571","7189","0142","5821","2564","5747","5422","1101","3942","3961","4277","6276","3174","3055","7644","6621","8553","6920","2118","7503","0325","6672","4382","1793","3550","1179","3357","2927","8101"};
//     int times = BFS(target,deadends);
//     cout<<times;

// }



// class Solution {
// public:
//     int openLock(vector<string>& deadends, string target) {
//         int times;
//         string start = "0000";
//         queue<pair<string,int>> q;
//         set<string> SET;
//         set<string> deads;
//         for(auto i:deadends)
//             deads.insert(i);
//         if(deads.count(start))
//             return -1;
//         q.push({start,0});
//         SET.insert(start);
//         while(!q.empty()){
//             string cur = q.front().first;
//             times = q.front().second;
//             q.pop();
//             // cout<<cur<<endl;
//             if(target==cur)
//                 return times;
//             else if(target != cur){
//                 for(int i = 0; i < start.size(); i++){
//                     string plus = Plus(cur,i);
//                     string minus = Minus(cur,i);
//                     if(!deads.count(plus)&&!SET.count(plus)){
//                         q.push({plus,times+1});
//                         SET.insert(plus);
//                     }
//                     if(!deads.count(minus)&&!SET.count(minus)){
//                         SET.insert(minus);
//                         q.push({minus,times+1});
//                     }
//                 }
//             }
//         }
//         return -1;
//     }
//     string Plus(string s,int index){
//         if(s[index]=='9')
//             s[index] = '0';
//         else 
//             s[index] += 1;
//         return s;
//     }

//     string Minus(string s,int index){
//         if(s[index]=='0')
//             s[index] ='9';
//         else
//             s[index] -= 1;
//         return s;
//     }
// };

// int main(){
//     Solution solver; //
//     vector<string> deadends{"0201","0101","0102","1212","2002"};
//     string target = "0000"; 
//     cout<<solver.openLock(deadends,target);
// }



class Solution {
private:
    vector<vector<int>> target{{1,2,3},{4,5,0}};
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>> q;
        set<vector<vector<int>>> s;
        q.push(board);
        int times =0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                vector<vector<int>> cur = q.front();
                q.pop();
                s.insert(cur);
                if(isRight(cur))
                    return times;
                Find(cur);
                int i= Find(cur).first,j=Find(cur).second;
                vector<vector<int>> temp;
                temp = Down(cur,i,j);
                if(!s.count(temp))
                    q.push(temp);

                temp = Up(cur,i,j);
                if(!s.count(temp))
                    q.push(temp);

                temp = Left(cur,i,j);
                if(!s.count(temp))
                    q.push(temp);

                temp = Right(cur,i,j);
                if(!s.count(temp))
                    q.push(temp);
            }
            ++times;
        }
        return times;

    }

    vector<vector<int>> Down(vector<vector<int>> board,int i,int j){
        if(i==1)
            return board;
        else{
            swap(board[i][j],board[i+1][j]);
            return board;
        }

    }
    vector<vector<int>> Up(vector<vector<int>> board,int i,int j){
        if(i==0)
            return board;
        else{
            swap(board[i][j],board[i-1][j]);
            return board;
        }
    }
    vector<vector<int>> Left(vector<vector<int>> board,int i,int j){
        if(j==0)
            return board;
        else{
            swap(board[i][j],board[i][j-1]);
            return board;
        }
    }
    vector<vector<int>> Right(vector<vector<int>> board,int i,int j){
        if(j==2)
            return board;
        else{
            swap(board[i][j],board[i][j+1]);
            return board;
        }
    }

    bool isRight(vector<vector<int>> board){
        int i,j;
        for(i=0;i<2;++i){
            j=0;
            for(;j<3;++j){
                if(board[i][j]!=target[i][j])
                    return false;
            }
        }
        return true;
    }

    pair<int,int> Find(vector<vector<int>> board){
        int i,j;
        for(i=0;i<2;++i){
            int j=0;
            for(;j<3;++j){
                if(board[i][j]==0)
                    return pair<int,int>{i,j};
            }
        }
        return pair<int,int>{i,j};
    }
};



int main(){
    Solution solver;
    vector<vector<int>> board {{1,2,3},{4,0,5}};
    int times = solver.slidingPuzzle(board);
    cout<<times<<endl;
}