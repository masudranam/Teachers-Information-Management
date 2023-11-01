#include <bits/stdc++.h>
using namespace std;

bool Wrong(int a, int b)
{
    if (a > b)
    {
        cout << "Enter a correct no.\n";
        return false;
    }
    return true;
}

int main()
{
    cout << "\n\t\t\t..........University Type..........\n";
    string U_t;
    ifstream U_u_f;
    U_u_f.open("main.txt");
    int P = 1;
    vector<string> U_n_v;
    while (getline(U_u_f, U_t))
    {
        U_n_v.push_back(U_t);

        cout << P << ". " << U_t << endl;
        P++;
    }
    int op;
    cout << "\nChose University Type : ";
    cin >> op;
    system("cls");

    string F_nn, F_n, U_n;
    F_nn = U_n_v[op - 1] + '/' + "main.txt";
    F_n = U_n_v[op - 1] + '/';
    ifstream File;
    // file.open();
    File.open(F_nn);
    P = 1;
    vector<string> v;
    cout << "\n\n\t\t\t University List........\n\n";
    while (getline(File, U_n))
    {
        // string Ptr;
        // ifstream name;
        v.push_back(U_n);
        // for(auto &x:U_n)

        cout << P << ". " << U_n << "\n";
        if(P%5==0)cout<<endl;
        P++;
    }
    int size1 = v.size();
    //  op;
    // while()
    cout << "\nEnter the University No : ";
    cin >> op;
    int ii = 1;
    while (1)
    {
        if (Wrong(op, size1))
            break;
        cout << "\nEnter the correct University No : ";
        cin >> op;
        if (ii == 5)
        {
            cout << "Error occur. Try again.\n";
            return 0;
        }
        ii++;
    }
    system("cls");

    string Ptr;
    ifstream name;
    string Uni_name = v[op - 1];
    string s = F_n + v[op - 1] + "/" + v[op - 1] + ".txt";
    // cout << "Path " << s << endl;
    name.open(s);
    P = 1;
    vector<string> vvs;
    cout << "\n\t\t\tIT Background Depertments of " << Uni_name << " are.......\n\n";
    while (getline(name, Ptr))
    {
        vvs.push_back(Ptr);
        cout << P << ". " << Ptr << "\n";
        // if(P%5==0)cout<<endl;
        P++;
    }
    s = F_n + v[op - 1] + "/";
    size1 = vvs.size();
    cout << "\nEnter Depertment no : ";
    cin >> op;
    ii = 1;
    while (1)
    {
        if (Wrong(op, size1))
            break;
        if (ii == 5)
        {
            cout << "Error occur. Try again.\n";
            return 0;
        }
        cout << "\nEnter the correct Depertment No : ";
        cin >> op;
        ii++;
    }
    system("cls");
    s += vvs[op - 1] + ".txt";
    string Dept_n = vvs[op - 1];
    // cout << s << endl;
    // mbstu\ICT.txt
    ifstream Mname;
    Mname.open(s);
    string Ss;
    vector<vector<string>> vs, vss;
    vector<string> ss, sss;
    string nn = "", nm = "";
    while (getline(Mname, Ss))
    {
        for (int i = 0; Ss[i]; ++i)
        {
            // if (Ss[i] != '/' || Ss[i] != ';')
            if (Ss[i] == ';')
                break;
            if (Ss[i] == '/')
                continue;
            nn += Ss[i];
            // if (Ss[i] != '/'||Ss[i]!=';')
            //     nm+=Ss[i];
        }
        if (Ss != "")
            ss.push_back(Ss);
        if (nn != "")
            sss.push_back(nn);
        nn = "";
    }
    // vs.push_back(ss);
    cout << "\n\t\t\tTeacher List of " << Dept_n << " Depertment of " << Uni_name << " .....\n\n";
    vss.push_back(sss);
    int p = 1;
    string st = "";
    for (auto ans : vss)
    {
        for (auto x : ans)
        {
            // if(x!='/'||x!=)
            cout << p << ". " << x << "\n";
            // if(p%5==0)cout<<endl;
            if (x == " ")
                break;
            st = x;
            p++;
        }
        // cout << p << "." << ans << endl;
    }
    size1 = ss.size();
    cout << "\nEnter Teacher no : ";
    cin >> op;
    ii = 1;
    while (1)
    {
        if (Wrong(op, size1))
            break;
        if (ii == 5)
        {
            cout << "Error occur. Try again.\n";
            return 0;
        }
        cout << "\nEnter correct teacher no : ";
        cin >> op;
        ii++;
    }
    system("cls");
    auto it = ss.begin();
    advance(it, op - 1);
    // cout << *it;
    vector<string> Fans(3, "");

    // for (auto x : *it)
    // {
    //     //    cout << "Name : ";
    //     // if (x == '/')
    //     // {
    //     //     cout << "Name : ";
    //     //     continue;
    //     // }
    //     if (x == ';')
    //     {
    //         cout << "\nEmail : ";
    //         continue;
    //     }
    //     else if (x == ':')
    //     {
    //         cout << "\nMobile No : ";
    //         continue;
    //     }
    //     else
    //         cout << "Name : ";
    //     cout << x;
    // }
    int v1 = 0, v2 = 0, v3 = 0;
    for (auto x : *it)
    {
        if (x == ';')
            v1 = 1;
        if (!v1 && !v2 && x != '/')
            Fans[0].push_back(x);
        if (x == ':')
            v2 = 1;
        if (v1 && !v2 && x != ';')
            Fans[1].push_back(x);
        if (v1 && v2 && x != ':')
            Fans[2].push_back(x);
    }
    cout << "\n\t\t\t Information About " << Fans[0] << " (Sir/Mam) From " << Uni_name << endl
         << endl
         << endl;
    if (Fans[2].size() < 3)
        Fans[2] = "Not Found";
    if (Fans[1].size() < 2)
        Fans[2] = "Not Found";
    cout << "Name : " << Fans[0] << " \n"
         << "Email : " << Fans[1] << " \n"
         << "Monile no : " << Fans[2];

    // getchar();
}