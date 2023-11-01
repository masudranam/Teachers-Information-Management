#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
// map<string, pair<int, double>> M_m;

vector<string> V_S;

static int size1 = 6, size2;

struct Ans
{
    vector<string> Ans_s;
    vector<double> Ans_d;
    vector<int> Ans_i;
};

Ans *ans = new Ans();

double M_p = 0;
ifstream File;
// vector<vector<pair<double, int>>> V_m1[6];
vector<string> v_s[6];

vector<string> u_s;

void Read(int p)
{
    string n = to_string(p) + ".txt";
    File.open(n);
    string s;
    while (getline(File, s))
        v_s[p - 1].push_back(s);

    size2 = v_s[p - 1].size();
    File.close();
    // size1 = 6;
}

void print(auto v)
{
    for (auto &y : v)
    {
        cout << y << "\n";
    }
}

void read(string s)
{
    File.open(s);
    string ss;
    while (getline(File, ss))
    {
        u_s.push_back(ss);
    }
    // size1=u_s.size();
    File.close();
}

void Print(vector<string> &us)
{
    int p = 1;
    for (auto &x : us)
    {
        cout << p << "." << x << "  ";
        p++;
    }
    cout << endl;
}

void Menu()
{
    string s = "Main.txt";
    read(s);
    print(u_s);
}

void ShowBill()
{
    system("cls");
    cout << endl
         << endl
         << "..........................Your Bill.......................\n";
    // int l=ans->Ans_s.size();
    for (auto a : V_S)
        cout << a << endl
             << endl;

    cout << "\n\t\t\t\t\tTotal Price : ";
    printf("%0.3lf",M_p);
}

void Info(int l_i, int m_i)
{
    // map<string,>m;
    string s = v_s[m_i][l_i];
    // M_m[s];
    cout << "...........................Info of item " << s << "....................." << endl;
    int q;
    double p;
    q = rand() % 10 + 1;
    p = (rand() % 100 + 10) / 1.55;
    cout << "\tQuantity: " << q << "\n\tPrice: " << p << " Taka (per kilo/liter/peice)\n\n";
    int Q;
    cout << "Enter Quantity: ";
    cin >> Q;
    int ii = 1;
    while (1)
    {
        if (ii == 5)
        {
            cout << "Error occured\n";
            ShowBill();
            return;
        }
        if (Q < 1 || q - Q < 0)
        {
            cout << "\nIteam out of stock. Enter Quantity again: ";
            cin >> Q;
        }
        else
        {
            break;
            // cout << "Iteam out of stock. Enter Quantity again: ";
            // cin >> Q;
        }
        ii++;
    }
    cout << endl;
    s = "";
    // if(q-Q<0){cout<<"Iteam out of stock.\n";return;}
    s = "Product name: " + v_s[m_i][l_i] + "       Price: " + to_string(p) + " Taka     Brought: " + to_string(Q);
    V_S.push_back(s);
    M_p += (double)(p * Q);
}

// void ShowBill()
// {
//     system("cls");
//     cout << endl
//          << endl
//          << "..........................Your Bill.......................\n";
//     // int l=ans->Ans_s.size();
//     for (auto a : V_S)
//         cout << a << endl
//              << endl;

//     cout << "\n\t\t\t\t\tTotal Price : " << M_p;
// }

int main()
{
    srand(time(0));
    string s = "Main.txt";
    Menu();
    // getch();
    int op;
    // read(s);
    // print(u_s);
    int valid = 1, it = 0;
    while (valid)
    {
        // if (it % 2 == 0 && it)
        // {
        //     Menu();
        //     // system("cls");
        // }
        if (it >= 1)
            cout << "\npress 0 to see bill.\n";
        // Menu();
        if(!it)cout << "\nEnter product type no : ";
        else cout<<"\nYou may chose another iteam. Enter Product type no: ";
        cin >> op;
        int ii = 1;
        while (1)
        {
            if (op == 0)
            {
                ShowBill();
                return 0;
            }
            if (op <= size1)
                break;
            cout << "\nWrong option...!..Enter product type no again : ";
            cin >> op;
            if (op <= size1)
                break;
            if (ii == 5)
            {
                cout << "Error!!....Try again.";
                return 0;
            }
            ii++;
        }
        // if (op == 0)
        // {
        //     ShowBill();
        //     break;
        // }
        // system("cls");
        cout<<endl;
        Read(op);
        Print(v_s[op - 1]);
        int m_i = op - 1;
        cout << "\nEnter a option for the iteam : ";
        cin >> op;
        ii = 1;
        while (1)
        {
            if (op == 0)
            {
                ShowBill();
                return 0;
            }
            if (op <= size2)
                break;
            cout << "\nWrong option...!..Enter iteam no again : ";
            cin >> op;
            if (op <= size2)
                break;
            if (ii == 5)
            {
                cout << "Error!!....Try again.";
                return 0;
            }
            ii++;
        }
        // if (op == 0)
        // {
        //     ShowBill();
        //     break;
        // }
        // system("cls");
        // Menu();
        // if (it)
        //     cout << "press 0 to see bill.\n";
        int l_i = op - 1;
        Info(l_i, m_i);
        it++;
    }
    // cout << "start again";
    // for(auto ans:M_m)
    // {
    //     // cout<<
    //     printf("Product name: %s       Price: %lf     Brought: %d\n",ans.first,ans.second.first,ans.second.second);
    // }
    // cout<<"\t\t\t\t\tTotal Price : "<<M_p;

    return 0;
}