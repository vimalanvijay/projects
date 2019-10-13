#include <iostream>
#include<string>
#include <fstream>
#include<ostream>
#include<vector>
#include<map>


//onlt abridged protein file is implemented
//protein id hasnt been implemented
//can search and print with keywords but cant select which protein to view
//stats doesnt work 

//fuction declarations
using namespace std;
int global_input();
void display_main(int *x);
void display_global();
void overview();
void search_by_gi();
void search_by_ref();
void search_by_keyword();
void description();
void print_sequence();
void protein_stats();
void protein_count();
void save_to_file();
int mainmenu_input ();
void hitmenu();

using namespace std;
//global variables
string search_id,keyword;
int global;//newtotal=0;

ifstream protein_file("protein_a.fa");

struct protein
{
    public:
    string description;
    vector<string> sequence;
    int totalcount;
 
 };

protein chosen;

//main fucntion
int main()
{
    display_global();
}

void display_global()
{
    global= global_input();  //prints global menu
    while(global<3)
    {
        if(global==1)
        {
            display_main(&global);
        }
        if(global==2)
            display_main(&global);
    }
    
}//main menu function where user gets to use how to search
void display_main(int *x)
{
    int mainmenu=mainmenu_input();
    int global=*x;
    if(global==1) //abridged protein
    {
        switch (mainmenu)
        {
            case 1:
                overview();
                display_main(&global);
                break;
            case 2:
                cout<<"DOESN'T YET WORK"<<endl;
                break;
            case 3:
                search_by_gi();
                break;
            case 4:
                search_by_ref();
                break;
            case 5:
                search_by_keyword();
                break;
            case 6:
                exit(0);
        }
    }
}

void hitmenu() //prints hit menu and calls fucntions for selected protein and continues until 6 entered for main menu
{
    cout<< "\n******-----PROTEIN MENU-----******"<<endl;
    cout<<"Select an option from menu below:"<<endl;
    cout<<"1) Description of the protein"<<endl;
    cout<<"2) Protein sequence"<<endl;
    cout<<"3) Protein statistics"<<endl;
    cout<<"4) Record protein to file"<<endl;
    cout<<"5) Return to main menu"<<endl;
    
    int choice;
    cin>>choice;
    
    switch(choice)
    {
        case 1: //description
        {
            cout<<chosen.description<<endl;
            hitmenu();
            break;
        }
        case 2: //protein sequence
        {
            for (auto x : chosen.sequence) cout << x << endl;
            hitmenu();
            break;
        }
            
        case 3:
        {
            protein_stats();
            //protein_count();
            hitmenu();
            break;
        }
            
        case 4:
        {
            save_to_file();
            hitmenu();
            break;
        }
        default: display_main(&global);
            break;
    }
}

//just prints the overview
void overview()
{
    cout<< "\nThe proteins in the database are from GenBank(R)"<<endl;
    cout<< "Total number of proteins in the database: 110386"<<endl;
    cout<< "Amino acids are represented by the following characters:"<<endl;
    cout<< "A alanine P proline"<<endl;
    cout<< "B aspartate/asparagine Q glutamine"<<endl;
    cout<< "C cystine R arginine"<<endl;
    cout<< "D aspartate S serine"<<endl;
    cout<< "E glutamate T threonine"<<endl;
    cout<< "F phenylalanine U selenocysteine"<<endl;
    cout<< "G glycine V valine"<<endl;
    cout<< "H histidine W tryptophan"<<endl;
    cout<< "I isoleucine Y tyrosine"<<endl;
    cout<< "K lysine Z glutamate/glutamine"<<endl;
    cout<< "L leucine X any"<<endl;
    cout<< "M methionine * translation stop"<<endl;
    cout<< "N asparagine - gap of indeterminate length"<<endl;
}


//gets gi input
void search_by_gi()
{
    cout<<"Enter gi value:"<<endl;
    cin>>search_id;
    description();
    print_sequence();
    hitmenu();

}

//gets ref input
void search_by_ref()
{
    cout<<"Enter ref value:"<<endl;
    cin>>search_id;
    description();
    print_sequence();
    hitmenu();
}

