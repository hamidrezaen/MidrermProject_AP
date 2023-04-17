#include "animal.h"
using namespace std;

int main(){

    srand((unsigned) time(NULL));

    int fun1 = 1;

    while(fun1 != 0){

        
        cout << "///////////WELCOME///////////" << endl;
        cout << "Choose wich one do you want to work with" << endl;
        cout << "Press 1 to work with Genome." << endl;
        cout << "Press 2 to work with Cell." << endl;
        cout << "Press 3 to work with Animal" << endl;
        cout << "Press 0 to exit" << endl;


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

        int fun_cell = 1;

        while(fun_cell != 0){
            
            cout << endl;
            cout << "Choose one of the following functions: " << endl;
            cout << "Press 1 to do the tiny-jump" << endl;
            cout << "Press 2 to do the big-jump" << endl;
            cout << "Press 3 to do the reverse-jump" << endl;
            cout << "Press 4 to find all complement-palindrome-sub-strings " << endl;
            cout << "Press 5 to check if the chromosome is death." << endl;
            cout << "Press 0 to Exit" << endl;
            cout << endl;
            
            cin >> fun_cell;

            // the tiny-jump
            if(fun_cell == 1){
                
                cout << "Please choose the character you want to be deleted." << endl;
                char b;
                cin >> b;

                cout << "Please choose the character you want to be replaced." << endl;
                char a;
                cin >> a;

                cout << "How many of the " << b << " characters you want to delete and replace with " << a << "?" << endl;
                int n_change;
                cin >> n_change;

                cout << "Choose one of the chromosomes" << endl;
                int n_chrom;
                cin >> n_chrom;

                Cell.tiny_jump(b, a, n_change, n_chrom);
            }

            // the big-jump
            else if(fun_cell == 2){

                cout << "Please tyoe the first sub-string" << endl;
                string str1;
                cin >> str1;

                cout << "Please choose the first chromosome" << endl;
                int n1;
                cin >> n1;

                cout << "Please tyoe the second sub-string" << endl;
                string str2;
                cin >> str2;

                cout << "Please choose the second chromosome" << endl;
                int n2;
                cin >> n2;

                Cell.big_jump(str1, n1, str2, n2);
                //maybe i should change the big-jump fun in the cell part /////////////////////////////////////////////////////////
                cout << endl;
            }

            // do the reverse jump
            else if(fun_cell == 3){

                cout << "Please tyoe the sub-string you want to be revesed." << endl;
                string rev_str;
                cin >> rev_str;

                cout << "Please choose the chromosome" << endl;
                int n_chrom;
                cin >> n_chrom;

                Cell.reverse(rev_str, n_chrom);
                cout << endl;
            }

            else if(fun_cell == 4){

                cout << "Please choose your chromosome " << endl;
                
                int n_chrom;
                cin >> n_chrom;

                Cell.pal_comp(n_chrom);
            
            }

            else if(fun_cell == 5){
                Cell.DeathOfCell();
            }

        }

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

        int fun_an = 1;

        while(fun_an != 0){

            
            cout << endl;
            cout << "Choose one of the following functions: " << endl;
            cout << "Press 1 to calculate the similarity between two animals. " << endl;
            cout << "Press 2 to check if the animals are similar." << endl;
            cout << "Press 3 to do the Asexual reproduction" << endl;
            cout << "Press 4 to do the Sexual reproduction" << endl;
            cout << "Press 5 to check if the chromosome is death" << endl;
            cout << "Press 6 to call the virus" <<endl;
            cout << "Press 0 to Exit" << endl;
            cout << endl;

            cin >> fun_an;

            //calculate the similarity between two animals
            if(fun_an == 1){
                cout << "the similarity between 2 animals is: " << (an1 == an2) << endl;
                cout << endl;
            }

            // check if the animals are similar
            else if(fun_an == 2){
                if((an1==an2) > 70){
                    cout << "The animals are similar because the similarity between them is equal to: " << (an1 == an2) << "%" << endl;
                    cout << endl;
                }
                else if ((an1==an2) < 70) {
                    cout << "The animals are NOT similar because the similarity between them is equal to: " << (an1==an2) << "%" << endl;
                    cout << endl;
                } 
            }

            //do the Asexual reproduction
            else if(fun_an == 3){

                animal an3;
                
                cout << "Do you want to do the Asexual reproduction with the first animal? " << endl;
                cout << "Please type [yes] or [no]" << endl;

                string asexual_an;

                if(asexual_an == "yes"){

                    an1.gheyre_jensi(an1, an3);
                    cout << "mobarake. The baby is: " << endl;
                    an3.print_cell();
                }

                else{
                    an2.gheyre_jensi(an2, an3);
                    an3.print_cell();
                }
            }

            //do the Sexual reproduction
            else if(fun_an == 4){

                animal an3, an4;

                an1.gheyre_jensi(an1, an3);
                an2.gheyre_jensi(an2, an4);

                animal an5;
                an5 = (an3+an4);

                cout << "Thanks to you, the animals made a baby" << endl;
                cout << "the baby is: " << endl;
                an5.print_cell();
                cout << endl;
            }

            // check if the chromosome is death
            else if(fun_an == 5){
                cout<<"Ghasd koshtan kodam cellul ra darid ? : ";
                int m;
                cin>>m;
                if (m==1){
                    an1.die();
                }
                else if (m==2){
                    an2.die();
                }
                else{
                    cout<<"wrong number ";
                }
            }

            // work with virus
            else if(fun_an == 6){
                cout<<"" ;
            }


        }
    }
    }
    return 0;
}
