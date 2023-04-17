#include <bits/stdc++.h>
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
    void tiny_jump(char before, char after, int n_change, int n_chrom){
        chromosomes[n_chrom].tiny_jump(before, after, n_change);
    }
    Genome get_chrom(int n){
        return chromosomes[n];
    }
    void big_jump(string str1,int n1,string str2,int n2){
        chromosomes[n1].big_jump(str1, str2);
        chromosomes[n2].big_jump(str2, str1);
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
            if((AT>CG*3) || miss>5){
                chromosomes.clear();
                cout<<"Cell Died. x_x" << endl;

            }
            else{
                cout<<"I'm Still alive basta..." << endl;
            }
        }
    }

    void chromosome_kill(int x){
        chromosomes[x].DNA.DNA1=" x_x";
        chromosomes[x].DNA.DNA2=" x_x";
        chromosomes[x].RNA=" x_x";
        for(int i=0; i<chromosomes.size(); i++){

            cout << "the first RNA of the DNA is: ";
            cout << chromosomes[i].DNA.DNA1 << endl;
            cout << "the second RNA of the DNA is: ";
            cout << chromosomes[i].DNA.DNA2 << endl;
            cout << endl;
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
    
    void pal_comp(int n_chrom){

        string str = chromosomes[n_chrom].DNA.DNA1;
        int n = chromosomes[n_chrom].DNA.DNA1.length();

        for(int i=0; i<n; i++){
            for(int j=3; j<=n-i;j++){
                string substr = str.substr(i,j);
                if(is_palindrome_comp(substr)){
                cout << substr << endl;
                }
            }
        }
        cout << endl;
    }
};
