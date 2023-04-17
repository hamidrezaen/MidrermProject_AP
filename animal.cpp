#include <bits/stdc++.h>
#include "Cell.h"
using namespace std;


class animal : public cell{

    public:

    int levenshtein_distance(string s1, string s2) {
    int l1 = s1.length();
    int l2 = s2.length();
    int dp[l1 + 1][l2 + 1];

    for (int i = 0; i <= l1; i++) {
        for (int j = 0; j <= l2; j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
        }
    }

    return dp[l1][l2];
}

    double similarity_percentage(string s1, string s2) {

        int lev_dis = levenshtein_distance(s1, s2);
        double max_l = max(s1.length(), s2.length());

        return ((max_l - lev_dis) / max_l) * 100.0;
    }


    double operator==(animal &an2){

        double precent = 0;
        double chrom_size = chromosomes.size();

        for(int i=0; i<chrom_size; i++){

            string s1 = chromosomes[i].DNA.DNA1;
            string s2 = an2.chromosomes[i].DNA.DNA1;

            precent += similarity_percentage(s1, s2);
        }
        precent = precent / chrom_size;

        return precent;
    }

    void gheyre_jensi(animal &an1, animal &an3){
        do{
        vector <Genome> seed;
        vector <Genome> b3;
        int count = chromosomes.size();
        for (int i=0 ; i<count; i++){
            seed.push_back(get_chrom(i));
            seed.push_back(get_chrom(i));
        }
        int j = count;
        for (int i=0 ; j>0 ; i++){
            int rand_number = (rand() % 10) + 1;
            if (rand_number > 5){
                b3.push_back(seed[i]);
                j--;
            }
        }
        an3.SetChromosomes(b3);

        }while((an1==an3)<70);
    }

    animal operator+(animal &an2){
        vector <Genome> c2;
        for (int i=0 ; i<an2.chromosomes.size();i++){
            int rand_num = (rand()%2) +1;
            Genome gen1("","","");
            if (rand_num==1){
                gen1 = get_chrom(i);
            }
            else{
                gen1 = an2.get_chrom(i);
            }
            c2.push_back(gen1);
        }
        animal anF;
        anF.SetChromosomes(c2);
        return anF;

    }

    void print_cell(){
        for(int i=0; i<chromosomes.size(); i++){

            cout << "the first RNA of the DNA is: ";
            cout << chromosomes[i].DNA.DNA1 << endl;

            //create its comp
            string str = chromosomes[i].DNA.DNA1;
            cout << "the second RNA of the DNA is: ";
            cout << create_comp(str) << endl;
            cout << endl;
        }
    }

    void die(){
        DeathOfCell();
    }

};

//check if the RNA is made of ATGC
bool HasOtherWords(string str){
    for(int i=0; i<str.length(); i++){
        if(str[i] != 'A'
        && str[i] != 'C'
        && str[i] != 'G'
        && str[i] != 'T'){
            return 1;
        }
    }
    return 0;
}
class Animal;

class Virus{
    string RNA;
    
    public:
    
    //Input Rna
    void rna_set(string RNA){
        this -> RNA = RNA;
    }
    // Most repeated sub-String
    string common (vector <string> rnas){
        string ans;
        if (rnas.size()==1)
            ans = rnas[0];
        else{
            string s=rnas[0];
            int n = rnas.size();
            int n2 = s.length();

            for(int i=0 ; i<n2 ; i++ ){
                for (int j=i+1 ; j<=n2 ; j++){
                    string sub = s.substr(i,j);
                    int k = 1;
                    for ( ; k<n ; k++){
                        if (rnas[k].find(sub)==std::string::npos)
                            break;
                    }
                    if (k==n && ans.length() < sub.length())
                        ans = sub;
                }
            } 
        }

        return ans;
    }

    bool IsDangerous(Animal anim);

};