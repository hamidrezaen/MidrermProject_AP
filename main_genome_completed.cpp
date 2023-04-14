#include<bits/stdc++.h>
using namespace std;

class Genome{
    
    public:
    string RNA;

    //creating a structure variable for DNA because it has two parts
    struct{
        string FirstRNA, CompRNA;
    } DNA;

    Genome(string RNA, string F_RNA, string S_RNA){

        this -> RNA = RNA;

        DNA.FirstRNA = F_RNA;
        DNA.CompRNA = S_RNA;
    }


    void create_comp(){
        string comp_RNA = RNA;
        for(int i=0; i<comp_RNA.length(); i++){
        if(comp_RNA[i] == 'A'){comp_RNA[i] = 'T';}
            else if(comp_RNA[i] == 'T'){comp_RNA[i] = 'A';}
            else if(comp_RNA[i] == 'C'){comp_RNA[i] = 'G';}
            else if(comp_RNA[i] == 'G'){comp_RNA[i] = 'C';}
        }
        cout << comp_RNA << endl;
        cout << endl;
    }

    void tiny_jump(char before, char after, int NumOfChange){

        //1- do the function for RNA
        int count_befores = 0;
        for(int i=0; i < RNA.length(); i++){
            if(RNA[i] == before){
                count_befores++;
                if(count_befores <= NumOfChange){
                    RNA[i] = after;
                }
            }
        }
       //create a char to change the function for DNA easier
        char after_comp;
        if(after == 'A'){after_comp = 'T';}
        else if(after == 'T'){after_comp = 'A';}
        else if(after == 'G'){after_comp = 'C';}
        else if(after == 'C'){after_comp = 'G';}

        // 2- do the function for DNA
        count_befores = 0;
        for(int i=0; i < DNA.FirstRNA.length(); i++){

            if(DNA.FirstRNA[i] == before){
                count_befores++;
                if(count_befores <= NumOfChange){
                    DNA.FirstRNA[i] = after;
                    DNA.CompRNA[i] = after_comp;
                }
            }
            
            else if(DNA.CompRNA[i] == before){
                count_befores++;
                if(count_befores <= NumOfChange){
                DNA.CompRNA[i] = after;
                DNA.FirstRNA[i] = after_comp;
                }
            }
        }

    void big_jump(string before, string after){
        
        int before_len = before.length();
        //1- for RNA
        int position = RNA.find(before);
        if(position!=string::npos){
        RNA.replace(position, before_len, after);
        }

        //2- for DNA
        
        int position_first, position_comp;
        position_first = DNA.FirstRNA.find(before);
        position_comp = DNA.CompRNA.find(before);

        if(position_comp != string::npos || position_first != string::npos){

            string after_comp = after;
        for(int i=0; i<=after.length(); i++){
            if(after_comp[i] == 'A'){after_comp[i] = 'T';}
            else if(after_comp[i] == 'T'){after_comp[i] = 'A';}
            else if(after_comp[i] == 'C'){after_comp[i] = 'G';}
            else if(after_comp[i] == 'G'){after_comp[i] = 'C';}
        }

        if (position_first <= position_comp){ 
            DNA.FirstRNA.replace(position_first, before_len, after);
            DNA.CompRNA.replace(position_first, before_len, after_comp);
            }
        else if(position_first > position_comp){ 
            DNA.CompRNA.replace(position_comp, before_len, after);
            DNA.FirstRNA.replace(position_comp, before_len, after_comp);
        }
        }
    }

    void reverse(string str){
        
        //reverse str
        string reverse_str = str;
        int l = str.length();
        for(int i=0; i<l/2; i++){
                char temp = reverse_str[i];
                reverse_str[i]=reverse_str[l-1-i];
                reverse_str[l-1-i]=temp;
        }

        //creating a string to change 'A'&'T' and 'G'&'C' to use in the DNA part
        string reverse_comp = reverse_str;
        for(int i=0; i<l; i++){
            if(reverse_comp[i] == 'A'){reverse_comp[i] = 'T';}
            else if(reverse_comp[i] == 'T'){reverse_comp[i] = 'A';}
            else if(reverse_comp[i] == 'C'){reverse_comp[i] = 'G';}
            else if(reverse_comp[i] == 'G'){reverse_comp[i] = 'C';}
        }
        
        //1 - for RNA
        int position = RNA.find(str);

        if(position != string::npos){
            RNA.replace(position, l, reverse_str);
        }

        //2- for DNA 
        int position_first = DNA.FirstRNA.find(str);
        int position_comp = DNA.CompRNA.find(str);

        if(position_comp != string::npos || position_first != string::npos){
        if(position_first >= position_comp){
            position = position_first;

            DNA.FirstRNA.replace(position, l, reverse_str);
            DNA.CompRNA.replace(position, l, reverse_comp);
            
        }
        else if(position_first < position_comp){
            position = position_comp;

            DNA.CompRNA.replace(position, l, reverse_str);
            DNA.FirstRNA.replace(position, l, reverse_comp);
            
        }
        }
    }
};

class cell{
    private:
    vector<Genome> chromosomes;
    public:
    void SetChromosomes(vector<Genome> a){
        for(auto x:a)
            chromosomes.push_back(x);
    }
    void tiny_jump(char A, char B, int n, int m){
        chromosomes[m].tiny_jump(A, B, n);
    }
    void big_jump(string A,int n,string B,int m){
        chromosomes[m].big_jump(A,B);
        chromosomes[n].big_jump(B,A);
    }
    void reverse(string A,int n){
        chromosomes[n].reverse(A);
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

int main(){

    //F_RNA is the first RNA of the DNA
    //S_RNA is the comp. RNA of the DNA
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

    cout << "Please enter the comp. RNA of the DNA" << endl;
    cin >> S_RNA;
    //check if the RNA is made of ATGC
    while(HasOtherWords(S_RNA)){
        cout << "It was an invalid input, please enter the RNA correctly" << endl;
        cin >> S_RNA;
    }
    cout << "The comp. RNA of the DNA is: " << S_RNA << endl;
    cout << endl;

    Genome chrom(RNA, F_RNA, S_RNA);

    return 0;
}