#include <iostream>
#include <fstream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

/*string Read_line()
{
    string line;

    ifstream myfile ("test.txt");

      if (myfile.is_open())  {

        while ( getline (myfile,line) )
        {
          cout << line << '\n';
        }
        myfile.close();
      }else{
          cout << "Unable to open file";
      }




    //line = ("Kakie 2 chisla nado peremnozhit, chtobi poluchilos 8?(-56,+2,-67,-16,+4)");

    return line;
} */



int FindCharFirst(string kek2,char character)
{
    std::size_t found = kek2.find_first_of(character);
    return found;
}



bool DoQuestion (string kek)
{
    vector <string> corrects;
    vector <string> answers;
    vector <string> user_check;
    vector <string> pluses;

    int skobka,counter,comma;
    //string kek;
    //kek = Read_line();
    skobka = FindCharFirst(kek,'(');

    counter = skobka;
    int ans_num=0;

    int closepoint = FindCharFirst(kek,')');

    std::size_t found = kek.find(',',skobka);



    string str_temp_first = kek.substr(skobka+2,found-skobka-2);
    answers.push_back(str_temp_first);

    string plusminus_str_first = kek.substr(skobka+1,1);
    corrects.push_back(plusminus_str_first);

    while (found<closepoint)
    {
        int found_temp=found;
        found=kek.find(",",found+1);
        string str_temp = kek.substr(found_temp+2,found-found_temp-2);
        string plusminus_str = kek.substr(found_temp+1,1);
        corrects.push_back(plusminus_str);
        if (found>closepoint)
        {
            str_temp = str_temp.substr(0, str_temp.size()-1);
            answers.push_back(str_temp);
        }
        else
        {
            answers.push_back(str_temp);
        }
    }

    string Question = kek.substr(0,skobka);
    cout<<"Question: "<<Question<<'\n';

    for (int i=0; i<answers.size(); i++)
        cout<<"Answer "<<i+1<<" is: "<<answers[i]<<'\n';



    cout<<"Vvedite otvety cherez zapyatuyu:"<<'\n';



    string otvet;
    string user_str_first;
    cin>>otvet;
    int user_ans = 0, user_ans_temp;

    user_ans=otvet.find_first_of(",");

    if (user_ans==-1)
    {
        user_str_first = otvet;
    }
    else
    {
        user_str_first = otvet.substr(0,user_ans);
    }

    user_check.push_back(user_str_first);
    while (user_ans<otvet.length())
    {
        if (user_ans==-1) break;
        user_ans_temp=user_ans;
        user_ans=otvet.find(",",user_ans+1);

        string user_str = otvet.substr(user_ans_temp+1,user_ans-user_ans_temp-1);

        user_check.push_back(user_str);

    }

    if (user_ans>0)
    {
        string user_str_last = otvet.substr(user_ans_temp+1,otvet.length()-user_ans_temp);

        user_check.push_back(user_str_last);
    }


    int True_counter=0;
    bool Mistake = false;


    for (int z=0; z<corrects.size(); z++)
    {
        string temp_check_mid = corrects[z];

        if (temp_check_mid.compare("+"))
        {


        }
        else
        {
            pluses.push_back("+");
        }

    }



    for (int y=0; y<user_check.size(); y++)
    {
        string temp_check = corrects[atoi( user_check[y].c_str())-1];

        if (temp_check.compare("+"))
        {
            cout<<"YOU ARE WRONG!\n\n";
            Mistake = true;
            break;
        }



        else
        {

            True_counter++;

        }




    }

    if ((pluses.size()==True_counter))
    {
        cout<<"CORRECT!\n\n";
    }
    else if (Mistake==false)
    {
        cout<<"YOU ARE WRONG!\n\n";
        Mistake = true;

    }

    return Mistake;
}

int main(){
    string line;
    int Correct_answers=0;
    int Questions=0;

    ifstream myfile ("test.txt");

      if (myfile.is_open())  {

        while ( getline (myfile,line) )
        {
          cout << line << '\n';
          if (!DoQuestion(line)) Correct_answers++ ;
          Questions++;
        }
        myfile.close();
      }else{
          cout << "Unable to open file";
      }

      cout<<"\nResult is: "<<Correct_answers<<"/"<<Questions<<".\n";




}