//gets keyword input
void search_by_keyword()
{
    ifstream protein_file("protein_a.fa");
    string line,keyword;
    int offset;
    cout<<"Enter keyword:"<<endl;
    cin>>keyword;
    int count=0;
    
    if (protein_file.is_open()) // for now only abridged
    {
        while ( getline (protein_file,line) )
        {
            if((offset= line.find(keyword,0))!= string::npos)
            {
                cout<<count+1<<")"<<line<<endl;
                ++count;
            }
            
        }
        if(count==0)
        {   cout<<"KEYWORD NOT FOUND"<<endl;
            search_by_keyword();
        }
        
        
        if(count>0)
        {
            cout<<"\n"<<count<<" matches found: "<<endl;
            cout<<"Type ";
        }
        
        protein_file.close();
    }else cout << "Unable to open file";
}

//prints selected protein description
void description()
{
    ifstream protein_file("protein_a.fa");
    string line;
    int offset;
    if (protein_file.is_open()) // for now only abridged //doesnt print protein sequence
    {
        bool lineFound = false;
        while ( getline (protein_file,line) )
        {
            if(!lineFound && (offset= line.find(search_id,0))!= string::npos)
            {
                lineFound = true;
                chosen.description=line;
            }
        }
    }
}

void print_sequence()
{
    int newtotal=0,total=0;
    ifstream protein_file("protein_a.fa");

    string line;
    int offset;
    if (protein_file.is_open()) // for now only abridged //doesnt print protein sequence
    {
        bool lineFound = false;
        while ( getline (protein_file,line) )
        {
            if(!lineFound && (offset= line.find(search_id,0))!= string::npos)
            {
                lineFound = true;
            }
            else if (lineFound)
            {
                if (line[0] != '>')
                {
                    chosen.sequence.push_back(line);
                    chosen.sequence.size();
                }
                else break;
            }
            newtotal=newtotal+total;
        }
        chosen.totalcount=newtotal;
    }
}

void protein_stats() //need to count total number and total of each
{
        cout<<"Total number of amino acids:"<<chosen.totalcount<<endl;
   
}

/*void protein_count()
{
    vector<int> v(26, 0);
                    
        for (auto s : chosen.sequence)
            for (auto c : s)
                ++v[c - int('A')];
    
    for (int i = 0 ;i < 26 ;++i)
    {  if(v[i])
                cout << char(i + 'A') << " : " << v[i] << endl;
    }
    
} */

void save_to_file()
{
    ifstream protein_file("protein_a.fa");
    string line;
    int offset;
    ofstream savefile;
    bool lineFound = false;
    savefile.open("selected_protein.txt");
    while ( getline (protein_file,line) )
    {
        if(!lineFound && (offset= line.find(search_id,0))!= string::npos)
        {   savefile<<line;
            lineFound = true;
        }
        else if (lineFound)
        {
            if (line[0] != '>')
                savefile<<line;
            else break;
        }
    }
    cout<<endl;
    cout<< "Selected protein has been saved to text file."<<endl;
    savefile.close();
}


//gets which protein file to open (full protein doesnt work)
int global_input()
{
    int choice;
    cout<<"\n*****WELCOME******"<<endl;
    cout<<"Please choose one."<<endl;
    cout<<"\nEnter 1 to load abridged protein data. "<<endl;
    cout<<"Enter 2 to load full protein data."<<endl;
    cout<<"Enter 3 to quit "<<endl;
    
    cin>>choice;
    if(choice==3)
        exit(0);
    return choice;
}


//main menu where user can choose what to view
int mainmenu_input ()
{
    int main_choice;
    cout<< "\n*****-----MAIN MENU-----******"<<endl;
    cout<<"Please choose one."<<endl;
    cout<<"\nEnter 1 to show overview of database. "<<endl;
    cout<<"Enter 2 to search by protein id.(DOESNT WORK YET)"<<endl;
    cout<<"Enter 3 to search by gi id. (Ex: 53828740) "<<endl;
    cout<<"Enter 4 to search by ref id. (Ex: XP_011542109.1) "<<endl;
    cout<<"Enter 5 to search by keywords."<<endl;
    cout<<"Enter 6 to quit "<<endl;
    
    cin>>main_choice;
    return main_choice;
}
