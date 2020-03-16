#include "getsolution.h"
#include <sstream>
#include <QDebug>
#include <iomanip>

GetSolution::GetSolution()
{

}

string GetSolution::solve(string s)
{
    string ans;
    stringstream ss, ss1;
    int n;
    GetSolution m1, m2;
    vector<double> co1, b, x;
    double t;

    ss<<s;
    ss>>n;
//    qDebug() << n;

    co1.resize(0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ss >> t;
            co1.push_back(t);
        }
    }

    m1.setMatrix(n, n, co1);

    b.resize(0);
    for(int i = 0; i < n; i++) {
        ss >> t;
        b.push_back(t);
    }

    x = m1.Solution(b);

    for (int i=0; i<n; i++) {
        ss1<<fixed<<setprecision(2)<<x[i*(n+1)+n];
        ans += ss1.str() + " ";

        ss1.str("");
        ss1.clear();
    }

    ans.pop_back();

    return ans;
}

void GetSolution::setMatrix(int r,int c, vector<double> co) {
    row = r;
    column = c;
    coefficient.resize(co.size());
    coefficient = co;
}
vector<double> GetSolution::Solution(vector<double> b) {
    vector<double> co(row*(column+1), 0);
    double n;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
            co[i*(column+1)+j] = coefficient[i*column+j];
        co[i*(column+1)+column] = b[i];
    }

    for(int k = 1; k < row; k++)
    {
        for(int i = k; i < row; i++)
        {
            n = co[i*(column+1)+(k-1)]/co[(k-1)*(column+1)+(k-1)];
            for(int j = 0; j < (column+1); j++)
                co[i*(column+1)+j] -= n*co[(k-1)*(column+1)+j];
        }
    }

    for(int i = row-1; i >= 0; i--)
    {
        n = co[i*(column+1)+i];
        for(int j = 0; j < column+1; j++)
            co[i*(column+1)+j] /= n;

        for(int j = i-1; j >= 0; j--)
        {
            n = co[j*(column+1)+i];
            for(int k = 0; k < column+1; k++)
                co[j*(column+1)+k] -= n*co[i*(column+1)+k];
        }
    }
    return  co;
}
