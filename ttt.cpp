#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <random>


using namespace std;
struct play
{

    int b, c, d, e, f, g, ile, los4, tura;
    //bool t = false, t2 = false;
    vector <char> tab{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    vector <int> v{ 30, 30, 30, 30, 30, 30, 30, 30, 30 };
    vector <int> v2, obrona;
    vector <int> v3{ 0, 1, 2, 3, 4, 5, 6, 7, 8 };
    vector <int> def0, def1, linia;
    vector<vector<int>>def{
    { 0,1,2 },
    { 0,3,6 },
    { 2,5,8 },
    { 6,7,8 },
    };
    vector<vector<int>>of{
    { 0,1,2 },
    { 0,3,6 },
    { 2,5,8 },
    { 6,7,8 },
    { 1,4,7 },
    { 3,4,5 },
    { 2,4,6 },
    { 0,4,8 },
    };

    vector<int>scan2, scan3;

    int win(vector<char>t, int winer)
    {
        vector<vector<int>>of{

    { 0,3,6 },
    { 2,5,8 },
    { 6,7,8 },
    { 1,4,7 },
    { 3,4,5 },

    { 0,4,8 },
    { 2,4,6 },
    { 0,1,2 },
        };

        int l = 0;
        int l1 = 0;


        for (int i = 0; i < of.size(); i++)
        {
            l = 0;
            l1 = 0;
            for (int j = 0; j < of[i].size(); j++)
            {


                if (t[of[i][j]] == winer)
                {

                    l++;
                    /*cout << "licznik" << l << endl;
                    cout << "j" << j << endl;
                    cout << "i" << i << endl;*/
                }

                if (l == 3)
                {
                    //cout << "WIN" << winer << endl;
                    for (int k = 0; k < 3; k++) linia.push_back(of[i][k]);
                    return 1;


                }








            }
            // cout << endl;

        }



    }
    vector<int> skanuj(vector<char>t, int raz, int dwa)
    {

        vector<vector<int>> skan = {
    { 0,1,2 },
    { 0,3,6 },
    { 2,5,8 },
    { 6,7,8 },
    { 1,4,7 },
    { 3,4,5 },
    { 2,4,6 },
    { 0,4,8 },
        };

        scan3.clear();

        for (size_t i = 0; i < skan.size(); i++)
        {
            int l = 0;

            scan2.clear();
            for (size_t j = 0; j < skan[i].size(); j++)
            {
                if (t[skan[i][j]] != raz)
                {
                    if (t[skan[i][j]] == dwa)
                    {

                        l++;
                        /*cout << "licznik" << l << endl;
                        cout << "j" << j << endl;
                        cout << "i" << i << endl;*/
                        scan2.push_back(skan[i][j]);



                    }
                    else scan2.insert(scan2.begin(), skan[i][j]);
                    if (scan2.size() == 3 && l == 2)
                    {
                        //cout << "scan_d" << scan2[0];
                        scan3.push_back(scan2[0]);
                    }



                }
            }
            // cout << endl;

        }
        //for (int it : scan3) cout << it;
        return scan3;
    }


    vector<int> defence(int v)
    {
        def0.clear();
        int licz = 0;

        //def.erase(def.begin());
        for (size_t i = 0; i < of.size(); i++)
        {


            for (size_t j = 0; j < of[i].size(); j++)
            {

                if (of[i][j] == v)
                {

                    licz++;
                    //cout << "licz" << licz;


                    if (licz >= 1)
                    {
                        for (size_t k = 0; k < of[i].size(); k++)  def0.push_back(of[i][k]);
                        //for (int k = 3; k < def[i].size(); k++)  def1[k] = (def[i][k]);
                    }
                    //for (int k = 3; k < def[i].size(); k++) def1.push_back(def[i][k]);


                //else for (int k = 0; k < def[i].size(); k++) def0.push_back(def[i][k]);

                }

            }

            //cout << endl;

        }
        //for (size_t i = 0; i < def0.size(); i++) cout << def0[i];
       // cout << endl;
        sort(def0.begin(), def0.end());
        def0.erase(unique(def0.begin(), def0.end()), def0.end());
        //for (int i = 0; i < def1.size(); i++) cout << def1[i];
        return def0;

    }
    vector<int> ofence(int v)
    {
        def1.clear();
        int licz = 0;

        //def.erase(def.begin());
        for (size_t i = 0; i < of.size(); ++i)
        {
            for (size_t j = 0; j < of[i].size(); )
            {
                if (of[i][j] == v)
                {
                    of.erase(of.begin() + i);
                    --i;
                    break;
                }
                else {
                    ++j;
                }
            }
        }
        for (size_t i = 0; i < of.size(); i++)
        {


            for (size_t j = 0; j < of[i].size(); j++)
            {




                def1.push_back(of[i][j]);




            }

            //cout << endl;

        }
        /*for (size_t i = 0; i < of.size(); i++)
        {
            for (size_t j = 0; j < of[i].size(); j++)
            {
                cout << of[i][j] << " ";
            }
            cout << endl;
        }*/

        //for (size_t i = 0; i < def1.size(); i++) cout << def1[i];
        //for (int i = 0; i < def1.size(); i++) cout << def1[i];
       // cout << endl;
        sort(def1.begin(), def1.end());
        // cout << "sort" << endl;
        // for (size_t i = 0; i < def1.size(); i++) cout << def1[i];
        // cout << endl;
        def1.erase(unique(def1.begin(), def1.end()), def1.end());
        //cout << "unique" << endl;
       // for (size_t i = 0; i < def1.size(); i++) cout << def1[i];
        return def1;

    }


    vector<int> of_def(vector<int>d)
    {
        vector<int> duplicate;

        // STL function to sort the array of string
        sort(d.begin(), d.end());

        for (size_t i = 1; i < d.size(); i++) {
            if (d[i - 1] == d[i]) {

                // STL function to push the duplicate
                // words in a new vector string
                if (duplicate.empty())
                    duplicate.push_back(d[i]);
                else if (d[i] != duplicate.back())
                    duplicate.push_back(d[i]);
            }
        }

        /* if (duplicate.size() == 0)
             cout << "No Duplicate" << endl;
         else
             for (size_t i = 0; i < duplicate.size(); i++)
                 cout << duplicate[i] << endl;*/
        return duplicate;
    }
    int graj()
    {
        srand((unsigned int)time(NULL));


        while (true)
        {

            ile++;
            tab = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
            v3 = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
            v.clear();
            v2.clear();

            for (tura = 0; tura < 9; tura++)
            {




                //cout << endl;
               //cout << "10" << tura << endl;

                if (tura == 0) {
                    los4 = v3[rand() % (v3.size())];
                    tab[los4] = 'X';
                    v2.insert(v2.begin(), los4);
                    Sleep(1000);




                    v3.erase(remove(v3.begin(), v3.end(), los4), v3.end());

                }
                else
                {

                    if (tura % 2 == 0) { c = 'X'; d = 'O'; e = 'O'; f = 'X'; g = 'X'; }
                    else { c = 'O'; d = 'X'; e = 'X'; f = 'O'; g = 'O'; }
                    auto nv = defence(v2.front());
                    auto nv1 = ofence(v2.front());
                    auto obrona = skanuj(tab, c, d);
                    auto atak = skanuj(tab, e, f);
                    //cout << "OBRONA";
                   // for (int it : obrona) cout << it;
                   // cout << endl;
                   // cout << "ATAK";
                   // for (int it : atak) cout << it;
                  //cout << endl;
                  //cout << "nv_main";


                    //for (size_t it : nv) cout << it;
                   // cout << endl;
                    for (size_t j = 0; j < v.size(); j++)
                        nv.erase(remove(nv.begin(), nv.end(), v[j]), nv.end());
                    for (size_t j = 0; j < v2.size(); j++)
                        nv.erase(remove(nv.begin(), nv.end(), v2[j]), nv.end());
                    for (size_t j = 0; j < v.size(); j++)
                        nv1.erase(remove(nv1.begin(), nv1.end(), v[j]), nv1.end());
                    for (size_t j = 0; j < v2.size(); j++)
                        nv1.erase(remove(nv1.begin(), nv1.end(), v2[j]), nv1.end());
                    for (size_t j = 0; j < nv1.size(); j++)
                        nv.push_back(nv1[j]);
                    auto d_o = of_def(nv);
                    // cout << "nv.size" << nv.size() << endl;
                    // cout << "nv?";
                    // for (int it : nv) cout << it;
                   //  cout << endl;
                    if (atak.size() > 0) {
                        tab[atak.front()] = g; v2.insert(v2.begin(), atak.front());
                        v3.erase(remove(v3.begin(), v3.end(), atak.front()), v3.end());

                    }

                    else if (obrona.size() > 0) {
                        tab[obrona.front()] = g; v2.insert(v2.begin(), obrona.front());
                        v3.erase(remove(v3.begin(), v3.end(), obrona.front()), v3.end());

                    }
                    else if (d_o.size() > 0)
                    {
                        int los3 = d_o[rand() % (d_o.size())];

                        //   cout << "LOS3 " << los3 << endl;
                        v2.insert(v2.begin(), los3);




                        v3.erase(remove(v3.begin(), v3.end(), los3), v3.end());
                        tab[los3] = g;

                    }
                    else if (nv.size() > 0)
                    {
                        int los = nv[rand() % (nv.size())];

                        //    cout << "LOS" << los << endl;
                        v2.insert(v2.begin(), los);




                        v3.erase(remove(v3.begin(), v3.end(), los), v3.end());
                        tab[los] = g;
                        //   cout << "ZOSTALO" << endl;
                       //    for (int it : nv) cout << it;
                       //    cout << endl;

                    }
                    else {
                        //cout << "ERROR" << endl;
                        int los2 = v3[rand() % (v3.size())];

                        tab[los2] = g; v2.insert(v2.begin(), los2);
                        v3.erase(remove(v3.begin(), v3.end(), los2), v3.end());

                    }

                    //if (i == 8) tab[nv.front()] = 10;
                }
                //cout << "JESZCZE";
                //for (int it : v3) cout << it;
               // cout << endl;

               // for (int j = 0; j < 9; j++) { cout << tab[j] << " "; if (j == 2 || j == 5) cout << endl; }
               //cout << endl;



                auto wygrana10 = win(tab, 'X');
                auto wygrana20 = win(tab, 'O');
                if (wygrana10 == 1 || wygrana20 == 1) {
                    return g; break;
                }
            }
            //cout << "ile" << ile << endl;
            //if (obrona.size()>0) break;
            auto wygrana10 = win(tab, 10);
            auto wygrana20 = win(tab, 20);
            if (wygrana10 == 1 || wygrana20 == 1) {
                break;
            }

        }

    }
};
int main()
{

    play zwyciezcy[10];
    vector <int> wygral;

    //play rozgrywka[10];
    //play wygral[10];
    for (size_t i = 0; i < 10; i++)
    {
        zwyciezcy[i].graj();
        //cout << "wyswietl zwyciezce" << i << rozgrywka[i].g;


        zwyciezcy[i].g;
        zwyciezcy[i].tab;
        zwyciezcy[i].los4;
        cout << "pierwszy ruch" << i << zwyciezcy[i].los4 << endl;
        zwyciezcy[i].tura;
        zwyciezcy[i].linia;

    }
    for (int i = 0; i < 10; i++) { {for (int j = 0; j < 3; j++) cout << "linia" << zwyciezcy[i].linia[j]; }
    cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "----------" << endl;
        for (int j = 0; j < 9; j++)
        {






            if (j == zwyciezcy[i].linia[0] || j == zwyciezcy[i].linia[1] || j == zwyciezcy[i].linia[2])
            {
                HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }





            cout << zwyciezcy[i].tab[j]; if (j == 2 || j == 5) cout << endl;
        }
        cout << endl;

    }



}
