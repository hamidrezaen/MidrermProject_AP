#include<bits/stdc++.h>
#include "animal.h"
#include "cell.h"

using namespace std;

string create_comp(string str){
        
        for(int i=0; i<str.length(); i++){
        if(str[i] == 'A'){str[i] = 'T';}
            else if(str[i] == 'T'){str[i] = 'A';}
            else if(str[i] == 'C'){str[i] = 'G';}
            else if(str[i] == 'G'){str[i] = 'C';}
        }
        return str;
    }

class Genome{
    
    public:
    string RNA;

    //creating a structure variable for DNA because it has two parts
    struct{
        string DNA1, DNA2;
    } DNA;

    Genome(string RNA, string F_RNA, string S_RNA){

        this -> RNA = RNA;

        DNA.DNA1 = F_RNA;
        DNA.DNA2 = S_RNA;
    }


    string create_comp_RNA(){
        string comp_RNA = RNA;
        for(int i=0; i<comp_RNA.length(); i++){
        if(comp_RNA[i] == 'A'){comp_RNA[i] = 'T';}
            else if(comp_RNA[i] == 'T'){comp_RNA[i] = 'A';}
            else if(comp_RNA[i] == 'C'){comp_RNA[i] = 'G';}
            else if(comp_RNA[i] == 'G'){comp_RNA[i] = 'C';}
        }
        return comp_RNA;
    }

    void tiny_jump(char before, char after, int NumOfChange){

        int count_befores;

        if(RNA != " "){
        //1- do the function for RNA
        count_befores = 0;
        for(int i=0; i < RNA.length(); i++){
            if(RNA[i] == before){
                count_befores++;
                if(count_befores <= NumOfChange){
                    RNA[i] = after;
                }
            }
        }

        // if the number of changes is greater than the characters do this:
        if(count_befores < NumOfChange){
            cout << "The number of changes was greater than the characters already exist in the string" << endl
            << "so we changed " << count_befores << " characters." << endl;
            cout << endl;
        }
        
        cout << "Now the new RNA is: " << RNA << endl;
        cout << endl;
        }

        //create a char to change the function for DNA easier
        char after_comp;
        if(after == 'A'){after_comp = 'T';}
        else if(after == 'T'){after_comp = 'A';}
        else if(after == 'G'){after_comp = 'C';}
        else if(after == 'C'){after_comp = 'G';}

        // 2- do the function for DNA
        count_befores = 0;
        for(int i=0; i < DNA.DNA1.length(); i++){

            if(DNA.DNA1[i] == before){
                count_befores++;
                if(count_befores <= NumOfChange){
                    DNA.DNA1[i] = after;
                    DNA.DNA2[i] = after_comp;
                }
            }
            
            else if(DNA.DNA2[i] == before){
                count_befores++;
                if(count_befores <= NumOfChange){
                DNA.DNA2[i] = after;
                DNA.DNA1[i] = after_comp;
                }
            }
        }
        
        // if the number of changes is greater than the characters do this:
        if(count_befores < NumOfChange){
            cout << "The number of changes was greater than the characters already exist in the string" << endl
            << "so we changed " << count_befores << " characters." << endl;
            cout << endl;
        }
        
        cout << "Now the first RNA of the DNA is: " << DNA.DNA1 << endl;
        cout << "Now the comp. RNA of the DNA is: " << DNA.DNA2 << endl;
        cout << endl;
    }

