//
//  main.cpp
//  NBA Data
//
//  Created by Anish Malhotra on 3/27/17.
//  Copyright © 2017 CS2134. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Player{
public:
    Player(const string& name, const string& team, int age, int gp, int wins, int losses, double mpg, double ppg, double fgm, double fga, double fgpct, double threepm, double threepa, double threeppct, double ftm, double fta, double ftpct, double oreb, double dreb, double reb, double ast, double tov, double stl, double blk, double pf, int dd2, int td3, double bpm)
    :
    name(name), team(team), age(age), gp(gp), wins(wins), losses(losses), mpg(mpg), ppg(ppg), fgm(fgm), fga(fga), fgpct(fgpct), threepm(threepm), threepa(threepa), threeppct(threeppct), ftm(ftm), fta(fta), ftpct(ftpct), oreb(oreb), dreb(dreb), reb(reb), ast(ast), tov(tov), stl(stl), blk(blk), pf(pf), dd2(dd2), td3(td3), bpm(bpm)
    {}
    
    void printBaseStats() const{
        cout << name << ' ' << team << ' ' << ppg << ' ' << reb << ' ' << ast << endl;
    }
    
private:
    const string name, team;
    int age, gp, wins, losses, dd2, td3;
    double mpg, ppg, fgm, fga, fgpct, threepm, threepa, threeppct, ftm, fta, ftpct, oreb, dreb, reb, ast, tov, stl, blk, pf, bpm;
};

void printPlayersBaseStats(const vector<Player>& data){
    vector<Player>::const_iterator itr = data.begin();
    for(; itr != data.end(); ++itr){
        itr->printBaseStats();
    }
}

vector<Player> readData(const string& path){
    vector<Player> data;
    ifstream ifs;
    ifs.open(path.c_str());
    if(!ifs){
        cerr << "Could not find path";
        return data;
    }
    string name, team;
    int pNo, age, gp, wins, losses, dd2, td3;
    double mpg, ppg, fgm, fga, fgpct, threepm, threepa, threeppct, ftm, fta, ftpct, oreb, dreb, reb, ast, tov, stl, blk, pf, bpm;
    
    int i = 0;
    while(ifs >> pNo >> name >> team >> age >> gp >> wins >> losses >> mpg >> ppg >> fgm >> fga >> fgpct >> threepm >> threepa >> threeppct >> ftm >> fta >> ftpct >> oreb >> dreb >> reb >> ast >> tov >> stl >> blk >> pf >> dd2 >> td3 >> bpm){
        if(i == 3)
            break;
        Player foo(name, team, age, gp, wins, losses, mpg, ppg, fgm, fga, fgpct, threepm, threepa, threeppct, ftm, fta, ftpct, oreb, dreb, reb, ast, tov, stl, blk, pf, dd2, td3, bpm);
        data.push_back(foo);
        i++;
    }
    
    ifs.close();
    return data;
}

int main(int argc, const char * argv[]) {
    vector<Player> data = readData("2016-2017NBAStats.txt");
    printPlayersBaseStats(data);
    return 0;
}
