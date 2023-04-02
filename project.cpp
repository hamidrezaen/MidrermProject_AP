#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Genome{
    
    public:
    string RNA;

    //creating a structure variable for DNA because it has two parts
    struct{
        string FirstRNA, SecondRNA;
    } DNA;

    Genome(string RNA, string F_RNA, string S_RNA){

        this -> RNA = RNA;

        DNA.FirstRNA = F_RNA;
        DNA.SecondRNA = S_RNA;
    }


    void create_comp(){
        string comp_RNA = RNA;
        replace( comp_RNA.begin(), comp_RNA.end(), 'A','T' );
        replace( comp_RNA.begin(), comp_RNA.end(), 'T','A' );
        replace( comp_RNA.begin(), comp_RNA.end(), 'G','C' );
        replace( comp_RNA.begin(), comp_RNA.end(), 'C','G' );
        cout << comp_RNA;
    }

    void tiny_jump(char before, char after, int n){

        // 1- do it for RNA
        int sum = 0;
        for(int i=0; i<RNA.length(); i++){
            if(RNA[i] == before){
                sum++;
            }
        }
        if(sum < n){
            cout << "The considered character is not enough to do this" << endl;
        }
        else{
            sum=0;
            int i;
            while(sum != n){
                if(RNA[i] == before){
                    replace( RNA.begin(), RNA.end(), before, after);
                    sum++;
                }
                i++;
            }
        }

        // 2- do it for DNA/////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    //S_RNA is the second RNA of the DNA
    string RNA, F_RNA, S_RNA;

    cout << "Please enter the RNA (with A,G,C,T)" << endl;
    cin >> RNA;
    
    //check if the RNA is made of ATGC
    while(HasOtherWords(RNA)){
        cout << "It was an invalid input, please enter the RNA correctly" << endl;
        cin >> RNA;
    }
    cout << "The RNA is: " << RNA << endl;

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


    cin >> S_RNA;
    //check if the RNA is made of ATGC
    while(HasOtherWords(S_RNA)){
        cout << "It was an invalid input, please enter the RNA correctly" << endl;
        cin >> S_RNA;
    }
    cout << "The second RNA of the DNA is: " << S_RNA << endl;

    Genome Gen(RNA, F_RNA, S_RNA);
    }