    void big_jump(string before, string after){
        
        int before_len = before.length();

        if(RNA != " "){
        //1- for RNA
        int position = RNA.find(before);
        if(position!=string::npos){
        RNA.replace(position, before_len, after);
        cout << "Now the new RNA is: " << RNA << endl;
        }
        else{cout << "It wasn't in the RNA." << endl;}
        }

        //2- for DNA
        
        int position_first, position_comp;
        position_first = DNA.DNA1.find(before);
        position_comp = DNA.DNA2.find(before);

        if(position_comp != string::npos || position_first != string::npos){

            string after_comp = create_comp(after);

        if (position_first <= position_comp){ 
            DNA.DNA1.replace(position_first, before_len, after);
            DNA.DNA2.replace(position_first, before_len, after_comp);
            cout << "Now the first RNA of the DNA is: " << DNA.DNA1 << endl;
            cout << "Now the comp. RNA of the DNA is: " << DNA.DNA2 << endl;
            cout << endl;
            }
        else if(position_first > position_comp){ 
            DNA.DNA2.replace(position_comp, before_len, after);
            DNA.DNA1.replace(position_comp, before_len, after_comp);
            cout << "Now the first RNA of the DNA is: " << DNA.DNA1 << endl;
            cout << "Now the comp. RNA of the DNA is: " << DNA.DNA2 << endl;
            cout << endl;
        }
        }

        else{cout << "It wasn't in the DNA." << endl;}
    }

    
    void reverse_jump(string str){
        
        //reverse str
        string reverse_str = str;
        int l = str.length();
        for(int i=0; i<l/2; i++){
                char temp = reverse_str[i];
                reverse_str[i]=reverse_str[l-1-i];
                reverse_str[l-1-i]=temp;
        }

        //creating a string to change 'A'&'T' and 'G'&'C' to use in the DNA part
        string reverse_comp = create_comp(reverse_str);
        int position;

        if( RNA != " "){
        //1 - for RNA
        position = RNA.find(str);

        if(position != string::npos){
            RNA.replace(position, l, reverse_str);
            cout << "Now the new RNA is: " << RNA << endl;
        }

        else{
            cout << "It wasn't in the RNA." << endl;
        }
        }

        //2- for DNA 
        int position_first = DNA.DNA1.find(str);
        int position_comp = DNA.DNA2.find(str);

        if(position_comp != string::npos || position_first != string::npos){
        if(position_first >= position_comp){
            position = position_first;

            DNA.DNA1.replace(position, l, reverse_str);
            DNA.DNA2.replace(position, l, reverse_comp);
            
            cout << "Now the first RNA of the DNA is: " << DNA.DNA1 << endl;
            cout << "Now the second RNA of the DNA is: " << DNA.DNA2 << endl;
            cout << endl;
        }
        else if(position_first < position_comp){
            position = position_comp;

            DNA.DNA2.replace(position, l, reverse_str);
            DNA.DNA1.replace(position, l, reverse_comp);
            
            cout << "Now the first RNA of the DNA is: " << DNA.DNA1 << endl;
            cout << "Now the second RNA of the DNA is: " << DNA.DNA2 << endl;
            cout << endl;
        }
        }

        else{cout << "It wasn't in the DNA." << endl;}
    }
};

class cell{

    public:

    vector <Genome> chromosomes;

    void SetChromosomes(vector<Genome> a){
        for(auto x:a)
            chromosomes.push_back(x);
    }
    void tiny_jump(char A, char B, int n, int m){
        chromosomes[m].tiny_jump(A, B, n);
    }
    Genome get_chrom(int n){
        return chromosomes[n];
    }
    void big_jump(string A,int n,string B,int m){
        chromosomes[m].big_jump(A,B);
        chromosomes[n].big_jump(B,A);
    }
    void reverse(string A,int n){
        chromosomes[n].reverse_jump(A);
    }
    void DeathOfCell(){
        for(int i =0;i<chromosomes.size();i++){
            int AT = 0;
            int CG = 0;
            int miss = 0;
            for(int j=0 ; j<chromosomes[i].DNA.DNA1.size();j++){
            if(chromosomes[i].DNA.DNA1[j]== 'A' && chromosomes[i].DNA.DNA2[j]== 'T'){ AT++;}
            if(chromosomes[i].DNA.DNA1[j]== 'T' && chromosomes[i].DNA.DNA2[j]== 'A'){ AT++;}
            if(chromosomes[i].DNA.DNA1[j]== 'C' && chromosomes[i].DNA.DNA2[j]== 'G'){CG++;}
            if(chromosomes[i].DNA.DNA1[j]== 'G' && chromosomes[i].DNA.DNA2[j]== 'C'){CG++;}
            if(chromosomes[i].DNA.DNA1[j]== 'A' && chromosomes[i].DNA.DNA2[j]!= 'T'){ miss++;}
            if(chromosomes[i].DNA.DNA1[j]== 'T' && chromosomes[i].DNA.DNA2[j]!= 'A'){ miss++;}
            if(chromosomes[i].DNA.DNA1[j]== 'C' && chromosomes[i].DNA.DNA2[j]!= 'G'){miss++;}
            if(chromosomes[i].DNA.DNA1[j]== 'G' && chromosomes[i].DNA.DNA2[j]!= 'C'){miss++;}
            }
            if((AT/CG>3) || miss>5){
                chromosomes.clear();
                cout << "VAAAAAY hossein ghad ghotel." << endl;
                delete this;
                break;
        }
        }
    }

    bool is_palindrome_comp(string str){

    int n = str.length();
    string comp_str = create_comp(str);

    for(int i=0; i<n/2; i++){
                char temp = comp_str[i];
                comp_str[i]=comp_str[n-1-i];
                comp_str[n-1-i]=temp;
        }
    
    for(int i=0; i<n; i++){
        if(str[i] != comp_str[i]){
            return false;
        }
    }
    return true;
}

void pal_substr(string str){
    int n = str.length();
    for(int i=0; i<n; i++){
        for(int j=3; j<=n-i;j++){
            string substr = str.substr(i,j);
            if(is_palindrome_comp(substr)){
            cout << substr << endl;
            }
        }
    }
}
};

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

    void print_chrom(){
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

    void death(){

        cout << "VAAAAAY hossein ghad ghotel." << endl;
        delete this;
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

int main(){

    srand((unsigned) time(NULL));

    cout << "///////////WELCOME///////////" << endl;
    cout << "Choose wich one do you want to work with" << endl;
    cout << "Press 1 to work with Genome." << endl;
    cout << "Press 2 to work with Cell." << endl;
    cout << "Press 3 to work with Animal" << endl;

    int fun1;
    cin >> fun1;

    //working with Genome class
    if (fun1 == 1){

    //F_RNA is the first RNA of the DNA
    //S_RNA is the complement RNA of the DNA
    string RNA, F_RNA, S_RNA;

    cout << "Please enter the RNA (with A,G,C,T)" << endl;
    cin >> RNA;
    
    //check if the RNA is made of ATGC
    while(HasOtherWords(RNA)){
        cout << "It was an invalid input, please enter the RNA correctly" << endl;
        cin >> RNA;
    }
    cout << "The RNA is: " << RNA << endl;
    cout << endl;

    //creating DNA
    cout << "Now create your DNA" << endl;
    cout << "Please enter the First RNA of the DNA" << endl;
    cin >> F_RNA;
    //check if the RNA is made of ATGC
    while(HasOtherWords(F_RNA)){
        cout << "It was an invalid input, please enter the RNA correctly" << endl;
        cin >> F_RNA;
    }
    cout << "The first RNA of the DNA is: " << F_RNA << endl;
    cout << endl;

    cout << "Please enter the complement RNA of the DNA" << endl;
    cin >> S_RNA;
    //check if the RNA is made of ATGC
    while(HasOtherWords(S_RNA)){
        cout << "It was an invalid input, please enter the RNA correctly" << endl;
        cin >> S_RNA;
    }
    cout << "The complement RNA of the DNA is: " << S_RNA << endl;
    cout << endl;

    Genome chrom(RNA, F_RNA, S_RNA);


    int fun_gen =1;

    // show complement of the RNA
    while(fun_gen != 0){

    cout << "Please choose one of the following functions: " << endl;
    cout << "Press 1 to show the complement of the RNA" << endl;
    cout << "Press 2 to do the tiny-jump" << endl;
    cout << "Press 3 to do the big-jump" << endl;
    cout << "Press 4 to do the reverse jump" << endl;
    cout << "Press 0 to exit." << endl;
    cin >> fun_gen;

    if(fun_gen == 1){
        cout << endl;
        cout << "The RNA is: " << RNA << endl;
        cout << "The complement of the RNA is: " << chrom.create_comp_RNA() << endl;
        cout << endl;
    }
    
    // do the tiny-jump
    if(fun_gen == 2){

        cout << endl;
        cout << "Please choose the character you want to be deleted: " << endl;
        char b;
        cin >> b;
        cout << "Please choose the character you want to be replaced: " << endl;
        char a;
        cin >> a;
        cout << "How many of the " << b << " characters you want to delete and replace with " << a << "?" << endl;
        int n_change;
        cin >> n_change;

        chrom.tiny_jump(b, a, n_change);

        cout << endl;
    }

    //do the big-jump
    if(fun_gen == 3){

        cout << endl;
        cout <<  "Please enter the sub-string you want to be deleted. " << endl;
        string before;
        cin >> before;

        cout << "Please enter the sub-string you want to be replaced." << endl;
        string after;
        cin >> after;

        chrom.big_jump(before, after);

        cout << endl;
    }

    // do the reverse jump
    if(fun_gen == 4){

        cout << endl;
        cout << "Please enter the sub-string you want to be replaced " << endl;
        string rev_str;
        cin >> rev_str;

        chrom.reverse_jump(rev_str);

        cout << endl;
    }
    }
    }

    // working with cell class
    else if(fun1 == 2){

        int n_chrom;
        vector <Genome> c;

        cout << "how much chromosomes do you want to have in cell? " << endl;
        cin >> n_chrom;

        for(int i=0; i<n_chrom; i++){

            string DNA1, DNA2;

            // cin the first RNA of the DNA
            cout << "Please enter the first RNA of the DNA (with A,G,C,T)" << endl;
            cin >> DNA1;

            //check if the RNA is made of ATGC
            while(HasOtherWords(DNA1)){
            cout << "It was an invalid input, please enter the RNA correctly" << endl;
            cin >> DNA1;
            }

            // cin the complement RNA of the DNA
            cout << "Please enter the complement RNA of the DNA (with A,G,C,T)" << endl;
            cin >> DNA2;

            //check if the RNA is made of ATGC
            while(HasOtherWords(DNA2)){
            cout << "It was an invalid input, please enter the RNA correctly" << endl;
            cin >> DNA2;
            }

            cout << "The first RNA of the DNA is: " << DNA1 << endl;
            cout << "The complement RNA of the DNA is: " << DNA2 << endl;
            cout << endl;

            Genome gen1(" ", DNA1, DNA2);

            c.push_back(gen1);
        }
        cell Cell;
        Cell.SetChromosomes(c);


    }

    else if (fun1 == 3){

        animal an1, an2;
        int n_rna;
        
        cout << "Enter the number of chromosomes of the animals. " << endl;
        cin >> n_rna;

        // create a vector to use it for "chromosomes" vector
        vector <Genome> b1;

        cout << "Now lets create the first animal" << endl;
        for(int i=0; i<n_rna; i++){

            string RNA1;

            cout << "Please enter the RNA (with A,G,C,T)" << endl;
            cin >> RNA1;    
            //check if the RNA is made of ATGC
            while(HasOtherWords(RNA1)){
            cout << "It was an invalid input, please enter the RNA correctly" << endl;
            cin >> RNA1;
            }
            cout << "The RNA is: " << RNA1 << endl;
            cout << endl;


            Genome gen1(" ", RNA1, create_comp(RNA1));
            b1.push_back(gen1);
        }
        // save the data for the first animal
        an1.SetChromosomes(b1);

        
        // create a vector to use it for "chromosomes" vector
        vector <Genome> b2;

        cout << "Now lets create the second animal" << endl;
        for(int i=0; i<n_rna; i++){

            string RNA2;

            cout << "Please enter the RNA (with A,G,C,T)" << endl;
            cin >> RNA2;    
            //check if the RNA is made of ATGC
            while(HasOtherWords(RNA2)){
            cout << "It was an invalid input, please enter the RNA correctly" << endl;
            cin >> RNA2;
            }
            cout << "The RNA is: " << RNA2 << endl;
            cout << endl;

            //creating a "gen1" with Genome data type to save the second RNA of the DNA
            // chromosome only has DNA so its RNA is NULL
            // creating the complement of the DNA with "create_comp" function
            Genome gen2(" ", RNA2, create_comp(RNA2));
            b2.push_back(gen2);
        }
        // save the data for the second animal
        an2.SetChromosomes(b2);
        cout << (an1==an2) << endl;

        //animal an3;
        //an1.print_chrom();
        //an1.gheyre_jensi(an1,an3);
        //an3.print_chrom();
        //cout << (an1==an3) << endl;

        //animal an3,an4;
        //an1.gheyre_jensi(an1,an3);
        //an2.gheyre_jensi(an2,an4);

        //animal an5;
        //an5 = (an3+an4);
        

    }
    return 0;
}
